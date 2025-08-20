#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Struct para armazenar dia, mes e ano
struct Data {
    int dia;
    int mes;
    int ano;
};

// Struct principal que inclui a quantidade e a data
struct Registro {
    int quantidade;
    struct Data data_registro;
};

// Função para imprimir a data
void imprimirData(struct Data d) {
    printf("%d/%d/%d", d.dia, d.mes, d.ano);
}

// Função para imprimir o registro completo
void imprimirRegistro(struct Registro r) {
    printf("\n--------Quantidade--------");
    printf("\nQuantidade: %d", r.quantidade);
    printf("\nData do registro: ");
    imprimirData(r.data_registro);
    printf("\n-----------------------------------\n");
}

void main(void) {
    setlocale(LC_ALL, "Portuguese");

    // Declara e inicializa uma variável da struct Registro
    struct Registro entrada_estoque;
    entrada_estoque.quantidade = 150;
    entrada_estoque.data_registro.dia = 20;
    entrada_estoque.data_registro.mes = 8;
    entrada_estoque.data_registro.ano = 2025;
    
    // Chama a função para imprimir os dados
    imprimirRegistro(entrada_estoque);

    // Outro exemplo, inicializando diretamente
    struct Registro saida_estoque = {50, {21, 8, 2025}};
    imprimirRegistro(saida_estoque);
}
