#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>
/* acrescente demais includes que voce queira ou precise */

// Retorna um numero aleatorio entre o min e max
int aleat (int min, int max) {
	return (min + (rand() % (max+1-min)));
};

// Maximo divisor comum entre a e b - Metodo de Euclides
int mdc (int a, int b) {
	//No caso de a ser menor que b - inverte
	if (a < b) {
		int temp = b;
		b = a;
		a = temp;
	};

	//Arrumar casos negativos
	if (a < 0) {
		a*=(-1);
	};
	if (b < 0) {
		b*=(-1);
	};

	if ((a%b) == 0 ) {
		return b;
	};

	return mdc(b, (a%b));
};

// Minimo multiplo comum entre a e b
int mmc (int a, int b) {
	return ((a*b)/(mdc(a,b)));
};

// Simplifica o racional - Sempre valido
struct racional simplifica_r (struct racional r) {

	int rMDC = mdc(r.num,r.den);
	
	r.num/= rMDC;
	r.den/= rMDC;

	/*Tratamento de caso: Ambos negativos e apenas denominador negativo
	  Visto que ambos os casos invertem os sinais*/
	if (((r.num < 0)&&(r.den < 0)) || ((r.num > 0) && (r.den < 0))) {
		r.num*=(-1);
		r.den*=(-1);
	};

	return r;
};

// Criar um numero racional
struct racional cria_r (int numerador, int denominador) {
	
	struct racional racional0;

	racional0.num = numerador;
	racional0.den = denominador;
	racional0.valido = (valido_r(racional0));

	return racional0;
};

//Sorteia um numero racional que tem alg ate n
struct racional sorteia_r (int n) {
	
	struct racional temp;

	int numerador = aleat(0, n);
	int denominador = aleat(0, n);

	temp = cria_r (numerador, denominador); 

	return temp;
};

//Imprime o racional na tela
void imprime_r (struct racional r) {

	//Tratamento de invalido
	if (r.valido == 0) {
		printf("Invalido");
		return;
	} else {
	
		//Tratamento de casos
		if (r.num == 0) {
			printf("0");
			return;
		};

		r = simplifica_r(r);

		if (r.den == 1) {
			printf("%d", r.num);
			return;
		};

		//Outros casos ja sao tratados no simplifica_r

		//Caso Padrao
		printf("%d/%d", r.num, r.den);
		return;
	};
};

//Verifica se o numero eh valido
int valido_r (struct racional r) {

	if (r.den == 0) {
		return 0;
	};
	
	return 1;
};

/*Aqui todas as contas entre racionais vao acontecer
Todas os racionais a partir daqui sao validos*/

struct racional soma_r (struct racional r1, struct racional r2) {

	struct racional soma;

	soma = cria_r ( ((r1.num*r2.den) + (r2.num*r1.den)), (r1.den*r2.den) );
	return soma;
};

struct racional subtrai_r (struct racional r1, struct racional r2) {

	struct racional subtracao;

	subtracao = cria_r ( ((r1.num*r2.den) - (r2.num*r1.den)), (r1.den*r2.den) );
	return subtracao;
};

struct racional multiplica_r (struct racional r1, struct racional r2) {

	struct racional multiplicacao;

	multiplicacao = cria_r ( (r1.num*r2.num), (r1.den*r2.den) );
	return multiplicacao;
};

struct racional divide_r (struct racional r1, struct racional r2) {

	struct racional divisao;

	divisao = cria_r ( (r1.num*r2.den), (r1.den*r2.num)  );
	return divisao;
};

