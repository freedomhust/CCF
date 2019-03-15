#include<cstdio>

int main(void){
	int N;
	scanf("%d",&N);
	int sum;
	int x,y,z;
	x = N/50;
	N = N%50;
	y = N/30;
	N = N%30;
	z = N/10;
	sum = 7*x+4*y+z;
	printf("%d",sum);
} 
