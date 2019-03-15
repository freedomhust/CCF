#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
	string find;
	getline(cin,find);
	
	int turn;
	scanf("%d",&turn);
	int M;
	scanf("%d",&M);
	getchar();
	
	string data[M];
	string test;
	//¥Û–°–¥√Ù∏– 
	if(turn == 1){
		for(int i = 0; i < M; i++){
			getline(cin,data[i]);
			if(data[i].find(find) != string::npos){
				cout << data[i] << endl;
			}
		}	
		
	}
	 
	else{
		transform(find.begin(), find.end(), find.begin(), ::toupper);
		for(int i = 0; i < M; i++){
			getline(cin,data[i]);
			test = data[i];
			transform(test.begin(), test.end(), test.begin(), ::toupper);
			if(test.find(find) != string::npos){
				cout << data[i] << endl;
			}
		}
	}
}
