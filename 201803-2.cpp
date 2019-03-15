#include<cstdio>
#include<algorithm>

using namespace std;

struct ball{
	int num;
	int pos;
	int left;
	int right;
}balls[101];

bool cmp1(ball a, ball b){
	return a.pos < b.pos;
}

bool cmp2(ball a, ball b){
	return a.num < b.num;
}

int main(void){
	int N,L,T;
	scanf("%d%d%d",&N,&L,&T);
	for(int i = 0; i < N; i++){
		balls[i].num = i;
		balls[i].right = 1;
		balls[i].left = 0;
		scanf("%d",&balls[i].pos);
	}
	sort(balls,balls+N,cmp1);
//	for(int i = 0; i < N; i++){
//		printf("%d %d\n",balls[i].num,balls[i].pos);
//	}
	for(int i = 0; i < T; i++){
		//进行一次位置的改变
		for(int j = 0; j < N; j++){
			balls[j].pos = balls[j].pos+balls[j].right-balls[j].left;
		}
		
		//然后开始 判断是否需要改变方向
		for(int j = 0; j < N; j++){
			//第一个球碰到了左边且是向左移动的 
			if(balls[j].pos == 0 && balls[j].left == 1){
				balls[j].left = 0;
				balls[j].right = 1;
			}
			//最后一个球碰到了右边且是向右移动的 
			if(balls[j].pos == L && balls[j].right == 1){
				balls[j].right = 0;
				balls[j].left = 1;
			}
			if(j != 0){
				//相撞 
				if(balls[j].pos == balls[j-1].pos){
					balls[j].left = !balls[j].left;
					balls[j].right = !balls[j].right;
					balls[j-1].left = !balls[j-1].left;
					balls[j-1].right = !balls[j-1].right;
				}
			} 
		} 
	}
	
	sort(balls,balls+N,cmp2);
	for(int i = 0; i < N; i++){
		printf("%d ",balls[i].pos);
	}
	
	
}
