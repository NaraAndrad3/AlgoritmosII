#include <stdio.h>
#include <locale.h>
int invertido(int);
int main(){
	setlocale(LC_ALL,"");
	int num, num2;
	printf("Digite um numero:\n");
	scanf("%d",&num);
	num2 = invertido(num);
	printf("O numero invertido é: \n%d",num2);
	return 0;
}
int invertido(int num){
	int i;
	int resto, inverte=0,n;
	while(num>0)
	{
		resto = num%10;
		inverte = inverte*10+resto;
		num = num/10;
		i++;
	}
	return inverte;
}