#include<cstdio>

int main(void){
	int a,b;
	int num = 1;
	int N;
	scanf("%d",&N);
	if(N == 1){
		scanf("%d",&a);
		printf("%d",num);
	} 
	else{
		scanf("%d",&a);
		for(int i = 1; i < N; i++){
			scanf("%d",&b);
			if(b != a) num++;
			a = b;
		}
		printf("%d",num);
	} 
}
