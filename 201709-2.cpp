#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream> 

using namespace std;

int position[1001];

struct time{
	int key_num;
	//1表示还，0表示借 
	int action_key;
	int time;
}times[2000];

bool cmp(time a, time b){
	if(a.time != b.time) return a.time < b.time;
	//如果时间相等则先还再借 
	else{
		if(a.action_key != b.action_key) return a.action_key > b.action_key;
		//还的时候keynum从小到大排序 
		else {
			return a.key_num < b.key_num;
		}
	}
}

int main(void){
	int N,T;
	scanf("%d%d",&N,&T);
	for(int i = 1; i <= N; i++){
		position[i] = i;
	}
	int action_num = 0;
	int key,class_on,class_over;
	for(int i = 0; i < T; i++){
		scanf("%d%d%d",&key,&class_on,&class_over);
		times[action_num].action_key = 0;
		times[action_num].key_num = key;
		times[action_num].time = class_on;
		action_num++;
		times[action_num].action_key = 1;
		times[action_num].key_num = key;
		times[action_num].time = class_on+class_over;
		action_num++;
	}
	
	sort(times,times+action_num,cmp);

	for(int i = 0; i < action_num; i++){
		//如果是借，遍历找到钥匙的位置 
		if(times[i].action_key == 0){
			for(int j = 1; j <= N; j++){
				if(position[j] == times[i].key_num){
					position[j] = -1;
					break;
				} 
			} 
		}
		//如果是还，从左到右遍历直到找到第一个钥匙空的位置
		else{
			for(int j = 1; j <= N; j++){
				if(position[j] == -1){
					position[j] = times[i].key_num;
					break;
				}
			}
		} 
	}
	
	for(int i = 1; i <= N; i++){
		printf("%d ",position[i]);
	}
}
