#pragma once
class Tabuleiro
{
public:
	//Tabuleiro
	char Mesa[22][22];
	
	//Posiçao da saida
	int posicaoSaida = 0;
	
	//Posição do obstaculo
	int posicaoObstaculoX = 0;
	int posicaoObstaculoY = 0;

	//Posicao do Jogador - Inicial 1,1
	int posicaoJogadorX = 1;
	int posicaoJogadorY = 1;

	void LimparMesa();
	void PreencherLimites();
	void PreencherObstaculo();
	void PreencherSaida();
	void ImprimirMesa();
	void SetaPosicaoJogador(int x, int y);
	bool EncontrouSaida();

	Tabuleiro();
	~Tabuleiro();
};

