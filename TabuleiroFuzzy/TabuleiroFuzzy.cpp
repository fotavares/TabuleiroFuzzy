// TabuleiroFuzzy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tabuleiro.h"
#include "Fuzzy.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Tabuleiro t;
	Fuzzy f;
	double regra1 = 0, regra2 = 0, resultado = 0;
	t.LimparMesa();
	t.PreencherLimites();
	t.PreencherObstaculo();
	t.PreencherSaida();

	t.SetaPosicaoJogador(1, 1);
	t.ImprimirMesa();
	getchar();

	//Setar os termos "Perto" e "Longe"
	f.SetarTermos();
	while (!t.EncontrouSaida())
	{
		//Não está na direção da saida
		if (t.posicaoJogadorX != t.posicaoSaida)
		{
			//Regras de movimentação
			//Se parede baixo longe OU obstaculo Y longe - Move baixo
			regra1 = f.CalcularFuzzificacao(f.Termos[1], 21 - t.posicaoJogadorY);
			regra2 = f.CalcularFuzzificacao(f.Termos[1], 21 - t.posicaoObstaculoY);
			resultado = f.VerificarRegra(regra1, regra2, "OU");
			if (resultado != 0)
			{
				t.SetaPosicaoJogador(t.posicaoJogadorX, f.CalcularProximaPosicao(resultado, t.posicaoJogadorY));
				t.ImprimirMesa();
				printf("Se parede baixo longe[21] OU obstaculo Y longe[%d] - Move baixo\n", t.posicaoObstaculoY);
				printf("Valor 1: %f; Valor 2: %f; Movimento [X,Y]: [%d,%d]", regra1, regra2, t.posicaoJogadorX, t.posicaoJogadorY);
				getchar();
			}
		}
		if (t.posicaoJogadorX != t.posicaoSaida)
		{
			//Se parede baixo perto ou Obstaculo y perto - Move lado 
			regra1 = f.CalcularFuzzificacao(f.Termos[0], 21 - t.posicaoJogadorY);
			regra2 = f.CalcularFuzzificacao(f.Termos[0], 21 - t.posicaoObstaculoY);
			resultado = f.VerificarRegra(regra1, regra2, "OU");
			if (resultado != 0)
			{
				t.SetaPosicaoJogador(f.CalcularProximaPosicao(resultado, t.posicaoJogadorX), t.posicaoJogadorY);
				t.ImprimirMesa();
				printf("Se parede baixo perto[21] ou Obstaculo y perto[%d] - Move lado \n", t.posicaoObstaculoY);
				printf("Valor 1: %f; Valor 2: %f; Movimento [X,Y]: [%d,%d]", regra1, regra2, t.posicaoJogadorX, t.posicaoJogadorY);
				getchar();
			}
		}
		if (t.posicaoJogadorX != t.posicaoSaida)
		{
			//se parede baixo perto e obstaculo x perto - move baixo 
			regra1 = f.CalcularFuzzificacao(f.Termos[0], 21 - t.posicaoJogadorY);
			regra2 = f.CalcularFuzzificacao(f.Termos[0], t.posicaoObstaculoX - t.posicaoJogadorX);
			resultado = f.VerificarRegra(regra1, regra2, "E");
			if (resultado != 0)
			{
				t.SetaPosicaoJogador(f.CalcularProximaPosicao(resultado, t.posicaoJogadorX), t.posicaoJogadorY);
				t.ImprimirMesa();
				printf("se parede baixo perto e obstaculo x perto - move baixo\n", t.posicaoObstaculoY);
				printf("Valor 1: %f; Valor 2: %f; Movimento [X,Y]: [%d,%d]", regra1, regra2, t.posicaoJogadorX, t.posicaoJogadorY);
				getchar();
			}
		}
		if (t.posicaoJogadorX != t.posicaoSaida)
		{
			//Se parede baixo perto ou saida perto - Move lado 
			regra1 = f.CalcularFuzzificacao(f.Termos[0], 21 - t.posicaoJogadorY);
			regra2 = f.CalcularFuzzificacao(f.Termos[0], t.posicaoSaida - t.posicaoJogadorX);
			resultado = f.VerificarRegra(regra1, regra2, "OU");
			if (resultado != 0)
			{
				t.SetaPosicaoJogador(f.CalcularProximaPosicao(resultado, t.posicaoJogadorX), t.posicaoJogadorY);
				t.ImprimirMesa();
				printf("Se parede baixo perto[21] ou Obstaculo y perto[%d] - Move lado \n", t.posicaoObstaculoY);
				printf("Valor 1: %f; Valor 2: %f; Movimento [X,Y]: [%d,%d]", regra1, regra2, t.posicaoJogadorX, t.posicaoJogadorY);
				getchar();
			}
		}

		if (t.posicaoJogadorX == t.posicaoSaida)
		{
			t.SetaPosicaoJogador(t.posicaoJogadorX, 20);
			t.ImprimirMesa();
			getchar();
		}
		
		if (t.EncontrouSaida())
		{
			printf("Saída encontrada!");
			break;
		}

		

	}
	getchar();
	return 0;
}

