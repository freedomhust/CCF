#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>

using namespace std;

string text[102];
string variable[102];
string variable_name[102];
string variable_text[102];

int main(void){
	int M,N;
	scanf("%d%d",&M,&N);
	getchar();
	for(int i = 0; i < M; i++){
		getline(cin,text[i]);
	}
	for(int i = 0; i < N; i++){
		getline(cin,variable[i]);
	}
	
	int place;
	for(int i = 0; i < N; i++){
		int j;
		for(j = 0; j < variable[i].size(); j++){
			if(variable[i][j] == ' '){
				place = j;
				break;
			}
		}
		variable_name[i] = variable[i].substr(0,j);
		variable_text[i] = variable[i].substr(j+2,variable[i].size()-j-3);
	}
	
	for(int i = 0; i < N; i++){
		variable_name[i] = "{{ " + variable_name[i] + " }}";
	}
	
	for(int i = 0; i < M; i++){
		int index = 0;
		while(text[i].find("{{ ",index) != string::npos && text[i].find(" }}",index) != string::npos){
			int j;
			for(j = 0; j < N; j++){
				string::size_type k = text[i].find(variable_name[j],index);
				if(k != string::npos){
					text[i].replace(k,variable_name[j].size(),variable_text[j]);
					index = k+variable_text[j].size();
					break;
				}
			}
			if(j == N){
				text[i].replace(text[i].find("{{ "),text[i].find(" }}")-text[i].find("{{ ")+3,"");
			}
		}
		cout << text[i] << endl;
	}
} 
