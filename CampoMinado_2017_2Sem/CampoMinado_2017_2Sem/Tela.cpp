/* tela.c */
#include <stdio.h>
#include "Tela.h"
#define N 5

void semente(void) { //cria  valores randomicos.
	srand(time(NULL));
	rand();
}
void coloca_x(int NN, char campo[NN][NN]) { //agrega valor X para tds posiçoes da matriz.
	int i, j;//declara variaveis q serao usadas para definir posicoes da matriz, possibilitando muda-las.
	for (i = 0;i<NN;i++) {//seleciona linha ate atingir o valor maximo de linhas.
		for (j = 0;j<NN;j++) {//seleciona coluna ate atingir o valor maximo de colunas.
			campo[i][j] = 'X';//agrega o valor X para posição em questao.
		}
	}
}
void le_nivel(int NN, int *nivell) { //função para ler nivel.
	int aux2;//auxiliar para testes
	do {
		printf("Escolha nivel\n1-Facil\n2-Medio\n3-Dificil\n");//imprime as possibilidades de nivel.
		scanf("%d", nivell);fflush(stdin);//le nivel, e a altera (na main) por ponteiro.
		aux2 = *nivell; //altera valor de aux2 para testar em while.
		if (*nivell == 1) { //testa se o nivel inserido foi 1.
			*nivell = (NN*NN)*0.25;//altera, por ponteiro, valor de nivel para numero total de bombas.
		}
		if (*nivell == 2) {
			*nivell = (NN*NN)*0.5;
		}
		if (*nivell == 3) {
			*nivell = (NN*NN)*0.75;
		}
	} while ((aux2 > 3) || (aux2 < 1)); //testa se aux2 recebeu um valor diferente dos possiveis.
}
void coloca_bombas(int NN, int dificuldade, char campo[NN][NN]) { //bola as bombas.
	int b;
	for (b = 1; b <= dificuldade; ) { //coloca bombas ate atingir o valor da dificuldade(nivel).
		int l = rand() % NN;//usa a funçao randomica para selecionar linha.
		int c = rand() % NN;//usa a funçao randomica para selecionar coluna.
		if (campo[l][c] != 'B') {//testa se a posição ja apresenta valor B.
			campo[l][c] = 'B';//agrega valor B para posiçao.
			b++;//soma 1 ao valor de 'b'.
		}
	}
}
void imprime_tela(int NN, char campo[NN][NN]) {//imprime o jogo na tela.
	int i, j;//declara variaveis q serao usadas para definir posicoes da matriz, possibilitando muda-las.
	printf("\n");
	for (i = 0;i<NN;i++) {//seleciona linha ate atingir o valor maximo de linhas.
		printf("\n ");
		for (j = 0;j<NN;j++) {//seleciona coluna ate atingir o valor maximo de colunas.
			if ((campo[i][j]) == 'B')//testa se o valor da posiçao é B.
				printf("|X");//imprime X.
			else
				printf("|%c", campo[i][j]);//imprime o valor da posiçao.
		}
	}
}
void le_jogada(int *ii, int *jj) {//le, por ponteiros, as posiçoes da jogada.
	printf("\n\n escolha uma linha: ");
	scanf("%d", ii); fflush(stdin);//le e altera por ponteiros os valores(incluindo na memoria).
	printf(" escolha uma coluna: ");
	scanf("%d", jj); fflush(stdin);//le e altera por ponteiros os valores(incluindo na memoria).
}
void testa_jogada(int NN, int ii, int jj, char campo[NN][NN], int *auxx, int nivell) {//testa se eh possivel efetuar a jogada
	if (campo[ii][jj] == 'X') {//testa se a posiçao apresenta valor 'X'
		campo[ii][jj] = 'O';//caso seja verdadeiro recebe valor 'O'
		*auxx = *auxx + 1;/*aux recebe +1, a casa jogada ele recebe esse valor
						  q eh alterado na memoria por ponteiros, ao atingir numero maximo de jogas outro teste finaliza o jogo*/
	}
	else {//caso a afirmativa seja falsa...
		if (campo[ii][jj] == 'B') {//se a posiçao tenha valor 'B'
			*auxx = (NN*NN);//aux recebe valor maximo de jogadas
			printf("\n---------------------------------------");
			printf("\n--------------VOCE PERDEU--------------");
			printf("\n---------------------------------------");
			printf("\n");//imprime a derrota do jogador
			for (ii = 0;ii<NN;ii++) {
				printf("\n ");
				for (jj = 0;jj<NN;jj++) {
					if ((campo[ii][jj]) == 'B') {
						printf("|B");//mostra aonde estavam as bombas
					}
					else {
						printf("|O", campo[ii][jj]);//para tudo q nao for bomba ele print 'O'
					}
				}
			}
		}
		else {//se a afirmativa for falsa...
			printf("\n ERROR: digite outra posicao");//imprime msg de erro e volta oara ler posiçao
		}
	}
}
void teste_ganha(int NN, int ii, int jj, char campo[NN][NN], int *auxx, int nivell) {
	if (*auxx == ((NN*NN) - nivell)) {//testa se ja foram feitas o numero maximo de jogadas(excluindo as bombas).
		*auxx = (NN*NN);//altera o valor do aux(na main) para o numero maximo de possibilidades.
		for (ii = 0;ii<NN;ii++) {
			printf("\n ");
			for (jj = 0;jj<NN;jj++) {
				if ((campo[ii][jj]) == 'B')
					printf("|B");//mostra aonde estavam as bombas
				else
					printf("|O", campo[ii][jj]);//mostra td o resto q nao eram bombas como 'O'
			}
		}
		printf("\n----------------------------------");
		printf("\n--------------VENCEU--------------");
		printf("\n----------------------------------");
	}
}