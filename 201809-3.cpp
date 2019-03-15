#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct line{
	int num;
	int level;
	string label;
	string id;
	string parent;
	string parent_id;
	int parent_line;
}lines[101];


int main(void){
	int N,M;
	string str;
	string parent;
	int parent_line;
	string parent_id;
	string label;
	scanf("%d%d\n",&N,&M);
	for(int i = 1; i <= N; i++){
		getline(cin,str);
//		int pos;
		int j;
		for(j = 0; j < str.size(); j++){
			if(str[j] != '.') break;
		}
		//当前行的级别 
		lines[i].level = j/2;
		lines[i].num = i;
		
		//将点去除 
		str = str.substr(j,str.size()-j);
		string::size_type pos = str.find(" ");
		
		//如果自带标签 
		if(pos != string::npos){
			//分离出标签和id 
			label = str.substr(0,pos);
			transform(label.begin(), label.end(), label.begin(), ::tolower);
			lines[i].label = label;
			lines[i].id = str.substr(pos+1,str.size()-pos-1); 
		}
		else{
			//没有标签 
			label = str;
			transform(label.begin(), label.end(), label.begin(), ::tolower);
			lines[i].label = label;
			lines[i].id = "";
		}
	}
	
	//从下往上确认从属关系 
	for(int i = N; i >= 1; i--){
			//第一行没有parent 
			if(i == 1){
				lines[i].parent_line = 0;
				lines[i].parent_id = "";
				lines[i].parent = "";
			} 
			//如果此行和下一行都是同一级则代表他们有同一个祖先 
			if(i != N && lines[i].level == lines[i+1].level){
				lines[i].parent = lines[i+1].parent;
				lines[i].parent_id = lines[i+1].parent_id;
				lines[i].parent_line = lines[i+1].parent_line;
			}
			//不然就老老实实遍历 
			else{
				//向上找到最靠近的以及就是它的祖先 
				for(int j = i; j >= 1; j--){
					if(lines[i].level == lines[j].level+1){
						lines[i].parent = lines[j].label;
						lines[i].parent_id = lines[j].id;
						lines[i].parent_line = j;
						break;
					}
				}
			}
	}
	
//	for(int i = 1; i <= N; i++){
//		cout << lines[i].num << " " << lines[i].level << " ";
//		cout << lines[i].label << " " << lines[i].id << " ";
//		cout << lines[i].parent_line << " " << lines[i].parent << " " << lines[i].parent_id;
//		cout << endl;
//	} 
	
	string k[100];
	int find_satisfy[100];
	int find_num = 0;
	//处理输入
	for(int i = 0; i < M; i++){
		getline(cin,str);
		str = " " + str + " ";
		int num = 0;
		find_num = 0;
		string::size_type pos = str.find(" ");
		string::size_type pos2 = str.find(" ",pos+1);
		while(pos2 != string::npos){
			//如果两个 / 不相邻 
			if(pos+1 != pos2){
				k[num] = str.substr(pos+1,pos2-pos-1);
				num++;
			}
			pos = pos2;
			pos2 = str.find(" ",pos+1);
		}
//		for(int j= 0; j < num; j++) cout << k[j] << " ";
//		cout <<endl;

		//如果不是后代选择器 
		if(num == 1){
			//如果是id选择 
			if(k[0][0] == '#'){
				for(int j = 1; j <= N; j++){
					if(lines[j].id == k[0]){
						find_satisfy[find_num] = j;
						find_num++;
					}
				}
			}
			//如果是标签选择 
			else{
				//先将标签转换成小写
				transform(k[0].begin(), k[0].end(), k[0].begin(), ::tolower);
				for(int j = 1; j <= N; j++){
					if(lines[j].label == k[0]){
						find_satisfy[find_num] = j;
						find_num++;
					}
				}
			} 
		}
		//如果是后代选择器 
		else{
			//如果是id选择 
			if(k[0][0] == '#'){
				//遍历所有行
				for(int j = 1; j <= N; j++){
					if(lines[j].id == k[num-1]){
						//开始根据一开始的从属关系有没有符合条件的parent
						int m = j;
						int x = num-2;
							string par_id = lines[m].parent_id;
							int par_line = lines[m].parent_line;
							while(par_line != 0){
								if(par_id == k[x]){
									x--;
								}
								//如果全部都满足条件就不用循环了 
								if(x == -1){
									break;
								}
								else{
									par_id = lines[par_line].parent_id;
									par_line = lines[par_line].parent_line;
								}
							}
							//如果当前行满足条件,则可以加一了 
							if(par_line != 0){
								find_satisfy[find_num] = j;
								find_num++;
							}
					}
				} 
			}
			//如果是标签选择
			else{
				//先将标签转化成小写
				for(int j = 0; j < num; j++){
					transform(k[j].begin(), k[j].end(), k[j].begin(), ::tolower);
				}
				
				//遍历所有行
				for(int j = 1; j <= N; j++){
					if(lines[j].label == k[num-1]){
						//开始根据一开始的从属关系有没有符合条件的parent
						int m = j;
						int x = num-2;
							string par_label = lines[m].parent;
							int par_line = lines[m].parent_line;
							while(par_line != 0){
								if(par_label == k[x]){
									x--;
								}
								//如果全部都满足条件就不用循环了 
								if(x == -1){
									break;
								}
								else{
									par_label = lines[par_line].parent;
									par_line = lines[par_line].parent_line;
								}
							}
							//如果当前行满足条件,则可以加一了 
							if(par_line != 0){
								find_satisfy[find_num] = j;
								find_num++;
							}
					}
				} 
				
			} 
		}
		
		cout << find_num << " ";
		for(int j = 0; j < find_num; j++){
			cout << find_satisfy[j] << " ";
		}
		cout << endl;
	} 


}
