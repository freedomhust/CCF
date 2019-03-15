#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

struct numa {
	int number;
	int value;
}num[1002];

bool cmp(numa x,numa y){
	if(x.value != y.value) return x.value > y.value;
	else return x.number < y.number;
}

int main(void){
	for(int m = 0; m < 1001; m++){
		num[m].number = 0;
		num[m].value = 0;
	}
	int M,N;
	scanf("%d",&M);
	int i;
	int k = 0;
	for(i = 0; i < M; i++){
		scanf("%d",&N);
		if(num[N].value == 0) k++;
		num[N].value++;
		num[N].number = N;
	}
	
	sort(num,num+1002-1,cmp);
	
	for(int j = 0; j < k; j++){
		printf("%d %d\n",num[j].number,num[j].value);
	}
}
