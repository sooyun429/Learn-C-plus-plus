# 191212 | 4일차 Counting & Probability

## 과제 내용

  <이론 강의 영상>
SW EXPERT ACADEMY -> Learn -> Course -> Programming Professional -> n일차

<문제>
SW EXPERT ACADEMY -> Learn -> Course -> Programming Professional -> n일차 -> 제일 하단

4일차 Counting & Probability 

(11시 30분)

\1. 4일차 Inversion Counting
\2. 3064. Binary Indexed Tree (club box 에 있습니다.)  





|  K번째 Dijkstra

https://www.acmicpc.net/problem/1854
http://boj.kr/aedc1cb66eae41e1815acc78fa5de2f8

```c++
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define M 1009
#define INF 1e9+9
using namespace std;

struct pp{
	int data, pos;
	pp(){}
	pp(int p, int d){ pos=p; data=d; }
	bool operator<(const pp &q)const{
		return data > q.data;
	}
};

vector<int> d[M];
vector<pp> v[M];
priority_queue<pp> q;
int n,m,k,chk[M];

bool put(int pos, int data){
	if (!d[pos].empty() && d[pos].back() < data) return false;
	d[pos].push_back(data);
	for (int i=d[pos].size()-1;i>0;i--) if (d[pos][i] < d[pos][i-1]) swap(d[pos][i], d[pos][i-1]);
	while (d[pos].size() > k) d[pos].pop_back();
	return true;
}

void dijkstra(){
	int i;
	for (i=1;i<=n;i++) put(i, INF);
	
	q.push(pp(1, 0));
	put(1,0);
	while(!q.empty()){
		pp here = q.top(); q.pop();
		if (chk[here.pos] >= k) continue;
		chk[here.pos]++;
		for (int j=0;j<v[here.pos].size();j++){
			pp there = v[here.pos][j];
			if (put(there.pos, here.data + there.data))
				q.push(pp(there.pos, here.data + there.data));
		}
	}
	for (i=1;i<=n;i++){
		if (d[i].size() < k || d[i][k-1] == INF) printf("-1\n");
		else printf("%d\n",d[i][k-1]);
	}
}

int main(){
	int i;
	scanf("%d %d %d",&n,&m,&k);
	for (i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(pp(b,c));
	}
	dijkstra();
}
```







2일차 - 가장 짧은 길 전부 청소하기
도 풀어주세요.
우리가 배운 Dijkstra 를 활용하여 생각해보면 좋습니다.



가장 짧은 길 전부 청소하기

```c++
#include <stdio.h>
#include <algorithm>
#define N_MAX 200009
#define M 1000009
using namespace std;
 
struct Edge {
	int left, right;
	long long int dist;
	Edge(){}
	Edge(int a, int b, long long int c) { left=a; right=b; dist=c; }
}edge[M], temp[M];
 
struct min_heap {
	int N;
	Edge s[M];	
	void init() { N=0; }
	void push(Edge a){
		s[++N] = a;
		for (int i=N;i>1;i>>=1){
			int j = i>>1;
			if (s[i].dist < s[j].dist) swap(s[i], s[j]);
			else break;
		}
	}
	bool empty(){ return N==0; }
	void pop(){
		s[1]=s[N--];
		for (int i=1;i*2<=N;){
			int j = 2*i;
			if (2*i+1<=N && s[2*i+1].dist < s[2*i].dist) j=2*i+1;
			if (s[i].dist > s[j].dist){ swap(s[i], s[j]); i=j; }
			else break;
		}
	}
	Edge top(){ return s[1]; }
}q;
 
void sort(int left, int right){
	if (left == right) return;	
	int mid=(left+right)>>1;
	sort(left, mid); sort(mid+1, right);
	int l = left, r = mid+1, i = left;
	while(l <= mid && r <= right){
		if (edge[l].left < edge[r].left) temp[i++] = edge[l++];
		else temp[i++] = edge[r++];
	}
	while(l <= mid) temp[i++] = edge[l++];
	while(r <= right) temp[i++] = edge[r++];
	for (i=left;i<=right;i++) edge[i] = temp[i];
}
 
int tc, n, m, chk[N_MAX], start_i[N_MAX], end_i[N_MAX];
long long int d[N_MAX], ans, local_min;
 
void dijkstra(){
	int i;
	for (i=1;i<=n;i++) d[i]=-1;
	q.init();
	q.push(Edge(1, 0, 0));
	d[1] = 0;
	while(!q.empty()){
		Edge here = q.top(); q.pop();
		if (d[here.left] < here.dist) continue;
		for (i=start_i[here.left];i<=end_i[here.left];i++){
			Edge there = edge[i];
			if (d[there.right] == -1 || d[there.right] > here.dist + there.dist) {
				d[there.right] = here.dist + there.dist;
				q.push(Edge(there.right, 0, d[there.right]));
			}
		}
	}
}
 
int main(){
	int i;
	int T; scanf("%d",&T); while (T--) {
		scanf("%d %d",&n,&m);
		for (i=1;i<=m;i++){
			scanf("%d %d %d", &edge[2*i-1].left, &edge[2*i-1].right, &edge[2*i-1].dist);
			edge[2*i] = Edge(edge[2*i-1].right, edge[2*i-1].left, edge[2*i-1].dist);
		}
		m<<=1;
		sort(1, m);
		for (i=1;i<=n;i++) start_i[i]=0;
		for (i=1;i<=m;i++){
			if (!start_i[edge[i].left]) start_i[edge[i].left] = i;
			end_i[edge[i].left] = i;
		}
		dijkstra();
		ans = 0;
		for (i=2;i<=n;i++) {
			local_min = 2e9+9;
			for (int j=start_i[i];j<=end_i[i];j++) 
				if (d[edge[j].right] + edge[j].dist == d[edge[j].left] && local_min > edge[j].dist)
					local_min = edge[j].dist;
			ans += local_min;
		}
		printf("#%d %lld\n", ++tc, ans);
	}
}
```





basic Indexed Tree code & Inversion counting (with BIT)

```c++
#include <stdio.h>
#define M 131072
 
int n, m, tc, index[2*M+9];
 
void update(int pos, int delta){
	while(pos){
		index[pos]+=delta;
		pos>>=1;
	}
}
 
int get(int left, int right){
	int ret=0;
	while(left<=right){
		if (left==right){
			ret+=index[left];
			break;
		}
		if (left&1) ret+=index[left],left++;
		if (!(right&1)) ret+=index[right],right--;
		left>>=1;
		right>>=1;
	}
	return ret;
}
 
//// BIT	
//int main(){
//	int i;
//	int T; scanf("%d",&T); while(T--){
//		printf("#%d",++tc);
//		scanf("%d %d\n",&n,&m);
//		for (i=1;i<2*M;i++) index[i]=0;
//		for (i=1;i<=n;i++) {
//			int a;
//			scanf("%d", &a);
//			update(i+M-1, a);
//		}
//		for (i=1;i<=m;i++){
//			int a,b,c;
//			scanf("%d %d %d",&a,&b,&c);
//			if (a==1) update(b+M-1, c);
//			else printf(" %d",get(b+M-1, c+M-1));
//		}
//		printf("\n");
//	}
//}
 
// INVERSION
int pos[M];
int main(){
	int i;
	long long int sum;
	int T; scanf("%d", &T); while(T--){
		printf("#%d", ++tc);
		scanf("%d",&n);
		for (i=1;i<2*M;i++) index[i]=0;
		for (i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			pos[a] = i;
		}
		sum = 0;
		for (i=1;i<=n;i++){
			sum += get(pos[i]+1+M-1, n+M-1);
			update(pos[i]+M-1, 1);
		}
		printf(" %lld\n",sum);
	}
}
```



adjacency_list

```c++
#include <stdio.h>
#include <algorithm>
#define MAX_N 10009
#define MAX_M 1000009
using namespace std;
 
struct Edge {
	int left, right, dist;
	Edge() {}
	Edge(int _left, int _right, int _dist){
		left = _left;
		right = _right;
		dist = _dist;
	}
	bool operator<(const Edge &e)const{
		return left < e.left;
	}
};
 
struct dynamic_adjacency_list {
	int m, start_index[MAX_N];
	Edge e[MAX_M];
	void init(int n){
		m = 0;
		for (int i=1;i<=n;i++) start_index[i]=0;
	}
	void push(int _left, int _right, int _dist){
		e[++m] = Edge(_left, _right, _dist);
	}
	void sort(){
		std::sort(e+1, e+m+1);
		for (int i=1;i<=m;i++) if (!start_index[e[i].left]) start_index[e[i].left] = i;
	}
	int get_start(int left){
		return start_index[left];
	}
}edge_list;
 
int main(){
	int n,m,k,i;
	scanf("%d %d %d",&n,&m,&k);
	edge_list.init(n);
	for (i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edge_list.push(a,b,c);
	}
	edge_list.sort();
	for (i=1;i<=edge_list.m;i++) printf("%d %d %d\n",edge_list.e[i].left, edge_list.e[i].right, edge_list.e[i].dist);
}
```

