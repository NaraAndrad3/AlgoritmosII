#include <stdio.h>
int main(){
	int num[10],i,j;
	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
	}
	printf("Elemento\tValor\t\tHistograma\n");
	for(i=0;i<num[i];i++){
		printf("%d\t\t%d\t\t", i, num[i]);
		for(j=0;j<num[i];j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}