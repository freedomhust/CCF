#include<cstdio>

int main(void){
	long long N;
	scanf("%lld",&N);
	int sum = 0;
	while(N/10 != 0){
		sum = sum + N%10;
		N = N/10;
	}
	sum = sum+N;
	printf("%d",sum);
}
