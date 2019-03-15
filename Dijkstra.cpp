#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

struct node{
	int v;
	int weight;
};

vector<node> graph[1000];
bool vis[1000] = {false};
const int  INF = 1000000000;
int d[1000];
int v_num,line_num;
int first_v;

void Dijkstra(int s){
	fill(d,d+1000,INF);
	d[s] = 0;
	//���ڵ�һ���������ͼ 
	for(int i = 0; i < v_num; i++){
		int u = -1,MIN = INF;
		//�ҵ�d����С��u��Ȼ��ѡ��u���з��� 
		for(int j = 0; j < v_num; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		if(u == -1) return;
		//����u�ڵ� 
		vis[u] = true;
		
		//�������е�Ԫ�ؿ���������uΪ�����Ƿ��������·��Ҫ�� 
		for(int j = 0; j < graph[u].size(); j++){
			int v = graph[u][j].v;
			//���vδ����������㾭��u����v��֮ǰ���ķ���vҪ�����Ż� 
			if(vis[v] == false && d[u] + graph[u][j].weight < d[v]){
				d[v] = d[u] + graph[u][j].weight;
			}
		}
		
	}
}

int main(void){

	int begin_v,end_v,weight;
	scanf("%d%d%d",&v_num,&line_num,&first_v);
	for(int i = 0; i < line_num; i++){
		scanf("%d%d%d",&begin_v,&end_v,&weight);
		node x;
		x.v = end_v;
		x.weight = weight;
		graph[begin_v].push_back(x);
	}
	
	d[first_v] = 0;
	
}
