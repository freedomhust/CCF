#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 1000;
const int INF = 1000000000;

int v_num;
int m,st,ed;

//�жϽڵ��Ƿ񱻷��� 
bool vis[MAX] = {false};

//�洢���·�� 
vector<int> pre[MAX];

//�洢��ʱ·��������·�� 
vector<int> tempPath,path;

//�洢�ڵ���Ϣ 
int graph[MAX][MAX];

//�洢�ڵ�֮��ķ��� 
int cost[MAX][MAX]; 

//��㵽ÿһ���ڵ����̾��� 
int d[MAX];

//����ĳ�ڵ��������� 
int c[MAX];

void Dijkstra(int s){
	//���Ƚ��г�ʼ��
	fill(d,d+MAX,INF);
//	memset(c,0,sizeof(c));
	
	//Ȼ����и�ֵ���� 
	d[s]= 0;
	
	//�����ڵ㣬���ڵ�һ���������ͼ 
	for(int i = 0; i < v_num; i++){
		int u = -1;
		int MIN = INF;
		
		//�ҵ�d��������̵�·�� 
		for(int j = 0; j < v_num; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		} 
		
		if( u == -1) return;
		
		vis[u] = true;
		
		//����u���ܵ�������нڵ㿴�Ƿ����Ż�·��
		for(int v = 0; v < v_num; v++){
			//vδ��������u�ܵ���v 
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
	//��������˶��㣬���ʾ���ݹ�߽��� 
	if(v == st){
		tempPath.push_back(v);
		int tempCost = 0;
		//��ѯ�����·����������� 
		for(int i = tempPath.size()-1; i > 0; i--){
			int id = tempPath[i], idNext = tempPath[i-1];
			tempCost += cost[id][idNext];
		}
		
		//��������·�����ѱȵ�ǰ���·������Ҫ�� 
		if(TempCost < minCost){
			minCost = tempCost;
			path = tempPath;
		}
		
		tempPath.pop_back();
		return;
	}
	
	//���ڵ�v����tempPath�� 
	tempPath.push_back(v);
	//ÿ��һ���ֲ�ͱ�ʾ��һ�����· 
	for(int i = 0; i < pre[v].size(); i++){
		DFS(pre[v][i]);
	}
	
	tempPath.pop_back();
}

int main(void){
	
}
