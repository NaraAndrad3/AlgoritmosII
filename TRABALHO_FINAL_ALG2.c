#include <stdio.h>
#include <locale.h>

int main(int argc, char** argv)
{
	setlocale(LC_ALL,"");
	int cont = 0;
	int nCasas, i = 0, y, soma;
	FILE *entrada, *saida;//ponteiros para os arquivos
	entrada = fopen("Entrada.txt", "r");//abri para leitura
	if(entrada == NULL)
	{
		printf("Erro o encontrar o arquivo\n");
	}
	else
	{
		//li primeiro valor (numero de casas)
		fscanf(entrada, "%d", &nCasas);
		int casas[nCasas];//vetor para armazenar os numeros das casas
		while(!feof(entrada))
		{
			fscanf(entrada, "%d", &casas[i]);
			i++;
			if(i == nCasas)//condição de parada
			{
				break;
			}
		}
		fscanf(entrada, "%d", &soma);//lendo a soma	
		int vetor[nCasas];//vetor de teste
		for(y = 0; y < nCasas; y++)
		{
			vetor[y] = casas[y];
		}
		
		int j, k, aux, aux2;

		for(j = 0; j < nCasas; j++)
		{
			for(k = 0; k < nCasas; k++)
			{
				if(vetor[j] + casas[k] == soma)
				{
					aux = vetor[j];
					aux2 = casas[k];
				}
				cont++;
			}
		}
		//printf("Iterações: %d",cont);
		SaidaArq(aux, aux2,*saida);	
	}
	fclose(entrada);
	return 0;
}
void SaidaArq(int aux, int aux2, FILE *saida)
{
	saida = fopen("saida.txt", "w");
	if(saida == NULL)
	{
		printf("problemas ao abrir o arquivo.\n");
	}
	else
	{
		//condicional para imprimir o menor seguido
		//do maior
		if(aux < aux2)
		{
			fprintf(saida, "%d %d", aux, aux2);
		}
		else
		{
			fprintf(saida, "%d %d", aux2, aux);
		}
		
	}

	fclose(saida);
}