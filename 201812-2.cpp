#include<cstdio>

int main(void){
	int r,y,g;
	scanf("%d%d%d",&r,&y,&g);
	int N;
	scanf("%d",&N);
	long long time = 0;
	int status,t;
	for(int i = 0; i < N; i++){
		scanf("%d%d",&status,&t);
		long long k = time%(r+g+y); 
		//�ǵ�·�Ļ�ֱ�ӼӾͺ� 
		if(status == 0){
			time = time+t;
		}
		//�Ǻ�Ƽ��㵽·��ʱ��ʲô�� 
		else if(status == 1){
			if(k < t){
				time = time + t-k;
			} 
			else if(k >= t && k < t+g){
				time = time+0;
			}
			else if(k >= t+g && k < r+g+y){
				time = time + g+y+r-k+t;
			}
		}
		//�ǻƵƼ��㵽·��ʱ��ʲô�� 
		else if(status == 2){
			if(k < t+r){
				time = time + t+r-k;
			} 
			else if(k >= t+r && k < t+r+g){
				time = time + 0;
			}
			else if(k >= t+r+g && k < r+g+y){
				time = time + t+r + g+r+y - k;
			}
		}
		//�̵�ֱ�ӹ� 
		else if(status == 3){
			if(k < t){
				time = time+0;
			}
			else if(k >= t && k < t+y+r){
				time = time + t+y+r - k;
			}
			else if(k >= t+y+r && k < r+g+y){
				time = time + 0;
			}
		}
	}
	printf("%lld",time);
}
