

struct node{
	//边的终点编号 
	int v;
	//边权 
	int weight;
	
	//构造函数 
//	node(int _v,int _w):v(_v),w(_w){} 
}; 

vector<node> graph[N];

node temp;
temp.v = x;
temp.w = y;
graph[i].push_back(temp);

//graph[i].push_back(node(x,y));

const MAXV = 1000;
const INF = 1000000000;

//邻接矩阵DFS
int n,G[MAXV][MAXV];
bool vis[MAXV] = {false};

void DFS(int u, int depth){
	vis[u] = true;
	
	//对所有节点进行枚举看当前节点是否能到达该结点且未被访问 
	for(int v = 0; v < n; v++){
		if(vis[v] == false && G[u][v] != INF){
			DFS(v,depth+1);
		}
	}
}

void DFSTrave(){
	for(int u = 0; u < n; u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	} 
}

//邻接表DFS
vector<int> adj[MAXV];

int n;

bool vis[MAXV] = {false};

void DFS(int u, int depth){
	vis[u] = true;
	
	for(int i = 0; i < adj[i].size(); i++){
		int v = adj[u][i];
		if(vis[v] == false){
			DFS(v,depth+1);
		}
	}
} 

void DFSTrave(){
	for(int u = 0; u < n; u++){
		if(vis[u] == false){
			DFS(u,1);
		}
	}
}
