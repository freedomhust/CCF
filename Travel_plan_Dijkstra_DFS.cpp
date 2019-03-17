#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 1000;
const int INF = 1000000000;

int v_num;
int m,st,ed;

//判断节点是否被访问 
bool vis[MAX] = {false};

//存储最短路径 
vector<int> pre[MAX];

//存储临时路径，最优路径 
vector<int> tempPath,path;

//存储节点信息 
int graph[MAX][MAX];

//存储节点之间的费用 
int cost[MAX][MAX]; 

//起点到每一个节点的最短距离 
int d[MAX];

//到达某节点的最短消费 
int c[MAX];

void Dijkstra(int s){
	//首先进行初始化
	fill(d,d+MAX,INF);
//	memset(c,0,sizeof(c));
	
	//然后进行赋值操作 
	d[s]= 0;
	
	//遍历节点，将节点一个个纳入版图 
	for(int i = 0; i < v_num; i++){
		int u = -1;
		int MIN = INF;
		
		//找到d数组中最短的路径 
		for(int j = 0; j < v_num; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		} 
		
		if( u == -1) return;
		
		vis[u] = true;
		
		//遍历u所能到达的所有节点看是否能优化路径
		for(int v = 0; v < v_num; v++){
			//v未被访问且u能到达v 
			if(vis[j] == false && graph[u][v] != 0){
				if(d[u] + graph[u][v] < d[v]){
					d[v] = d[u] + graph[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u] + graph[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		} 
	} 
}


void DFS(int v){
	//如果到达了顶点，则表示到递归边界了 
	if(v == st){
		tempPath.push_back(v);
		int tempCost = 0;
		//查询该最短路径的消费情况 
		for(int i = tempPath.size()-1; i > 0; i--){
			int id = tempPath[i], idNext = tempPath[i-1];
			tempCost += cost[id][idNext];
		}
		
		//如果该最短路径花费比当前最短路径花费要少 
		if(TempCost < minCost){
			minCost = tempCost;
			path = tempPath;
		}
		
		tempPath.pop_back();
		return;
	}
	
	//将节点v纳入tempPath中 
	tempPath.push_back(v);
	//每有一个分叉就表示多一条最短路 
	for(int i = 0; i < pre[v].size(); i++){
		DFS(pre[v][i]);
	}
	
	tempPath.pop_back();
}

int main(void){
	
}
