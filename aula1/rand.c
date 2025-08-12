#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(void){
	setlocale(LC_ALL,"Portuguese");
	//criar um bilhete de loteria
	int tamanho = 6;
	int bilhete[tamanho];
	
	srand (time(NULL));
	int i ;
	for(i = 0;i < tamanho; i++)
	{
		int aux = rand()%60 + 1;
		//printf("%d",aux);
		bilhete[i] = aux;	
	}
	for(i = 0; i < tamanho; i++){
		printf("%d",bilhete[i]);
	}
	return 0;
}
