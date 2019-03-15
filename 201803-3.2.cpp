#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int n, m;
vector<string> rules[100];   // n(n <= 100)������
vector<string> values;       //�����Ӧ������
int isAdd[100];              //���� i �Ƿ��� / ��β��������Ϊ 1��
                             //��ʾ��������� /���Ա����ַ�������

vector<string> str2vec(string str) //�ѹ���Ͳ��Ե��ַ����� / Ϊ�ָ����ָ������
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

bool isnum(string str)     //�ж�һ���ַ����ǲ������ִ����ο��������������͵�����
{       
    if(str[0] == '-')      //��Ϊ��ĿԼ��Ϊ�޷�������������"-22"�����Ĵ�ҲӦ�ò���������              
        return false;      //����������Ӧ��û��ô��̬���˴������Է���һ

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

string str2int2str(string str)  //�� "0123" �����Ĵ�ת���� "123" �������ַ���
{
    stringstream sin(str) , sout;
    int i;
    sin >> i;
    sout << i;
    sout >> str;
    return str;
}

string url(string test)         //����һ�������ַ��������Ƿ�ƥ�䣬���ظ��ַ��������ս��
{
    vector<string> vs;
    string result = "";

    vs = str2vec(test);
    for(int c = 0; c < n; c++)   //��ÿ������ѭ��
    {   
        if((isAdd[c] == 1 && test[test.size() - 1] == '/') || 
           (isAdd[c] == 0 && test[test.size() - 1] != '/'))
            continue;
        int i(0);
        for(i = 0; i < vs.size() && i < rules[c].size(); )  //�Բ�������ÿ���ָ�ɵĵ�λ����ƥ��
        {
            if(rules[c][i] == "<path>")   //�����������·��
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
            else if(isnum(vs[i]))    //�����ǰ���Ե�λ vs[i] ��һ�������ַ���
            {
                if(vs[i] == rules[c][i] || rules[c][i] == "<int>")
                    ++i;
                else break;
            }

            else       //�����ǰ��λ vs[i] ��һ���������ַ���
            {
                if(vs[i] == rules[c][i] || rules[c][i] == "<str>")
                    ++i;
                else break;
            }
        }

        if(i == vs.size() && i == rules[c].size())  
        {       //���е�λ�տ�ƥ�䲢�Ҳ����ַ����͹���պ�ƥ��ųɹ�
                //�˴������� <path>�������������ͱ�������
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
