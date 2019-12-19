# 191213 | 5일차 Counting & Probability + Dynamic Prgramming

## 과제 내용

  <이론 강의 영상>
SW EXPERT ACADEMY -> Learn -> Course -> Programming Professional -> n일차

<문제>
SW EXPERT ACADEMY -> Learn -> Course -> Programming Professional -> n일차 -> 제일 하단

5일차 Counting & Probability + Dynamic Programming

(11시 30분)

\1. Pro course -> 동적계획법 -> Largest Empty Square
\2. Pro course -> Counting & Probability -> Pole
\3. Problem -> 3135. 홍준이의 사진 놀이 (Club box 에 있습니다.)  



trie (1).pptx 2 Largest Empty Square.pptx 1 Pole.pptx



trie (c++)

```c++
#include <stdio.h>
 
struct NODE {
	NODE *next[26];
	int sum;
	NODE(){ sum = 0; }
}*root;
 
void init() {
	root = new NODE();
}
 
void insert(int buffer_size, char *buf){
	NODE *here = root;
	while(*buf){
		if (here->next[*buf-'a'] == nullptr) here->next[*buf-'a'] = new NODE();
		here = here->next[*buf-'a'];
		here->sum++;
		buf++;
	}
}
 
int query(int buffer_size, char *buf){
	NODE *here = root;
	while(*buf){
		if (here->next[*buf-'a'] == nullptr) return 0;
		here = here->next[*buf-'a'];
		buf++;
	}
	return here->sum;
}
```

