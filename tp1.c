/* Arquivo MAIN que usa o TAD racionais */
#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

	// Determina a seed do programa
	
		/*int seed;
		printf("Qual a seed?\t");
		scanf("%d", &seed);
		srand(seed);
		printf("\n");
		*/

		srand(time(NULL));

	// Variaveis globais + valores padroes
	int n, maximo;
	struct racional r1, r2;

	maximo = -1;
	n = -1;

	// Garante que os valores serao atendidos
	while ((n > 100) || (n < 0)) {
		printf("Digite o numero de linhas (0 a 100): \t");
		scanf("%d", &n);
	};

	while ((maximo > 30) || (maximo < 0)) {
		printf("Digite o valor maximo de inteiros (0 a 30): \t");
		scanf("%d", &maximo);
	};

	// Criacao das linhas
	for (int i=1; i <= n; i++) {
	
		r1 = sorteia_r (maximo);
		r2 = sorteia_r (maximo);

		printf("\n%d: ", i);

		imprime_r(r1);
		printf(" ");
		imprime_r(r2);
		printf(" ");

		//Valida
		if ((r1.valido == 0) || (r2.valido == 0)) {
			printf("NUMERO INVALIDO\n");
			return 1;
		} else {

			//Faz as contas
			struct racional somado = soma_r(r1,r2);
			struct racional subtraido = subtrai_r(r1,r2);
			struct racional multiplicado = multiplica_r(r1,r2);
			struct racional dividido = divide_r(r1,r2);

			//Verifica se eh possivel esta divisao
			if (dividido.den == 0) {
				printf("NUMERO INVALIDO\n");
				return 1;
			};

			//Imprime todas as operacoes
			imprime_r(somado);
			printf(" ");
			imprime_r(subtraido);
			printf(" ");
			imprime_r(multiplicado);
			printf(" ");
			imprime_r(dividido);
		};
		
	};

	printf("\n");
	return 0;
}
