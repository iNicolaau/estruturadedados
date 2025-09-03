#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 0;
	int final = 0;
	int contador;
	
	for(contador = 25; contador < 200; contador++){
		if(contador % 2 == 0){
			printf("\n Esse numero eh par: %d",contador);
			final +=contador;
			n++;
		
		}
	}
		contador = contador + contador;
		printf("\nA soma dos numeros sao %d",final);
		printf("\nQuantos numeros foram achados? %d", n);
}
