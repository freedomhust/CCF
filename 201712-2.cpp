#include<cstdio>

int student[1001];

int main(void){
	int N,K;
	scanf("%d%d",&N,&K);
	int rest_num = N;
	int sub = 0;
	int value = 1;
	for(int i = 0; i < N; i++){
		student[i] = 1;
	}
	
	while(rest_num != 1){
		if(student[sub] == 0){
			sub = (sub+1)%N;
			continue;
		}
		if(value%K == 0 || value%10 == K){
			student[sub] = 0;
			rest_num--;
		}
		value++;
		sub = (sub+1)%N;
	}
	
	for(int i = 0; i < N; i++){
		if(student[i] == 1){
			printf("%d",i+1);
			break;
		}
	}
}
