#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>


int main(void){
//	using namespace std;
	char str[13];
	scanf("%s",str);
//	string s[4];
//	S[0] = str[0];
//	S[1] = str.substr(2,4);
//	S[2] = str.substr(6,10);
//	S[3] = str[12];
	int sum;
	sum = str[0]-'0' + (str[2]-'0')*2 + (str[3]-'0')*3
		 +(str[4]-'0')*4 + (str[6]-'0')*5 + (str[7]-'0')*6
		 +(str[8]-'0')*7 + (str[9]-'0')*8 + (str[10]-'0')*9;
	if((sum % 11) == (str[12]-'0') || ((sum%11)==10 && str[12] == 'X')) printf("Right");
	else {
		if((sum % 11) != 10) str[12] = sum%11+'0';
		else str[12] = 'X';
		printf("%s",str);
	}
	
} 
