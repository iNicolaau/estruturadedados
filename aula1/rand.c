#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct Lista{ //estrutura de dados homogenea
	char nome[20];
	char endereco[40];
};

//criar um bilhete de loteria
void main(void){
	setlocale(LC_ALL,"Portuguese");
	int tamanho = 6;
	int bilhete[tamanho];
	
	srand (time(NULL));
	int i ;
	for(i = 0;i < tamanho; i++)
	{
		int j,exist = 0 ,aux = rand()%60 + 1;
		for(j = 0;j < i;j++){
			if(bilhete[j] == aux){
				i--;
				exist = 1;
				break;
			}
		}
		if(exist = 0){
			bilhete[i] = aux;	
		}
	}
	for(i = 0; i < tamanho; i++){
		printf("%d",bilhete[i]);
	}
	
	struct Lista lista[10]; //estrutura de dados homogenea
	for(i = 0;i < 10; i++){
		strcpy(lista[i].nome, "");
		strcpy(lista[i].endereco, " ");
	}
	strcpy(lista[0].nome, "Juliano");
	strcpy(lista[0].endereco, " Rua 5");
	
	strcpy(lista[1].nome, "Gustavo");
	strcpy(lista[1].endereco, "avenida aguia de haia 2100");
	printf("\n\n");
	
	for(i = 0; i <10 && strcmp(lista[i].nome = ""); i++){
		printf("nome: %s,\t Endereço: %s \n",lista[i].nome,lista[i].endereco);
	}
}