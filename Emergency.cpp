#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

const int INF = 1000000000;
const int MAX = 1000;

struct node{
	int v;
	int weight;
	int save_num;
};

int save_num[MAX];
int save_sum[MAX];
bool vis[MAX] = {false};
int d[MAX];
int short_path_num[MAX];
int v_num;


vector<node> graph[MAX];

void Dijkstra(int s, int e){
	fill(d,d+MAX,INF);
	memset(short_path_num,0,sizeof(short_path_num));
	memset(save_sum,0,sizeof(save_sum));
	d[s] = 0;
	save_sum[s] = save_num[s];
	short_path_num[s] = 1;
	
	//遍历所有节点，将所有节点纳入版图 
	for(int i = 0; i < v_num; i++){
		int u = -1,MIN = INF;
		//找到d中最小的u，然后选择u进行访问 
		for(int j = 0; j < v_num; i++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				d[j] = MIN;
			}
		}
		
		if(u == -1) return;
		
		vis[u] = true;
		//对u能到达的节点进行分析 
		for(int j = 0; j < graph[u].size(); j++){
			node x = graph[u][j];
			//如果该节点未访问且该节点可以优化d 
			if(vis[x.v] == false && d[u] + x.weight < d[x.v]){
				//优化路径 
				d[x.v] = d[u] + x.weight;
				//更新总救援数量 
				save_sum[x.v] = save_sum[u] + x.save_num;
				//最短路径 
				short_path_num[x.v] = short_path_num[u];
			}
			else if(d[u] + graph[u][x.v] == d[x.v]){
				if(save_sum[u] + save_num[x.v] > save_sum[x.v]){
					save_sum[x.v] = save_sum[u] + save_num[x.v];
				}
				short_path_num[x.v] += short_path_num[u];
			} 
		}
		
	} 
}

void Dijkstra(int s){
	//将所有需要累加或者计算的数组进行初始化
	fill(d,d+MAX,INF);
	memset(short_path_num,0,sizeof(short_path_num));
	memset(save_sum,0,sizeof(save_sum));
	//然后赋一个初值 
	d[s] = 0;
	save_sum[s] = save_num[s];
	short_path_num[s] = 1;
	
	//遍历所有的节点，将节点一个个纳入版图中
	for(int i = 0; i < v_num; i++){
		//首先在所有节点中找到一个dis最小的节点u
		
		//然后将vis[u]置为true，表示已经进行了访问
		
		//对节点u，对他所能触及的节点进行遍历
		
		//如果通过节点u然后到达某节点v发现可以优化路径则进行路径优化
		
		//在这里顺便可以进行其他第二标尺的计算 
		
	} 
	
	//累加结束后图遍历结束 
}


int main(void){
	
}
