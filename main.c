#include <stdio.h>

int x;
int y;

const int FRENTE = 0;
const int DIREITA = 1;
const int TRAS = 2;
const int ESQUERDA = 3;

int Anda(int anda);
void Limite(void);
void teste();


int main()
{

	int comida = 1;
	int cx = 1;
	int cy = 6;
	x = 1 ;
	y = 1;

	printf("Comida Local (%d,%d)\n", cx, cy);






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
