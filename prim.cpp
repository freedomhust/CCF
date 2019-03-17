#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

int n,m,graph[MAXV][MAXV];
//顶点与集合s的距离 
int d[MAXV];

bool vis[MAXV] = {false};

int prim(){
	//初始化数组
	fill(d,d+MAXV,INF);
	
	//赋初值
	d[0] = 0;
	
	//ans 表示最小生成树的边权 
	int ans = 0; 
	
	for(int i = 0; i < n; i++){
		int u = -1; 
		int MIN = INF;
		
		//遍历数组d找到最小的d[u]加入集合s 
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			} 
		}
		
		if(u == -1) return -1;
		
		//将u放入集合中 
		vis[u] = true;
		//存储最小生成树的边权之和 
		ans = ans+d[u];
		
		for(int v = 0; v < v_num; v++){
			if(vis[v] == false && graph[u][v] != 0 && graph[u][v] < d[v]){
				d[v] = graph[u][v];
			}
		}
	}
	return ans;
}

int main(void){
	
}
