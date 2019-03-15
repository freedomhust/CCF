#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

struct year{
	int year;
	int month[13]; 
	int month_first_day[13];
	int month_last_day[13];
	int special; 
}years[201];

int main(void){
	int a,b,c;
	int left_year,right_year;
	
	scanf("%d%d%d%d%d",&a,&b,&c,&left_year,&right_year);
	
	//计算出每一年月份以及是否是闰年以及1月1日是周几 
	for(int i = 1850,j = 0; i <= 2050; i++,j++){
		years[j].year = i;
		//如果是闰年 
		if(i%400 == 0 || (i%4 == 0 && i%100 != 0)){
			years[j].special =1; 
			years[j].month[2] = 29;
		}
		else{
			years[j].special = 0; 
			years[j].month[2] = 28;
		}
		years[j].month[1] = 31;
		years[j].month[3] = 31;
		years[j].month[4] = 30;
		years[j].month[5] = 31;
		years[j].month[6] = 30;
		years[j].month[7] = 31;
		years[j].month[8] = 31;
		years[j].month[9] = 30;
		years[j].month[10] = 31;
		years[j].month[11] = 30;
		years[j].month[12] = 31;
		
		//确定每个月的第一天是周几 
		if(i == 1850){
			years[j].month_first_day[1] = 2;
			
			years[j].month_last_day[1] = years[j].month[1]%7 - 1 + years[j].month_first_day[1]; 
		} 
		else{
			 years[j].month_first_day[1] = 
			(years[j-1].month_last_day[12]+1)%7 ? (years[j-1].month_last_day[12]+1)%7 : 7;
			 years[j].month_last_day[1] = 
			(years[j].month[1]%7 - 1 + years[j].month_first_day[1])%7 ? 
			(years[j].month[1]%7 - 1 + years[j].month_first_day[1])%7 : 7;
		} 
		
		for(int k = 2; k <= 12; k++){
			years[j].month_first_day[k] = 
			(years[j].month_last_day[k-1]+1)%7 ? 
			(years[j].month_last_day[k-1]+1)%7 : 7;
			
			years[j].month_last_day[k] = (years[j].month[k]%7 - 1 + years[j].month_first_day[k])%7 ?
										 (years[j].month[k]%7 - 1 + years[j].month_first_day[k])%7 : 7;
		}
	}
	
	for(int m = left_year; m <= right_year; m++){
		int week = 0,day = 0;
		int x = 0;
		int T = years[m-1850].month_first_day[a];
		//计算出是这个月的第几天 
		for(x = 1; x <= years[m-1850].month[a]; x++){
			if(T == c) week++;
			if(week == b) break;
			T = (T+1)%7 ? (T+1)%7 : 7;
		}
		if(week != b) printf("none\n");
		else{
			printf("%d/%02d/%02d\n",m,a,x);
		} 
	}
}
