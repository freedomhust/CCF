#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	string str1 = "123";
	string str2 = "13";
	if(str1 < str2) cout << str1 << " < " << str2;
	else if(str1 > str2) cout << str1 << " > " << str2;
}
