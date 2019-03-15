#include<string>
#include<iostream>
#include<algorithm>

#include<ctype.h>

using namespace std;

struct url_rule{
	string name[100];
	int name_num;
	string parameter[100];
	int parameter_num;
	string result;
	int have_path;
	int have_xie;
}url_rules[101];

int main(void){
	int N,M;
	string str;
	scanf("%d%d",&N,&M);
	for(int i = 0; i < N; i++){
		url_rules[i].name_num = 0;
		url_rules[i].parameter_num = 0;
		url_rules[i].have_path = 0;
		url_rules[i].have_xie = 0;
		cin >> str;
		cin >> url_rules[i].result;
		
		str = "/" + str + "/";
		if(str[str.size()-2] == '/') url_rules[i].have_xie = 1;
		string::size_type pos = str.find("/");
		string::size_type pos2 = str.find("/",pos+1);
		while(pos2 != string::npos){
			//如果两个 / 不相邻 
			if(pos+1 != pos2){
				url_rules[i].name[url_rules[i].name_num] = str.substr(pos+1,pos2-pos-1);
				if(url_rules[i].name[url_rules[i].name_num] == "<path>"){
					url_rules[i].have_path = 1;
				}
				url_rules[i].name_num++;
			}
			pos = pos2;
			pos2 = str.find("/",pos+1);
		}
	}

	string address[100]; 
	//处理地址 
	for(int i = 0; i < M; i++){
		cin >> str;
		int address_num = 0;
		str = "/" + str + "/";
		string::size_type pos = str.find("/");
		string::size_type pos2 = str.find("/",pos+1);
		while(pos2 != string::npos){
			//如果两个 / 不相邻 
			if(pos+1 != pos2){
				address[address_num] = str.substr(pos+1,pos2-pos-1);
				address_num++;
			}
			pos = pos2;
			pos2 = str.find("/",pos+1);
		}
		
		int j; 
		int find_url = 0;
		//对处理过后的地址与所有的地址规则进行匹配
		for(j = 0; j < N; j++){
			if(url_rules[j].have_path != 1){
				//如果里面没有path且参数数量不匹配则说明肯定不是换下一个 
				if(url_rules[j].name_num != address_num) continue;
				else{
					int k = 0;
					//如果参数数量相等则有匹配的可能
					for(k = 0; k < address_num; k++){
						if(url_rules[j].name[k] == "<str>"){
							int is_str = 0;
							for(int x = 0; x < address[k].size(); x++){
								if(address[k][x] < '0' || address[k][x] > '9'){
									is_str = 1;
								}
							}
							if(is_str == 1){
								url_rules[j].parameter[url_rules[j].parameter_num] = address[k];
								url_rules[j].parameter_num++;
							}
							else break;
							

						}
						else if(url_rules[j].name[k] == "<int>"){
							int not_int = 0;
							for(int x = 0; x < address[k].size(); x++){
								if(address[k][x] < '0' || address[k][x] > '9'){
									not_int = 1;
								}
							}
							if(not_int == 1) break;
							
							//处理前导0 
							int y;
							for(y = 0; y < address[k].size(); y++){
								if(address[k][y] != '0') break;
							}
							if(y == address[k].size()) y = y-1;
							
							url_rules[j].parameter[url_rules[j].parameter_num] = address[k].substr(y,address[k].size()-y);
							url_rules[j].parameter_num++;
						}
						else{
							//这条规则不匹配，转到下一条
							if(url_rules[j].name[k] != address[k]){
								break;
							}
						}
					}
					//如果顺利走完了循环则说明就是这条，已经匹配了 
					if(k == address_num) {
						if((str[str.size()-2] != '/' && url_rules[j].have_xie == 0) || (str[str.size()-2] == '/' && url_rules[j].have_xie == 1) ){
							find_url = 1;
							break;
						}	
					}
				}
			}
			//如果参数里有path 
			else{
					int k = 0;
					//一直遍历到最后的path 
					for(k = 0; k < url_rules[j].name_num; k++){
						if(url_rules[j].name[k] == "<str>"){
							url_rules[j].parameter[url_rules[j].parameter_num] = address[k];
							url_rules[j].parameter_num++;
						}
						else if(url_rules[j].name[k] == "<int>"){
							int not_int = 0;
							for(int x = 0; x < address[k].size(); x++){
								if(address[k][x] < '0' || address[k][x] > '9'){
									not_int = 1;
								}
							}
							if(not_int == 1) break;
							
							//处理前导0 
							int y;
							for(y = 0; y < address[k].size(); y++){
								if(address[k][y] != '0') break;
							}
							if(y == address[k].size()) y = y-1;
							
							url_rules[j].parameter[url_rules[j].parameter_num] = address[k].substr(y,address[k].size()-y);
							url_rules[j].parameter_num++;
						}
						else if(url_rules[j].name[k] == "<path>") {
							for(int x = k; x < address_num; x++){
								url_rules[j].parameter[url_rules[j].parameter_num] = url_rules[j].parameter[url_rules[j].parameter_num] + address[x] + "/";
							}
							if(str[str.size()-2] != '/')
							url_rules[j].parameter[url_rules[j].parameter_num] = 
							url_rules[j].parameter[url_rules[j].parameter_num].substr(0,url_rules[j].parameter[url_rules[j].parameter_num].size()-1);
							url_rules[j].parameter_num++;
						}
						else{
							//这条规则不匹配，转到下一条 
							if(url_rules[j].name[k] != address[k]){
								break;
							}
						}
					}
					//如果顺利走完了循环则说明就是这条，已经匹配了 
					if(k == url_rules[j].name_num) {
						if(str[str.size()-2] != '/'){
							find_url = 1;
							break;
						}
					}
			}
		}
		
		if(find_url == 1){
			int legal = 1;
			for(int k = 0; k < str.size(); k++){
				if(str[i]!='/'&&str[i]!='.'&&str[i]!='-'&&str[i]!='_'&&!(isalpha(str[i])||isdigit(str[i]))){
					cout << "404" << endl;
					legal = 0;
				}
			}
			if(legal){
				cout << url_rules[j].result << " ";
				for(int k = 0; k < url_rules[j].parameter_num; k++) cout << url_rules[j].parameter[k] << " ";
				cout << endl;
			}
		}
		else{
			cout << "404" << endl;
		}
		
		for(int k = 0; k < N; k++) url_rules[k].parameter_num = 0;
	}
	
} 
