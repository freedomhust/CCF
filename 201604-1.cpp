#include<cstdio>

int num[1001];

int main(void){
	int x=0,y=0,z=0;
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&num[i]);
	}
	
	int res = 0;
	for(int i = 1; i < N-1; i++){
		if((num[i-1] > num[i] && num[i+1] > num[i]) 
		||(num[i] > num[i-1] && num[i] > num[i+1]) )
		res++;
	}
	printf("%d",res);
}
