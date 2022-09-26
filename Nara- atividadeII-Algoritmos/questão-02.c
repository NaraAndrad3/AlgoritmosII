#include <stdio.h>
int main(){
	int i=0;
	char name[25],big[25];
	
	scanf("%s",&name);
	
	for(i=0;i<20;i++){
		big[i] = toupper(name[i]);
	}
	printf("%s \t",big);	
}