#include<cstdio>
#include<cstring>

int main(void){
	
	int num;
	scanf("%d",&num);
	int S[10001];
	memset(S,0,sizeof(S));
	int m;
	
	for(int i = 1; i <= num; i++){
		scanf("%d",&m);
		S[m]++;
	}
	
	int j = 0;
	for(int k = 0; k < 10001; k++){
		if(S[k] > S[j]) j = k;
	}
	
	printf("%d",j);
} 
