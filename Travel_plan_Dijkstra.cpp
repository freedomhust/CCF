#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 1000;
const int INF = 1000000000;

int v_num;
int m,st,ed;

//是否被访问 
bool vis[MAX] = {false};

//节点之间的边权 
int graph[MAX][MAX];

//顶点之间的花费 
int cost[MAX][MAX];

//起点到各节点的最短距离 
int d[MAX];

//存储最短路径 
int pre[MAX];

//存储最短路径花费 
int c[MAX];

void Dijkstra(int s){
	//初始化各数组 
	fill(d,d+MAX,INF);
	memset(c,0,sizeof(c));
	memset(pre,0,sizeof(pre));
	
	//赋初值 
	d[s] = 0;
	c[s] = 0;
	for(int i = 0; i < v_num; i++) pre[i] = i;
	

	 //循环v_num次，将所有节点纳入版图 
	 for(int i = 0; i < v_num; i++){
		//找到与路径最短的节点进行访问纳入版图，因为d[j] 一开始时为无穷大 
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < v_num; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		if(u == -1) return;
		//将u纳入版图 
		vis[u] = true;
		
		//遍历节点u的所有边 
		for(int j = 0; j < v_num; j++){
			if(graph[u][j] != 0 && vis[j] == false){
				//路径可以被优化 
				if(d[u] + graph[u][j] < d[j]){
					//优化路径 
					d[j] = d[u] + graph[u][j];
					//记录最短路径 
					pre[j] = u;
					//记录花费
					cost[j] = cost[u] + cost[u][j]; 
				}
				//如果路径长度相同，选花费最少的那条作为最短路径 
				else if(d[u] + graph[u][j] == d[j]){
					if(cost[u] + cost[u][j] < cost[j]){
						//选取花费较少的那一条作为前驱节点 
						pre[j] = u;
						//更新最短路径花费 
						cost[j] = cost[u] + cost[u][j];
					}
				}
			}
		}
	 }
}

//打印最短路径 
void DFS(int v){
	if(v == st){
		printf("%d ",v);
		return;
	}
	DFS(pre[v]);
	printf("%d ",v);
} 


int main(void){
	scanf("%d%d%d%d",&v_num,&m,&st,&ed);
	int u,v;
	memset(graph,0,sizeof(graph));
	for(int i = 0; i < m; i++){
		scanf("%d%d",&u,&v);
		scanf("%d%d",&graph[u][v],&cost[u][v]);
		graph[v][u] = graph[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
	DFS(ed);
	printf("%d %d\n",d[ed],c[ed]);
}
