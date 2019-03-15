#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 1000;
const int INF = 1000000000;

int v_num;
int m,st,ed;

//�Ƿ񱻷��� 
bool vis[MAX] = {false};

//�ڵ�֮��ı�Ȩ 
int graph[MAX][MAX];

//����֮��Ļ��� 
int cost[MAX][MAX];

//��㵽���ڵ����̾��� 
int d[MAX];

//�洢���·�� 
int pre[MAX];

//�洢���·������ 
int c[MAX];

void Dijkstra(int s){
	//��ʼ�������� 
	fill(d,d+MAX,INF);
	memset(c,0,sizeof(c));
	memset(pre,0,sizeof(pre));
	
	//����ֵ 
	d[s] = 0;
	c[s] = 0;
	for(int i = 0; i < v_num; i++) pre[i] = i;
	

	 //ѭ��v_num�Σ������нڵ������ͼ 
	 for(int i = 0; i < v_num; i++){
		//�ҵ���·����̵Ľڵ���з��������ͼ����Ϊd[j] һ��ʼʱΪ����� 
		int u = -1;
		int MIN = INF;
		for(int j = 0; j < v_num; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		if(u == -1) return;
		//��u�����ͼ 
		vis[u] = true;
		
		//�����ڵ�u�����б� 
		for(int j = 0; j < v_num; j++){
			if(graph[u][j] != 0 && vis[j] == false){
				//·�����Ա��Ż� 
				if(d[u] + graph[u][j] < d[j]){
					//�Ż�·�� 
					d[j] = d[u] + graph[u][j];
					//��¼���·�� 
					pre[j] = u;
					//��¼����
					cost[j] = cost[u] + cost[u][j]; 
				}
				//���·��������ͬ��ѡ�������ٵ�������Ϊ���·�� 
				else if(d[u] + graph[u][j] == d[j]){
					if(cost[u] + cost[u][j] < cost[j]){
						//ѡȡ���ѽ��ٵ���һ����Ϊǰ���ڵ� 
						pre[j] = u;
						//�������·������ 
						cost[j] = cost[u] + cost[u][j];
					}
				}
			}
		}
	 }
}

//��ӡ���·�� 
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
