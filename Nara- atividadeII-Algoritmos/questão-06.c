#include <stdio.h>
int main(){
	int linha,coluna;
	int  n,m,p,x,produto,i;
	//matriz 1
	printf("Digite o numero de linhas da Matriz 1:\n");
	scanf("%d",&m);
	printf("Digite o numero de colunas da matriz 1:\n");
	scanf("%d",&n);
	printf("Digite o numero de colunas da Matriz 2:\n");
	scanf("%d",&x);
	int matriz1[m][n];
	int matriz2[n][x];
	int matrizRes[m][x];
	for(linha=0;linha<m;linha++){//preenchendo matrizes
		for(coluna=0;coluna<n;coluna++){
			scanf("%d",&matriz1[linha][coluna]);
		}
	}
	for(linha=0;linha<n;linha++){
		for(coluna=0;coluna<x;coluna++){
			scanf("%d",&matriz2[linha][coluna]);
		}
	}
	printf("Matriz 1:\n");//mostrando matrizes
	for(linha=0;linha<m;linha++){
		for(coluna=0;coluna<n;coluna++){
			printf("%d\t",matriz1[linha][coluna]);
		}
		printf("\n");
	}
	printf("\nMatriz 2:\n");
	for(linha=0;linha<n;linha++){
		for(coluna=0;coluna<x;coluna++){
			printf("%d\t",matriz2[linha][coluna]);
		}
		printf("\n");
	}
	for(linha=0;linha<m;linha++){
		for(coluna=0;coluna<x;coluna++){
			produto=0;
			for(i=0;i<m;i++){
				produto += matriz1[linha][i]*matriz2[i][coluna];
				 matrizRes[linha][coluna]= produto;
			}
		}
	}
	printf("\nMatriz Resultado:\n");
	for(linha=0;linha<m;linha++){
		for(coluna=0;coluna<x;coluna++){
			printf("%d\t",matrizRes[linha][coluna]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	
}