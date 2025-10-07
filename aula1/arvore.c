#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Definição do nó da árvore
typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Declaração das funções
Node* novoNo(int valor);
void imprimir_arvore_1(Node* raiz, char* espaco, const char* marcador_raiz);
void imprimir_arvore(Node* raiz);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    Node* raiz = NULL;
    raiz = novoNo(10);
    raiz->esquerda = novoNo(5);
    raiz->direita = novoNo(27);
    raiz->esquerda->esquerda = novoNo(1);
    raiz->esquerda->direita = novoNo(8);
    raiz->direita->esquerda = novoNo(16);
    raiz->direita->direita = novoNo(31);

    imprimir_arvore(raiz);

    return 0;
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
void imprimir_arvore_1(Node* raiz, char* espaco, const char* marcador_raiz) {
    if (raiz != NULL) {
        if (strlen(espaco) == 0) {
            printf("%d\n", raiz->valor);
        } else {
            printf("%.*sL_%d\n", (int)(strlen(espaco) - strlen(marcador_raiz)), espaco, raiz->valor);
        }

        // Prepara próximo nível do espaço
        char novo_espaco[1000];
        strcpy(novo_espaco, espaco);
        strcat(novo_espaco, marcador_raiz);

        // Primeiro direita, depois esquerda
        imprimir_arvore_1(raiz->direita, novo_espaco, marcador_raiz);
        imprimir_arvore_1(raiz->esquerda, novo_espaco, marcador_raiz);
    }
}

// Função principal para imprimir a árvore
void imprimir_arvore(Node* raiz) {
    imprimir_arvore_1(raiz, "", "    ");
}
