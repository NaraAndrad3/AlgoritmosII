#include <stdio.h>
#include <string.h>
int main(){
	int i,j;
	char nome[5][20];
	float medida[5][3],maiorAlt,maiorPeso;
	
	for(i=0;i<5;i++){
		printf("digite o nome:\n");
		scanf("%s",&nome[i]);
		printf("Digite respectivamente a altura, o peso e o ira:\n");
		for(j=0;j<3;j++){
			scanf("%f",&medida[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<5;i++){//maior altura
		for(j=i+1;j<3;j++){
			if(medida[0][i] > medida[0][j] ){
				maiorAlt = medida[i][j];
			}
		}
		printf("\n");
	}
	printf("A maior altura é: %f\n",maiorAlt);
	
	printf("Altura\t\tPeso\t\tIra\n");
	for(i=0;i<5;i++){
		//printf("Nome :%s\n",nome[i]);
		for(j=0;j<3;j++){
			//printf("");
			printf("%.2f\t\t",medida[i][j]);
		}
		printf("\n");
	}
	
	
	   return 0;	
}
