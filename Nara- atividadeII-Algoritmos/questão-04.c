#include <stdio.h>
#define quant 10
int main()
{
	int num[quant], num2[quant],a;
	int i, j;

	for(i=0;i<quant;i++){
		printf("Digite: \n");
		scanf("%d",&num[i]);
		if(num[i] >=10 && num[i<=100]){
			for(j=0;j<i;j++){
				if(num[i] == num2[j]){
					a +=1;
				}
			}
			if(!a){
				printf(" ----> %d",num[i]);
			}
			num2[i]=num[i];
			a=0;
		}
	}
	


	return 0;
}
