#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int month_day[2][13];
map <string, int> transfer;
//long long begin_time,end_time;

struct command{
	int minute[60];
	int hours[24];
	int day_of_month[32];
	int month[13];
	int day_of_week[7];
	string command;
}commands[21];

void next_time(int &year, int &month, int &day, int &hour, int &minute){
	minute = (minute+1)%60;
	if(minute == 0){
		hour = (hour+1)%24;
		if(hour == 0){
			//如果是闰年 
			if((year%4 == 0 && year%100 != 0) || year%400 == 0){
				if(day == month_day[1][month]) day = 1;
				else day = (day+1)%month_day[1][month] ? (day+1)%month_day[1][month] : month_day[1][month];
			}
			else{
				if(day == month_day[0][month]) day = 1;
				else day = (day+1)%month_day[0][month] ? (day+1)%month_day[0][month] : month_day[0][month];
			} 
			if(day == 1){
				month = (month+1)%12 ? (month+1)%12 : 12;
				if(month == 1){
					year++;
				}
			}
		}
	}
}

int CaculateWeekDay(int y, int m, int d)  
{
    if(m==1||m==2) //把一月和二月换算成上一年的十三月和是四月  
    {  
        m+=12;  
        y--;
    }
    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7; 
	Week = (Week+1)%7;
	return Week;
}

int main(void){
	month_day[0][1] = 31;
	month_day[1][1] = 31;
	month_day[0][2] = 28;
	month_day[1][2] = 29;
	month_day[0][3] = 31;
	month_day[1][3] = 31;
	month_day[0][4] = 30;
	month_day[1][4] = 30;
	month_day[0][5] = 31;
	month_day[1][5] = 31;
	month_day[0][6] = 30;
	month_day[1][6] = 30;
	month_day[0][7] = 31;
	month_day[1][7] = 31;
	month_day[0][8] = 31;
	month_day[1][8] = 31;
	month_day[0][9] = 30;
	month_day[1][9] = 30;
	month_day[0][10] = 31;
	month_day[1][10] = 31;
	month_day[0][11] = 30;
	month_day[1][11] = 30;
	month_day[0][12] = 31;
	month_day[1][12] = 31;
	transfer["jan"] = 1;
	transfer["feb"] = 2;
	transfer["mar"] = 3;
	transfer["apr"] = 4;
	transfer["may"] = 5;
	transfer["jun"] = 6;
	transfer["jul"] = 7;
	transfer["aug"] = 8;
	transfer["sep"] = 9;
	transfer["oct"] = 10;
	transfer["nov"] = 11;
	transfer["dec"] = 12;
	transfer["sun"] = 0;
	transfer["mon"] = 1;
	transfer["tue"] = 2;
	transfer["wed"] = 3;
	transfer["thu"] = 4;
	transfer["fri"] = 5;
	transfer["sat"] = 6;
	transfer["0"] = 0;
	transfer["1"] = 1;
	transfer["2"] = 2;
	transfer["3"] = 3;
	transfer["4"] = 4;
	transfer["5"] = 5;
	transfer["6"] = 6;
	transfer["7"] = 7;
	transfer["8"] = 8;
	transfer["9"] = 9;
	transfer["10"] = 10;
	transfer["11"] = 11;
	transfer["12"] = 12;
	
	int N;
	long long begin_time,end_time;
	cin >> N >> begin_time >> end_time;
	int now_year,now_month,now_day,now_hour,now_minute;
	int end_year,end_month,end_day,end_hour,end_minute;
	
		end_minute=end_time%100;end_time/=100;
        end_hour=end_time%100;end_time/=100;
        end_day=end_time%100;end_time/=100;
        end_month=end_time%100;end_time/=100;
        end_year=end_time;

        now_minute=begin_time%100;begin_time/=100;
        now_hour=begin_time%100;begin_time/=100;
        now_day=begin_time%100;begin_time/=100;
        now_month=begin_time%100;begin_time/=100;
        now_year=begin_time;
        
        
	string str;
	
	string small;
	int first,end;
	string::size_type pos_dou1;
	string::size_type pos_dou2;
	string::size_type pos_;
	int pos1,pos2;
	string strA;
	
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 60; j++) commands[i].minute[j] = 0;
		for(int j = 0; j < 24; j++) commands[i].hours[j] = 0;
		for(int j = 1; j < 32; j++) commands[i].day_of_month[j] = 0;
		for(int j = 1; j < 13; j++) commands[i].month[j] = 0;
		for(int j = 0; j < 7; j++)  commands[i].day_of_week[j] = 0;
		
		//minutes
		cin >> str;
		if(str[0] == '*'){
			for(int j = 0; j < 60; j++) commands[i].minute[j] = 1;
		}
		else{
					first = atoi(str.c_str());
					commands[i].minute[first] = 1;
		}
		
		//hour
		cin>>str;
		if(str[0] == '*'){
			for(int j = 0; j < 24; j++) commands[i].hours[j] = 1;
		}
		else{
					first = atoi(str.c_str());
					commands[i].hours[first] = 1;
		}
		
		//day of month
		cin>>str;
		if(str[0] == '*'){
			for(int j = 1; j < 32; j++) 
				commands[i].day_of_month[j] = 1;
		}
		else{
					first = atoi(str.c_str());
					commands[i].day_of_month[first] = 1;
		}
		
		//month
		cin>>str;
		if(str[0] == '*'){
			for(int j = 1; j < 13; j++) commands[i].month[j] = 1;
		}
		else{
			strA = str;
					first = transfer[strA];
					commands[i].month[first] = 1;
		}
		
		//day of week
		cin>>str;
		if(str[0] == '*'){
			for(int j = 0; j < 7; j++) commands[i].day_of_week[j] = 1;
		}
		else{
					strA = str;

					first = transfer[strA];
					commands[i].day_of_week[first] = 1;
		}
		
		cin >> commands[i].command;
//		for(int j = 0; j < 60; j++) cout << commands[i].minute[j] << " ";
//		cout << endl;
//		for(int j = 0; j < 24; j++) cout << commands[i].hours[j] << " ";
//		cout << endl;
//		for(int j = 1; j < 32; j++) cout << commands[i].day_of_month[j] << " ";
//		cout << endl;
//		for(int j = 1; j < 13; j++) cout << commands[i].month[j] << " ";
//		cout << endl;
//		for(int j = 0; j < 7; j++)  cout << commands[i].day_of_week[j] << " ";
//		cout << endl;
		
	}
	
		int Week;
		while(end_minute != now_minute || end_hour != now_hour || end_day != now_day 
			|| end_month != now_month || now_year != end_year ){
		Week = CaculateWeekDay(now_year,now_month,now_day);
		
		for(int i = 0; i < N; i++){
			if(commands[i].minute[now_minute] && 
				commands[i].hours[now_hour] && 
				commands[i].day_of_month[now_day] && 
				commands[i].month[now_month] && 
				commands[i].day_of_week[Week]){
				printf("%04d%02d%02d%02d%02d %s\n",now_year,now_month,now_day,now_hour,now_minute,commands[i].command.c_str());
			}
		}
		next_time(now_year,now_month,now_day,now_hour,now_minute);
//		cout << now_year << " " << now_month << " " << now_day <<  " " << now_hour << " " << now_minute << endl;
		}
}
