#include <stdio.h>
#define tam 10
int main(){
	int i,id[tam];
	char word[20],word2[20],op;
	printf("Informe uma palavra: ");
	scanf("%s",&word);
	for(i=0;i<20;i++){
		if(word[i] == 'r'){
			word[i]= 'l';
			//word2[i]=word[i];
		}
		
	}
	printf("O cebolinha falaria : %s\n",word);
	printf("Houve alteracao nos itens: ");
	for(i=1;i<=20;i++){
		if( word[i] == 'l'){
			printf("%d,",i);
		}
	}
	
}