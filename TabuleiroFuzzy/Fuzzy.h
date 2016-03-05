#pragma once
class Fuzzy
{
public:
	typedef struct termo
	{
		char* Nome;
		//Posicao 1
		double min;
		//Posicao 2
		double med;
		//Posicao 3
		double max;
	} ;

	termo Termos[2];
	void SetarTermos();
	double CalcularFuzzificacao(termo t, int posicao);
	double VerificarRegra(double condicao1, double condicao2, char* operacao);
	int CalcularProximaPosicao(double resultadoRegra, int posicaoAnterior);
	Fuzzy();
	~Fuzzy();
};

