#include<cstdio>

int main(void){
	int res = 0;
	int N;
	int score = 1;
	int position;
	scanf("%d",&position);
	while(position != 0){
		if(position == 2 && score == 1){
			score = 2;
			res = res + score;
		}
		else if(position == 2 && score != 1){
			score = score + 2;
			res = res+score;
		}
		else{
			score = 1;
			res = res+score;
		}
		scanf("%d",&position);
	}
	printf("%d",res);
}
