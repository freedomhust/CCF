#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int num[1001];

int main(void){
	memset(num,0,sizeof(num));
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+N);
	int res = 10001;
	for(int i = 0; i < N; i++){
		if(i != 0){
			res = min(res,abs(num[i]-num[i-1])); 
		}
	}
	printf("%d",res);
}
