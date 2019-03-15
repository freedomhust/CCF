#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int num[1002];

int main(void){
	memset(num,0,sizeof(num));
	int begin,end;
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&num[i]);
	}
	
	sort(num,num+N);
//	for(int i = 0; i < N; i++) printf("%d ",num[i]);

	int res = -1;
	begin = 0;
	end = begin;
	for(int i = 0; i < N; i++){
		if(end+1 < N && num[begin] == num[end+1]){
			end++;
		}
		else{
			if(begin == N-end-1){
				res = num[begin];
				break;
			}
			begin = end+1;
		}
	}
	printf("%d",res);
	
}
