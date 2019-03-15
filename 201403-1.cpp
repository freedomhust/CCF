#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void){
	int S[1001];
	memset(S,0,sizeof(S));
	
	int num,m;
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		scanf("%d",&m);
		S[abs(m)]++;
	}
	int res = 0;
	for(int i = 0; i < 1001; i++){
		if(S[i] == 2) res++;
	}
	printf("%d",res);
} 
