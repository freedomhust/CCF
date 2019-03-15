#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream> 

using namespace std;

int position[1001];

struct time{
	int key_num;
	//1��ʾ����0��ʾ�� 
	int action_key;
	int time;
}times[2000];

bool cmp(time a, time b){
	if(a.time != b.time) return a.time < b.time;
	//���ʱ��������Ȼ��ٽ� 
	else{
		if(a.action_key != b.action_key) return a.action_key > b.action_key;
		//����ʱ��keynum��С�������� 
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
		//����ǽ裬�����ҵ�Կ�׵�λ�� 
		if(times[i].action_key == 0){
			for(int j = 1; j <= N; j++){
				if(position[j] == times[i].key_num){
					position[j] = -1;
					break;
				} 
			} 
		}
		//����ǻ��������ұ���ֱ���ҵ���һ��Կ�׿յ�λ��
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
