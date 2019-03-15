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
	
	//�������нڵ㣬�����нڵ������ͼ 
	for(int i = 0; i < v_num; i++){
		int u = -1,MIN = INF;
		//�ҵ�d����С��u��Ȼ��ѡ��u���з��� 
		for(int j = 0; j < v_num; i++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				d[j] = MIN;
			}
		}
		
		if(u == -1) return;
		
		vis[u] = true;
		//��u�ܵ���Ľڵ���з��� 
		for(int j = 0; j < graph[u].size(); j++){
			node x = graph[u][j];
			//����ýڵ�δ�����Ҹýڵ�����Ż�d 
			if(vis[x.v] == false && d[u] + x.weight < d[x.v]){
				//�Ż�·�� 
				d[x.v] = d[u] + x.weight;
				//�����ܾ�Ԯ���� 
				save_sum[x.v] = save_sum[u] + x.save_num;
				//���·�� 
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
	//��������Ҫ�ۼӻ��߼����������г�ʼ��
	fill(d,d+MAX,INF);
	memset(short_path_num,0,sizeof(short_path_num));
	memset(save_sum,0,sizeof(save_sum));
	//Ȼ��һ����ֵ 
	d[s] = 0;
	save_sum[s] = save_num[s];
	short_path_num[s] = 1;
	
	//�������еĽڵ㣬���ڵ�һ���������ͼ��
	for(int i = 0; i < v_num; i++){
		//���������нڵ����ҵ�һ��dis��С�Ľڵ�u
		
		//Ȼ��vis[u]��Ϊtrue����ʾ�Ѿ������˷���
		
		//�Խڵ�u���������ܴ����Ľڵ���б���
		
		//���ͨ���ڵ�uȻ�󵽴�ĳ�ڵ�v���ֿ����Ż�·�������·���Ż�
		
		//������˳����Խ��������ڶ���ߵļ��� 
		
	} 
	
	//�ۼӽ�����ͼ�������� 
}


int main(void){
	
}
