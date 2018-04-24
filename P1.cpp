#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "p1.h"

using namespace std;

int main()
{
	mt19937 rng;
    rng.seed(std::random_device()());
    uniform_int_distribution<mt19937::result_type> dist(1,59);// Gera numero aleatorio para determinar a posicao inicial no eixo horizontal do veiculo
    uniform_int_distribution<mt19937::result_type> dist2(1,29);// Gera numero aleatorio para determinar a posicao inicial no eixo vertical do veiculo
    uniform_int_distribution<mt19937::result_type> dist3(1,4);// Gera numero aleatorio para determinar para onde o veiculo se  move

	int x;
	int i;
	int j;
	int p;
	int q;

		int y = 30;
		int z = 60;
		int map[30][60] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

		vector <Carro*> cH;// Cria vetor base onde os objetos Carro serao inicializados
		vector <Caminhao*> tH;// Cria vetor base onde os objetos Caminhao serao inicializados
		vector <Moto*> mH;// Cria vetor base onde os objetos Moto serao inicializados
		vector <Carro> c;// Vetor carro que pode ser acessador estaticamente
		vector <Caminhao> t;// Vetor caminhao que pode ser acessador estaticamente
		vector <Moto> m;// Vetor moto que pode ser acessador estaticamente
		vector <int> motos;//Vetor para guardar os indices das motos que sao destruidas
		vector <int> carros;//Vetor para guardar os indices dos carros que sao destruidos
		vector <int> caminhoes;//Vetor para guardar os indices dos caminhoes que sao destruidos
		for(i=0;i<10;i++)
		{
			cH.push_back(new Carro(dist(rng), dist2(rng)));//Cria objeto carro dentro do vetor cH
			c.push_back(*(cH.at(i)));//armazena o objeto carro criado no vetor c
		}
		for(i=0;i<10;i++)
		{
			tH.push_back(new Caminhao(dist(rng), dist2(rng)));//Cria objeto Moto no vetor tH
			t.push_back(*(tH.at(i)));//armazena o objeto criado acima no no vetor t
		}
		for(i=0;i<10;i++)
		{
			mH.push_back(new Moto(dist(rng), dist2(rng)));//Cria objeto Moto no vetor mH
			m.push_back(*(mH.at(i)));//armazena o objeto criado acima no no vetor m
		}
		cH.clear();//limpa o vetor cH
		tH.clear();//limpa o vetor th
		mH.clear();//limpa o vetor mH

		int k;

		while(true)
		{
				for(i=0;i<30;i++)
				{
					for(j=0;j<60;j++)
					{
						
						for(k=0;k<t.size();k++)
						{
							if((t.at(k).getPos_y() == i) && (t.at(k).getPos_x() == j))// imprime no mapa o objeto caminhao
							{
								cout << "\033[47m \033[0m";//Imprime o caminhao no mapa na cor branca
								if((map[i][j] == 2) && (t.at(k).getFab() == true))//Cria Caminhao quando o objeto passa pela fabrica
								{
									t.at(k).setFab(false);//set o indicativo de fabrica para falso
									tH.push_back(new Caminhao(dist(rng), dist2(rng)));//Cria um novo objeto caminhao e adiciona-o ao vetor mH
								}
								if((map[i][j] == 1) && (t.at(k).getFab() == false))//set o indicativo de fabrica para verdadeiro
								{
									t.at(k).setFab(true);
								}
								j += 1;
							}
						}
						for(k=0;k<tH.size();k++)
						{
							t.push_back(*(tH.at(0)));//Adiciona ao vetor t os novos objectos Caminhao criados
						}
						tH.clear();//limpa o vetor tH
						for(k=0;k<c.size();k++)
						{
							if((c.at(k).getPos_y() == i) && (c.at(k).getPos_x() == j))// imprime no mapa o objeto carro
							{
								cout << "\033[46m \033[0m";//Imprime o carro no mapa na cor cyan
								if((map[i][j] == 2) && (c.at(k).getFab() == true))//Cria Carro quando o objeto passa pela fabrica
								{
									c.at(k).setFab(false);//set o indicativo de fabrica para falso
									cH.push_back(new Carro(dist(rng), dist2(rng)));// Cria um novo objeto carro e adiciona-o a cH
								}
								if((map[i][j] == 1) && (c.at(k).getFab() == false))
								{
									c.at(k).setFab(true);// set o indicativo de fabrica para verdadeiro
								}
								j += 1;
							}
						}
						for(k=0;k<cH.size();k++)
						{
							c.push_back(*(cH.at(0)));//Adiciona ao vetor c os novos objetos Carro criados
						}
						cH.clear();//limpa o vetor cH

						for(k=0;k<m.size();k++)
						{
							if((m.at(k).getPos_y() == i) && (m.at(k).getPos_x() == j))// imprime no mapa o objeto carro
							{
										cout << "\033[43m \033[0m";//Imprime a moto no mapa na cor amarela
									if((map[i][j] == 2) && (m.at(k).getFab() == true))//Cria Moto quando o objeto passa pela fabrica
									{
										m.at(k).setFab(false);//set o indicativo de fabrica para falso
										mH.push_back(new Moto(dist(rng), dist2(rng)));//cria novo objeto Moto e adiciona-o a mH
									}
									if((map[i][j] == 1) && (m.at(k).getFab() == false))
									{
										m.at(k).setFab(true);//set o indicativo de fabrica para verdadeiro
									}
									j += 1;
							}
						}
						for(k=0;k<mH.size();k++)
						{
							m.push_back(*(mH.at(0)));// Adiciona os novos objetos Moto criados ao vetor m
						}
						mH.clear();// limpa o vetor mH

						//Preenche o mapa
						
							if(map[i][j] == 1)
							{
								cout << "\033[42m \033[0m";
								if(j==59)
								{
									puts("");
								}
							}
							if(map[i][j] == 0)
							{
								cout << "\033[40m \033[0m";
							}
							if(map[i][j] == 2)
							{
								cout << "\033[41m \033[0m";
							}
						
					}
				}

//_____________COLISAO ENTRE MOTOS E OUTROS VEICULOS_________________________________________________________
				for(p=0;p<m.size();p++)//Verifica Colisao de motos entre si
				{
					for(q=0;q<m.size();q++)
					{
						if((m.at(p).getPos_x() == m.at(q).getPos_x()) && (m.at(p).getPos_y() == m.at(q).getPos_y()) && (p != q)) //guarda o indice das motos deletadas
						{
							motos.push_back(p);
						}
					}
				}
				int n = 0;
				for(p=0;p<motos.size();p++)
				{
					m.erase(m.begin() + motos.at(p) - n);//deleta as motos que nao sobreviveram
					n += 1;
				}
				motos.clear();// limpa o vetor motos que guarda o indice das motos que foram deletadas
				for(p=0;p<m.size();p++)//Verifica colisao de motos com carros
				{
					for(q=0;q<c.size();q++)
					{
						if((m.at(p).getPos_x() == c.at(q).getPos_x()) && (m.at(p).getPos_y() == c.at(q).getPos_y())) //guarda o indice das motos deletadas
						{
							motos.push_back(p);
						}
					}
				}

				n = 0;
				for(p=0;p<motos.size();p++)
				{
					m.erase(m.begin() + motos.at(p) - n);//deleta as motos que nao sobreviveram
					n += 1;
				}
				motos.clear();// limpa o vetor motos que guarda o indice das motos que foram deletadas

				for(p=0;p<m.size();p++)//Verifica colisao de motos com caminhoes
				{
					for(q=0;q<t.size();q++)
					{
						if((m.at(p).getPos_x() == t.at(q).getPos_x()) && (m.at(p).getPos_y() == t.at(q).getPos_y()))//guarda o indice das motos deletadas
						{
							motos.push_back(p);
						}
					}
				}

				n = 0;
				for(p=0;p<motos.size();p++)
				{
					m.erase(m.begin() + motos.at(p) - n);//deleta as motos que nao sobreviveram
					n += 1;
				}
				motos.clear();// limpa o vetor motos que guarda o indice das motos que foram deletadas
//__________________________________________________________________________________________________________________________

//_____________COLISAO ENTRE CARROS E OUTROS VEICULOS________________________________________________________________________

				for(p=0;p<c.size();p++)//Verifica Colisao de carros entre si
				{
					for(q=0;q<c.size();q++)
					{
						if((c.at(p).getPos_x() == c.at(q).getPos_x()) && (c.at(p).getPos_y() == c.at(q).getPos_y()) && (p != q)) //guarda o indice dos carros deletados
						{
							carros.push_back(p);
						}
					}
				}

				n = 0;
				for(p=0;p<carros.size();p++)
				{
					c.erase(c.begin() + carros.at(p) - n);//deleta os carros que nao sobreviveram
					n += 1;
				}
				carros.clear();//limpa o vetor carros que guarda os indices dos carros que nao sobreviveram

				for(p=0;p<c.size();p++)//Verifica Colisao entre carros e caminhoes
				{
					for(q=0;q<t.size();q++)
					{
						if((c.at(p).getPos_x() == t.at(q).getPos_x()) && (c.at(p).getPos_y() == t.at(q).getPos_y()))//guarda o indice dos carros deletados
						{
							carros.push_back(p);
						}
					}
				}

				n = 0;
				for(p=0;p<carros.size();p++)
				{
					c.erase(c.begin() + carros.at(p) - n);//deleta os carros que nao sobreviveram
					n += 1;
				}
				carros.clear();//limpa o vetor carros que guarda os indices dos carros que nao sobreviveram
//__________________________________________________________________________________________________________________________

//_____________COLISAO DE CAMINHOES ENTRE SI________________________________________________________________________________

			for(p=0;p<t.size();p++)
				{
					for(q=0;q<t.size();q++)
					{
						if((t.at(p).getPos_x() == t.at(q).getPos_x()) && (t.at(p).getPos_y() == t.at(q).getPos_y()) && (p != q))
						{
							caminhoes.push_back(p);
						}
					}
				}

				n = 0;
				for(p=0;p<caminhoes.size();p++)
				{
					t.erase(t.begin() + caminhoes.at(p) - n);//deleta os caminhoes que nao sobreviveram
					n += 1;
				}
				caminhoes.clear();//limpa o vetor caminhoes que guarda os indices dos caminhoes que nao sobreviveram

//__________________________________________________________________________________________________________________________



				for(k=0;k<c.size();k++)// move os objetos carro
				{
					c.at(k).move(dist3(rng));
				}
				for(k=0;k<m.size();k++)// move os objetos moto
				{
					m.at(k).move(dist3(rng));
				}
				for(k=0;k<t.size();k++)// move os objetos caminhao
				{
					t.at(k).move(dist3(rng));
				}



				system("clear");
		}

	return 0;
}