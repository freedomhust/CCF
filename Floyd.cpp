#include<cstdio>
#include<algorithm>

using namespace std;

const int INF = 1000000000;
const int MAXV = 200;

int n,m;

int dis[MAXV][MAXV];

void Floyd (){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}
