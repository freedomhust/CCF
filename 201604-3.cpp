#include <iostream>
#include <string>
#include<cstdio>

using namespace std;

string dirs[1000];
string current_dirs[1000]; 

string w,k[1000];

int main(void){
	int N;
	scanf("%d\n",&N);
	getline(cin,w);
	
	//获得当前目录的路径 
	w = "/" + w + "/";
	int current_s_num = 0;
	string::size_type pos = w.find("/");
	string::size_type pos2 = w.find("/",pos+1);
	while(pos2 != string::npos){
		//如果两个 / 不相邻 
		if(pos+1 != pos2){
			current_dirs[current_s_num] = w.substr(pos+1,pos2-pos-1);
			current_s_num++;
		}
		pos = pos2;
		pos2 = w.find("/",pos+1);
	}
	w.clear();
	
	//获取需要处理的路径 
	for(int i = 0; i < N; i++){
		getline(cin,w);
		if(w.length() == 0) {
			cout << "/";
			for(int i = 0; i < current_s_num; i++){
				cout << current_dirs[i];
				if(i != current_s_num - 1) cout << "/";
			}
			cout << endl;
		}
		
		else{
			//如果是绝对路径的正规化 
			if(w[0] == '/'){
				
				//分离出了所有/之间的值 
				w = "/" + w + "/";
				int s = 0;
				string::size_type pos = w.find("/");
				string::size_type pos2 = w.find("/",pos+1);
				while(pos2 != string::npos){
					//如果两个 / 不相邻 
					if(pos+1 != pos2){
						k[s] = w.substr(pos+1,pos2-pos-1);
						s++;
					}
					pos = pos2;
					pos2 = w.find("/",pos+1);
				}
//				for(int i = 0; i < s; i++){
//					cout << k[i] << endl;
//				}
				
				dirs[0] = "/";
				int M = 0;
				for(int i = 0; i < s; i++){
					if(M != 0 && k[i] == "..") M--;
					if(k[i] != ".." && k[i] != "."){
						M++;
						dirs[M] = k[i];
					}
				}
				
				for(int i = 0; i <= M; i++){
					cout << dirs[i];
					if(i != M && i != 0) cout << "/";
				}
				cout << endl;
			}
			
			//如果是相对路径的正规化 
			else{
				
				//分离出了所有/之间的值 
				w = "/" + w + "/";
				int s = 0;
				string::size_type pos = w.find("/");
				string::size_type pos2 = w.find("/",pos+1);
				while(pos2 != string::npos){
					//如果两个 / 不相邻 
					if(pos+1 != pos2){
						k[s] = w.substr(pos+1,pos2-pos-1);
						s++;
					}
					pos = pos2;
					pos2 = w.find("/",pos+1);
				}
//				for(int i = 0; i < s; i++){
//					cout << k[i] << endl;
//				}

				//将当前路径也续上 
				dirs[0] = "/";
				int M = 0;
				for(int i = 0; i < current_s_num; i++){
					M++;
					dirs[M] = current_dirs[i];
				}
				//然后开始接输入的相对路径 
				for(int i = 0; i < s; i++){
					if(M != 0 && k[i] == "..") M--;
					if(k[i] != ".." && k[i] != "."){
						M++;
						dirs[M] = k[i];
					}
				}
				
				for(int i = 0; i <= M; i++){
					cout << dirs[i];
					if(i != M && i != 0) cout << "/";
				}
				cout << endl;
			} 
		}
		//每次处理完一次输入，将目录和k的值清空，还有w 
		w.clear();
		for(int i = 0; i < 1000; i++){
			k[i].clear();
			dirs[i].clear();
		}
	}
	

	return 0;
}
