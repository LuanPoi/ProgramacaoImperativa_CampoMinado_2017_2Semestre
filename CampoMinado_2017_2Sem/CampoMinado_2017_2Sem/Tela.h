/* tela.h */

#ifndef TELA_H
#define TELA_H

void semente(void);
void coloca_x(int NN, char campo[NN][NN]);
void le_nivel(int NN, int *nivell);
void coloca_bombas(int NN, int dificuldade, char campo[NN][NN]);
void imprime_tela(int NN, char campo[NN][NN]);
void le_jogada(int *ii, int *jj);
void testa_jogada(int NN, int ii, int jj, char campo[NN][NN], int *auxx, int nivell);
void teste_ganha(int NN, int ii, int jj, char campo[NN][NN], int *auxx, int nivell);

#endif