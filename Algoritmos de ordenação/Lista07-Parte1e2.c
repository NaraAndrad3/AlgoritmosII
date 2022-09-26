#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
typedef  struct
{
	int chave;
	char nome[30];
	char endereco[50];
	char telefone[14];

} Alunos;
void ordenando(Alunos v[], int n, int tipoOrdem, int ordemChave);
void gerarDados(Alunos v[ ], int n, int ordemChave);
void bolha(Alunos v[ ], int n, int tipoOrdem, int ordemChave);
void selecao(Alunos v[ ], int n, int tipoOrdem, int ordemChave);
void insercao(Alunos v[ ], int n, int tipoOrdem, int ordemChave);

int main()
{
	setlocale(LC_ALL, "");
	int n, ordemChave, tipoOrdem;
	scanf("%d", &n);
	Alunos v[n];
	do
	{
		printf("Digite a ordem e o tipo de ordenacao\n");
		scanf("%d", &ordemChave);
		if(ordemChave != 3)
		{
			scanf("%d", &tipoOrdem);
			ordenando(v, n, tipoOrdem, ordemChave);
		}
	}
	while(ordemChave != 3);
	//printf("Fim");
	return 0;
}
//Ordenando de acordo com a opc escolhida
void ordenando(Alunos v[], int n, int tipoOrdem, int ordemChave)
{
	if(tipoOrdem == 0)
	{
		printf("Bolha\n");
		bolha(v, n, tipoOrdem, ordemChave);
	}
	else if(tipoOrdem == 1)
	{
		printf("Seleção\n");
		selecao(v, n, tipoOrdem, ordemChave);
	}
	else
	{
		printf("Inserção\n");
		insercao(v, n, tipoOrdem, ordemChave);
	}
}
//Gerando os dados para preencher o vetor
void gerarDados(Alunos v[ ], int n, int ordemChave)
{
	int i;
	if(ordemChave == 0)
	{
		for(i = 0; i < n; i++)
		{
			v[i].chave = i;
		}

		//printf("Vetor não ordenado:\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", v[i].chave);
		}
		printf("\n");

	}
	else if(ordemChave == 1)
	{
		for(i = 0; i < n; i++)
		{
			v[i].chave = rand() % 100;
		}
		//printf("Vetor não ordenado:\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", v[i].chave);
		}
		printf("\n");
	}
	else
	{
		for(i = n - 1; i >= 0; i--)
		{
			v[i].chave = i;
		}
		//printf("Vetor não ordenado:\n");
		for(i = n - 1; i >= 0; i--)
		{
			printf("%d ", v[i].chave);
		}
		printf("\n");
	}
}
//Metodo de ordenação Bolha
void bolha(Alunos v[ ], int n, int tipoOrdem, int ordemChave)
{
	int i, j;
	Alunos aux;
	gerarDados(v, n, ordemChave);
	for(i = 0; i < n - 1; i++)
	{
		for(j = 1; j < n - i; j++)
		{
			if(v[j].chave < v[j - 1].chave)
			{
				aux = v[j - 1];
				v[j - 1].chave = v[j].chave;
				v[j].chave = aux.chave;

			}
		}
	}

	for(i = 0; i < n; i++)
	{

		printf("%d ", v[i].chave);
	}
	printf("\n");
}
//metodo de ordenação Seleção
void selecao(Alunos v[ ], int n, int tipoOrdem, int ordemChave)
{
	int i, j, min;
	Alunos aux;
	gerarDados(v, n, ordemChave);//Se não chamar a função aqui a selecao não tem acesso aos dados!!
	for(i = 0; i < n - 1; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
		{
			if(v[j].chave < v[min].chave )
			{
				min = j;
			}
		}

		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}

	for(i = 0; i < n; i++)
	{

		printf("%d ", v[i].chave);
	}
	printf("\n");
}
//Metodo de ordenação inserção
void insercao(Alunos v[ ], int n, int tipoOrdem, int ordemChave)
{
	int i, j;
	Alunos aux;
	gerarDados(v, n, ordemChave);
	for(i = 1; i < n; i++)
	{
		aux = v[i];
		j = i - 1;
		while((j >= 0) && (aux.chave < v[j].chave))
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = aux;
	}

	for(i = 0; i < n; i++)
	{

		printf("%d ", v[i].chave);
	}
	printf("\n");
}

