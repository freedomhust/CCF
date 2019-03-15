#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>

using namespace std;

void CaculateWeekDay(int y, int m, int d)  
{  
    if(m==1||m==2) //把一月和二月换算成上一年的十三月和是四月  
    {  
        m+=12;  
        y--;  
    }  
    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;  
    switch(Week)  
    {
        case 0: cout << "是星期一" << endl; break;  
        case 1: cout << "是星期二" << endl; break;  
        case 2: cout << "是星期三" << endl; break;  
        case 3: cout << "是星期四" << endl; break;  
        case 4: cout << "是星期五" << endl; break;  
        case 5: cout << "是星期六" << endl; break;  
        case 6: cout << "是星期日" << endl; break;  
    }  
}

int main(void){
	int y,m,d;
	scanf("%d%d%d",&y,&m,&d);
	CaculateWeekDay(y,m,d);
}
