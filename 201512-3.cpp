#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>

char graph[105][105];
int M,N,Q;

void Tchong(int x, int y, char s){
	//œÚ◊Û±ﬂÃÓ≥‰ 
	if(x != 0 && graph[x-1][y] != '-' && graph[x-1][y] != '|' 
			&& graph[x-1][y] != '+' && graph[x-1][y] != s){
		graph[x-1][y] = s;
		Tchong(x-1,y,s);
	}
	//œÚ…œ±ﬂÃÓ≥‰ 
	if(y != N-1 && graph[x][y+1] != '-' && graph[x][y+1] != '|' 
			&& graph[x][y+1] != '+' && graph[x][y+1] != s){
		graph[x][y+1] = s;
		Tchong(x,y+1,s);
	} 
	
	//œÚ”“±ﬂÃÓ≥‰
	if(x != M-1 && graph[x+1][y] != '-' && graph[x+1][y] != '|'
			&& graph[x+1][y] != '+' && graph[x+1][y] != s){
		graph[x+1][y] = s;
		Tchong(x+1,y,s);			
	}
	
	//œÚœ¬±ﬂÃÓ≥‰
	if(y != 0 && graph[x][y-1] != '-' && graph[x][y-1] != '|'
			&& graph[x][y-1] != '+' && graph[x][y-1] != s){
		graph[x][y-1] = s;
		Tchong(x,y-1,s);			
	}
}

int main(void){
	memset(graph,'.',sizeof(graph));
	int num;
	int x1,y1,x2,y2;
	int tcx,tcy;
	char tc_character;
	scanf("%d%d%d",&M,&N,&Q);
	for(int i = 0; i < Q; i++){
		scanf("%d ",&num);
		if(num == 0){
			scanf("%d ",&x1);
			scanf("%d ",&y1);
			scanf("%d ",&x2);
			scanf("%d",&y2);
			//ÃÓ |  
			if(x1 == x2){
				if(y1 > y2){
					for(int j = y2; j <= y1; j++){
						if(graph[x1][j] == '-' || graph[x1][j] == '+') graph[x1][j] = '+';
						else graph[x1][j] = '|';
					}
				}
				else {
					for(int j = y1; j <= y2; j++){
						if(graph[x1][j] == '-' || graph[x1][j] == '+') graph[x1][j] = '+';
						else graph[x1][j] = '|';
					}	
				}
			}
			//ÃÓ - 
			else if(y1 == y2){
				if(x1 > x2){
					for(int j = x2; j <= x1; j++){
						if(graph[j][y1] == '|' || graph[j][y1] == '+') graph[j][y1] = '+';
						else graph[j][y1] = '-';
					}
				} 
				else {
					for(int j = x1; j <= x2; j++){
						if(graph[j][y1] == '|' || graph[j][y1] == '+') graph[j][y1] = '+';
						else graph[j][y1] = '-';
					}
				}
			}
		}
		else if(num == 1){
			scanf("%d ",&tcx);
			scanf("%d ",&tcy);
			scanf("%c",&tc_character);
			Tchong(tcx,tcy,tc_character);
		}
	}
	
	for(int x = N-1; x >= 0; x--){
		for(int y = 0; y < M; y++){
			printf("%c",graph[y][x]);
		}
		printf("\n");
	}
} 
