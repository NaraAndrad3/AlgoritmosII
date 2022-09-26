#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
cod: código da locação (inteiro)
carro: nome do veículo (vetor de 20 caracteres)
valor: valor da locação (ponto flutuante simples)
*/
void formatacaoBin();
void escritaBin();
void leituraBin();
void buscarBin();
typedef struct
{
	int cod;
	char nomeVeiculo[20];
	float valorLoc;

} locacao;
int main()
{
	int esc;
	do{
	printf("Qual operacaoo deseja realizar?\n1-Formatacao\n2-Escrita\n3-Leitura\n4-Busca\n0-Finalizar\n");
	scanf("%d", &esc);
	switch(esc)
	{
	case 1:
		formatacaoBin();
		break;
	case 2:
		escritaBin();
		break;
	case 3:
		leituraBin();
		break;
	case 4:
		buscarBin();
		break;
	default:
		printf("Sistema Finalizado\n");
		break;
	}
	}while(esc !=0);

	return 0;
}
void formatacaoBin()
{
	locacao loc = {0, "", 0.00}; //struct que criei lá em cima
	int i;
	FILE *arq;
	arq = fopen("dados.bin", "wb"); //wb abre arquivo em modo binário
	if(arq == NULL)//testa se o arquivo abriu corretamente
	{
		printf("\n\tArquivo nao pode ser aberto.\n");
	}
	else
	{
		printf("Arquivo aberto com sucesso!\n");
	}
	for (i = 0; i < 1001; i++)
	{
		fwrite(&loc, sizeof(loc), 1, arq);//escreve no arquivo binário
	}
	printf("Operacao finalizada com sucesso\n");
	fclose(arq);
}
void escritaBin()
{
	locacao loc;
	FILE *arq;
	arq = fopen("dados.bin", "rb+"); //rb+ abre arquivo binario para leitura e escrita
	if(arq == NULL)//testa se o arquivo abriu corretamente
	{
		printf("\n\tArquivo nao pode ser aberto.\n");
	}
	else
	{
		printf("Arquivo aberto com sucesso!\n");
		printf("Digite o codigo do veiculo:");
		scanf("%d", &loc.cod);
		while(loc.cod != 0)
		{
			
			if(loc.cod == 0)
			{
				break;
			}
			printf("Digite o nome do veiculo:\n");
			fflush(stdin); // limpa
			gets(loc.nomeVeiculo);
			//scanf("%s",&loc.nomeVeiculo);
			printf("Digite o valor da locacao do veiculo:\n");
			scanf("%f", &loc.valorLoc);
			fseek(arq, (loc.cod - 1) * sizeof (loc), SEEK_SET ); //fseek posiciona o ponteiro do arquivo
			fwrite(&loc, sizeof(locacao), 1 , arq); //numero de cópias
			printf("Digite o codigo do veiculo:\n");
			scanf("%d", &loc.cod);
			
		}
		
	}
	printf("Operação finalizada com sucesso\n");
	fclose(arq);
}


void leituraBin()
{
	locacao loc = {0, " ", 0.0};
	//void escritaBin();
	FILE *arq; // criando ponteiro de arquivos
	int i = 0;
	arq = fopen("dados.bin", "rb+"); // abrindo arquivos binario
	if (arq == NULL)
	{
		printf("Arquivos nao encontrado!!!\n");
	}
	else
	{
		while (!feof(arq))
		{
			
			fread(&loc, ((i) *sizeof(locacao)), 1, arq);
			if (loc.cod != 0)
			{
				printf("codigo\tNome\tPreco\n");
				printf("%d\t%s\t%.2f\n", loc.cod, loc.nomeVeiculo, loc.valorLoc);
			}
			i++;
		}
	}
	printf("Operacao de LEITURA FINALIZADA \n");
	fclose(arq);
}
void buscarBin()
{
	FILE *arq;
	locacao loc;

	arq = fopen("dados.bin", "rb+");
	rewind(arq);
	if(arq == NULL)
	{
		printf("Erro ao encontrar o arquivo.\n");
	}
	else
	{
		printf("Arquivo encontrado");

		printf("Digite o codigo do Veiculo:\n");
		scanf("%d", &loc.cod);

		fseek(arq, ((loc.cod - 1) * sizeof(loc)), SEEK_SET);
		fread(&loc, sizeof(loc), 1, arq);
		if(loc.cod == 0)
		{
			printf("Registro não encontrado\n");
		}
		else
		{
			printf("codigo\tNome\tPreco \n");
			printf("%3d  %3s %.2f", loc.cod, loc.nomeVeiculo, loc.valorLoc);
		}
	}
	printf("\n Operacao finalizada com sucesso");
	fclose(arq);
}
