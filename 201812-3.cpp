#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#include<cmath> 

using namespace std;

struct IP_address{
	int a[4];
	int len;
}ip_addresses[1000001];

bool cmp(IP_address a, IP_address b){
	if(a.a[3] != b.a[3]) return a.a[3] < b.a[3];
	else if(a.a[2] != b.a[2]) return a.a[2] < b.a[2];
	else if(a.a[1] != b.a[1]) return a.a[1] < b.a[1];
	else if(a.a[0] != b.a[0]) return a.a[0] < b.a[0];
	else return a.len < b.len;
} 

int main(void){
	int N;
	string str;
	scanf("%d",&N);
	//处理输入 
	for(int i = 0; i < N; i++){
		int ip_num = 0;
		cin >> str;
		ip_addresses[i].a[3] = 0;
		ip_addresses[i].a[2] = 0;
		ip_addresses[i].a[1] = 0;
		ip_addresses[i].a[0] = 0;
		ip_addresses[i].len = 0;
		string::size_type pos_xie = str.find("/");
		
		if(pos_xie != string::npos){
			//先将len存储起来再说 
			ip_addresses[i].len = atoi(str.substr(pos_xie+1).c_str()); 
			str = str.substr(0,pos_xie);
			str = "." + str + ".";
				string::size_type pos = str.find(".");
				string::size_type pos2 = str.find(".",pos+1);
				while(pos2 != string::npos){
					//如果两个 / 不相邻 
					if(pos+1 != pos2){
						ip_addresses[i].a[3-ip_num] = atoi(str.substr(pos+1,pos2-pos-1).c_str());
						ip_num++;
					}
					pos = pos2;
					pos2 = str.find(".",pos+1);
				}
		}
		else{
				str = "." + str + ".";
				string::size_type pos = str.find(".");
				string::size_type pos2 = str.find(".",pos+1);
				while(pos2 != string::npos){
					//如果两个 / 不相邻 
					if(pos+1 != pos2){
						ip_addresses[i].a[3-ip_num] = atoi(str.substr(pos+1,pos2-pos-1).c_str());
						ip_num++;
					}
					pos = pos2;
					pos2 = str.find(".",pos+1);
				}
				ip_addresses[i].len = 8*ip_num;
		}
//		
//		cout << ip_addresses[i].a[3] << "." << ip_addresses[i].a[2] << ".";
//		cout << ip_addresses[i].a[1] << "." << ip_addresses[i].a[0] << "/" << ip_addresses[i].len << endl;
	}
	
	sort(ip_addresses,ip_addresses+N,cmp);
	
	//开始从小到大合并
	long long ip_address_value_min_a,ip_address_value_max_a;
	long long ip_address_value_min_b,ip_address_value_max_b;
	for(int i = 0; i < N; i++){
		ip_address_value_min_a = 
		ip_addresses[i].a[0] + ip_addresses[i].a[1]*256 + ip_addresses[i].a[2]*256*256 + ip_addresses[i].a[3]*256*256*256;
		int a0,a1,a2,a3;
		int j = (32-ip_addresses[i].len)/8;
		if(j == 0){
			a0 = pow(2,32-ip_addresses[i].len)-1;
			a1 = 0;
			a2 = 0;
			a3 = 0;
		}
		else if(j == 1){
			a0 = 255;
			a1 = pow(2,ip_addresses[i].len-8)-1;
			a2 = 0;
			a3 = 0;
		}
		else if(j == 2){
			a0 = 255;
			a1 = 255;
			a2 = pow(2,32-ip_addresses[i].len-16)-1;
			a3 = 0;
		}
		else if(j == 3){
			a0 = 255;
			a1 = 255;
			a2 = 255;
			a3 = pow(2,32-ip_addresses[i].len-24)-1;
		}
		else if(j == 4){
			a0 = 255;
			a1 = 255;
			a2 = 255;
			a3 = 255;
		}
		ip_address_value_max_a = ip_address_value_min_a +
		a0 + a1*256 + a2*256*256 + a3*256*256*256;
		
		if(i != N-1){
		ip_address_value_min_b = 
		ip_addresses[i+1].a[0] + ip_addresses[i+1].a[1]*256 + ip_addresses[i+1].a[2]*256*256 + ip_addresses[i+1].a[3]*256*256*256;
		int b0,b1,b2,b3;
		j = (32-ip_addresses[i+1].len)/8;
		if(j == 0){
			b0 = pow(2,32-ip_addresses[i].len)-1;
			b1 = 0;
			b2 = 0;
			b3 = 0;
		}
		else if(j == 1){
			b0 = 255;
			b1 = pow(2,32-ip_addresses[i].len-8)-1;
			b2 = 0;
			b3 = 0;
		}
		else if(j == 2){
			b0 = 255;
			b1 = 255;
			b2 = pow(2,32-ip_addresses[i].len-16)-1;
			b3 = 0;
		}
		else if(j == 3){
			b0 = 255;
			b1 = 255;
			b2 = 255;
			b3 = pow(2,32-ip_addresses[i].len-24)-1;
		}
		else if(j == 4){
			b0 = 255;
			b1 = 255;
			b2 = 255;
			b3 = 255;
		}
		ip_address_value_max_b = ip_address_value_min_b +
		b0 + b1*256 + b2*256*256 + b3*256*256*256;
		//如果b是a的子集,将b从列表中删除，再从a开始继续遍历 
		if(ip_address_value_min_b >= ip_address_value_min_a && ip_address_value_max_b <= ip_address_value_max_a) {
			ip_addresses[i+1].a[0] = 256;
			sort(ip_addresses,ip_addresses+N,cmp);
			N = N-1;
			i = i-1;
		}
		
		}
	}
	
	
	
	if(ip_addresses[0].a[3] == 0 && ip_addresses[0].a[2] == 0 && 
		ip_addresses[0].a[1] == 0 && ip_addresses[0].a[0] == 0 && ip_addresses[0].len == 0){
			cout << ip_addresses[0].a[3] << "." << ip_addresses[0].a[2] << ".";
			cout << ip_addresses[0].a[1] << "." << ip_addresses[0].a[0] << "/" << ip_addresses[0].len << endl;
		}
	
	else{
		for(int i = 0; i < N; i++){
			cout << ip_addresses[i].a[3] << "." << ip_addresses[i].a[2] << ".";
			cout << ip_addresses[i].a[1] << "." << ip_addresses[i].a[0] << "/" << ip_addresses[i].len << endl;
		}
	}

}
