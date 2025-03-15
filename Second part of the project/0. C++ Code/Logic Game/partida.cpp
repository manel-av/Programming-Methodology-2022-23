#include "partida.h"

// Inicializa el tablero del juego a partir de un archivo
void Partida::inicialitza(const string& nomFitxer)
{
	ifstream file;
	Candy c;
	int mov, obj;
	file.open(nomFitxer);
	if (file.is_open())
	{
		int i = 0;
		file >> c >> obj >> mov;
		caramel = c; quantitat = obj; moviments = mov;
		file >> c;
		while (!file.eof() and i < MAX_FILES)
		{
			for (int j = 0; j < MAX_COLUMNES; j++)
			{
				m_tauler.setCandy(c, i, j);
				file >> c;
			}
			i++;
		}
	}
	file.close();
	m_tauler.setProximCandy(0);
	puntuacio = 0;
}


// Escribe tablero en un archivo
void Partida::escriuTauler(const string& nomFitxer)
{
	ofstream file;
	string lletra;
	file.open(nomFitxer);
	if (file.is_open())
	{
		for (int i = 0; i < MAX_FILES; i++)
		{
			for (int j = 0; j < MAX_COLUMNES; j++)
			{
				if (m_tauler.getCandy(i, j).getColor() == NO_COLOR)
					file << "-";
				else
					lletra = m_tauler.getCandy(i, j).conversor(m_tauler.getCandy(i, j).getColor());  file << lletra << " ";
			}
			if (i < MAX_FILES - 1) {
				file << endl;
			}
		}
	}
	file.close();
}

void Partida::dibuixa()
{
	string msg1 = "Puntuacio: " + to_string(puntuacio);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, PUNTS_INIT_X, PUNTS_INIT_Y, 1.0, msg1);

	string msg2 = "Moviments: " + to_string(moviments);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, MOVIMENTS_INIT_X, MOVIMENTS_INIT_Y, 1.0, msg2);
	caramel.dibuixaCaramel( 8, -2);
	string msg3 = to_string(quantitat);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, OBJECTIU_INIT_X, OBJECTIU_INIT_Y, 1.0, msg3);
	
	m_tauler.dibuixaTauler();
}

bool Partida::iniciaMoviment(const Posicio& pos1, const Posicio& pos2)
{
	Posicio posInV, posFinV, posInH, posFinH;
	int num;
	Candy candy;
	m_tauler.intercanviaCaramel(pos1, pos2);
	if(moviments > 0)
		moviments--;
	if (!m_tauler.cercaPosVertical(posInV, posFinV, num, candy) and !m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
	{
		m_tauler.intercanviaCaramel(pos2, pos1);
		moviments++;
		return false;
	}
	return true;
}

void Partida::continuaMoviment(const Posicio& pos1, const Posicio& pos2, const int& paso, bool& continua, TipusMatch& match)
{
	Posicio posInV, posFinV, posInH, posFinH;
	int num, num1, num2;
	Candy candy;
	
	if (paso == 0 and continua)
	{
		match = MATCHING_SECUNDARI;
	}
	
	switch (paso)
	{
	case 0:
		while (m_tauler.cercaPosVertical(posInV, posFinV, num, candy) or m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
		{
			switch (match)
			{
			case MATCHING_PRIMARI: // Cuando es el jugador el que hace la alineación
				if (m_tauler.cercaPosVertical(posInV, posFinV, num1, candy) and m_tauler.cercaPosHoritzontal(posInH, posFinH, num2, candy))
				{
					m_tauler.cercaPosVertical(posInV, posFinV, num1, candy);
					m_tauler.cercaPosHoritzontal(posInH, posFinH, num2, candy);
					m_tauler.eliminaCaramel(posInV, posFinV, VERTICAL);
					m_tauler.eliminaCaramel(posInH, posFinH, HORIZONTAL);
					if (candy == caramel)
					{
						puntuacio += 20 * num1;
						puntuacio += 20 * num2;
						quantitat = quantitat - num1 - num2 + 1;
					}
					else
					{
						puntuacio += 10 * num1;
						puntuacio += 10 * num2;
					}
					if (posInH.getFila() != -1)
					{
						m_tauler.aparicioRatllat(pos1, pos2, posInH, posFinH, num, candy);
					}
					if (posInV.getFila() != -1)
					{
						m_tauler.aparicioRatllat(pos1, pos2, posInV, posFinV, num, candy);
					}
				}
				else
				{
					if (m_tauler.cercaPosVertical(posInV, posFinV, num, candy))
					{
						m_tauler.cercaPosVertical(posInV, posFinV, num, candy);
						m_tauler.eliminaCaramel(posInV, posFinV, VERTICAL);
						if (candy == caramel)
						{
							puntuacio += 20 * num;
							quantitat -= num;
						}
						else
						{
							puntuacio += 10 * num;
						}
						m_tauler.aparicioRatllat(pos1, pos2, posInV, posFinV, num, candy);
					}
					if (m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
					{
						m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy);
						m_tauler.eliminaCaramel(posInH, posFinH, HORIZONTAL);
						if (candy == caramel)
						{
							puntuacio += 20 * num;
							quantitat -= num;
						}
						else
						{
							puntuacio += 10 * num;
						}
						m_tauler.aparicioRatllat(pos1, pos2, posInH, posFinH, num, candy);
					}
				}
				break;
			case MATCHING_SECUNDARI: // Cuando la alineación es producida por "cascada"
				if (m_tauler.cercaPosVertical(posInV, posFinV, num1, candy) and m_tauler.cercaPosHoritzontal(posInH, posFinH, num2, candy))
				{
					m_tauler.cercaPosVertical(posInV, posFinV, num1, candy);
					m_tauler.cercaPosHoritzontal(posInH, posFinH, num2, candy);
					m_tauler.eliminaCaramel(posInV, posFinV, VERTICAL);
					m_tauler.eliminaCaramel(posInH, posFinH, HORIZONTAL);
					if (candy == caramel)
					{
						puntuacio += 20 * num1;
						puntuacio += 20 * num2;
					}
					else
					{
						puntuacio += 10 * num1;
						puntuacio += 10 * num2;
					}
					if (posInH.getFila() != -1)
					{
						if (num >= 4)
						{
							candy.setTipus(RATLLAT_HORIZONTAL);
							m_tauler.setCandy(candy, posInH.getFila(), posInH.getColumna());
						}
					}
					if (posInV.getFila() != -1)
					{
						if (num >= 4)
						{
							candy.setTipus(RATLLAT_VERTICAL);
							m_tauler.setCandy(candy, posInV.getFila(), posInV.getColumna());
						}
					}
				}
				else
				{
					if (m_tauler.cercaPosVertical(posInV, posFinV, num, candy))
					{
						m_tauler.cercaPosVertical(posInV, posFinV, num, candy);
						m_tauler.eliminaCaramel(posInV, posFinV, VERTICAL);
						if (candy == caramel)
						{
							puntuacio += 20 * num;
						}
						else
						{
							puntuacio += 10 * num;
						}
						if (num >= 4)
						{
							candy.setTipus(RATLLAT_VERTICAL);
							m_tauler.setCandy(candy, posInV.getFila(), posInV.getColumna());
						}
					}
					if (m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
					{
						m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy);
						m_tauler.eliminaCaramel(posInH, posFinH, HORIZONTAL);
						if (candy == caramel)
						{
							puntuacio += 20 * num;
						}
						else
						{
							puntuacio += 10 * num;
						}
						if (num >= 4)
						{
							candy.setTipus(RATLLAT_HORIZONTAL);
							m_tauler.setCandy(candy, posInH.getFila(), posInH.getColumna());
						}
					}
				}
				break;
			}

		}
		break;
	case 1:
		m_tauler.desplaçaCaramel();
		break;
	case 2:
		m_tauler.generaCaramel();
		break;
	case 3:
		if (m_tauler.cercaPosVertical(posInV, posFinV, num, candy) or m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
		{
			continua = true;
		}
		else
			continua = false;
		break;
	default:
		break;
	}
}