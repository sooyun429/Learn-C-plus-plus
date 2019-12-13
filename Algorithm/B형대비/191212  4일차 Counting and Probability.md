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



2일차 - 가장 짧은 길 전부 청소하기
도 풀어주세요.
우리가 배운 Dijkstra 를 활용하여 생각해보면 좋습니다.



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

