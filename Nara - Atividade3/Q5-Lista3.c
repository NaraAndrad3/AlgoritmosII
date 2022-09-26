#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int adivinha();
void retorno(int,int);
int main(){
	setlocale(LC_ALL,"");
	srand(time(NULL));
	int numero,num;
	numero= adivinha();
	printf("Eu tenho um número entre 1 e 1000.\nVocê pode adivinhar meu número?\n");
	printf("Digite seu primeiro palpite:\n");
	do{
		//printf("D:\n");
		scanf("%d",&num);
		retorno(num,numero);
	}while(num!=numero);
	
	
}
int adivinha(){
	return rand()%1000;
}
void retorno(int num, int numero){
	if(num>numero){
		printf("Muito alto.Tente novamente.\n");
	}else if(num<numero){
		printf("Muito baixo. Tente novemante.\n");
	}else{
		printf("Excelente! Você adivinhou o número!");
	}
}