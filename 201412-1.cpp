#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>

int main(void){
	int M,N;
	int readers[1000];
	memset(readers,0,sizeof(readers));
	
	scanf("%d",&M);
	for(int i = 0; i < M; i++){
		scanf("%d",&N);
		readers[N-1]++;
		printf("%d ",readers[N-1]);
	}
	return 0;
}
