#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<iostream>

using namespace std;

struct character{
	char id;
	int parameter;
	int use;
	int appear;
	string para_string; 
};

int main(void){
	struct character letter[26];
	//��ʼ�����еĽṹ������ 
	for(int i = 0; i < 26; i++){
		letter[i].id = 'a'+i;
		letter[i].parameter = 0;
		letter[i].use = 0;
		letter[i].appear = 0;
	}
	//��ȡ����
	char S[52];
	scanf("%s",S);
	//������׼��������ĸ�Ƿ�����Լ��Ƿ�ᱻʹ��ȷ���� 
	for(int i = 0; i < strlen(S); i++){
		if(S[i] == ':'){
			letter[S[i-1]-'a'].parameter = 1;
		}
		else{
			letter[S[i]-'a'].parameter = 0;
			letter[S[i]-'a'].use = 1;
		}
	}
	
	int N;
	scanf("%d",&N);
	getchar(); 
	
	string command,k[150];
	int s;											//s�����ַ����ָ�ɶ��ٿ� 
	for(int i = 0; i < N; i++){
		s = 0;
		for(int j = 0; j < 150; j++) k[j].clear(); 
		//��ȡ������
		getline(cin,command);
		//���ַ������зָ�
		for (int j = 0; j < command.length(); j++) { //���ַ����ָ���ַ�������
			if (command[j] == ' ') {                 //�Կո���Ϊ�ָ���
				s++;
				continue;
			}
			k[s] += command[j];                      //���ָ�õ��ַ����ŵ�K������
		}
		
		for(int j = 1; j <= s; j++){
			if(k[j][0] != '-' || k[j][1] < 'a' || k[j][1] > 'z' || k[j].size() > 2) break;
			if(letter[k[j][1]-'a'].use == 0) break;
			else{
				letter[k[j][1]-'a'].appear = 1;
				//�������һ����������ѡ�� 
				if(letter[k[j][1]-'a'].parameter == 1){
					if((j+1) == s+1) break;
					letter[k[j][1]-'a'].para_string.clear();
					letter[k[j][1]-'a'].para_string = k[j+1];
					j++;
				}
			}
		}
		
		printf("Case %d: ",i+1);
		for(int j = 0; j < 26; j++){
			if(letter[j].appear == 1){
				printf("-%c ",letter[j].id);
				if(letter[j].parameter == 1){
					cout << letter[j].para_string << ' ';
				}
			}
		}
		printf("\n"); 
		
		for(int j = 0; j < 26; j++){
			letter[j].appear = 0;
		}

	}
}
