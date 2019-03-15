#include<stdio.h>

int x[1000][1000];
int main(void){
	int M,N;
	scanf("%d%d",&M,&N);
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			scanf("%d",&x[i][j]);
		}
	}
	
	for(int k = N-1; k >= 0; k--){
		for(int l = 0; l < M; l++){
			printf("%d ",x[l][k]);
		}
		printf("\n");
	}
}
