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
	
	//��õ�ǰĿ¼��·�� 
	w = "/" + w + "/";
	int current_s_num = 0;
	string::size_type pos = w.find("/");
	string::size_type pos2 = w.find("/",pos+1);
	while(pos2 != string::npos){
		//������� / ������ 
		if(pos+1 != pos2){
			current_dirs[current_s_num] = w.substr(pos+1,pos2-pos-1);
			current_s_num++;
		}
		pos = pos2;
		pos2 = w.find("/",pos+1);
	}
	w.clear();
	
	//��ȡ��Ҫ�����·�� 
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
			//����Ǿ���·�������滯 
			if(w[0] == '/'){
				
				//�����������/֮���ֵ 
				w = "/" + w + "/";
				int s = 0;
				string::size_type pos = w.find("/");
				string::size_type pos2 = w.find("/",pos+1);
				while(pos2 != string::npos){
					//������� / ������ 
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
			
			//��������·�������滯 
			else{
				
				//�����������/֮���ֵ 
				w = "/" + w + "/";
				int s = 0;
				string::size_type pos = w.find("/");
				string::size_type pos2 = w.find("/",pos+1);
				while(pos2 != string::npos){
					//������� / ������ 
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

				//����ǰ·��Ҳ���� 
				dirs[0] = "/";
				int M = 0;
				for(int i = 0; i < current_s_num; i++){
					M++;
					dirs[M] = current_dirs[i];
				}
				//Ȼ��ʼ����������·�� 
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
		//ÿ�δ�����һ�����룬��Ŀ¼��k��ֵ��գ�����w 
		w.clear();
		for(int i = 0; i < 1000; i++){
			k[i].clear();
			dirs[i].clear();
		}
	}
	

	return 0;
}
