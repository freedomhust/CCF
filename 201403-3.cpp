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
	//初始化所有的结构体数组 
	for(int i = 0; i < 26; i++){
		letter[i].id = 'a'+i;
		letter[i].parameter = 0;
		letter[i].use = 0;
		letter[i].appear = 0;
	}
	//读取内容
	char S[52];
	scanf("%s",S);
	//做先手准备，将字母是否带参以及是否会被使用确定好 
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
	int s;											//s代表字符串分割成多少块 
	for(int i = 0; i < N; i++){
		s = 0;
		for(int j = 0; j < 150; j++) k[j].clear(); 
		//读取命令行
		getline(cin,command);
		//对字符串进行分割
		for (int j = 0; j < command.length(); j++) { //将字符串分割成字符串数组
			if (command[j] == ' ') {                 //以空格作为分隔符
				s++;
				continue;
			}
			k[s] += command[j];                      //将分割好的字符串放到K数组里
		}
		
		for(int j = 1; j <= s; j++){
			if(k[j][0] != '-' || k[j][1] < 'a' || k[j][1] > 'z' || k[j].size() > 2) break;
			if(letter[k[j][1]-'a'].use == 0) break;
			else{
				letter[k[j][1]-'a'].appear = 1;
				//如果这是一个带参数的选项 
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
