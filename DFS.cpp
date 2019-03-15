#include<cstring>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int n,k,x,maxSumSqu = -1,A[maxn];

vector<int> temp,ans;

void DFS(int index, int nowK, int sum, int SumSqu){
	//如果找到了符合结果的值则进行判断后返回 
	if(nowK == k && sum == x){
		if(SumSqu > maxSumSqu){
			maxSumSqu = SumSqu;
			ans = temp;
		}
		return;
	}
	
	//若已经处理完了k个数但不等于k或者所有数都处理完了则返回
	if(nowK > K || index == n || sum > x) return;
	temp.push_back(A[index]);
	DFS(index + 1, nowK + 1, sum+A[index], SumSqu + A[index]*A[index] );
	temp.pop_back();
}

int main(void){
	
} 
