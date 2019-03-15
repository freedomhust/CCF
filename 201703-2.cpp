#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

struct position{
	int student_num;
	int position;
}P[1001];

int student[1001];

bool cmp(position a, position b){
	return a.position < b.position;
}

int main(void){
	int n,m;
	scanf("%d",&n);
	P[0].position = 0;
	P[0].student_num = 0;
	for(int i = 1; i <= n; i++){
		P[i].position = i;
		P[i].student_num = i;
	}
	for(int i = 1; i <= n; i++){
		student[i] = i;
	}
	scanf("%d",&m);
	int p,q;
	for(int i = 0; i < m; i++){
		scanf("%d%d",&p,&q);
		//����ƶ� 
		if(q > 0){
			//�ȰѺ������ǰ�� 
			for(int j = student[p]+1; j <= student[p]+q; j++){
				P[j].position--;
				student[P[j].student_num] = P[j].position;
			}
			//Ȼ��Ҫ��λ��ѧ���͵�ָ��λ��
			P[student[p]].position =  P[student[p]].position+q;
			student[p] = P[student[p]].position;
			//����position��������
			sort(P+1,P+1+n,cmp); 
		}
		//��ǰ�� 
		else if(q < 0){
			//��ǰ���ѧ������ƶ� 
			for(int j = student[p]+q; j <= student[p]-1; j++){
				P[j].position++;
				student[P[j].student_num] = P[j].position;
			} 
			//�ٰ�ѧ���Ž�ǰ���λ��
			P[student[p]].position =  P[student[p]].position+q;
			student[p] = P[student[p]].position;
			//����position��������
			sort(P+1,P+1+n,cmp);
		}
	}
	for(int i = 1; i <= n; i++){
		printf("%d ",P[i].student_num);
	}
}
