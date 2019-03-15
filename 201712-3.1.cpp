//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
//int month_day[2][13];
//map <string, int> transfer;
//
//
//struct command{
//	int minute[60];
//	int hours[24];
//	int day_of_month[32];
//	int month[13];
//	int day_of_week[7];
//	string command;
//}commands[21]; 
//
//void next_time(int &year, int &month, int &day, int &hour, int &minute){
//	minute = (minute+1)%60;
//	if(minute == 0){
//		hour = (hour+1)%24;
//		if(hour == 0){
//			//如果是闰年 
//			if((year%4 == 0 && year%100 != 0) || year%400 == 0){
//				 day = (day+1)%month_day[1][month] ? (day+1)%month_day[1][month] : month_day[1][month+1];
//			}
//			else day = (day+1)%month_day[0][month] ? (day+1)%month_day[0][month] : month_day[0][month+1];
//			if(day == 1){
//				month = (month+1)%12 ? (month+1)%12 : 12;
//				if(month == 1){
//					year++;
//				}
//			}
//		}
//	}
//}
//
//int CaculateWeekDay(int y, int m, int d)  
//{
//    if(m==1||m==2) //把一月和二月换算成上一年的十三月和是四月  
//    {  
//        m+=12;  
//        y--;
//    }
//    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7; 
//	Week = (Week+1)%7;
//	return Week;
//}
//
//int main(void){
//	month_day[0][1] = 31;
//	month_day[1][1] = 31;
//	month_day[0][2] = 28;
//	month_day[1][2] = 29;
//	month_day[0][3] = 31;
//	month_day[1][3] = 31;
//	month_day[0][4] = 30;
//	month_day[1][4] = 30;
//	month_day[0][5] = 31;
//	month_day[1][5] = 31;
//	month_day[0][6] = 30;
//	month_day[1][6] = 30;
//	month_day[0][7] = 31;
//	month_day[1][7] = 31;
//	month_day[0][8] = 31;
//	month_day[1][8] = 31;
//	month_day[0][9] = 30;
//	month_day[1][9] = 30;
//	month_day[0][10] = 31;
//	month_day[1][10] = 31;
//	month_day[0][11] = 30;
//	month_day[1][11] = 30;
//	month_day[0][12] = 31;
//	month_day[1][12] = 31;
//	transfer["Jan"] = 1;
//	transfer["Feb"] = 2;
//	transfer["Mar"] = 3;
//	transfer["Apr"] = 4;
//	transfer["May"] = 5;
//	transfer["Jun"] = 6;
//	transfer["Jul"] = 7;
//	transfer["Aug"] = 8;
//	transfer["Sep"] = 9;
//	transfer["Oct"] = 10;
//	transfer["Nov"] = 11;
//	transfer["Dec"] = 12;
//	transfer["Sun"] = 0;
//	transfer["Mon"] = 1;
//	transfer["Tue"] = 2;
//	transfer["Wed"] = 3;
//	transfer["Thu"] = 4;
//	transfer["Fri"] = 5;
//	transfer["Sat"] = 6;
//	transfer["0"] = 0;
//	transfer["1"] = 1;
//	transfer["2"] = 2;
//	transfer["3"] = 3;
//	transfer["4"] = 4;
//	transfer["5"] = 5;
//	transfer["6"] = 6;
//	transfer["7"] = 7;
//	transfer["8"] = 8;
//	transfer["9"] = 9;
//	transfer["10"] = 10;
//	transfer["11"] = 11;
//	transfer["12"] = 12;
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
//	
//	
//	
//	int N;
//	string begin_time,end_time;
//	cin >> N >> begin_time >> end_time;
//	int now_year,now_month,now_day,now_hour,now_minute;
//	int end_year,end_month,end_day,end_hour,end_minute;
//	
//	string str;
//	str = begin_time.substr(0,4);
//	now_year = atoi(str.c_str());
//	str = begin_time.substr(4,2);
//	now_month = atoi(str.c_str());
//	str = begin_time.substr(6,2);
//	now_day = atoi(str.c_str());
//	str = begin_time.substr(8,2);
//	now_hour = atoi(str.c_str());
//	str = begin_time.substr(10,2);
//	now_minute = atoi(str.c_str());
//	
//	str = end_time.substr(0,4);
//	end_year = atoi(str.c_str());
//	str = end_time.substr(4,2);
//	end_month = atoi(str.c_str());
//	str = end_time.substr(6,2);
//	end_day = atoi(str.c_str());
//	str = end_time.substr(8,2);
//	end_hour = atoi(str.c_str());
//	str = end_time.substr(10,2);
//	end_minute = atoi(str.c_str());
//	
//	string small;
//	int first,end;
//	string::size_type pos_dou1;
//	string::size_type pos_dou2;
//	string::size_type pos_;
//	int pos1,pos2;
//	int smallsize;
//	//处理输入的命令
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < 60; j++) commands[i].minute[j] = 0;
//		for(int j = 0; j < 24; j++) commands[i].hours[j] = 0;
//		for(int j = 1; j < 32; j++) commands[i].day_of_month[j] = 0;
//		for(int j = 1; j < 13; j++) commands[i].month[j] = 0;
//		for(int j = 0; j < 7; j++) commands[i].day_of_week[j] = 0;
//		
//		
//		//minutes
//		cin >> str;
//		if(str[0] == '*'){
//			for(int j = 0; j < 60; j++) commands[i].minute[j] = 1;
//		}
//		else{
//			pos1 = 0;
//			pos2 = pos1;
//			for(int j = 0; j < str.size(); j++){
//				//有逗号即分离逗号 
//				if(str[j] == ','){
//					pos2 = j;
//					small = str.substr(pos1+1, pos2-pos1-1);
//					smallsize = small.size();
//					pos1 = pos2;
//					pos_ = small.find("-");
//					if(pos_ != string::npos){
////						first = atoi(small.substr(0,pos_).c_str());
////						end = atoi(small.substr(pos_+1,smallsize-pos_-1).c_str());
//						first = transfer[small.substr(0,pos_)];
//						end = transfer[small.substr(pos_+1,smallsize-pos_-1)];
//						for(int j = first; j <= end; j++) 
//							commands[i].minute[j] = 1;
//					}
//					else{
//						first = transfer[small];
//						commands[i].minute[first] = 1;
//					}
//				}
//			}
//			//如果没有逗号 
//			if(pos1 == 0){
//				first = transfer[str];
//				commands[i].minute[first] = 1;
//			}
//		}
//
//		//hours
//		cin>>str;
//		if(str[0] == '*'){
//			for(int j = 0; j < 24; j++) commands[i].hours[j] = 1;
//		}
//		else{
//			str = ","+str+",";
//			pos_dou1 = str.find(",");
//			pos_dou2 = str.find(",",pos_dou1+1);
//			//不断地将逗号之间的数字分离开来 
//			while(pos_dou2 != string::npos){
//				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
//				pos_ = small.find("-");
//				if(pos_ != string::npos){
//					first = atoi(small.substr(0,pos_).c_str());
//					end = atoi(small.substr(pos_+1,small.size()-pos_-1).c_str());
//					for(int j = first; j <= end; j++) 
//						commands[i].hours[j] = 1;
//				}
//				else{
//					first = atoi(small.c_str());
//					commands[i].hours[first] = 1;
//				}
//				pos_dou1 = pos_dou2;
//				pos_dou2 = str.find(",",pos_dou1+1);
//			}
//		}
//
//		
//		//day of month
//		cin>>str;
//		if(str[0] == '*'){
//			for(int j = 1; j < 32; j++) 
//				commands[i].day_of_month[j] = 1;
//		}
//		else{
//			str = ","+str+",";
//			pos_dou1 = str.find(",");
//			pos_dou2 = str.find(",",pos_dou1+1);
//			//不断地将逗号之间的数字分离开来 
//			while(pos_dou2 != string::npos){
//				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
//				pos_ = small.find("-");
//				if(pos_ != string::npos){
//					first = atoi(small.substr(0,pos_).c_str());
//					end = atoi(small.substr(pos_+1,small.size()-pos_-1).c_str());
//					for(int j = first; j <= end; j++) 
//						commands[i].day_of_month[j] = 1;
//				}
//				else{
//					first = atoi(small.c_str());
//					commands[i].day_of_month[first] = 1;
//				}
//				pos_dou1 = pos_dou2;
//				pos_dou2 = str.find(",",pos_dou1+1);
//			}
//		}
//		
//		//month
//		cin>>str;
//		if(str[0] == '*'){
//			for(int j = 1; j < 13; j++) commands[i].month[j] = 1;
//		}
//		else{
//			str = ","+str+",";
//			pos_dou1 = str.find(",");
//			pos_dou2 = str.find(",",pos_dou1+1);
//			//不断地将逗号之间的数字分离开来 
//			while(pos_dou2 != string::npos){
//				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
//				pos_ = small.find("-");
//				if(pos_ != string::npos){
//					first = transfer[small.substr(0,pos_)];
//					end = transfer[small.substr(pos_+1,small.size()-pos_-1)];
//					for(int j = first; j <= end; j++) 
//						commands[i].month[j] = 1;
//				}
//				else{
//					first = transfer[small];
//					commands[i].month[first] = 1;
//				}
//				pos_dou1 = pos_dou2;
//				pos_dou2 = str.find(",",pos_dou1+1);
//			}
//		}
//		
//		//day of week
//		cin>>str;
//		if(str[0] == '*'){
//			for(int j = 0; j < 7; j++) commands[i].day_of_week[j] = 1;
//		}
//		else{
//			str = ","+str+",";
//			pos_dou1 = str.find(",");
//			pos_dou2 = str.find(",",pos_dou1+1);
//			//不断地将逗号之间的数字分离开来 
//			while(pos_dou2 != string::npos){
//				small = str.substr(pos_dou1+1, pos_dou2-pos_dou1-1);
//				pos_ = small.find("-");
//				if(pos_ != string::npos){
//					first = transfer[small.substr(0,pos_)];
//					end = transfer[small.substr(pos_+1,small.size()-pos_-1)];
//					for(int j = first; j <= end; j++) 
//						commands[i].day_of_week[j] = 1;
//				}
//				else{
//					first = transfer[small];
//					commands[i].day_of_week[first] = 1;
//				}
//				pos_dou1 = pos_dou2;
//				pos_dou2 = str.find(",",pos_dou1+1);
//			}
//		}
//		
//		//command
//		cin >> commands[i].command;
////		commands[i].command = str;
//	}
//	
//	
//		int find_minute = 0;
//		int find_hours = 0;
//		int find_day_of_month = 0;
//		int find_month = 0;
//		int find_day_of_week = 0;
//		int Week;
//	//开始进行匹配
//	while(now_year != end_year || end_month != now_month || end_day != now_day || end_hour != now_hour || end_minute != now_minute){
//		find_minute = 0;
//		find_hours = 0;
//		find_day_of_month = 0;
//		find_month = 0;
//		find_day_of_week = 0;
//		Week = CaculateWeekDay(now_year,now_month,now_day);
//		
//		for(int i = 0; i < N; i++){
//			if(commands[i].minute[now_minute] == 1){
//				find_minute = 1;
//			}
//			else continue;
//			if(commands[i].hours[now_hour] == 1){
//				find_hours = 1;
//			}
//			else continue;
//			if(commands[i].day_of_month[now_day] == 1){
//				find_day_of_month = 1;
//			}
//			else continue;
//			if(commands[i].month[now_month] == 1){
//				find_month = 1;
//			}
//			else continue;
//			if(commands[i].day_of_week[Week] == 1){
//				find_day_of_week = 1;
//			}
//			else continue;
////			if(find_minute && find_hours && find_day_of_month && find_month && find_day_of_week){
////				cout << now_year;
////				if(now_month < 10) cout << "0";
////				cout << now_month;
////				if(now_day < 10) cout << "0";
////				cout << now_day;
////				if(now_hour < 10) cout << "0";
////				cout << now_hour;
////				if(now_minute < 10) cout << "0";
////				cout << now_minute;
//				printf("%04d%02d%02d%02d%02d ",now_year,now_month,now_day,now_hour,now_minute);
//				cout << commands[i].command << endl;
////			}
//		}
//		next_time(now_year,now_month,now_day,now_hour,now_minute);
//	}
//	
//}



// 遍历开始年初到结束年底的每一天，检查是否符合n条规则，
// 检查日月时用数组查找法
// 星期几单独检查，需要编写判断星期几的函数, 1970/01/01是thu
// 时分通过匹配到的规则中的时分数组生成
// 如果符合就放到结果结构体数组
// 最后连同起始时间、结束时间一起将结果数组排序，顺序输出排序结果
 

 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
 
const char MONTH_NAME[13][4] = {"", "jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
const char WEEKDAY_NAME[7][4] = {"sun","mon","tue","wed","thu","fri","sat"};
const int MONTH_DAY[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
int n = 0, cnt = 0;
bool is_star[25][3] = {};		// 各条规则中“日”“月”“星期几”是否是"*"
std::set<int> rule[25][5];		// 各条规则规定的时间条件数组,0-minutes, 1-hours, 2-day, 3-month, 4-week
char com[25][101];				// 各条规定的命令字符串
 
inline bool is_runnian(int year)							// 判断是否是闰年
{
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
struct Event {
	int year, month, date, hour, minute;
	int ind;							// 匹配到的crontab命令的编号（用于输出排序）
	char command[101];
 
	Event(void): year(0), month(0), date(0), hour(0), minute(0), ind(-2)
	{
		strcpy(command, "");
	}
	Event(int yy, int mm, int dd, int hh, int min, int ii, char cc[101]):
		year(yy), month(mm), date(dd), hour(hh), minute(min), ind(ii)
	{
		strcpy(command, cc);
	}
	Event(const Event & e):
		year(e.year), month(e.month), date(e.date), hour(e.hour), minute(e.minute), ind(e.ind)
	{
		strcpy(command, e.command);
	}
 
	bool operator== (const Event & e) const
	{
		if (year == e.year && month == e.month && date == e.date && hour == e.hour && minute == e.minute && ind == e.ind
			&& strcmp(command, e.command) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
 
	bool operator!= (const Event & e) const
	{
		if (year == e.year && month == e.month && date == e.date && hour == e.hour && minute == e.minute && ind == e.ind
			&& strcmp(command, e.command) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
 
	bool operator< (const Event &e) const
	{
		if (year < e.year)
		{
			return true;
		}
		else if (year == e.year)
		{
			if (month < e.month)
			{
				return true;
			}
			else if (month == e.month)
			{
				if (date < e.date)
				{
					return true;
				}
				else if (date == e.date)
				{
					if (hour < e.hour)
					{
						return true;
					}
					else if (hour == e.hour)
					{
						if (minute < e.minute)
						{
							return true;
						}
						else if (minute == e.minute)
						{
							if (ind < e.ind)
							{
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}
 
	void print()					// 按题目要求的格式打印结果
	{
		printf("%04d%02d%02d%02d%02d %s\n", year, month, date, hour, minute, command);
	}
 
	void addOneDay()				// 增加一天，用于遍历日期
	{
		int date_end;
		if (is_runnian(year) && month == 2)
		{
			date_end = 29;
		}
		else
		{
			date_end = MONTH_DAY[month];
		}
		if (date == date_end)
		{
			if (month == 12)
			{
				year++;
				month = 1;
				date = 1;
			}
			else
			{
				month ++;
				date = 1;
			}
		}
		else
		{
			date ++;
		}
	}
 
	int day_compare(const Event & e) const	// 仅比较日期，用于日期遍历
	{
		if (year < e.year)
		{
			return -1;
		}
		else if (year > e.year)
		{
			return 1;
		}
		else
		{
			if (month < e.month)
			{
				return -1;
			}
			else if (month > e.month)
			{
				return 1;
			}
			else
			{
				if (date < e.date)
				{
					return -1;
				}
				else if (date > e.date)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
 
} ansList[10005];								// 结果数组
 
 
int which_day (int year, int month, int day)		// 输入日期计算星期几, 1970/01/01是星期一
{
	int days = 0, i;
	for (i=1970; i<year; i++)
	{
		if (is_runnian(i))
		{
			days += 366;
		}
		else
		{
			days += 365;
		}
	}
	for (i=1; i<month; i++)
	{
		if (is_runnian(year) && i == 2)
		{
			days += 29;
		}
		else
		{
			days += MONTH_DAY[i];
		}
	}
	days += day;
	return (days+3)%7;
}
 
 
void solve (char str[101], int type, int ind)				// 解析规则中含有的"*" "," "-" 和英文缩写
	// type: 0-minutes, 1-hours, 2-day, 3-month, 4-week
{
	std::set<int> ans;
	int i = 0, j = 0, k = 0, len = strlen(str), num = 0, prenum = 0;
	char numstr[4];
	bool flag = false;										// '-'号标记
	int is_char = -1;										// 字符串首字母的位置，如果不是字符串则 = -1
	if (strcmp(str, "*") == 0)
	{
		if (type == 0)
		{
			for (j=0; j<60; j++)
			{
				ans.insert(j);
			}
		}
		else if (type == 1)
		{
			for (j=0; j<24; j++)
			{
				ans.insert(j);
			}
		}
		else
		{
			is_star[ind][type-2] = true;
		}
	}
	else
	{
		num = 0;
		for (i=0; i<len; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				num = num *10 + (str[i] - '0');
			}
			else if (str[i] == ',')
			{
				if (is_char != -1)
				{
					strncpy(numstr, str+is_char, 4);
					numstr[3] = '\0';
					if (type == 3)
					{
						for (k=1; k<=12; k++)
						{
							if (strcmp(numstr, MONTH_NAME[k]) == 0)
							{
								num = k;
							}
						}
					}
					else if (type == 4)
					{
						for (k=0; k<7; k++)
						{
							if (strcmp(numstr, WEEKDAY_NAME[k]) == 0)
							{
								num = k;
							}
						}
					}
				}
				is_char = -1;
				if (flag)
				{
					flag = false;
					for (j=prenum; j<=num; j++)
					{
						ans.insert(j);
					}
				}
				else
				{
					ans.insert(num);
				}
				num = 0;
			}
			else if (str[i] == '-')
			{
				if (is_char != -1)
				{
					strncpy(numstr, str+is_char, 3);
					if (type == 3)
					{
						for (k=1; k<=12; k++)
						{
							if (strcmp(numstr, MONTH_NAME[k]) == 0)
							{
								num = k;
							}
						}
					}
					else if (type == 4)
					{
						for (k=0; k<7; k++)
						{
							if (strcmp(numstr, WEEKDAY_NAME[k]) == 0)
							{
								num = k;
							}
						}
					}
				}
				is_char = -1;
				prenum = num;
				flag = true;
				num = 0;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				if (is_char == -1)
				{
					is_char = i;
				}
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				if (is_char == -1)
				{
					is_char = i;
				}
				str[i] -= 'A';
				str[i] += 'a';
			}
 
		}
		// 对结尾的处理等同于逗号
		if (is_char != -1)
		{
			strncpy(numstr, str+is_char, 3);
			if (type == 3)
			{
				for (k=1; k<=12; k++)
				{
					if (strcmp(numstr, MONTH_NAME[k]) == 0)
					{
						num = k;
					}
				}
			}
			else if (type == 4)
			{
				for (k=0; k<7; k++)
				{
					if (strcmp(numstr, WEEKDAY_NAME[k]) == 0)
					{
						num = k;
					}
				}
			}
		}
		is_char = -1;
		if (flag)
		{
			flag = false;
			for (j=prenum; j<=num; j++)
			{
				ans.insert(j);
			}
		}
		else
		{
			ans.insert(num);
		}
		num = 0;
	}
	rule[ind][type] = ans;
}
 
void generate_ans_through_days(int year, int month, int day)	// 给定特定的一天，判断是否符合n条规则，生成结果
{
	int ind = 0;						// 规则号
	bool match = true;					// 这一天是否满足这条规则
	std::set<int>::iterator it1, it2;
	for (ind=0; ind<n; ind++)
	{
		match  = true;
		if (!is_star[ind][0])
		{
			if (rule[ind][2].find(day) == rule[ind][2].end())
			{
				match = false;
				goto start_to_put;
			}
		}
		if (!is_star[ind][1])
		{
			if (rule[ind][3].find(month) ==  rule[ind][3].end())
			{
				match = false;
				goto start_to_put;
			}
		}
		if (!is_star[ind][2])
		{
			if (rule[ind][4].find(which_day(year,month,day)) == rule[ind][4].end())
			{
				match = false;
				goto start_to_put;
			}
		}
start_to_put: if (match)
		{
			for (it1 = rule[ind][0].begin(); it1 != rule[ind][0].end(); it1++)
			{
				for (it2 = rule[ind][1].begin(); it2 != rule[ind][1].end(); it2++)
				{
					Event ev(year, month, day, *it2, *it1, ind, com[ind]);
					ansList[cnt++] = ev;
				}
			}
		}
	}
}
 
 
void through_days(Event start_time, Event end_time)			// 遍历从起始日到终止日的所有日子
{
	Event itev(start_time);
	for (; itev.day_compare(end_time)!=1; itev.addOneDay())
	{
		generate_ans_through_days(itev.year, itev.month, itev.date);
	}
}
 
int main()
{
	int i, j, i_start = 0, i_end = 0;
	char str[101], s_year[4], s_month[2], s_date[2], s_hour[2], s_minute[2];
	scanf("%d", &n);
	scanf("%s", str);
	strncpy(s_year, str, 4);
	strncpy(s_month, str+4, 2);
	strncpy(s_date, str+6, 2);
	strncpy(s_hour, str+8, 2);
	strncpy(s_minute, str+10, 2);
	Event start_time(atoi(s_year), atoi(s_month), atoi(s_date), atoi(s_hour), atoi(s_minute), -1, "System_Start");
	scanf("%s", str);
	strncpy(s_year, str, 4);
	strncpy(s_month, str+4, 2);
	strncpy(s_date, str+6, 2);
	strncpy(s_hour, str+8, 2);
	strncpy(s_minute, str+10, 2);
	Event end_time(atoi(s_year), atoi(s_month), atoi(s_date), atoi(s_hour), atoi(s_minute), -1, "System_End");
	for (i=0; i<n; i++)
	{
		for (j=0; j<5; j++)
		{
			scanf("%s", str);
			solve(str, j, i);
		}
		scanf("%s", com[i]);
	}
	through_days(start_time, end_time);
	ansList[cnt++] = start_time;
	ansList[cnt++] = end_time;
	std::sort(ansList, ansList+cnt);
	// 求start_time和end_time在ansList中的位置
	for (i=0; i<cnt; i++)
	{
		if (ansList[i] == start_time)
		{
			i_start = i;
			break;
		}
	}
	for (i=cnt-1; i>=0; i--)
	{
		if (ansList[i] == end_time)
		{
			i_end = i;
			break;
		}
	}
	// 只输出start_time和end_time中间的结果
	for (i=i_start+1; i<i_end; i++)
	{
		if (start_time < ansList[i] && ansList[i] < end_time)
		{
			ansList[i].print();
		}
	}
	return 0;
}

