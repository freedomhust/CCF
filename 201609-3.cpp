#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std; 

struct player{
	int servent_num;
}players[2];

struct hero{
	int health;
	int attack;
	int num;
}heroes[2];

struct servant{
	int health;
	int num;
	int attack;
}servant_first[7],servant_last[7];

bool cmp(servant x,servant y){
	return x.num < y.num;
}

int main(void){
	//0表示先手玩家，1表示后手玩家 
	int player = 0;
	for(int i = 0; i < 7; i++){
		servant_first[i].num = 8;
		servant_last[i].num = 8;
	}
	heroes[0].num = 0;
	heroes[0].attack = 0;
	heroes[0].health = 30;
	heroes[1].num = 0;
	heroes[1].attack = 0;
	heroes[1].health = 30;
	players[0].servent_num = 0;
	players[1].servent_num = 0;
	
//	for(int i = 0; i < 7; i++){
//		printf("%d %d \n",servant_first[i].num,servant_last[i].num);
//	}

	int N;
	scanf("%d",&N);
	
	char op[10];
	int position;
	int attack;
	int health;
	int attacker;
	int defender;
	//依次处理所有的命令 
	for(int i = 0; i < N; i++){
		scanf("%s",op);
		//如果是summon 
		if(op[0] == 's'){
			scanf("%d %d %d",&position,&attack,&health);
//			printf("%s %d %d %d\n",op,position,attack,health);
			//如果是先手玩家进行行动 
			if(player == 0){
				 //在最右边插入随从 
				 if(servant_first[position-1].num == 8){
				 	servant_first[position-1].attack = attack;
				 	servant_first[position-1].health = health;
				 	servant_first[position-1].num = position;
				 	players[0].servent_num++;
				}
				//在1-num中插入随从 
				else{
					//首先把该随从加到最后 
					servant_first[players[0].servent_num].attack = attack;
					servant_first[players[0].servent_num].health = health;
					servant_first[players[0].servent_num].num = position;
					players[0].servent_num++;
					//然后将 该 随从序号之后的随从的num++
					for(int j = position-1; j < players[0].servent_num-1; j++){
						servant_first[j].num++;
					}
					//对servant利用num排一遍序
					sort(servant_first,servant_first+players[0].servent_num,cmp); 
				}
			}
			//如果是后手玩家 
			else{
				 //在最右边插入随从 
				 if(servant_last[position-1].num == 8){
				 	servant_last[position-1].attack = attack;
				 	servant_last[position-1].health = health;
				 	servant_last[position-1].num = position;
				 	players[1].servent_num++;
				}
				//在1-num中插入随从 
				else{
					//首先把该随从加到最后 
					servant_last[players[1].servent_num].attack = attack;
					servant_last[players[1].servent_num].health = health;
					servant_last[players[1].servent_num].num = position;
					players[1].servent_num++;
					//然后将 该 随从序号之后的随从的num++
					for(int j = position-1; j < players[1].servent_num-1; j++){
						servant_last[j].num++;
					}
					//对servant利用num排一遍序
					sort(servant_last,servant_last+players[1].servent_num,cmp); 
				}
			}
		}
		//如果是attack 
		else if(op[0] == 'a'){
			scanf("%d %d",&attacker,&defender);
//			printf("%s %d %d\n",op,attacker,defender);
			//如果是先手玩家 
			if(player == 0){
				//我方随从的血量减少 
				servant_first[attacker-1].health = 
				servant_first[attacker-1].health - servant_last[defender-1].attack;
				//如果我方随从死亡，后面的随从的序号变更，重新计数 
				if(servant_first[attacker-1].health <= 0){
					servant_first[attacker-1].num = 8;
					for(int j = attacker; j < players[0].servent_num; j++){
						servant_first[j].num--;
					}
					sort(servant_first,servant_first+players[0].servent_num,cmp);
					players[0].servent_num--; 
				}
				
				if(defender == 0){
					heroes[1].health = heroes[1].health - servant_first[attacker-1].attack;
				}
				else{
				servant_last[defender-1].health = 
				servant_last[defender-1].health - servant_first[attacker-1].attack;
				
				//如果敌方随从死亡，也需要进行更改 
				if(servant_last[defender-1].health <= 0){
					servant_last[defender-1].num = 8;
					for(int j = defender; j < players[1].servent_num; j++){
						servant_last[j].num--;
					}
					sort(servant_last,servant_last+players[1].servent_num,cmp);
					players[1].servent_num--;
				}
				} 

			}
			else{
				servant_last[attacker-1].health = 
				servant_last[attacker-1].health - servant_first[defender-1].attack;
				//如果我方随从死亡，后面的随从的序号变更，重新计数 
				if(servant_last[attacker-1].health <= 0){
					servant_last[attacker-1].num = 8;
					for(int j = attacker; j < players[1].servent_num; j++){
						servant_last[j].num--;
					}
					sort(servant_last,servant_last+players[1].servent_num,cmp);
					players[1].servent_num--;
				}
				
				if(defender == 0){
					heroes[0].health = heroes[0].health - servant_last[attacker-1].attack;
				}
				else{
				 servant_first[defender-1].health = 
				servant_first[defender-1].health - servant_last[attacker-1].attack;
				
				//如果地方随从死亡，也需要进行更改 
				if(servant_first[defender-1].health <= 0){
					servant_first[defender-1].num = 8;
					for(int j = defender; j < players[0].servent_num; j++){
						servant_first[j].num--;
					}
					sort(servant_first,servant_first+players[0].servent_num,cmp);
					players[0].servent_num--;
				}
				}

			}
		}
		//如果是end 
		else{
//			printf("%s\n",op);
			if(player == 0) player = 1;
			else player = 0;
		}
	}
	
	if(heroes[0].health <= 0) printf("-1\n");
	else if(heroes[1].health <= 0) printf("1\n");
	else printf("0\n");
	printf("%d\n",heroes[0].health);
	printf("%d ",players[0].servent_num);
	for(int i = 0; i < players[0].servent_num; i++){
		printf("%d ",servant_first[i].health);
	}
	printf("\n");
	
	printf("%d\n",heroes[1].health);
	printf("%d ",players[1].servent_num);
	for(int i = 0; i < players[1].servent_num; i++){
		printf("%d ",servant_last[i].health);
	}
//	printf("\n");
	


}
