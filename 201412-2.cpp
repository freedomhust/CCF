#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>

int main(void){
	int M;
	int quat[500][500];
	memset(quat,0,sizeof(quat));
	scanf("%d",&M);

	for(int m = 0; m < M; m++){
		for(int n = 0; n < M; n++){
			scanf("%d",&quat[m][n]);
		}
	}
	int i = 0;
	int j = 0;
	int status = 0;
	printf("%d ",quat[i][j]);
	
	while(M != 1){
		if(i == 0 && j < M-1 && status != 1){
			j++;
			printf("%d ",quat[i][j]);
			status = 1;
			if(i == M-1 && j == M-1) break;
			continue;
		}
		else if(j == M-1 && status != 1){
			i++;
			printf("%d ",quat[i][j]);
			status = 1;
			if(i == M-1 && j == M-1) break;
			continue;
		}
		else if(i < M-1 && j == 0 && status != 0){
			i++;
			printf("%d ",quat[i][j]);
			status = 0;
			if(i == M-1 && j == M-1) break;
			continue;
		}
		else if(i == M-1 && status != 0){
			j++;
			printf("%d ",quat[i][j]);
			status = 0;
			if(i == M-1 && j == M-1) break;
			continue;
		}
		
		if(status){
			i++;
			j--;
			printf("%d ",quat[i][j]);
		}
		else{
			i--;
			j++;
			printf("%d ",quat[i][j]);
		}
		
		if(i == M-1 && j == M-1) break;
	}
}
