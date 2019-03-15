#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int N,K;

int graph[2010][2010];
bool vis[2010] = {false};
map<string,int> graph_node;
map<int, string> graph_node_int_tostring; 

int num = 0;
int vmax = 0;
int graph_sum = 0;
int gang_num = 0; 
int ganghead;
int gang_num_sum[2010];
int gang_head_sum[2010];
int head_num = 0;

void DFS(int v){
	gang_num++;
	vis[v] = true;
	int vsum = 0;
	int i;
	for(i = 0; i < N; i++){
		if(graph[v][i] != 0){
			vsum = vsum + graph[v][i];
			graph_sum += graph[v][i];
			
			if(vis[i] == false){
				
				DFS(i);
			}
		}
	}
	if(vsum > vmax){
		vmax = vsum;
		ganghead = v;
	} 
}

void DFSTrave(){
	for(int i = 0; i < N; i++){
		graph_sum = 0;
		gang_num = 0;
		vmax = 0;
		//遍历一次遍历一张图 
		if(vis[i] == false){
			DFS(i);
		}
		//如果过了线 
		if(graph_sum/2 > K && gang_num > 2){
			gang_head_sum[head_num] = ganghead;
			gang_num_sum[head_num] = gang_num;
			head_num++;
		}
	}
}


int main(void){
	memset(graph,0,sizeof(graph));
	scanf("%d%d\n",&N,&K);
	
	string va,vb;
	int weight;
	for(int i = 0; i < N; i++){
		cin >> va >> vb >> weight;
	
		int exist = graph_node.count(va);
		//如果当前节点之前没有出现过 
		if(exist == 0){
			graph_node[va] = num;
			graph_node_int_tostring[num] = va;
			num++;
		}
		exist = graph_node.count(vb);
		if(exist == 0){
			graph_node[vb] = num;
			graph_node_int_tostring[num] = vb;
			num++;
		}
		
		graph[graph_node[va]][graph_node[vb]] += weight; 
		graph[graph_node[vb]][graph_node[va]] += weight;
	}
	
//	for(int i = 0; i < N; i++){
//		cout << graph_node_int_tostring[i] << " ";
//		for(int j = 0; j < N; j++){
//			if(graph[i][j] != 0){
//				cout << graph_node_int_tostring[j] << " " << graph[i][j] << " ";
//			}
//		}
//		cout <<endl;
//	}
	
	DFSTrave();
	
	cout << head_num << endl;
	for(int i = 0; i < head_num; i++){
		cout << graph_node_int_tostring[gang_head_sum[i]] << " " << gang_num_sum[i] << endl;
	}
//	cout << endl;
	

	
//	for(map<string, int>::iterator it = graph_node.begin(); it != graph_node.end(); it++ ){
//		cout << it->first << " " << it->second << endl;
//	}
}
