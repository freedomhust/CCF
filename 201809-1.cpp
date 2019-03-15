#include<stdio.h>

int main(void){
	int m;
	while(~scanf("%d",&m)){
		int before[m];
		int after[m];
		for(int i = 0; i < m; i++) scanf("%d",&before[i]);
		getchar();
		for(int i = 0; i < m; i++){
			if(i == 0) after[i] = (before[i]+before[i+1])/2;
			else if(i == m-1){
				after[i] = (before[i-1]+before[i])/2;
			}
			else after[i] = (before[i-1]+before[i]+before[i+1])/3;
		}
		for(int i = 0; i < m; i++){
			if(i == m-1) printf("%d\n",after[i]);
			else printf("%d ",after[i]);
		}
	}
}
