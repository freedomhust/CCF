#include<iostream>
using namespace std;
int salaryrange[7]={3500,3500+1500,3500+4500,3500+9000,3500+35000,3500+55000,3500+80000};
int taxrate[7]={3,10,20,25,30,35,45};
int range[7];//˰�����ö�Ӧ�ķ�Χ
int main()
{
	range[0]=salaryrange[0];
	for(int i=1;i<7;i++)//����˰�����ö�Ӧ�ķ�Χ
		range[i]=range[i-1]+(salaryrange[i]-salaryrange[i-1])*(100-taxrate[i-1])/100;
	
	int t = 0,b,i; 
	cin>>t;
	while(t != 10000){

	for(i=0;i<7;i++)
		if(t<range[i])
			break;
	
	if(i==0)
		b=t;
	else
		b=salaryrange[i-1]+(t-range[i-1])*100/(100-taxrate[i-1]);  
	
	cout<<b<<endl;
	t = t + 100;
	}

	return 0;
}
