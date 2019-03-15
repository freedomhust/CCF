#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

string str;

string res;

map<string,string> mp;

void format(string &value){
		string::size_type pos3 = value.find("\\\"");
		string::size_type pos4 = value.find("\\\\");
		while(pos3 != string::npos || pos4 != string::npos){
			if(pos3 != string::npos) 
			value.erase(pos3,1);
			if(pos4 != string::npos) 
			value.erase(pos4,1);
			pos3 = value.find("\\\"");
			pos4 = value.find("\\\\");
		}
}

void deal(string::size_type pos,string mom){
	string value;
	if(res[pos+2] == '\"'){
		string::size_type pos2 = res.find("\"",pos+3);
		while(res[pos2-1] == '\\'){
			pos2 = res.find("\"",pos2+1);
		} 
		value = res.substr(pos+3,pos2-pos-3);
		format(value);
		mp[mom] = value;
	}
}


int main(void){
	int N,M;
	scanf("%d%d\n",&N,&M);
	//取出str中的所有空格 
	for(int i = 0; i < N; i++){
		getline(cin,str);
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		res = res + str;
	}
	res = res.substr(1,res.size()-2);
	
	string name;
	//找到双引号的位置 
	string::size_type pos_yin1 = res.find("\"");
	string::size_type pos_yin2 = res.find("\"",pos_yin1+1);
	name = res.substr(pos_yin1+1,pos_yin2-1-pos_yin1);
	format(name);
	deal(pos_yin2,name);
	string::size_type pos_dou;
	if(res[pos_yin2+2] == '\"'){
		pos_dou = res.find(",",pos_yin2+2);
	}
	//只能处理两层嵌套 
	else if(res[pos_yin2+2] == '{'){
		pos_dou = res.find("},",pos_yin2+2);
	}
	while(pos_dou != string::npos){
		pos_yin1 = res.find("\"",pos_dou+1);
		pos_yin2 = res.find("\"",pos_yin1+1);
		name = res.substr(pos_yin1+1,pos_yin2-1-pos_yin1);
		format(name);
		deal(pos_yin2,name);
		if(res[pos_yin2+2] == '\"'){
			pos_dou = res.find(",",pos_yin2+2);
		}
		//只能处理两层嵌套 
		else if(res[pos_yin2+2] == '{'){
			pos_dou = res.find("},",pos_yin2+2);
		}
	}
	
	
	for(int i = 0; i < M; i++){
		getline(cin,name);
		if(mp[name] != "")
		cout << "STRING " << mp[name] << endl;
		else cout << "NOTEXIST" << endl;
	}
	
}
