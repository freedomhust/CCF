#include<cstdio>
#include<cstring>

int num[30][30];
int status[30][30];

int main(void){
	memset(num,0,sizeof(num));
	memset(status,0,sizeof(status));
//	for(int i = 0; i < 30; i++){
//		for(int j = 0; j < 30; j++){
//			printf("%d ",status[i][j]);
//		}
//		printf("\n");
//	}
	int M,N;
	scanf("%d%d",&M,&N);
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			scanf("%d",&num[i][j]);
		}
	}
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			//开始对数组中的每一个值进行讨论
			int place = 0;
			
			//往左边平移看 
			for(int x = j; x >= 0; x--){
				//如果左边的值和正在进行判断的值相等 
				 if(num[i][x] == num[i][j]){
				 	place = x;
				 }
				 else break;
			}
			//如果满足条件 
			if(j-place >= 2){
				for(int k = place; k <= j; k++) status[i][k] = 1; 
			} 
			
			//往右边平移看
			for(int x = j; x < N; x++){
				//如果右边的值和正在进行判断的值相等
				if(num[i][x] == num[i][j]){
					place = x;
				} 
				else break;
			} 
			//如果满足条件
			if(place-j >= 2){
				for(int k = j; k <= place; k++) status[i][k] = 1;
			} 
			
			
			//往上边平移看看
			for(int y = i; y >= 0; y--){
				if(num[y][j] == num[i][j]){
					place = y;
				}
				else break;
			} 
			//如果满足条件
			if(i-place >= 2){
				for(int k = place; k <= i; k++) status[k][j] = 1;
			} 
			
			//向下移进行判断
			for(int y = i; y < M; y++){
				if(num[y][j] == num[i][j]){
					place = y;
				}
				else break;
			} 
			//如果满足条件
			if(place-i >= 2){
				for(int k = i; k <= place; k++) status[k][j] = 1;
			} 

//			if(j+2 < N){
//				if(num[i][j] == num[i][j+1] && num[i][j+1] == num[i][j+2]){
//					status[i][j] = 1;
//					status[i][j+1] = 1;
//					status[i][j+2] = 1;
//				} 
//			}
//			if(i+2 < M){
//				if(num[i][j] == num[i+1][j] && num[i+1][j] == num[i+2][j]){
//					status[i][j] = 1;
//					status[i+1][j] = 1;
//					status[i+2][j] = 1;
//				} 
//			}
		}
	}
	
	//输出
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++){
			if(status[i][j] == 1) printf("0");
			else printf("%d",num[i][j]); 
			if(j != N-1) printf(" ");
		}
		if(i != M-1) printf("\n"); 
	}
}
