#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int sum = 0;
	int S;
	int num;
	int min;
	scanf("%d",&num);
	int height[num];
	for(int i = 0; i < num; i++){
		scanf("%d",&height[i]);
	}
	for(int i = 0; i < num; i++){
		min = height[i];
		for(int j = i; j < num; j++){
			if(height[j] < min) min = height[j];
			S = min*(j-i+1);
			if(S > sum) sum = S;
		}
	}
	printf("%d",sum);
} 
