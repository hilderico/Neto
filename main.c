#include <stdio.h>

int x;
int y;

const int FRENTE = 0;
const int DIREITA = 1;
const int TRAS = 2;
const int ESQUERDA = 3;
const int RETX = 4;
const int RETY = 5;

int Anda(int anda);
void Limite(void);
int Movimenta(int aa, int fx, int fy, int kreturn);
void teste();


int main()
{

	int comida = 1;
	int cx = 10;
	int cy = 60;
	int range = 10;
	int opc;
	x = 1;
	y = 1;

	opc = 1;

	printf("Comida Local (%d,%d)\n", cx, cy);

	if ((range >= cx) and(range >= cy))
	{
		printf(" Comida proximo ( < 10)\n");
	}


	while (opc != 'n')
	{
		if (x < cx)
		{
			x = Movimenta(Anda(DIREITA), x, y, RETX);
			printf("opc = ");
			opc = getchar();
		}

		if (x > cx)
		{
			x = Movimenta(Anda(ESQUERDA), x, y, RETX);
			printf("opc = ");
			opc = getchar();
		}

		if (y < cy)
		{
			y = Movimenta(Anda(FRENTE), x, y, RETY);
			printf("opc = ");
			opc = getchar();
		}

		if (y > cy)
		{
			y = Movimenta(Anda(TRAS), x, y, RETY);
			printf("opc = ");
			opc = getchar();
		}
		if ((x == cx) && (y == cy))
		{
			printf(" Comida achado\n");
			break;
		}
	}

	printf(" Fim do Programa");

	return 0;
}

int Anda(int anda)
{
	int reta;
	if (anda == FRENTE)
	{
		printf(" Ponto anda pra Frente\n");
		reta = FRENTE;
		return reta;
	}
	if (anda == DIREITA)
	{
		printf(" Ponto anda pra Direita\n");
		reta = DIREITA;
		return reta;
	}
	if (anda == TRAS)
	{
		printf(" Ponto anda pra Tras\n");
		reta = TRAS;
		return reta;
	}
	if (anda == ESQUERDA)
	{
		printf(" Ponto anda pra Esquerda\n");
		reta = ESQUERDA;
		return reta;
	}

}

void Limite(void)
{
	printf("\n\n");
}

int Movimenta(int aa, int fx, int fy, int kreturn)
{

	if (aa == FRENTE)
	{
		fy++;
		printf("Ponto Local (%d,%d)\n", x, y);
		if (kreturn == RETY)
		{
			return fy;
		}

	}

	if (aa == DIREITA)
	{
		fx++;
		printf("Ponto Local (%d,%d)\n", x, y);
		if (kreturn == RETX)
		{
			return fx;
		}
	}

	if (aa == TRAS)
	{
		fy--;
		printf("Ponto Local (%d,%d)\n", x, y);
		if (kreturn == RETY)
		{
			return fy;
		}
	}

	if (aa == ESQUERDA)
	{
		fx--;
		printf("Ponto Local (%d,%d)\n", x, y);
		if (kreturn == RETX)
		{
			return fx;
		}
	}

}

void teste()
{
	printf(" Nascimento\n");
	printf(" Criando um ponto\n");
	printf(" Ponto Criado\n");

	printf(" Ponto procura Comida\n");
	printf(" Ponto come Comida\n");

	int aa;

	Limite();

	x = 0;
	y = 0;
	printf("Ponto Local (%d,%d)\n", x, y);

	aa = Anda(FRENTE);
	if (aa == FRENTE)
	{
		y++;
	}
	printf("Ponto Local (%d,%d)\n", x, y);

	aa = Anda(DIREITA);
	if (aa == DIREITA)
	{
		x++;
	}
	printf("Ponto Local (%d,%d)\n", x, y);
	aa = Anda(TRAS);
	if (aa == TRAS)
	{
		y--;
	}
	printf("Ponto Local (%d,%d)\n", x, y);
	aa = Anda(ESQUERDA);
	if (aa == ESQUERDA)
	{
		x--;
	}
	printf("Ponto Local (%d,%d)\n", x, y);

	Limite();


}
