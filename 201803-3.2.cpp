#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int n, m;
vector<string> rules[100];   // n(n <= 100)条规则
vector<string> values;       //规则对应的名字
int isAdd[100];              //规则 i 是否以 / 结尾，不是则为 1，
                             //表示后来添加了 /，以便于字符串解析

vector<string> str2vec(string str) //把规则和测试的字符串以 / 为分隔符分割成向量
{
    vector<string> vs;
    int pos;
    if(str[str.size() - 1] != '/')
        str += "/";
    str.erase(0, 1);
    while((pos = str.find('/')) != string::npos)
    {
        string sub = str.substr(0, pos);
        vs.push_back(sub);
        str.erase(0, pos + 1);
    }
    return vs;
}

bool isnum(string str)     //判断一个字符串是不是数字串，参考了网上其他博客的做法
{       
    if(str[0] == '-')      //因为题目约定为无符号整数，所以"-22"这样的串也应该不算整数。              
        return false;      //但测试数据应该没这么变态，此处用来以防万一

    stringstream stream(str);
    int i;
    char c;

    if( !(stream >> i))
        return false;
    if(stream >> c)
        return false;
    else
        return true;
}

string str2int2str(string str)  //把 "0123" 这样的串转换成 "123" 这样的字符串
{
    stringstream sin(str) , sout;
    int i;
    sin >> i;
    sout << i;
    sout >> str;
    return str;
}

string url(string test)         //对于一条测试字符串，看是否匹配，返回该字符串的最终结果
{
    vector<string> vs;
    string result = "";

    vs = str2vec(test);
    for(int c = 0; c < n; c++)   //对每条规则循环
    {   
        if((isAdd[c] == 1 && test[test.size() - 1] == '/') || 
           (isAdd[c] == 0 && test[test.size() - 1] != '/'))
            continue;
        int i(0);
        for(i = 0; i < vs.size() && i < rules[c].size(); )  //对测试数据每个分割成的单位进行匹配
        {
            if(rules[c][i] == "<path>")   //如果规则中是路径
            {
                result = values[c];
                result += " ";
                for(int j = 0 ; j < i; j ++)
                {
                    if(rules[c][j] == "<int>")
                    {
                        string temp = str2int2str(vs[j]);
                        result += temp;
                        result += " ";
                    }
                    else if(rules[c][j] == "<str>")
                    {
                        result += vs[j];
                        result += " ";
                    } 
                }
                for(int j = i; j < vs.size(); j++)
                {
                    result += vs[j];
                    result += "/";
                }
                result.erase(result.size() - 1, 1);
                return result;
            }
            else if(isnum(vs[i]))    //如果当前测试单位 vs[i] 是一个数字字符串
            {
                if(vs[i] == rules[c][i] || rules[c][i] == "<int>")
                    ++i;
                else break;
            }

            else       //如果当前单位 vs[i] 是一个非数字字符串
            {
                if(vs[i] == rules[c][i] || rules[c][i] == "<str>")
                    ++i;
                else break;
            }
        }

        if(i == vs.size() && i == rules[c].size())  
        {       //所有单位刚开匹配并且测试字符串和规则刚好匹配才成功
                //此处不会有 <path>，如果有在上面就被拦下了
            result = values[c];
            for(int j = 0; j < vs.size(); j++) 
            {
                if(rules[c][j] == "<int>")
                {
                    string temp = str2int2str(vs[j]);
                    result += " ";
                    result += temp;
                }
                else if(rules[c][j] == "<str>")
                {
                    result += " ";
                    result += vs[j];
                }
            }
            return result;
        }   
    }
    return "404";
}


int main()
{
    memset(isAdd, 0, sizeof(isAdd));
    //freopen("url.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string str, value;
        cin >> str >> value;
        if(str[str.size() - 1] != '/') isAdd[i] = 1;
        rules[i] = str2vec(str);
        values.push_back(value);
    }

    for(int c = 0; c < m; c++)
    {
        string test;
        cin >> test;
        cout << url(test) << endl;
    }
    return 0;
}
