#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct S{
	char action[8];
	int price1;
	int price2;
	int amount;
};


int main(void){
	struct S SA[5001];
	
	
	int i = 0;
	int number;
	int buyer_num = 0;
	int seller_num = 0;
	//读取数据 
	while(~scanf("%s",SA[i].action)){
		if(strcmp(SA[i].action,"cancel") != 0){
			scanf("%d.%d%d",&SA[i].price1,&SA[i].price2,&SA[i].amount);
		} 
		//如果要撤销则将前面的数据清零 
		if(strcmp(SA[i].action,"cancel") == 0){
			scanf("%d",&number);
			SA[number-1].price1 = 0;
			SA[number-1].price2 = 0;
			SA[number-1].amount = -1;
			SA[i].price1 = 0;
			SA[i].price2 = 0;
			SA[i].amount = -1; 
		}
		i++;
	}
	
	int p1 = 0;
	int p2 = 0;
	long long res_amount = 0;
	long long buy_amount = 0;
	long long sell_amount = 0;
	for(int j = 0; j < i; j++){
		if(SA[j].amount == -1){
			continue;
		}
		buy_amount = 0;
		sell_amount = 0;
		for(int k = 0; k < i; k++){
			if(SA[k].amount != -1){
				if(SA[k].action[0] == 'b'){
					if((SA[k].price1 > SA[j].price1) || (SA[k].price1 == SA[j].price1 && SA[k].price2 >= SA[j].price2)) 
					buy_amount = buy_amount + SA[k].amount;
				}
				else if(SA[k].action[0] == 's'){
					if((SA[k].price1 < SA[j].price1) || (SA[k].price1 == SA[j].price1 && SA[k].price2 <= SA[j].price2)) 
					sell_amount = sell_amount + SA[k].amount;
				}
			}
		}
		
		if(min(buy_amount,sell_amount) > res_amount){
			res_amount = min(buy_amount,sell_amount);
			p1 = SA[j].price1;
			p2 = SA[j].price2;
		}
		else if(min(buy_amount,sell_amount) == res_amount){
			if(SA[j].price1 > p1 || (SA[j].price1 == p1 && SA[j].price2 > p2)){
			p1 = SA[j].price1;
			p2 = SA[j].price2;	
			}
		}
	}
	
	printf("%d.%02d %lld",p1,p2,res_amount);
}
