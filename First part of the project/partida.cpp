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


// Se encarga de hacer un movimiento en el tablero
void Partida::fesMoviment(const Posicio& pos1, const Posicio& pos2)
{
	Posicio posInV, posFinV, posInH, posFinH;
	int num;
	Candy candy;
	TipusMatch match = MATCHING_PRIMARI;
	m_tauler.intercanviaCaramel(pos1, pos2);
	// Se intercambia un caramelo, si no hay una alineación vuelve a su sitio.
	if (!m_tauler.cercaPosVertical(posInV, posFinV, num, candy) and !m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
	{
		m_tauler.intercanviaCaramel(pos2, pos1);
	}
	else
	{
		do // Bucle para comprobar si hay alineaciones despues de desplazar y generar nuevos caramelos
		{
			// Bucle para comprobar si hay alineaciones para eliminarlas todas antes de empezar a desplazar caramelos
			while (m_tauler.cercaPosVertical(posInV, posFinV, num, candy) or m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
			{
				switch (match)
				{
				case MATCHING_PRIMARI: // Cuando es el jugador el que hace la alineación
					if (m_tauler.cercaPosVertical(posInV, posFinV, num, candy))
					{
						m_tauler.cercaPosVertical(posInV, posFinV, num, candy);
						m_tauler.eliminaCaramel(posInV, posFinV, VERTICAL);
						m_tauler.aparicioRatllat(pos1, pos2, posInV, posFinV, num, candy);
					}
					if (m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
					{
						m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy);
						m_tauler.eliminaCaramel(posInH, posFinH, HORIZONTAL);
						m_tauler.aparicioRatllat(pos1, pos2, posInH, posFinH, num, candy);
					}
					break;
				case MATCHING_SECUNDARI: // Cuando la alineación es producida por "cascada"
					if (m_tauler.cercaPosVertical(posInV, posFinV, num, candy))
					{
						m_tauler.cercaPosVertical(posInV, posFinV, num, candy);
						m_tauler.eliminaCaramel(posInV, posFinV, VERTICAL);
						if (num >= 4)
						{
							candy.setTipus(RATLLAT_VERTICAL);
							m_tauler.setCandy(candy, posInH.getFila(), posInH.getColumna());
						}
					}
					if (m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy))
					{
						m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy);
						m_tauler.eliminaCaramel(posInH, posFinH, HORIZONTAL);
						if (num >= 4)
						{
							candy.setTipus(RATLLAT_HORIZONTAL);
							m_tauler.setCandy(candy, posInH.getFila(), posInH.getColumna());
						}
					}
					break;
				}
				match = MATCHING_SECUNDARI;
			}
			m_tauler.desplaçaCaramel();
			m_tauler.generaCaramel();

		} while (m_tauler.cercaPosVertical(posInV, posFinV, num, candy) or m_tauler.cercaPosHoritzontal(posInH, posFinH, num, candy));
	}
}