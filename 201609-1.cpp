#include<cstdio>
#include<cmath>

int main(void){
	int N;
	scanf("%d",&N);
	int a=0,b=0;
	int res = 0;
	for(int i = 0; i < N; i++){
		a = b;
		scanf("%d",&b);
		if(i > 0){
			if(fabs(a-b) > res) res = fabs(a-b);
		}
	} 
	
	printf("%d",res);
}
