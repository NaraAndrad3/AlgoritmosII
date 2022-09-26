#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char artigo[][20] = {"o", "um", "algum", "todo", "qualquer"};
char substantivo[][20] = { "menino", "homem", "cachorro", "carro", "gato"};
char verbo[][20] = { "passou", "pulou", "correu", "saltos", "andou"};
char preposicao[][20] = { "sobre", "sob", "ante", "ate", "com"};

int sortear();
void criaFrase(char frase[]);
int concatena(char frase[], char palavra[], int pos);

int main() {
  char frase[100];  

  srand( (unsigned) time(NULL) );

  int i;

  for (i = 0; i < 20; i++)
  {
    criaFrase(frase);
    printf("Frase: %s\n", frase);
  }
  
  return 0;
}

void criaFrase(char frase[]){
  int s, pos = 0;

  s = sortear();
  pos = concatena(frase, artigo[s], pos);

  s = sortear();
  pos = concatena(frase, substantivo[s], pos);

  s = sortear();
  pos = concatena(frase, verbo[s], pos);

  s = sortear();
  pos = concatena(frase, preposicao[s], pos);

  s = sortear();
  pos = concatena(frase, artigo[s], pos);

  s = sortear();
  pos = concatena(frase, substantivo[s], pos);

  frase[0] -= 32;
  frase[pos-1] = '.';
  frase[pos] = '\0';

}

int sortear(){
    int s = rand()%5;
       
    return s;
}

int concatena(char frase[], char palavra[], int pos) {
    int i = 0;
    while( palavra[i] != '\0' ){
        frase[pos] = palavra[i];
        i++;
        pos++;
    }
    frase[pos] = ' ';
    pos++;    
    return pos;
}