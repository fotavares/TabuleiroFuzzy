#include "Tabuleiro.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio.h>
void Tabuleiro::PreencherLimites()
{
	//Preencher limites da mesa
	//Área de jogo deve ser 20 x 20
	for (int i = 0; i < 22; i++)
	{
		//Preencher Cima
		Mesa[i][0] = 'X';
		//Preencher Baixo
		Mesa[i][21] = 'X';
		//Preencher Lateral Esquerda
		Mesa[0][i] = 'X';
		//Preencher Lateral Direita
		Mesa[21][i] = 'X';
	}
}
void Tabuleiro::PreencherObstaculo()
{
	int i = 0;
	srand(time(NULL));
	//Pegar Posição Horizontal 1 - 15
	int x = rand() % 14 + 1;
	//Pegar Posição Vertical 1 - 20
	int y = rand() % 19 + 1;
	
	posicaoObstaculoX = x;
	posicaoObstaculoY = y;

	while (i < 6)
	{
		Mesa[x+i][y] = 'X';
		i++;
	}
	
}
void Tabuleiro::PreencherSaida()
{
	srand(time(NULL));
	//Pegar Posição Horizontal 1 - 15
	int x = rand() % 19 + 1;

	Mesa[x][21] = ' ';
	posicaoSaida = x;
}

void Tabuleiro::ImprimirMesa()
{
	if (system("CLS")) system("clear");

	for (int i = 0; i < 22; i++)
	{
		printf("|");
		for (int j = 0; j < 22; j++)
		{
			printf("%c|",Mesa[j][i]);
		}
		printf("\n");
	}
}

void Tabuleiro::LimparMesa()
{
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			Mesa[i][j] = ' ';
		}
	}
}

void Tabuleiro::SetaPosicaoJogador(int x, int y)
{
	if (Mesa[x][y] == 'X')	return;
	Mesa[posicaoJogadorX][posicaoJogadorY] = ' ';
	Mesa[x][y] = 'J';
	posicaoJogadorX = x;
	posicaoJogadorY = y;
}

bool Tabuleiro::EncontrouSaida()
{
	return (posicaoSaida == posicaoJogadorX && posicaoJogadorY == 20);
}
Tabuleiro::Tabuleiro()
{
}

Tabuleiro::~Tabuleiro()
{
}
