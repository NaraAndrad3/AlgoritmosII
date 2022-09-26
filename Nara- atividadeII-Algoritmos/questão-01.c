#include <stdio.h>
#include <locale.h>
#define n 10

int main()
{
	setlocale(LC_ALL, "");
	int vet[10], nota[10],teste[40], i,j,c=0, cont=0, res[n];

	for(i = 0; i < 10; i++)
	{
		scanf("%d", &vet[i]);
		if(vet[i] < 0)
		{
			break;
		}
	}
	for(i=0;i<10;i++){
		teste[i]=vet[i];
	}
	for(i=0;i<10;i++){
		cont++;
		for(j=c;j<10;j++){
			if(teste[i]==vet[j]){
				cont++;
				teste[j]=-1;
			}
		}
		res[i]=cont;
	}

	for(j = 0; j < 10; j++)
	{
		printf("\n%d\n        %d\n",j, res[j]);
	}

}
