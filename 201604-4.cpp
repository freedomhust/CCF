#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
	int r,l,t;
	node(int rr,int ll,int tt): r(rr),l(ll),t(tt) {}
};

bool vis[101][101][305] = {false};

int n,m,t;
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

void BFS(int x,int y){
	queue<node> Q;
	Q.push(node(1,1,0));
	vis[1][1][0] = true;
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++){
			int newX = top.r+X[i];
			int newY = top.l+Y[i];
			if(newX == n && newY == m){
				printf("%d",top.t+1);
				return ;
			}
			if(newX > 0 && newX <= n && newY > 0 &&newY <= m && vis[newX][newY][top.t+1] == false){
				Q.push(node(newX,newY,top.t+1));
				vis[newX][newY][top.t+1] = true;
			}
		}
	}
}

int main(void){
	scanf("%d%d%d",&n,&m,&t);
	int r,c,a,b;
	for(int i = 0; i < t; i++){
		scanf("%d%d%d%d",&r,&c,&a,&b);
		for(int j = a; j <= b; j++){
			vis[r][c][j] = true;
		}
	}
	BFS(1,1);
}
