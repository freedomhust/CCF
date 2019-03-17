#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXV = 205;

struct node{
	int x,y;
	int status;
	int layer;
}Node[MAXV];

int n,m,k;
long long r;

//存储图的可达情况 
int graph[MAXV][MAXV];

bool inq[MAXV] = {false};

//新添加的节点数目 
int status0_num[MAXV] = {0};

void BFS(int s){
	queue<int> q;
	q.push(s);
	inq[s] = true;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
//		if(Node[u].status == 0){
//			status0_num++;
//		}
		
		//枚举出所有的顶点 
		for(int v = 0; v < n+m; v++){
			//如果可达且未超出要求，则可以进行一次判断 
			if(graph[u][v] == 1 && status0_num[u] <= k && inq[v] == false){
				q.push(v);
				inq[v] = true;
				Node[v].layer = Node[u].layer + 1;
				if(Node[v].status == 0) status0_num[v] = status0_num[u] + 1;
				else status0_num[v] = status0_num[u];
				
				
				if(v == 1){
					printf("%d",Node[u].layer);
					return;
				}
			}
		}
	}
}
 
 
int main(void){
	memset(graph,0,sizeof(graph));
	cin >> n >> m >> k >> r;
	//存储所有输入数据 
	for(int i = 0; i < n; i++){
		cin >> Node[i].x >> Node[i].y;
		Node[i].status = 1;
		Node[i].layer = 0;
	}
	for(int i = 0; i < m; i++){
		cin >> Node[n+i].x >> Node[n+i].y;
		Node[n+i].status = 0;
		Node[n+i].layer = 0;
	}
	
	for(int i = 0; i < n+m; i++){
		for(int j = 0; j < n+m; j++){
			//如果可达 
			if( (Node[i].y - Node[j].y) * (Node[i].y - Node[j].y)  + (Node[i].x - Node[j].x) * (Node[i].x - Node[j].x)  <= r*r  ){
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
	}
	
	BFS(0);
	
}

