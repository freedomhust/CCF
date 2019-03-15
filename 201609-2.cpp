#include<cstdio>
#include<cstring>

int seats[20][6];
int op[105];

int main(void){
	memset(seats,0,sizeof(seats));
	memset(op,0,sizeof(op));
	
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&op[i]);
	}
	
//	for(int i = 0; i < N; i++) printf("%d ",op[i]);

	for(int i = 0; i < N; i++){
		int suitable = 0; 
		//遍历每一排 
		for(int j = 0; j < 20; j++){
			int full = 0;
			int num = 0;
			for(int k = 1; k <= 5; k++){
				if(seats[j][k] == 1) full = k;
				else{
					//如果位置是连续的 
					if(k != 1 && seats[j][k-1] == 0){
						num++; 
					}
					//如果位置不连续表明找到了第一个空位 
					else num = 1;
				}
				//如果此时找到的位置数已经能满足要求 
				if(num == op[i]) break; 
			}
			//如果是因为满足条件所以退出了循环 
			if(num == op[i]){
				//相应位置置为1，打出所有满足条件的位置号
				for(int k = full+1; k <= full+num; k++){
					seats[j][k] = 1;
					printf("%d ",j*5+k);
				}
				if(i != N-1) printf("\n");
				suitable = 1;
				//退出这次循环进行下一个买票操作循环 
				break;
			} 
			//如果只是因为遍历到5且没有满足条件退出了循环，不需要进行任何操作，继续遍历下一排就好 
			else{
				
			} 
			
		}
		
		//如果遍历完所有的排发现没有满足条件的,直接硬塞就行 
		if(suitable == 0){
			int num = 0;
			for(int j = 0; j < 20; j++){
				for(int k = 1; k <= 5; k++){
					if(seats[j][k] == 0){
						seats[j][k] = 1;
						num++;
						printf("%d ",j*5+k);
						//如果已经塞完 
						if(num == op[i]){
							if(i != N-1) printf("\n");break; 
						}
					}
				}
				if(num == op[i]){
					suitable = 1;
					break;
				}
			}
		}
	}
	
	
}
