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
		//����ÿһ�� 
		for(int j = 0; j < 20; j++){
			int full = 0;
			int num = 0;
			for(int k = 1; k <= 5; k++){
				if(seats[j][k] == 1) full = k;
				else{
					//���λ���������� 
					if(k != 1 && seats[j][k-1] == 0){
						num++; 
					}
					//���λ�ò����������ҵ��˵�һ����λ 
					else num = 1;
				}
				//�����ʱ�ҵ���λ�����Ѿ�������Ҫ�� 
				if(num == op[i]) break; 
			}
			//�������Ϊ�������������˳���ѭ�� 
			if(num == op[i]){
				//��Ӧλ����Ϊ1�������������������λ�ú�
				for(int k = full+1; k <= full+num; k++){
					seats[j][k] = 1;
					printf("%d ",j*5+k);
				}
				if(i != N-1) printf("\n");
				suitable = 1;
				//�˳����ѭ��������һ����Ʊ����ѭ�� 
				break;
			} 
			//���ֻ����Ϊ������5��û�����������˳���ѭ��������Ҫ�����κβ���������������һ�žͺ� 
			else{
				
			} 
			
		}
		
		//������������е��ŷ���û������������,ֱ��Ӳ������ 
		if(suitable == 0){
			int num = 0;
			for(int j = 0; j < 20; j++){
				for(int k = 1; k <= 5; k++){
					if(seats[j][k] == 0){
						seats[j][k] = 1;
						num++;
						printf("%d ",j*5+k);
						//����Ѿ����� 
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
