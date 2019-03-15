#include<cstdio>
#include<cstring>

int main(void){
	int quat[15][10];
	int small_quat[4][4];
	int place;
	memset(quat,0,sizeof(quat));
	memset(small_quat,0,sizeof(small_quat));
	for(int i = 14; i >= 0; i--){
		for(int j = 0; j < 10; j++){
			scanf("%d",&quat[i][j]);
		} 
	}
	
	for(int i = 3; i >= 0; i--){
		for(int j = 0; j < 4; j++){
			scanf("%d",&small_quat[i][j]);
		}
	}
	scanf("%d",&place);
	
	//确认小矩阵的底部为1的有多少
	int  bottom[4];
	for(int i = 0; i < 4; i++) bottom[i] = -1;
	for(int j = 0; j < 4; j++){
		for(int i = 0; i < 4; i++){
			if(small_quat[i][j] == 1){
				bottom[j] = i;
				break;
			}
		}
	}
	int hang[4],lie[4];
	int k = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(small_quat[i][j] == 1){
				hang[k] = i;
				lie[k] = j;
				k++;
			}
		}
	}
//	for(int i = 0; i < 4; i++) printf("%d ",bottom[i]);
	
	//确定列偏移 
//	for(int i = 0; i < 4; i++){
//		if(bottom[i] != -1){
//			place = place-i;
//			break;
//		}
//	}
	place = place -1;
	
	int x,y;
	//不断向下移动，直到达到退出的条件为止 
	for(x = 0; x <= 16; x++){
		int stop = 0;
		//判断下方是否有方块或者是否已经到达边界
		for(y = 0; y < 4; y++){
			if(bottom[y] != -1){
				//如果已经到底了 
				if(bottom[y]+12-x == 0) stop = 1;
				else{
					//如果这个部分的模块的下一个位移里有方块 
					if(quat[bottom[y]+12-x-1][y+place] == 1) stop = 1;
				}
			}
		}
		if(stop == 1) break;
	}
	
	for(int i = 0; i < 4; i++){
		quat[hang[i]+12-x][lie[i]+place] = 1;
	} 
	
	for(int i = 14; i >= 0; i--){
		for(int j = 0; j < 10; j++){
			printf("%d ",quat[i][j]);
		} 
		printf("\n");
	}
	
	
}
