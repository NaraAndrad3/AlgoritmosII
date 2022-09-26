#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int jogada();

int main(){
	int i,face,cara=0;
	srand(time(NULL));
	setlocale(LC_ALL,"");
	for(i=1;i<=100;i++){
		face = jogada();
		if(face == 1){
			   cara++;	
		}
	}
	printf("O número de caras foi: %d",cara);		  		
}
int jogada(){
	
	
	return rand()%2;
}