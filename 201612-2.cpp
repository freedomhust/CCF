#include<cstdio>

int main(void){ 
	int y = 0;
	scanf("%d",&y);

	float A;
	if(y <= 3500){
		printf("%d",y);
	}
	else if(3500 < y && y <= 4955){
		A = (y-3500)/0.97;
		printf("%d",(int)A+3500);
	}
	else if(4955 < y && y <= 7655){
		A = (y-3605)/0.9;
		printf("%d",(int)A+3500);
	}
	else if(7655 < y && y <= 11255){
		A = (y-4055)/0.8;
		printf("%d",(int)A+3500);
	}
	else if(11255 < y && y <= 30755){
		A = (y-4505)/0.75;
		printf("%d",(int)A+3500);
	}
	else if(30755 < y && y <= 44755){
		A = (y-6255)/0.7;
		printf("%d",(int)A+3500);
	}
	else if(44755 < y && y <= 61005){
		A = (y-9005)/0.65;
		printf("%d",(int)A+3500);
	}
	else{
		A = (y-17005)/0.55;
		printf("%d",(int)A+3500);
	}
}



