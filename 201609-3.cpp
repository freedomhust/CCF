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
	//0��ʾ������ң�1��ʾ������� 
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
	//���δ������е����� 
	for(int i = 0; i < N; i++){
		scanf("%s",op);
		//�����summon 
		if(op[0] == 's'){
			scanf("%d %d %d",&position,&attack,&health);
//			printf("%s %d %d %d\n",op,position,attack,health);
			//�����������ҽ����ж� 
			if(player == 0){
				 //�����ұ߲������ 
				 if(servant_first[position-1].num == 8){
				 	servant_first[position-1].attack = attack;
				 	servant_first[position-1].health = health;
				 	servant_first[position-1].num = position;
				 	players[0].servent_num++;
				}
				//��1-num�в������ 
				else{
					//���ȰѸ���Ӽӵ���� 
					servant_first[players[0].servent_num].attack = attack;
					servant_first[players[0].servent_num].health = health;
					servant_first[players[0].servent_num].num = position;
					players[0].servent_num++;
					//Ȼ�� �� ������֮�����ӵ�num++
					for(int j = position-1; j < players[0].servent_num-1; j++){
						servant_first[j].num++;
					}
					//��servant����num��һ����
					sort(servant_first,servant_first+players[0].servent_num,cmp); 
				}
			}
			//����Ǻ������ 
			else{
				 //�����ұ߲������ 
				 if(servant_last[position-1].num == 8){
				 	servant_last[position-1].attack = attack;
				 	servant_last[position-1].health = health;
				 	servant_last[position-1].num = position;
				 	players[1].servent_num++;
				}
				//��1-num�в������ 
				else{
					//���ȰѸ���Ӽӵ���� 
					servant_last[players[1].servent_num].attack = attack;
					servant_last[players[1].servent_num].health = health;
					servant_last[players[1].servent_num].num = position;
					players[1].servent_num++;
					//Ȼ�� �� ������֮�����ӵ�num++
					for(int j = position-1; j < players[1].servent_num-1; j++){
						servant_last[j].num++;
					}
					//��servant����num��һ����
					sort(servant_last,servant_last+players[1].servent_num,cmp); 
				}
			}
		}
		//�����attack 
		else if(op[0] == 'a'){
			scanf("%d %d",&attacker,&defender);
//			printf("%s %d %d\n",op,attacker,defender);
			//������������ 
			if(player == 0){
				//�ҷ���ӵ�Ѫ������ 
				servant_first[attacker-1].health = 
				servant_first[attacker-1].health - servant_last[defender-1].attack;
				//����ҷ�����������������ӵ���ű�������¼��� 
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
				
				//����з����������Ҳ��Ҫ���и��� 
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
				//����ҷ�����������������ӵ���ű�������¼��� 
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
				
				//����ط����������Ҳ��Ҫ���и��� 
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
		//�����end 
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
