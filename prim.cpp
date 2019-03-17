#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

int n,m,graph[MAXV][MAXV];
//�����뼯��s�ľ��� 
int d[MAXV];

bool vis[MAXV] = {false};

int prim(){
	//��ʼ������
	fill(d,d+MAXV,INF);
	
	//����ֵ
	d[0] = 0;
	
	//ans ��ʾ��С�������ı�Ȩ 
	int ans = 0; 
	
	for(int i = 0; i < n; i++){
		int u = -1; 
		int MIN = INF;
		
		//��������d�ҵ���С��d[u]���뼯��s 
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			} 
		}
		
		if(u == -1) return -1;
		
		//��u���뼯���� 
		vis[u] = true;
		//�洢��С�������ı�Ȩ֮�� 
		ans = ans+d[u];
		
		for(int v = 0; v < v_num; v++){
			if(vis[v] == false && graph[u][v] != 0 && graph[u][v] < d[v]){
				d[v] = graph[u][v];
			}
		}
	}
	return ans;
}

int main(void){
	
}
