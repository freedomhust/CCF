#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>

using namespace std;

void CaculateWeekDay(int y, int m, int d)  
{  
    if(m==1||m==2) //��һ�ºͶ��»������һ���ʮ���º�������  
    {  
        m+=12;  
        y--;  
    }  
    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;  
    switch(Week)  
    {
        case 0: cout << "������һ" << endl; break;  
        case 1: cout << "�����ڶ�" << endl; break;  
        case 2: cout << "��������" << endl; break;  
        case 3: cout << "��������" << endl; break;  
        case 4: cout << "��������" << endl; break;  
        case 5: cout << "��������" << endl; break;  
        case 6: cout << "��������" << endl; break;  
    }  
}

int main(void){
	int y,m,d;
	scanf("%d%d%d",&y,&m,&d);
	CaculateWeekDay(y,m,d);
}
