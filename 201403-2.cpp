#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

struct TAN{
	int x1,x2,y1,y2;
	int num;
	int pri;
};

bool cmp(TAN a, TAN b){
	return a.pri < b.pri;
}

int main(void){
	int N,M;
	scanf("%d%d",&N,&M);
	struct TAN tan[N];
	//将所有的窗口利用结构体表示出来 
	for(int i = 0; i < N; i++){
		scanf("%d%d%d%d",&tan[i].x1,&tan[i].y1,&tan[i].x2,&tan[i].y2);
		tan[i].pri = N-i;
		tan[i].num = i+1;
	} 
	sort(tan,tan+N,cmp);
	
	int x,y;
	int findxy = 0;
	for(int i = 0; i < M; i++){
		scanf("%d%d",&x,&y);
		findxy = 0;
		//对窗口按优先级进行遍历，看(x,y)是否在窗口上 
		for(int j = 0; j < N; j++){
			//如果发现(x,y)在窗口上，则将该窗口优先级置为1，将前面所有窗口的优先级++ 
			if(x >= tan[j].x1 && x <= tan[j].x2 && y >= tan[j].y1 && y <= tan[j].y2){
				findxy = 1;
				printf("%d\n",tan[j].num);
				tan[j].pri = 1;
				//原先在该窗口之上的窗口优先级全部++ 
				for(int k = j-1; k >= 0; k--){
					tan[k].pri++;
				}
				//对窗口结构体重新进行排序,退出循环 
				sort(tan,tan+N,cmp);
				break;
			}
		}
		if (findxy == 0) printf("IGNORED\n");
		
	}
}
