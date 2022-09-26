#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define tam 100

//Parte 1
typedef struct 
{
	int locChave;
	char nomeVeiculo[20];
}locacao;
//Parte 2
typedef struct 
{
	locacao itens[tam+1];
	int tamanho;
}Tabela;

void preencher(Tabela *tabela);
int salvarDados(Tabela *tabela, char nomeArq[]);
void restaurarDados(Tabela  *tabela2,char nomeArq[]);

int main(){
	int i,esc;
	char nomeArq[10];
	srand((unsigned)time(NULL));
	Tabela tabela;
	Tabela tabela2;
	preencher(&tabela);
	printf("-----SISTEMA DE BACKUP DE DADOS-----\n");
	printf("Digite a opera��o que deseja realizar:\n1-Salvar dados\n2-Restaurara dados\n");
	scanf("%d",&esc);
	switch(esc)
	{
	case 1:
		printf("Informe o nome do arquivo:\n");
		fflush(stdin);//limpa o buffer
		gets(nomeArq);//nome que quer salvar o arquivo
		salvarDados(&tabela,nomeArq);
		printf("Opera��o realizada com sucesso!\n");
		break;
	case 2:
		printf("Digite o nome do arquivo a ser restaurado:\n");
		fflush(stdin);//limpa o buffer
		gets(nomeArq);//nome do arquivo que quero restaurar
		restaurarDados(&tabela2,nomeArq);
		printf("Opera��o realizada com sucesso!\n");
		break;
	default:
		break;
	}
	return 0;		
}
//Quest�o01-(b)--> tabela backup preenchida com os dados da 
void restaurarDados(Tabela  *tabela2,char nomeArq[]){
	FILE *arq;
	int i,x;
	Tabela tabAux;
	arq=fopen(strcat(nomeArq,".txt"),"r");
	if(arq == NULL){//A fun��o fopen retorna NULL se der problema na cria��o/abertura do arquivo
		printf("Problemas na abertura do arquivo!!");
	}else{		
		printf("!!!\n");
	}
	i=0;
	do{
		fscanf(arq,"%s %d",tabela2->itens[i].nomeVeiculo,&tabela2->itens[i].locChave);//fscanf para ler o arquivo
		i++;	
	}while(!feof(arq));//condi��o para ler at� a �ltima linha do arquivo
	printf("Dados Restaurados\n");//imprimindo os dados da tabela de backup
	for(x=0;x<tam;x++){
	printf("%s %d\n",tabela2->itens[x].nomeVeiculo,tabela2->itens[x].locChave);
	}
	fclose(arq);
}


//Quest�o01-(a)II ---->salvando dados no arquivo
int salvarDados(Tabela *tabela,char nomeArq[]){
	int i;
	preencher(tabela);
	FILE *arq;
	arq=fopen(strcat(nomeArq,".txt"),"w");
	if(arq == NULL){
		return 0;
	}
	
	printf("%s",nomeArq);
	for(i=0;i<tam;i++){
		fprintf(arq,"%s %d\n",tabela->itens[i].nomeVeiculo,tabela->itens[i].locChave);
	}
	
	for(i=0;i<tam;i++){//Mostrar os dados da tabela 01
		printf("Nome: %s\n",tabela->itens[i].nomeVeiculo);	
		printf("Registro: %d\n",tabela->itens[i].locChave);
	}
	fclose(arq);
    return 0;	
}

//Quest�o01-(a)I
void preencher(Tabela *tabela){
	int i;
	for(i=0;i<tam;i++){
		tabela->itens[i].locChave= rand() % 1000;
		strcpy(tabela->itens[i].nomeVeiculo,"gol");
	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    