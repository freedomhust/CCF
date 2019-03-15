#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>

using namespace std;

int main(void){
	int num[10001];
	memset(num,0,sizeof(num));
	int N,M;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&M);
		num[M]++;
	}
	int res = 0;
	for(int i = 0; i < 10000; i++){
		if(num[i] == 1 && num[i+1] == 1)
			res++;
	} 
	printf("%d",res);
} 
