#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

int status[100][100] = {0};

int pos[100][100];

int N,M;

int num = 0;

struct node{
	int x;
	int y;
}Node;

void BFS(int x,int y){
	queue<node> Q;
	
	Node.x = x; 
	Node.y = y;
	
	Q.push(Node);
	
	status[x][y] = 1;
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		Node.x = top.x-1;
		Node.y = top.y;
		if(pos[Node.x][Node.y] == 1 && status[Node.x][Node.y] == 0){
			Q.push(Node);
			status[Node.x][Node.y] = 1;
		}2e
		Node.x = top.x+1;
		Node.y = top.y;
		if(pos[Node.x][Node.y] == 1 && status[Node.x][Node.y] == 0){
			Q.push(Node);
			status[Node.x][Node.y] = 1;
		}
		Node.x = top.x;
		Node.y = top.y-1;
		if(pos[Node.x][Node.y] == 1 && status[Node.x][Node.y] == 0){
			Q.push(Node);
			status[Node.x][Node.y] = 1;
		}
		Node.x = top.x;
		Node.y = top.y+1;
		if(pos[Node.x][Node.y] == 1 && status[Node.x][Node.y] == 0){
			Q.push(Node);
			status[Node.x][Node.y] = 1;
		}
	}
}

void DFS(int x,int y){
	//数组越界了 
	if(x < 0 || x >= N || y < 0 || y >= M){
		return;
	}
	
	//如果该位置是0则直接返回不做操作 
	if(pos[x][y] == 0) return;
	if(status[x][y] == 1) return;
	
	status[x][y] = 1;
	DFS(x-1,y);
	DFS(x+1,y);
	DFS(x,y-1);
	DFS(x,y+1);
}

int main(void){
	
//	for(int i = 0; i < 100; i++){
//		for(int j = 0; j < 100; j++){
//			cout << status[i][j] << " ";
//		}
//		cout << endl;
//	}


	scanf("%d%d",&N,&M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> pos[i][j];
		}
	}
	
//	for(int i = 0; i <N; i++){
//		for(int j = 0; j < M; j++){
//			cout << pos[i][j];
//		}
//		cout << endl;
//	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(pos[i][j] == 1 && status[i][j] == 0){
				num++;
				BFS(i,j);
			}
		}
	}
	
	cout << num;
	
	
}
