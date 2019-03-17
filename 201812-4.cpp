#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXV = 500000;
const int MAXE = 100000;

struct edge{
	int u,v;
	int cost;
}E[MAXE];

bool cmp(edge a, edge b){
	return a.cost < b.cost;
}

int father[MAXV];

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int kruskal(int n, int m){
	int longest_ = 0;
	int Num_Edge = 0;
	
	for(int i = 0; i < n; i++){
		father[i] = i;
	}
	sort(E,E+m,cmp);
	for(int i = 0; i <m; i++){
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		
		if(faU != faV){
			father[faU] = faV;
			if(E[i].cost > longest_) longest_ = E[i].cost;
			Num_Edge++;
			if(Num_Edge == n-1) break;
		}
	}
	if(Num_Edge != n-1) return -1;
	else return longest_;
}

int main(void){
	int n,m,root;
	scanf("%d%d%d",&n,&m,&root);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].cost);
	}
	int ans = kruskal(n,m);
	printf("%d",ans);
}
