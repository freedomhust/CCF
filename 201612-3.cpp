#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

struct privilege{
	string name;
	int level;
}privileges[100];

struct role{
	string name;
	int privilege_num;
	string privileges[10];
	int level[10];
}roles[100];

struct user{
	string name;
	int role_num;
	string roles[10];
	int roles_number[10];
}users[100];

int main(void){
	int p,r,u,q;
	string privilege_string;
	scanf("%d",&p);
	for(int i = 0; i < p; i++){
		cin >> privilege_string;
		//对输入的权限进行处理
		string::size_type pos = privilege_string.find(":");
		//如果是不分等级权限 
		if(pos == string::npos){
			privileges[i].name = privilege_string;
			privileges[i].level = -1;
		}
		else{
			privileges[i].name = privilege_string.substr(0,pos); 
			privileges[i].level = atoi(privilege_string.substr(pos+1,1).c_str());
		}
	}
	
//	for(int i = 0; i < p; i++){
//		cout << privileges[i].name << privileges[i].level << endl;
//	}
	
	string role_name;
	int privilege_num;
	int num = 0;
	string privilege_string_name; 
	scanf("%d",&r);
	for(int i = 0; i < r; i++){
		num = 0;
		cin >> role_name >> privilege_num;
		roles[i].name = role_name;
		//依次将所有权限名和等级录入 
		for(int j = 0; j < privilege_num; j++){
			cin >> privilege_string;
			string::size_type pos = privilege_string.find(":");
			//如果不分等级，也就不需要判断后面的数字了 
			//还是需要判断该权限是否重复出现的 
			if(pos == string::npos){
				privilege_string_name = privilege_string;
				int k;
				//判断之前是否出现过该种类 
				for(k = 0; k < num; k++){
					if(privilege_string_name == roles[i].privileges[k]){
						break;
					}
				}
				//如果没有重复出现过则录入 
				if(k == num){ 
					roles[i].privileges[num] = privilege_string;
					roles[i].level[num] = -1;
					num++;
				} 
			}
			//如果是分等级的，则需要判断是否之前出现过该类 
			else{
				int level = atoi(privilege_string.substr(pos+1,1).c_str());
				privilege_string_name =  privilege_string.substr(0,pos); 
				int k;
				//判断之前是否出现过该种类 
				for(k = 0; k < num; k++){
					if(privilege_string_name == roles[i].privileges[k]){
						break;
					}
				}
				//如果出现过,比较level的大小，取大的 
				if(k != num){
					roles[i].level[k] = max(roles[i].level[k],level); 
				} 
				//如果没有出现过，则直接录入 
				else{
					roles[i].privileges[num] = privilege_string_name;
					roles[i].level[num] = level;
					num++;
				}
			} 
		}
		roles[i].privilege_num = num;
	}
	
//	for(int i = 0; i < r; i++){
//		cout << roles[i].name << " " << roles[i].privilege_num << " ";
//		for(int j = 0; j < roles[i].privilege_num; j++){
//			cout << roles[i].privileges[j]<< roles[i].level[j] << " ";
//		}
//		cout << endl;
//	}
	
	string user_name;
	int role_num;
	scanf("%d",&u);
	for(int i = 0; i < u; i++){
		cin >> user_name >> role_num;
		users[i].name = user_name;
		users[i].role_num = role_num;
		for(int j = 0; j < role_num; j++){
			cin >> role_name;
			for(int k = 0; k < r; k++){
				if(role_name == roles[k].name){
					users[i].roles[j] = role_name;
					users[i].roles_number[j] = k;
				}
			}
		}
	}
	
//	for(int i = 0; i < u; i++){
//		cout << users[i].name << " " << users[i].role_num << " ";
//		for(int j = 0; j < users[j].role_num; j++) 
//			cout << users[i].roles[j];
//		cout << endl;
//	}
	
	scanf("%d",&q);
	for(int i = 0; i < q; i++){
		cin >> user_name >> privilege_string;
		//首先查找是否有该用户
		int j;
		for(j = 0; j < u; j++){
			if(user_name == users[j].name) break;
		} 
		//如果没有这个用户名 
		if(j == u){
			cout << "false" << endl; 
			continue;
		} 
		
		int k = 0;
		string::size_type position;
		string tmp;
		position = privilege_string.find(":");
		if(position == string::npos) tmp = privilege_string;
		else tmp = privilege_string.substr(0,position);
		//再来查找是否有该权限 
		for(k = 0; k < p; k++){
			if(tmp == privileges[k].name)
			 break;
		}
		//如果没有该权限 
		if(k == p){
			cout << "false" << endl;
			continue;
		}
		
		int find_p = 0;
		int find_level = -1;
		int no_level = 0;
		int res_level = -1;
		string::size_type pos = privilege_string.find(":");
		if(pos == string::npos){
			no_level = 1;
		}
		else{
			no_level = 0;
			find_level = atoi(privilege_string.substr(pos+1,1).c_str());
			privilege_string = privilege_string.substr(0,pos);
		}
		//开始正式的查找
		//遍历每个角色
		for(int x = 0; x < users[j].role_num; x++){
		//遍历每个角色的权限
			for(int y = 0; y < roles[users[j].roles_number[x]].privilege_num; y++){ 
				if(roles[users[j].roles_number[x]].privileges[y] == privilege_string){
					if(roles[users[j].roles_number[x]].level[y] == -1){
						find_p = 1;
						break;
					}
					else{
						if(no_level == 1){
							find_p = 1;
							res_level = max(res_level,roles[users[j].roles_number[x]].level[y]);
						}
						else{
							if(find_level <= roles[users[j].roles_number[x]].level[y]){
								find_p = 1;
								break;
							}
						}
					}
				}
			}
			if(find_p == 1 && no_level != 1) break; 
		}
		
		if(find_p == 0){
			cout << "false" << endl;
		}
		else if(find_p != 0 && no_level == 1 && res_level == -1){
			cout << "true" << endl;
		}
		else if(find_p != 0 && no_level == 1 && res_level != -1){
			cout << res_level << endl;
		}
		else if(find_p == 1 && no_level == 0){
			cout << "true" << endl;
		}
	}
	
}
