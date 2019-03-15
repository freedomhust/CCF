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
				else
				day = (day+1)%month_day[0][month] ? (day+1)%month_day[0][month] : month_day[0][month];
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
//	transfer["13"] = 13;
//	transfer["14"] = 14;
//	transfer["15"] = 15;
//	transfer["16"] = 16;
//	transfer["17"] = 17;
//	transfer["18"] = 18;
//	transfer["19"] = 19;
//	transfer["20"] = 20;
//	transfer["21"] = 21;
//	transfer["22"] = 22;
//	transfer["23"] = 23;
//	transfer["24"] = 24;
//	transfer["25"] = 25;
//	transfer["26"] = 26;
//	transfer["27"] = 27;
//	transfer["28"] = 28;
//	transfer["29"] = 29;
//	transfer["30"] = 30;
//	transfer["31"] = 31;
//	transfer["32"] = 32;
//	transfer["33"] = 33;
//	transfer["34"] = 34;
//	transfer["35"] = 35;
//	transfer["36"] = 36;
//	transfer["37"] = 37;
//	transfer["38"] = 38;
//	transfer["39"] = 39;
//	transfer["40"] = 40;
//	transfer["41"] = 41;
//	transfer["42"] = 42;
//	transfer["43"] = 43;
//	transfer["44"] = 44;
//	transfer["45"] = 45;
//	transfer["46"] = 46;
//	transfer["47"] = 47;
//	transfer["48"] = 48;
//	transfer["49"] = 49;
//	transfer["50"] = 50;
//	transfer["51"] = 51;
//	transfer["52"] = 52;
//	transfer["53"] = 53;
//	transfer["54"] = 54;
//	transfer["55"] = 55;
//	transfer["56"] = 56;
//	transfer["57"] = 57;
//	transfer["58"] = 58;
//	transfer["59"] = 59;
	
	
	
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
	//处理输入的命令
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
			str = ","+str+",";
			pos_dou1 = str.find(",");
			pos_dou2 = str.find(",",pos_dou1+1);
			
			//不断地将逗号之间的数字分离开来 
			while(pos_dou2 != string::npos){
				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
				pos_ = small.find("-");
				if(pos_ != string::npos){
					first = atoi(small.substr(0,pos_).c_str());
					end = atoi(small.substr(pos_+1,small.size()-pos_-1).c_str());
					for(int j = first; j <= end; j++) 
						commands[i].minute[j] = 1;
				}
				else{
					first = atoi(small.c_str());
					commands[i].minute[first] = 1;
				}
				pos_dou1 = pos_dou2;
				pos_dou2 = str.find(",",pos_dou1+1);
			}
		}

		//hours
		cin>>str;
		if(str[0] == '*'){
			for(int j = 0; j < 24; j++) commands[i].hours[j] = 1;
		}
		else{
			str = ","+str+",";
			pos_dou1 = str.find(",");
			pos_dou2 = str.find(",",pos_dou1+1);
			//不断地将逗号之间的数字分离开来 
			while(pos_dou2 != string::npos){
				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
				pos_ = small.find("-");
				if(pos_ != string::npos){
					first = atoi(small.substr(0,pos_).c_str());
					end = atoi(small.substr(pos_+1,small.size()-pos_-1).c_str());
					for(int j = first; j <= end; j++) 
						commands[i].hours[j] = 1;
				}
				else{
					first = atoi(small.c_str());
					commands[i].hours[first] = 1;
				}
				pos_dou1 = pos_dou2;
				pos_dou2 = str.find(",",pos_dou1+1);
			}
		}

		
		//day of month
		cin>>str;
		if(str[0] == '*'){
			for(int j = 1; j < 32; j++) 
				commands[i].day_of_month[j] = 1;
		}
		else{
			str = ","+str+",";
			pos_dou1 = str.find(",");
			pos_dou2 = str.find(",",pos_dou1+1);
			//不断地将逗号之间的数字分离开来 
			while(pos_dou2 != string::npos){
				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
				pos_ = small.find("-");
				if(pos_ != string::npos){
					first = atoi(small.substr(0,pos_).c_str());
					end = atoi(small.substr(pos_+1,small.size()-pos_-1).c_str());
					for(int j = first; j <= end; j++) 
						commands[i].day_of_month[j] = 1;
				}
				else{
					first = atoi(small.c_str());
					commands[i].day_of_month[first] = 1;
				}
				pos_dou1 = pos_dou2;
				pos_dou2 = str.find(",",pos_dou1+1);
			}
		}
		
		//month
		cin>>str;
		if(str[0] == '*'){
			for(int j = 1; j < 13; j++) commands[i].month[j] = 1;
		}
		else{
			str = ","+str+",";
			pos_dou1 = str.find(",");
			pos_dou2 = str.find(",",pos_dou1+1);
			//不断地将逗号之间的数字分离开来 
			while(pos_dou2 != string::npos){
				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
				pos_ = small.find("-");
				if(pos_ != string::npos){
					strA = small.substr(0,pos_);
					if(strA > "12" || strA < "1"){
						transform(strA.begin(), strA.end(), strA.begin(), ::tolower); 
					}
					first = transfer[strA];
					strA = small.substr(pos_+1,small.size()-pos_-1);
					if(strA > "12" || strA < "1"){
						transform(strA.begin(), strA.end(), strA.begin(), ::tolower); 
					}
					end = transfer[strA];
					for(int j = first; j <= end; j++) 
						commands[i].month[j] = 1;
				}
				else{
					strA = small;
					if(strA > "12" || strA < "1"){
						transform(strA.begin(), strA.end(), strA.begin(), ::tolower); 
					}
					first = transfer[strA];
					commands[i].month[first] = 1;
				}
				pos_dou1 = pos_dou2;
				pos_dou2 = str.find(",",pos_dou1+1);
			}
		}
		
		//day of week
		cin>>str;
		if(str[0] == '*'){
			for(int j = 0; j < 7; j++) commands[i].day_of_week[j] = 1;
		}
		else{
			str = ","+str+",";
			pos_dou1 = str.find(",");
			pos_dou2 = str.find(",",pos_dou1+1);
			//不断地将逗号之间的数字分离开来 
			while(pos_dou2 != string::npos){
				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
				pos_ = small.find("-");
				if(pos_ != string::npos){
					strA = small.substr(0,pos_);
					if(strA > "6" || strA < "0"){
						transform(strA.begin(), strA.end(), strA.begin(), ::tolower); 
					}
					first = transfer[strA];
					strA = small.substr(pos_+1,small.size()-pos_-1);
					if(strA > "6" || strA < "0"){
						transform(strA.begin(), strA.end(), strA.begin(), ::tolower); 
					}
					end = transfer[strA];
					for(int j = first; j <= end; j++) 
						commands[i].day_of_week[j] = 1;
				}
				else{
					strA = small;
					if(strA > "6" || strA < "0"){
						transform(strA.begin(), strA.end(), strA.begin(), ::tolower); 
					}
					first = transfer[strA];
					commands[i].day_of_week[first] = 1;
				}
				pos_dou1 = pos_dou2;
				pos_dou2 = str.find(",",pos_dou1+1);
			}
		}
		
		//command
		cin >> commands[i].command;
//		commands[i].command = str;

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
	
	
	
//		int find_minute = 0;
//		int find_hours = 0;
//		int find_day_of_month = 0;
//		int find_month = 0;
//		int find_day_of_week = 0;
		int Week;
	//开始进行匹配 
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

//	next_time(now_year,now_month,now_day,now_hour,now_minute);

//	cout << now_year << now_month << now_day << now_hour << now_minute << endl;
	
}
