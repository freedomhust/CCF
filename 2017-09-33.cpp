#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

string str;

string res_out;

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


void deal(string &mom, string &res){
	string name,value;
	for(int i = 0; i < res.size(); i++){
		if(res[i] == '"'){
			int j = res.find(":",i+1);
			name = res.substr(i+1,j-i-2);
			format(name);
			if(mom != ""){
				name = mom+"."+name;
			} 
			
			if(res[j+1] == '"'){
				if (res.find(",", j + 1) != string::npos)
					i = res.find(",", j + 1);
				else
					i = res.size() - 1;
				value = res.substr(j + 2, i - j - 3);
				format(value);
			}
			else{
				i = j + 2;
				int count = 1;
				while(count != 0){
					if(res[i] == '{') 
					count++;
					else if(res[i] == '}')
					count--;
					i++;
				}
				value = res.substr(j+1,i-j-1);
				format(value);
				deal(name,value);
			}
			mp[name] = value;
		}
	}
	
}

int main(void){
	int N,M;
	string name;
	scanf("%d%d\n",&N,&M);
	//取出str中的所有空格 
	for(int i = 0; i < N; i++){
		getline(cin,str);
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		res_out = res_out + str;
	}
	string add = "";
	deal(add,res_out);
	
	for(int i = 0; i < M; i++){
		getline(cin,name);
		if(mp[name] == "")
		cout << "NOTEXIST" << endl;
		else if(mp[name][0] == '{')
		cout << "OBJECT" << endl;
		else 
		cout << "STRING " << mp[name] << endl;
	}
}
