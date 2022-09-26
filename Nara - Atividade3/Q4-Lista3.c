#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dado();

int main(){
	srand(time(NULL));
	int dado1,dado2,soma=0;
	dado1=dado();
	dado2=dado();
	soma=dado1+dado2;
	
	if(soma==7 || soma==11){
		printf("A soma de %d + %d = %d\n",dado1,dado2,soma);
		printf("O jogador ganhou!!\n");
	}else
	{
		if(soma==2||soma==3||soma==12){
			printf("A soma de %d + %d = %d\n",dado1,dado2,soma);
			printf("A casa ganhou!!\n");
		}else if(soma==4||soma==5||soma==6||soma==8||soma==9||soma==10)
		{
			printf("A soma de %d + %d = %d\n",dado1,dado2,soma);
			printf("Ponto!!");
		}
	}
	return 0;
}
int dado(){
	  	  
return (1+rand()% 5);
}

