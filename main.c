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

int Anda(int anda);
void Limite(void);
int Movimenta(int aa, int fx, int fy, int kreturn);
int DetectaComida(int x, int y, int cx, int cy);
void Destino(int fx,int fy, int rotax, int rotay);

void teste();
void teste1();
void teste2();
void teste3();


int main()
{
int x = 1;
int y = 1;

Destino(x,y,25,10);
	
	
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

	   -1 + 1 (-1 -1)
	   x- cx

	   se resultado for < 0 multiplica (-1)

	   -2 -1 (-2 +1)
	   x - cx

	   se resultado for < 0 multiplica (-1)

	   -1 - 2
x - cx
	   ordena maior > menor

	   (-2+1)(*-1)

	   -5 +1 (-5-1)*(-1)
	   x - cx

	   +2+3
x - cx
	   ordena maior > menor

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
	
	//=====================
	
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
					z1= z1 * (-1);
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


	if (( z <= range)&& (z1 <= range))
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

void Destino(int fx,int fy, int rotax, int rotay)
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


		printf("ponto (x:%d,y:%d)\n ",fx,fy);

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
	DetectaComida(1,1,-15,15);
	DetectaComida(1,1,-9,9);
	DetectaComida(1,1,9,9);
	DetectaComida(1,1,-39,-1);
	DetectaComida(-32,10,-39,15);
	DetectaComida(1,1,-15,15);
	DetectaComida(1,1,-15,15);
	
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


		printf("ponto (x:%d,y:%d)\n ",x,y);

	}

}