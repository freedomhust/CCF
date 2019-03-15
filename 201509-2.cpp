#include<cstdio>

struct year{
	int month[13];
}year;

int main(void){
	int Y,D;
	scanf("%d%d",&Y,&D);
	//≈–∂œ «∑Ò «»ÚƒÍ
	if(Y%400 == 0 || (Y%4 == 0 && Y%100 != 0)){
		year.month[2] = 29;
	} 
	else year.month[2] = 28;
	
	year.month[1] = 31;
	year.month[3] = 31;
	year.month[4] = 30;
	year.month[5] = 31;
	year.month[6] = 30;
	year.month[7] = 31;
	year.month[8] = 31;
	year.month[9] = 30;
	year.month[10] = 31;
	year.month[11] = 30;
	year.month[12] = 31;
	
	int i;
	for(i = 1; i <= 12; i++){
		if(D - year.month[i] <= 0) break;
		D = D-year.month[i];
	}
	
	printf("%d\n%d\n",i,D);
}
