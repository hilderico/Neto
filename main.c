#include <stdio.h>

int x;
int y;


const int FRENTE = 0;
const int DIREITA = 1;
const int TRAS = 2;
const int ESQUERDA = 3;
const int RETX = 4;
const int RETY = 5;
const int COMIDASIM = 6;
const int COMIDANAO = 7;

int seed[] =
	{ 67, 3, 126, 11, 14, 92, 29, 47, 99, 86, 8, 12, 55, 21, 87, 110, 23, 1, 96, 57, 70, 17,
	26, 118, 27, 74, 31, 114, 122, 6, 61, 82, 41, 46, 15, 72, 52, 42, 69, 68, 4, 127, 93, 30, 48,
	100, 9, 13, 56, 22, 88, 111, 24, 2, 97, 58, 71, 119, 28, 75, 32, 115, 123, 7, 62, 83, 49, 16,
	73, 53, 43, 5, 128, 94, 76, 81, 95, 59, 106, 117, 18, 36, 50, 66, 89, 104, 116, 19, 38, 60, 80,
		102, 113, 20, 40, 65, 91, 109, 10, 44, 78, 103, 124, 37, 77, 105, 0, 51, 90, 121, 45, 98,
		25, 64, 112, 54, 108, 63, 33, 107, 84, 39, 79, 85, 120, 34, 35, 125, 101
};

int seed1[] =
	{74,
10, 126, 18, 21, 99, 36, 54, 106, 93, 15,
19, 62, 28, 94, 117, 30, 8, 103, 64, 77,
24, 33, 125, 34, 81, 38, 121, 122, 13, 68,
89, 48, 53, 22, 79, 59, 49, 76, 75, 11,
127, 100, 37, 55, 107, 16, 20, 63, 29, 95,
118, 31, 9, 104, 65, 78, 126, 35, 82, 39,
122, 123, 14, 69, 90, 56, 23, 80, 60, 50,
12, 128, 125, 83, 88, 102, 66, 113, 124, 25,
43, 57, 73, 96, 111, 123, 26, 45, 67, 87,
109, 120, 27, 47, 72, 98, 116, 17, 51, 85,
110, 124, 44, 84, 112, 7, 58, 97, 128, 52,
105, 32, 71, 119, 61, 115, 70, 40, 114, 91,
46, 86, 92, 127, 41, 42, 101
};

int Anda(int anda);
void Limite(void);
int Movimenta(int aa, int fx, int fy, int kreturn);
int DetectaComida(int x, int y, int cx, int cy);
void Destino(int fx, int fy, int rotax, int rotay);
void testram();
void cmpram();

void teste();
void teste1();
void teste2();
void teste3();
void teste4();
void teste5();
void teste6();


int main()
{
	int test128[128];
	
	for (x = 0; x < 128; x++)
	{
		test128[x] = 0;
	}
	
	for (x = 0; x < 128; x++)
	{
		test128[x] = seed[x] + 7;
		if(test128[x] > 128)
		{
			test128[x] = seed[x] % 129;
		}
	}
	
	printf("test128[0...128] = {");
	for (x = 0; x < 128; x++)
	{
		printf("%d, ", test128[x]);
		if ((x % 10) == 0)
		{
			printf("\n");
		}
	}

	printf("} ");
	
	
	
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
		printf("Ponto Local (%d,%d)\n", fx, fy);
		if (kreturn == RETY)
		{
			return fy;
		}

	}

	if (aa == DIREITA)
	{
		fx++;
		printf("Ponto Local (%d,%d)\n", fx, fy);
		if (kreturn == RETX)
		{
			return fx;
		}
	}

	if (aa == TRAS)
	{
		fy--;
		printf("Ponto Local (%d,%d)\n", fx, fy);
		if (kreturn == RETY)
		{
			return fy;
		}
	}

	if (aa == ESQUERDA)
	{
		fx--;
		printf("Ponto Local (%d,%d)\n", fx, fy);
		if (kreturn == RETX)
		{
			return fx;
		}
	}

}

int DetectaComida(int x, int y, int cx, int cy)
{
	int range = 10;
	int z = 0;
	int z1 = 0;

	/* 

	   -1 + 1 (-1 -1) x- cx

	   se resultado for < 0 multiplica (-1)

	   -2 -1 (-2 +1) x - cx

	   se resultado for < 0 multiplica (-1)

	   -1 - 2 x - cx ordena maior > menor

	   (-2+1)(*-1)

	   -5 +1 (-5-1)*(-1) x - cx

	   +2+3 x - cx ordena maior > menor

	   (3-2)


	   se resultado for < 0 multiplica por (-1)



	 */

	if (cx < 0)
	{
		if (x < 0)
		{
			if (x < cx)
			{
				z = (cx - x);
				if (z < 0)
				{
					z = z * (-1);
				}

			}
			else
			{
				z = x - cx;
				if (z < 0)
				{
					z = z * (-1);
				}

			}
		}
		else
		{
			if (x < cx)
			{
				z = (cx - x);
				if (z < 0)
				{
					z = z * (-1);
				}

			}
			else
			{
				z = x - cx;
				if (z < 0)
				{
					z = z * (-1);
				}

			}
		}
	}
	else
	{
		if (x < 0)
		{
			if (x < cx)
			{
				z = (cx - x);
				if (z < 0)
				{
					z = z * (-1);
				}

			}
			else
			{
				z = x - cx;
				if (z < 0)
				{
					z = z * (-1);
				}

			}
		}
		else
		{
			if (x < cx)
			{
				z = (cx - x);
				if (z < 0)
				{
					z = z * (-1);
				}

			}
			else
			{
				z = x - cx;
				if (z < 0)
				{
					z = z * (-1);
				}

			}
		}

	}

	// =====================

	if (cy < 0)
	{
		if (y < 0)
		{
			if (y < cy)
			{
				z1 = (cy - y);
				if (z1 < 0)
				{
					z1 = z1 * (-1);
				}

			}
			else
			{
				z1 = y - cy;
				if (z1 < 0)
				{
					z1 = z1 * (-1);
				}

			}
		}
		else
		{
			if (y < cy)
			{
				z1 = (cy - y);
				if (z1 < 0)
				{
					z1 = z1 * (-1);
				}

			}
			else
			{
				z1 = y - cy;
				if (z1 < 0)
				{
					z1 = z1 * (-1);
				}

			}
		}
	}
	else
	{
		if (y < 0)
		{
			if (y < cy)
			{
				z1 = (cy - y);
				if (z1 < 0)
				{
					z1 = z1 * (-1);
				}

			}
			else
			{
				z1 = y - cy;
				if (z1 < 0)
				{
					z1 = z1 * (-1);
				}

			}
		}
		else
		{
			if (y < cy)
			{
				z1 = (cy - y);
				if (z1 < 0)
				{
					z1 = z1 * (-1);
				}

			}
			else
			{
				z1 = y - cy;
				if (z1 < 0)
				{
					z1 = z1 * (-1);
				}

			}
		}

	}


	if ((z <= range) && (z1 <= range))
	{
		printf(" Comida proximo ( < 10)\n");
		return COMIDASIM;
	}
	else
	{
		printf(" Não Há comida\n");
		return COMIDANAO;
	}
}

void Destino(int fx, int fy, int rotax, int rotay)
{

	while ((fx != rotax) || (fy != rotay))
	{
		if (fx < rotax)
		{
			fx = Movimenta(Anda(DIREITA), fx, fy, RETX);
		}

		if (fx > rotax)
		{
			fx = Movimenta(Anda(ESQUERDA), fx, fy, RETX);
		}

		if (fy < rotay)
		{
			fy = Movimenta(Anda(FRENTE), fx, fy, RETY);
		}

		if (fy > rotay)
		{
			fy = Movimenta(Anda(TRAS), fx, fy, RETY);
		}


		printf("ponto (x:%d,y:%d)\n ", fx, fy);

	}

}

void testram()
{
	x = 0;
	int tam = 0;

	while (seed[x] != 101)
	{
		tam++;
		printf(" tam = %d\n", tam);
		x++;
	}

	x = 0;
	y = 0;

	while (x != tam)
	{
		printf(" x = %d\n y = %d\n\n", x, y);
		if (x == y)
		{
			y++;
		}

		if (seed[x] == seed[y])
		{
			printf("Numeros repetidos entre x e y. Altere y\n");
			getchar();
		}
		else
		{
			y++;
		}

		if (y == tam)
		{
			x++;
			y = 0;
		}

		if (y == (tam + 1))
		{
			x++;
			y = 0;
		}

	}

	if (x == tam)
	{
		printf(" Numeros randomicos completo 1 a 128\n");
	}

}

void cmpram()
{
	int test128[128];

	for (x = 0; x < 128; x++)
	{
		test128[x] = x;
	}

	printf("test128[0...128] = {");
	for (x = 0; x < 128; x++)
	{
		printf("%d, ", test128[x]);
		if ((x % 10) == 0)
		{
			printf("\n");
		}
	}

	printf("} ");
	x = 0;
	int tam = 0;

	while (seed[x] != 101)
	{
		tam++;
		x++;
	}

	printf(" tam = %d\n", tam);

	x = 0;
	y = 0;

	while (x < 128)
	{

		if (test128[x] == seed[y])
		{
			test128[x] = 999;
		}
		y++;
		if (y >= tam)
		{
			x++;
			y = 0;
		}
	}

	printf("test128[0...128] = {");
	for (x = 0; x < 128; x++)
	{
		if (test128[x] != 999)
		{
			printf("%d, ", test128[x]);
		}
		if ((x % 10) == 0)
		{
			printf("\n");
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

void teste1()
{
	int comida = 1;
	int cx = 10;
	int cy = 60;
	int range = 10;
	char opc;
	x = 1;
	y = 1;

	opc = 1;

	printf("Comida Local (%d,%d)\n", cx, cy);

	if ((range >= cx) && (range >= cy))
	{
		printf(" Comida proximo ( < 10)\n");
	}

	while (opc != 'n')
	{
		if (x < cx)
		{
			x = Movimenta(Anda(DIREITA), x, y, RETX);
		}

		if (x > cx)
		{
			x = Movimenta(Anda(ESQUERDA), x, y, RETX);
		}

		if (y < cy)
		{
			y = Movimenta(Anda(FRENTE), x, y, RETY);
		}

		if (y > cy)
		{
			y = Movimenta(Anda(TRAS), x, y, RETY);
		}
		if ((x == cx) && (y == cy))
		{
			printf(" Comida achado\n");
			break;
		}

		printf("opc = ");
		opc = getchar();
		printf("opc = %c\n", opc);
	}

}

void teste2()
{
	printf("Teste 1\n");
	DetectaComida(1, 1, -15, 15);
	DetectaComida(1, 1, -9, 9);
	DetectaComida(1, 1, 9, 9);
	DetectaComida(1, 1, -39, -1);
	DetectaComida(-32, 10, -39, 15);
	DetectaComida(1, 1, -15, 15);
	DetectaComida(1, 1, -15, 15);

}

void teste3()
{
	int x = 1;
	int y = 1;
	int rotax = 10;
	int rotay = 60;

	while ((x != rotax) || (y != rotay))
	{
		if (x < rotax)
		{
			x = Movimenta(Anda(DIREITA), x, y, RETX);
		}

		if (x > rotax)
		{
			x = Movimenta(Anda(ESQUERDA), x, y, RETX);
		}

		if (y < rotay)
		{
			y = Movimenta(Anda(FRENTE), x, y, RETY);
		}

		if (y > rotay)
		{
			y = Movimenta(Anda(TRAS), x, y, RETY);
		}


		printf("ponto (x:%d,y:%d)\n ", x, y);

	}

}

void teste4()
{
	int x = 1;
	int y = 1;

	Destino(x, y, 25, 10);

}

void teste5()
{
	testram();
	int test128[128];

	for (x = 0; x < 128; x++)
	{
		test128[x] = x;
	}

	printf("test128[0...128] = {");
	for (x = 0; x < 128; x++)
	{
		printf("%d, ", test128[x]);
		if ((x % 10) == 0)
		{
			printf("\n");
		}
	}

	printf("} ");
	x = 0;
	int tam = 0;

	while (seed[x] != 101)
	{
		tam++;
		x++;
	}

	printf(" tam = %d\n", tam);

	x = 0;
	y = 0;

	while (x < 128)
	{

		if (test128[x] == seed[y])
		{
			test128[x] = 999;
		}
		y++;
		if (y >= tam)
		{
			x++;
			y = 0;
		}
	}

	printf("test128[0...128] = {");
	for (x = 0; x < 128; x++)
	{
		if (test128[x] != 999)
		{
			printf("%d, ", test128[x]);
		}
		if ((x % 10) == 0)
		{
			printf("\n");
		}
	}
	
}

void teste6()
{
	testram();
	cmpram();
}