#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Declaração de variáveis globais


// Definição do nó da árvore
typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Declaração das funções
Node* novoNo(int valor);
void imprimir_arvore(Node* raiz);
void imprimir_arvore_1(Node* raiz, char* espaco, const char* marcador_raiz);
void emOrdem(Node* raiz);
void preOrdem(Node* raiz);
void posOrdem(Node* raiz);

void main(void){
	setlocale(LC_ALL,"Portuguese");	
    Node* raiz = NULL;
	raiz = novoNo(10);
	raiz->esquerda = novoNo(5);	
	raiz->direita = novoNo(27);
	raiz->esquerda->esquerda = novoNo(1);	
	raiz->esquerda->direita = novoNo(8);
	raiz->direita->esquerda = novoNo(16);
	raiz->direita->esquerda->direita = novoNo(20);
	raiz->direita->direita = novoNo(31);  
	imprimir_arvore(raiz);	
	printf("\nEm Ordem: \t");
	emOrdem(raiz);
	printf("\nPré Ordem: \t");
	preOrdem(raiz);
	printf("\nPós Ordem: \t");
	posOrdem(raiz);    
}

// Função para criar um novo nó
Node* novoNo(int valor) {
    Node* no = (Node*)malloc(sizeof(Node));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Função auxiliar para imprimir a árvore
void imprimir_arvore(Node* raiz){
	imprimir_arvore_1(raiz, "", "    ");
}

void imprimir_arvore_1(Node* raiz, char* espaco, const char* marcador_raiz) {
    if (raiz != NULL) {
        // Impressão da raiz
        if (strlen(espaco) == 0) {
            printf("%d\n", raiz->valor);
        } else {
            // Imprime a "linha" com +-
            printf("%.*sL__%d\n", (int)(strlen(espaco) - strlen(marcador_raiz)), espaco, raiz->valor);
        }

        // Prepara próximo nível do espaço
        char novo_espaco[1000]; // Tamanho suficiente
        strcpy(novo_espaco, espaco);
        strcat(novo_espaco, marcador_raiz);

        // Primeiro direita, depois esquerda
        imprimir_arvore_1(raiz->direita, novo_espaco, marcador_raiz);
        imprimir_arvore_1(raiz->esquerda, novo_espaco, marcador_raiz);
    }
}

void emOrdem(Node* raiz){
	if(raiz != NULL){
		emOrdem(raiz->esquerda);
		printf("%d ",raiz->valor);
		emOrdem(raiz->direita);	
	}	
}

void preOrdem(Node* raiz){
	if(raiz != NULL){
		printf("%d ",raiz->valor);
		preOrdem(raiz->esquerda);
		preOrdem(raiz->direita);	
	}	
}

void posOrdem(Node* raiz){
	if(raiz != NULL){		
		posOrdem(raiz->esquerda);
		posOrdem(raiz->direita);
		printf("%d ",raiz->valor);	
	}	
}


