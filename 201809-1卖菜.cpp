#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(void){
	int N;
	int a[2001];
	int b[2001];
	int c[2001];
	int d[2001];
	int sum;
	
	while(~scanf("%d",&N)){
		sum = 0;
		for(int i = 0; i < N; i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		for(int i = 0; i < N; i++){
			scanf("%d%d",&c[i],&d[i]);
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(a[i] <= c[j] && d[j] <= b[i]) sum = sum+d[j]-c[j];
				else if(c[j] <= a[i] && b[i] <= d[j]) sum = sum+b[i]-a[i];
				else if(c[j] <= a[i] && a[i] <= d[j] && d[j] <= b[i]) sum = sum+d[j]-a[i];
				else if(a[i] <= c[j] && c[j] <= b[i] && b[i] <= d[j]) sum = sum+b[i]-c[j];
			}
		}
		printf("%d\n",sum);
		
	}
}
