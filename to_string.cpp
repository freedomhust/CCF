////ʵ��to_string����
//#include<iostream>
//#include<string>
//using namespace std;
//#define max 100
//string to_String(int n)
//{
//    int m = n;
//    char s[max];
//    char ss[max];
//    int i=0,j=0;
//    if (n < 0)// ������
//    {
//        m = 0 - m;
//        j = 1;
//        ss[0] = '-';
//    }    
//    while (m>0)
//    {
//        s[i++] = m % 10 + '0';
//        m /= 10;
//    }
//    s[i] = '\0';
//    i = i - 1;
//    while (i >= 0)
//    {
//        ss[j++] = s[i--];
//    }    
//    ss[j] = '\0';    
//    return ss;
//}
//
//int main()
//{    
//    cout << "����������:";
//    int m;
//    cin >> m;    
//    string s = to_String(m) + "abc";
//    cout << s << endl;
//    system("pause");
//    return 0;
//}

#include<sstream> 
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
std::string str = "123";
int n = atoi(str.c_str());
printf("%d",n);
}
