/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include "tela.h"
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#endif
#define N 5
int main() {
	printf("******************************\n");
	printf("---------CAMPO MINADO---------\n");
	printf("******************************\n");
	char camp[N][N];
	int i, j, aux, nivel, conf;
	semente();
	do {
		aux = 0;
		coloca_x(N, camp);
		le_nivel(N, &nivel);
		coloca_bombas(N, nivel, camp);
		do {
			imprime_tela(N, camp);
			le_jogada(&i, &j);
			testa_jogada(N, i, j, camp, &aux, nivel);
			teste_ganha(N, i, j, camp, &aux, nivel);
		} while (aux <= ((N*N) - nivel));//testa se aux ja atingiu o numero maximo de jogadas possivel
		printf("\n\nDESEJA JOGAR NOVAMENTE?\nSe SIM digite qualquer numero inteiro exceto o 0\nSe NAO digite 0\n");
		scanf("%d", &conf);
		system("cls");
	} while (conf != 0);//confere se o valor de conf confirma continuar jogando ou finaliza o jogo
	printf("---------------------------------\n");
	printf("-----------FIM DE JOGO-----------\n");
	printf("---------------------------------\n");
	return 0;
}
