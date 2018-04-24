#include <iostream>
#include <cstdlib>
#include <string>
#include <random>

using namespace std;

class Veiculo
{
	protected:
		bool fab;//Indicativo de fabrica
		int g_factor;//Parametro para determinar qual veiculo sobrevive na colisao
		int velocidade;//velocidade
		int pos_x;//posicao no eixo horizontal do mapa
		int pos_y;//posicao no eixo vertical do mapa
	public:
		Veiculo(int a, int b)//construtor Veiculo
		{
			fab = true;
			velocidade = 1;
			pos_x = a;
			pos_y = b;

		}
		void setFab(bool a)//define o indicativo de fabrica
		{
			this->fab = a;
		}
		bool getFab()//obtem o indicativo de fabrica
		{
			return this->fab;
		}
		int getPos_y()//Obter posicao no eixo y
		{
			return pos_y;
		}
		int getPos_x()//obter posicao no eixo x
		{
			return pos_x;
		}
		int p_cima()//mover para cima
		{
			if(this->pos_y - velocidade >= 0)
			{
			return (this->pos_y - velocidade);
			}
			else
			{
				return (29 - (this->pos_y - velocidade)*(-1));
			}
		}
		int p_baixo()//mover para baixo
		{
			if(this->pos_y + velocidade < 29)
			{
			return (this->pos_y + velocidade);
			}
			else
			{
				return (this->pos_y + velocidade - 29);
			}
		}

		int p_direita()//mover para a direita
		{
			if(this->pos_x + velocidade < 59)
			{
				return (this->pos_x + velocidade);
			}
			else
				{	
				return (this->pos_x + velocidade - 59);
			}
		}
		int p_esquerda()//mover para a esquerda
		{
			if(this->pos_x + velocidade > 0)
			{
				return (this->pos_x - velocidade);
			}
			else
			{
				return (59 - (this->pos_x - velocidade)*(-1));
			}
		}

		void move(int a)// Seleciona aleatoriamente para onde o veiculo se move
		{
			if(a == 1)
			{
				this->pos_y = p_cima();
			}
			if(a == 2)
			{
				this->pos_y = p_baixo();
			}
			if(a == 3)
			{
				this->pos_x = p_direita();
			}
			if(a == 4)
			{
				this->pos_x = p_esquerda();
			}

		}

		int getVelocidade()// Obtem velocidade
		{
			return velocidade;
		}
		int getG_factor()// Obtem g_factor
		{
			return g_factor;
		}

};

class Carro: public Veiculo// Cria Classe Carro
{
	private:
		int velocidade;
		int g_factor;
	public:
		Carro(int a, int b): Veiculo(a, b)// Construtor classe carro
		{
			this->velocidade = 2;
			this->g_factor = 2;
		}
		int getVelocidade()// obtem velocidade do carro
		{
			return velocidade;
		}
		int getG_factor()// obtem g_factor do carro
		{
			return g_factor;
		}
};

class Moto: public Veiculo// Cria classe Moto
{
	private:
		int velocidade;
		int g_factor;
	public:
		Moto(int a, int b): Veiculo(a, b)// Construtor da classe Moto
		{
			this->velocidade = 3;
			this->g_factor = 1;
		}
		int getVelocidade()//Obtem velocidade da moto
		{
			return velocidade;
		}
		int getG_factor()//obtem g_factor da moto
		{
			return g_factor;
		}
};

class Caminhao: public Veiculo// Cria classe caminhao
{
	private:
		int velocidade;
		int g_factor;
	public:
		Caminhao(int a, int b): Veiculo(a, b)// Construtor da classe Caminhao
		{
			this->velocidade = 1;
			this->g_factor = 3;
		}
		int getVelocidade()// Obtem velocidade do caminhao
		{
			return velocidade;
		}
		int getG_factor()//Obtem g_factor do caminhao
		{
			return g_factor;
		}
};
