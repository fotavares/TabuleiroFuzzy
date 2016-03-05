#include "Fuzzy.h"
#include <cmath>
#include <string>

void Fuzzy::SetarTermos()
{
	Termos[0] = { "Perto", 0, 7, 14 };
	Termos[1] = { "Longe", 7, 14, 20 };
}

double Fuzzy::CalcularFuzzificacao(termo t, int p)
{
	double resultado = 0;

	//posicao = minimo E posicao = medio
	if (p == t.min && p == t.med)
	{
		resultado = 1.0;
	}
	//posicao = medio E posicao = maximo
	else if (p == t.med && p == t.max)
	{
		resultado = 1.0;
	}
	//posicao <= minimo ou posicao >= maximo
	else if (p <= t.min || p >= t.max)
	{
		resultado = 0;
	}
	//posicao = medio
	else if (p == t.med)
	{
		resultado = 1;
	}
	//posicao > minimo E posicao < medio
	else if ((p > t.min) && (p < t.med))
	{
		resultado = (p / (t.med - t.min)) - (t.min / (t.med - t.min));
	}
	//outras condições
	else
	{
		resultado = (-p / (t.max - t.med)) + (t.max / (t.max - t.med));
	}

	return resultado;
}
//Verifica as regras
double Fuzzy::VerificarRegra(double condicao1, double condicao2, char* operacao)
{
	if (strcmp(operacao, "E") == 0)
	{
		return fmin(condicao1, condicao2);
	}
	else if (strcmp(operacao, "OU") == 0)
	{
		return fmax(condicao1, condicao2);
	}
	else return 0.0;
}

//Defuzzyficar
int Fuzzy::CalcularProximaPosicao(double resultadoRegra, int posicaoAnterior)
{
	int proxima = posicaoAnterior + (int)round(resultadoRegra * 2);
	return (proxima > 20)?20:proxima;
}

Fuzzy::Fuzzy()
{
}


Fuzzy::~Fuzzy()
{
}
