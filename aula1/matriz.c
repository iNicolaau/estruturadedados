#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Data{
	int dia;
	int mes;
	int ano
};
struct Conta {
	int num_conta;
	char tipo_conta;
	char nome[80];
	float saldo;
	struct Data abertura;
	struct Data pagamento;
};

void main(void){
	setlocale(LC_ALL,"Portuguese");
	struct Conta cliente_novo,cliente_antigo;
	
	struct Conta cliente = {456,'P',"Gustavo",125.00,1,1,2012,10,8,2025};
	
	cliente_novo.num_conta = 7651;
	cliente_novo.tipo_conta = 'C';
	cliente_novo.saldo = 1762.00;
	strcpy(cliente_novo.nome, "Gustavo Nicolau");
	cliente_novo.abertura.dia = 12;
	cliente_novo.abertura.mes = 11;
	cliente_novo.abertura.ano = 2009;
	cliente_novo.pagamento.dia = 5;
	cliente_novo.pagamento.mes = 8;
	cliente_novo.pagamento.ano = 2025;
	
	imprimirConta(cliente);
}

void imprimirConta(struct Conta c){
	printf("\n-------------Cliente----------");
	printf("\nNúmero da conta: %d",c.num_conta);
	printf("\nNome cliente: %s",c.nome);
	printf("\nTipo da conta: %c",c.tipo_conta);
	printf("\nSaldo da conta: %f",c.saldo);
	printf("\n-------------------------------");
	printf("\nData de abertura: ");
	imprimirData(c.abertura);
	printf("\nData de pagamento: ");
	imprimirData(c.pagamento);
	
}

void imprimirData(struct Data d){
	printf("%d/%d/%d",d.dia,d.mes,d.ano);
}
