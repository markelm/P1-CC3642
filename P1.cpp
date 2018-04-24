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
						{1,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
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
						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

		vector <Carro*> cH;// Cria vetor base onde os objetos Carro serao inicializados
		vector <Caminhao*> tH;// Cria vetor base onde os objetos Caminhao serao inicializados
		vector <Moto*> mH;// Cria vetor base onde os objetos Moto serao inicializados
		vector <Carro> c;// Vetor carro que pode ser acessador estaticamente
		vector <Caminhao> t;// Vetor caminhao que pode ser acessador estaticamente
		vector <Moto> m;// Vetor moto que pode ser acessador estaticamente
		vector <Moto> m_buffer;//Vetor utilizado para alocar temporariamente as motos que nao sofrem colisoes e depois devolver para o vetor m
		vector <Carro> c_buffer;//Vetor utilizado para alocar temporariamente os carro que sobrevivem as colisoes
		vector <Caminhao> t_buffer;//Vetor utilizado para alocar temporariamente os caminhoes que sobrevivem as colisoes
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
			
//_____________COLISAO ENTRE MOTOS E OUTROS VEICULOS_________________________________________________________
			for(p=0;p<m.size();p++)//Verifica Colisao de motos entre si
				{
					for(q=0;q<m.size();q++)
					{
						if((m.at(p).getPos_x() == m.at(q).getPos_x()) && (m.at(p).getPos_y() == m.at(q).getPos_y()) && (p != q)) //ignora o objeto que sofreu colisao
						{
							break;
						}
						else
						{
							m_buffer.push_back(m.at(p)); // armazena os objetos que nao sofreram colisao no vetor m_buffer
						}
					}
				}
				m.clear();// limpa (temporariamente) o vetor m
				for(p=0;p<m_buffer.size();p++)
				{
					m.push_back(m_buffer.at(p));// devolve os objetos Moto que sobreviveram para o vetor m
				}
				m_buffer.clear();
				for(p=0;p<m.size();p++)//Verifica colisao de motos com carros
				{
					for(q=0;q<c.size();q++)
					{
						if((m.at(p).getPos_x() == c.at(q).getPos_x()) && (m.at(p).getPos_y() == c.at(q).getPos_y())) //ignora o objeto que sofreu colisao
						{
							break;
						}
						else
						{
							m_buffer.push_back(m.at(p)); // armazena os objetos que nao sofreram colisao no vetor m_buffer
						}
					}
				}
				m.clear(); //limpa (temporariamente) o vetor m
				for(p=0;p<m_buffer.size();p++)
				{
					m.push_back(m_buffer.at(p)); // devolve para o vetor m os objetos para o vetor m menos os que foram excluidos na cosisao
				}
				m_buffer.clear();// limpa o vetor  m_buffer

				for(p=0;p<m.size();p++)//Verifica colisao de motos com caminhoes
				{
					for(q=0;q<t.size();q++)
					{
						if((m.at(p).getPos_x() == t.at(q).getPos_x()) && (m.at(p).getPos_y() == t.at(q).getPos_y()))
						{
							break;
						}
						else
						{
							m_buffer.push_back(m.at(p)); // armazena os objetos que nao sofreram colisao no vetor m_buffer
						}
					}
				}
				m.clear();//limpa (temporariamente) o vetor m
				for(p=0;p<m_buffer.size();p++)
				{
					m.push_back(m_buffer.at(p));// devolve os objetos Moto que sobreviveram para o vetor m
				}
				m_buffer.clear();//limpa o vetor m_buffer
//__________________________________________________________________________________________________________________________

//_____________COLISAO ENTRE CARROS E OUTROS VEICULOS________________________________________________________________________

				for(p=0;p<c.size();p++)//Verifica Colisao de carros entre si
				{
					for(q=0;q<c.size();q++)
					{
						if((c.at(p).getPos_x() == c.at(q).getPos_x()) && (c.at(p).getPos_y() == c.at(q).getPos_y()) && (p != q)) //ignora o objeto que sofreu colisao
						{
							break;
						}
						else
						{
							c_buffer.push_back(c.at(p));// armazena os objetos que nao sofreram colisao no vetor c_buffer
						}
					}
				}
				c.clear();
				for(p=0;p<c_buffer.size();p++)
				{
					c.push_back(c_buffer.at(p));
				}
				c_buffer.clear();

				for(p=0;p<c.size();p++)//Verifica Colisao entre carros e caminhoes
				{
					for(q=0;q<t.size();q++)
					{
						if((c.at(p).getPos_x() == t.at(q).getPos_x()) && (c.at(p).getPos_y() == t.at(q).getPos_y()))
						{
							break;
						}
						else
						{
							c_buffer.push_back(c.at(p));
						}
					}
				}
				c.clear();//limpa (temporariamennte o vetor c)
				for(p=0;p<c_buffer.size();p++)
				{
					c.push_back(c_buffer.at(p));// devolve para o vetor c os objetos para o vetor m menos os que foram excluidos na cosisao
				}
				c_buffer.clear();// limpa o vetor c_buffer
//__________________________________________________________________________________________________________________________

//_____________COLISAO DE CAMINHOES ENTRE SI________________________________________________________________________________

			for(p=0;p<t.size();p++)
				{
					for(q=0;q<t.size();q++)
					{
						if((t.at(p).getPos_x() == t.at(q).getPos_x()) && (t.at(p).getPos_y() == t.at(q).getPos_y()) && (p != q))
						{
							break;
						}
						else
						{
							t_buffer.push_back(t.at(p));
						}
					}
				}
				t.clear();//limpa temporariamente o vetor t
				for(p=0;p<t_buffer.size();p++)
				{
					t.push_back(t_buffer.at(p)); // devolve para o vetor c os objetos para o vetor m menos os que foram excluidos na cosisao
				}
				t_buffer.clear();// limpa o vetor t_bufer

//__________________________________________________________________________________________________________________________*/

				for(i=0;i<30;i++)
				{
					for(j=0;j<60;j++)
					{
						
						for(k=0;k<c.size();k++)
						{
							if((t.at(k).getPos_y() == i) && (t.at(k).getPos_x() == j))// imprime no mapa o objeto caminhao
							{
								cout << "\033[47m \033[0m";
								if(map[i][j] == 2)//Cria Caminhao quando o objeto passa pela fabrica
								{
									tH.push_back(new Caminhao(dist(rng), dist2(rng)));
									t.push_back(*(tH.at(0)));
									tH.clear();
								}
								j += 1;
							}
							else 
								{
									if((c.at(k).getPos_y() == i) && (c.at(k).getPos_x() == j))// imprime no mapa o objeto carro
									{
										cout << "\033[46m \033[0m";
									if(map[i][j] == 2)//Cria Carro quando o objeto passa pela fabrica
									{
										cH.push_back(new Carro(dist(rng), dist2(rng)));
										c.push_back(*(cH.at(0)));
										cH.clear();
									}
										j += 1;
									}

									else
									{
										if((m.at(k).getPos_y() == i) && (m.at(k).getPos_x() == j))// imprime no mapa o objeto carro
										{
											cout << "\033[43m \033[0m";
										if(map[i][j] == 2)//Cria Moto quando o objeto passa pela fabrica
										{
											mH.push_back(new Moto(dist(rng), dist2(rng)));
											m.push_back(*(mH.at(0)));
											mH.clear();
										}
											j += 1;
										}
									}
								}

						}
						
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