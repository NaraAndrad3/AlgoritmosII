#include <stdio.h>
#include <string.h>
#define tam 100
int main(){
	int i,n,j;
	char num[tam],d;
	printf("Digitite o digito com defeito:\n");
	scanf("%c",&d);
	printf("Digite o valor real do contrato:\n");
	scanf("%s",&num);
	while(d!=0)
	{
		if (d != '0')
      {
        n = strlen(num);
        for (i = 0; i < n; i++)
	    {
            if (num[i] == d)
	        {
                for (j = i; j < n; j++)
                num[j] = num[j+1];
                num[n-1] = 0;
                n--;
                i--;
            } 
        }
        for (i = 0; i < n-1; i++)
	    {
            if (num[i] == '0')
	        {
                for (j = i; j < n; j++)
                num[j] = num[j+1];
                num[n-1] = 0;
                n--;
                i--;
            }
	        else
                break;
        }
        if (n == 0)
	    {
            num[0] = '0';
            num[1] = '\0';
        }

        printf("%s\n", num);

        scanf(" %c", &d);
        scanf("%s", num);
      }
	}
	
	
	
}