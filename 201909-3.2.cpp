#include <iostream>
#include <vector>
using namespace std;
struct snode{
    int level;  // 层级
    string tag; // 元素
    string id;  // ID
    snode* pre; // 父元素
    snode():level(-1), pre(NULL){}
};
// 将字符串转换为小写
void strToLower(string & s){
    for(int i=0; i<s.size();i++)
        if(isalpha(s[i]))
            s[i] = tolower(s[i]);
}
// 按空格拆分字符串，并将tag转换为小写
void strSplit(string str, vector<string>& ret){
    ret.clear();
    int s = 0, e=0;
    do{
        e = str.find(' ', s);
        string tmp = str.substr(s, e-s);
        if(tmp[0] != '#') strToLower(tmp);
        ret.push_back(tmp);
 
        s = e+1;
    }while(e != str.npos);
}
int main(){
    int n=0, m=0, i=0, j=0, k=0;
    cin>>n>>m;
    getchar();
 
    vector<snode*> vec;//存储结构化文档层级关系
    vector<snode*>::iterator it;
    string str;
    while(n > 0) {
        getline(cin, str);
 
        snode *node = new snode;
        j = str.find_first_not_of('.');
        k = str.find(' ', j);
        node->level = j / 2;
        node->tag = str.substr(j, k - j);
        if (k != str.npos)node->id = str.substr(k + 1);
        strToLower(node->tag);
 
        // 找到父元素
        for (vector<snode *>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++){
            if ((*rit)->level == (node->level - 1)) {
                node->pre = *rit;
                break;
            }
        }
        vec.push_back(node);
 
        n--;
    }
 
    vector<int> ret;// 遍历结果
    vector<string> splitRet;//字符串拆分结果
    vector<string>::reverse_iterator rit;
    while(m>0){
        getline(cin, str);
        strSplit(str, splitRet);
 
        ret.clear();
        if(splitRet.size() == 1){//为标签或者ID时，直接遍历得到结果
            for(it = vec.begin(); it != vec.end(); it++){
                if((*it)->tag == splitRet[0] || (*it)->id == splitRet[0])
                    ret.push_back(it - vec.begin()+1);
            }
        }else{//逐层向上搜索
            for(it = vec.begin(); it != vec.end(); it++){
                snode* cur = *it;
                rit = splitRet.rbegin();
                if(*rit != cur->tag && *rit != cur->id )continue;
                while(rit != splitRet.rend() && cur != NULL){
                    if(*rit == cur->tag || *rit == cur->id) {
                        rit++;
                    }
                    cur = cur->pre;
                }
 
                if(rit == splitRet.rend())  ret.push_back(it-vec.begin()+1);
            }
        }
 
 
        cout<<ret.size()<<" ";
        for(vector<int>::iterator it2 = ret.begin(); it2 != ret.end(); it2++)
            cout<<*it2<<" ";
        cout<<endl;
        m--;
    }
 
    for(it = vec.begin(); it != vec.end(); it++){
        delete *it;
    }
    return 0;
}

