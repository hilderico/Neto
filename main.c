#include <stdio.h>
#include <stdbool.h>

int x;
int y;
int comida_x[10];
int comida_y[10];
int comida = 3;
int salvacomida = 0;

int seed0[] =
	{ 67, 3, 126, 11, 14, 92, 29, 47, 99, 86, 8, 
	12, 55, 21, 87, 110, 23, 1, 96, 57, 70,
	 17, 26, 118, 27, 74, 31, 114, 122, 6, 61, 
	 82, 41, 46, 15, 72, 52, 42, 69, 68, 4, 
	 127, 93, 30, 48, 100, 9, 13, 56, 22, 88, 
	 111, 24, 2, 97, 58, 71, 119, 28, 75, 32, 
	 115, 123, 7, 62, 83, 49, 16,
	73, 53, 43, 5, 128, 94, 76, 81, 95, 59, 106, 117, 18, 36, 50, 66, 89, 104, 116, 19, 38, 60, 80,
	102, 113, 20, 40, 65, 91, 109, 10, 44, 78, 103, 124, 37, 77, 105, 0, 51, 90, 121, 45, 98,
	25, 64, 112, 54, 108, 63, 33, 107, 84, 39, 79, 85, 120, 34, 35, 125, 101
};

int seed1[] = { 74,
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


const int FRENTE = 0;
const int DIREITA = 1;
const int TRAS = 2;
const int ESQUERDA = 3;
const int RETX = 4;
const int RETY = 5;
const int COMIDASIM = 6;
const int COMIDANAO = 7;
const int DEBUGON = 8;
const int DEBUGOFF = 9;


int Anda(int anda);
void Limite(void);
int Movimenta(int aa, int fx, int fy, int kreturn);
int DetectaComida(int x, int y, int cx, int cy);
void Destino(int *fx, int *fy, int rotax, int rotay);
void DDestino(int *fx, int *fy, int rotax, int rotay, int debug);
void testram(int seed[128]);
void cmpram(int seed[128]);
void criaseed(int seed[128]);

void teste();
void teste1();
void teste2();
void teste3();
void teste4();
void teste5();
void teste6();
void teste7();
void teste8();


int main()
{
	x = 0;
	y = 0;
	salvacomida = comida;
	
	int cont = 0;
	

	comida_x[0] = seed0[63]; // 7
	comida_x[1] = seed0[15]; // 110
	comida_x[2] = seed0[23]; // 118

	comida_y[0] = seed1[62]; // 123
	comida_y[1] = seed1[22]; // 33
	comida_y[2] = seed1[30]; // 68
	
while((comida != 0) && (cont != 127))
{
	printf("cont = %d\n",cont);
	printf("comida = %d\n", comida);
	printf("comida loc 0 = (%d,%d)\n",comida_x[0], comida_y[0]);
		printf("comida loc 1 = (%d,%d)\n",comida_x[1], comida_y[1]);
			printf("comida loc 2 = (%d,%d)\n",comida_x[2], comida_y[2]);
	
	
//	getchar();
	DDestino(&x, &y, seed0[cont], seed1[127 - cont],DEBUGOFF);
	cont++;
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

void Destino(int *fx, int *fy, int rotax, int rotay)
{
	int fcx;
	int fcy;
	int ffx = *fx;
	int ffy = *fy;
	int key = 1;

	while ((ffx != rotax) && (ffy != rotay) || (key != 0))
	{
		printf("-> %d  -> %d \n",((ffx != rotax) && (ffy != rotay)), comida != 0);
//		getchar();
		if (ffx < rotax)
		{
			ffx = Movimenta(Anda(DIREITA), ffx, ffy, RETX);
		}

		if (ffx > rotax)
		{
			ffx = Movimenta(Anda(ESQUERDA), ffx, ffy, RETX);
		}

		if (ffy < rotay)
		{
			ffy = Movimenta(Anda(FRENTE), ffx, ffy, RETY);
		}

		if (ffy > rotay)
		{
			ffy = Movimenta(Anda(TRAS), ffx, ffy, RETY);
		}

printf("comida == %d\n",comida);
printf("rotax = %d\n",rotax);
printf("rotay = %d\n",rotay);
		printf("ponto (x:%d,y:%d)\n ", ffx, ffy);

		// detecta comida() aqui
		int cc = 0;
		while (cc != comida)
		{
			fcx = comida_x[cc];
			fcy = comida_y[cc];
			if (DetectaComida(ffx, ffy, fcx, fcy) == COMIDASIM)
			{
				rotax = fcx;
				rotay = fcy;
			}
			cc++;
		}
//		if(comida != 0)
//		{
		if((ffx == fcx) && (ffy == fcy))
		{
			printf(" *fx == fcx && *fy == fcy\n");
			getchar();
			comida--;
		}
		
		if((ffx != rotax) && (ffy != rotay))
		{
			key = 0;
		}
			
//		}
		

	}
	*fx = ffx;
	*fy = ffy;

}

void DDestino(int *fx, int *fy, int rotax, int rotay, int debug)
{
	
	int fcx = 0;
	int fcy = 0;
	int confcx = 0;
	int confcy = 0;
	int fidx = 0;
	int ffx = *fx;
	int ffy = *fy;
	int key = 1;
	int dcont =0;

	while ((ffx != rotax) || (ffy != rotay) || (key != 0))
	{
		dcont++;
		printf("ffx e ffy-> %d, comida-> %d, key-> %d\n",((ffx != rotax) || (ffy != rotay)), comida != 0,key);
		if(debug == DEBUGON)
		{
			if((dcont % 10) == 0)
			{
		getchar();
			}
		}
		if (ffx < rotax)
		{
			ffx = Movimenta(Anda(DIREITA), ffx, ffy, RETX);
		}

		if (ffx > rotax)
		{
			ffx = Movimenta(Anda(ESQUERDA), ffx, ffy, RETX);
		}

		if (ffy < rotay)
		{
			ffy = Movimenta(Anda(FRENTE), ffx, ffy, RETY);
		}

		if (ffy > rotay)
		{
			ffy = Movimenta(Anda(TRAS), ffx, ffy, RETY);
		}

printf("comida == %d\n",comida);
printf("rotax = %d\n",rotax);
printf("rotay = %d\n",rotay);
		printf("ponto (x:%d,y:%d)\n ", ffx, ffy);

		// detecta comida() aqui
		int cc = 0;
		while (cc != salvacomida)
		{
			fcx = comida_x[cc];
			fcy = comida_y[cc];
			if (DetectaComida(ffx, ffy, fcx, fcy) == COMIDASIM)
			{
				rotax = fcx;
				rotay = fcy;
				confcx = fcx;
				confcy = fcy;
				fidx = cc;
			}
			cc++;
			printf("while (cc != comida)\n");
		}
//		if(comida != 0)
//		{
		printf("ffx = %d\n",ffx);
		printf("confcx = %d\n",confcx);
		printf("ffy = %d\n",ffy);
		printf("confcy = %d\n",confcy);
		if((ffx == confcx) && (ffy == confcy))
		{
			printf(" *fx == fcx && *fy == fcy\n");
			if(debug == DEBUGON)
			{
			getchar();
			}
			comida--;
			comida_x[fidx] = 999;
			comida_y[fidx] = 999;
		}
		
		if((ffx == rotax) && (ffy == rotay))
		{
			key = 0;
			printf("if((ffx == rotax) && (ffy == rotay))\n");
		}
			
//		}
		

	}
	*fx = ffx;
	*fy = ffy;
	printf("*fx = ffx;\n*fy = ffy;\n");

}


void testram(int seed[128])
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

void cmpram(int seed[128])
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

void criaseed(int seed[128])
{
	int test128[128];

	for (x = 0; x < 128; x++)
	{
		test128[x] = 0;
	}

	for (x = 0; x < 128; x++)
	{
		test128[x] = seed[x] + 7;
		if (test128[x] > 128)
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

	Destino(&x, &y, 25, 10);

}

void teste5()
{
	testram(seed0);
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

	while (seed0[x] != 101)
	{
		tam++;
		x++;
	}

	printf(" tam = %d\n", tam);

	x = 0;
	y = 0;

	while (x < 128)
	{

		if (test128[x] == seed0[y])
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
	testram(seed0);
	cmpram(seed0);
}

void teste7()
{
	int test128[128];

	for (x = 0; x < 128; x++)
	{
		test128[x] = 0;
	}

	for (x = 0; x < 128; x++)
	{
		test128[x] = seed1[x] + 7;
		if (test128[x] > 128)
		{
			test128[x] = seed1[x] % 129;
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

}

void teste8()
{
		x = 0;
	y = 0;
	
	int cont = 0;
	

	comida_x[0] = seed0[63]; //123
	comida_x[1] = seed0[15]; // 110
	comida_x[2] = seed0[23]; //118

	comida_y[0] = seed1[62]; //123
	comida_y[1] = seed1[22]; //22
	comida_y[2] = seed1[30]; //30
	
while((comida != 0) && (cont != 127))
{
	printf("cont = %d\n",cont);
	printf("comida = %d\n", comida);
	printf("comida loc 0 = (%d,%d)\n",comida_x[0], comida_y[0]);
		printf("comida loc 1 = (%d,%d)\n",comida_x[1], comida_y[1]);
			printf("comida loc 2 = (%d,%d)\n",comida_x[2], comida_y[2]);
	
	
//	getchar();
	Destino(&x, &y, seed0[cont], seed1[cont]);
	cont++;
}
	
	
}
