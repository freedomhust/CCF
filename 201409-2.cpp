#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>

using namespace std;

int main(void){
	int quat[100][100];
	memset(quat,0,sizeof(quat));
	int N;
	int x1,y1,x2,y2;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int j = x1; j < x2; j++){
			for(int k = y1; k < y2; k++){
				quat[j][k]++;
			}
		}
	}
	
	int res = 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if(quat[i][j] > 0) res++;
		}
	}
	printf("%d",res);
}
