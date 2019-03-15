#include<cstdio>
#include<string>
#include<cstring>

int main(void){
	int n,k;
	int sum = 0;
	int num = 0;
	scanf("%d%d",&n,&k);
	int m;
	for(int i = 0; i < n; i++){
		scanf("%d",&m);
		sum = sum+m;
		if(sum >= k){
			num++,
			sum = 0;
		}
	}
	if(sum != 0){
		num++;
	}
	printf("%d",num);
} 
