#include "tauler.h"

// Constructor de la clase Tauler
Tauler::Tauler()
{
	nProximCandy = 0;
	for (int i = 0; i < MAX_FILES; i++)
	{
		for (int j = 0; j < MAX_COLUMNES; j++)
		{
			m_tauler[i][j].setColor(NO_COLOR);
			m_tauler[i][j].setTipus(NO_TIPUS);
		}
	}
}


// Getter para obtener un caramelo de una posición del tablero
Candy Tauler::getCandy(int fila, int columna)
{
	return m_tauler[fila][columna];
}


// Método para eliminar una alineación de caramelos
void Tauler::eliminaCaramel(const Posicio& posIn, const Posicio& posFin, const Direccio& direccio)
{
	switch (direccio) // Sirve para indicar que dirección tiene la alineación
	{
	case HORIZONTAL:
		// Bucle para reccorer cada posición de la alineación. Dentro se compueba el tipo de caramelo para saber como lo tiene que eliminar
		for (int i = posIn.getColumna(); i <= posFin.getColumna(); i++)
		{
			if (m_tauler[posIn.getFila()][i].getTipus() != NORMAL)
			{
				if (m_tauler[posIn.getFila()][i].getTipus() == RATLLAT_HORIZONTAL)
				{
					for (int k = 0; k < MAX_COLUMNES; k++)
					{
						m_tauler[posIn.getFila()][k].setColor(NO_COLOR);
						m_tauler[posIn.getFila()][k].setTipus(NO_TIPUS);
					}
				}
				else
					if (m_tauler[posIn.getFila()][i].getTipus() == RATLLAT_VERTICAL)
					{
						for (int k = 0; k < MAX_FILES; k++)
						{
							m_tauler[k][i].setColor(NO_COLOR);
							m_tauler[k][i].setTipus(NO_TIPUS);
						}
					}
			}
			m_tauler[posIn.getFila()][i].setColor(NO_COLOR);
			m_tauler[posIn.getFila()][i].setTipus(NO_TIPUS);
		}
		break;
	case VERTICAL:
		// Bucle para reccorer cada posición de la alineación. Dentro se compueba el tipo de caramelo para saber como lo tiene que eliminar
		for (int i = posIn.getFila(); i <= posFin.getFila(); i++)
		{
			if (m_tauler[i][posIn.getColumna()].getTipus() != NORMAL)
			{
				if (m_tauler[i][posIn.getColumna()].getTipus() == RATLLAT_HORIZONTAL)
				{
					for (int k = 0; k < MAX_COLUMNES; k++)
					{
						m_tauler[i][k].setColor(NO_COLOR);
						m_tauler[i][k].setTipus(NO_TIPUS);
					}
				}
				else
					if (m_tauler[i][posIn.getColumna()].getTipus() == RATLLAT_VERTICAL)
					{
						for (int k = 0; k < MAX_FILES; k++)
						{
							m_tauler[k][posIn.getColumna()].setColor(NO_COLOR);
							m_tauler[k][posIn.getColumna()].setTipus(NO_TIPUS);
						}
					}
			}
			m_tauler[i][posIn.getColumna()].setColor(NO_COLOR);
			m_tauler[i][posIn.getColumna()].setTipus(NO_TIPUS);
		}
		break;
	default:
		break;
	}
}


// Método para desplazar todos los caramelos que tengan un espacio vacio debajo
void Tauler::desplaçaCaramel()
{
	for (int j = 0; j < MAX_COLUMNES; j++)
	{
		int i = MAX_FILES - 1;
		while (i >= 0)
		{
			if (m_tauler[i][j].getColor() == NO_COLOR)
			{
				// Busca el primer caramelo que encuentre por encima
				int k = i - 1;
				while (k >= 0 && m_tauler[k][j].getColor() == NO_COLOR)
				{
					k--;
				}

				if (k >= 0) // Condición para saber si se ha encontrado un caramelo
				{
					m_tauler[i][j] = m_tauler[k][j]; // Desplaza el caramelo
					m_tauler[k][j].setColor(NO_COLOR); // Vacía la posición original
				}
			}
			i--;
		}
	}
}


// Método para generar caramelos. Se generan de izquierda a derecha y de abajo a arriba.
void Tauler::generaCaramel()
{
	for (int i = MAX_FILES - 1; i >= 0; i--)
	{
		for (int j = 0; j < MAX_COLUMNES; j++)
		{
			if (nProximCandy == 6)
			{
				nProximCandy = 0;
			}
			if (m_tauler[i][j].getColor() == NO_COLOR)
			{
				switch (nProximCandy)
				{
				case 0:
					m_tauler[i][j].setColor(VERMELL);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 1:
					m_tauler[i][j].setColor(TARONJA);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 2:
					m_tauler[i][j].setColor(GROC);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 3:
					m_tauler[i][j].setColor(BLAU);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 4:
					m_tauler[i][j].setColor(VERD);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 5:
					m_tauler[i][j].setColor(LILA);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				default:
					break;
				}
				nProximCandy++;
			}
		}
	}
}


// Método para intercambiar un caramelo
void Tauler::intercanviaCaramel(const Posicio& pos1, const Posicio& pos2)
{
	Candy c, aux = m_tauler[pos1.getFila()][pos1.getColumna()];
	m_tauler[pos1.getFila()][pos1.getColumna()] = m_tauler[pos2.getFila()][pos2.getColumna()];
	m_tauler[pos2.getFila()][pos2.getColumna()] = aux;
}


// Método para buscar una alineación en vertical. Este método calcula la posición inicial y la final, el número de caramelos alineados y de que color son
bool Tauler::cercaPosVertical(Posicio& posIn, Posicio& posFin, int& n, Candy& c)
{
	bool trobat = false;
	int i = 1, j = 0;
	// Bucle que comprueba las columnas en busca de alineaciones. El bucle empieza en la segunda fila, y compara el caramelo con la fila anterior
	while (j < MAX_COLUMNES and !trobat)
	{
		n = 1; // Sirve para contar los caramelos
		i = 1; // Fila inicial
		while (i < MAX_FILES and !trobat)
		{
			if (m_tauler[i][j].compatibles(m_tauler[i - 1][j]) and m_tauler[i - 1][j].getColor() != NO_COLOR)
			{
				if (n == 1) // Calcula la posición inicial
				{
					posIn.set(i - 1, j);
				}
				n++;
			}
			else {
				if (n >= 3) // Si hay tres caramelos o mas alineados, se calcula la posición final
				{
					posFin.set(posIn.getFila() + n - 1, j);
					trobat = true;
				}
				else // Se empieza a contar de nuevo
					n = 1;
			}
			i++;
		}
		j++;
	}
	// Si se encuentra una alineación se guardan los datos del caramelo. Si no se encuentra, las posiciones toman el valor (-1,-1)
	if (trobat)
	{
		c.setColor(m_tauler[posIn.getFila()][posIn.getColumna()].getColor());
		c.setTipus(NORMAL);
		return true;
	}
	else {
		posIn.set(-1, -1);
		posFin.set(-1, -1);
		return false;
	}
}


// Método para buscar una alineación en horizontal. Este método calcula la posición inicial y la final, el número de caramelos alineados y de que color son
bool Tauler::cercaPosHoritzontal(Posicio& posIn, Posicio& posFin, int& n, Candy& c)
{
	bool trobat = false;
	int i = 0, j = 1;
	// Bucle que comprueba las filas en busca de alineaciones. El bucle empieza en la segunda columna, y compara el caramelo con la columna anterior
	while (i < MAX_FILES and !trobat)
	{
		n = 1; // Sirve para contar los caramelos
		j = 1; // Fila inicial
		while (j < MAX_COLUMNES and !trobat)
		{
			if (m_tauler[i][j].compatibles(m_tauler[i][j - 1]) and m_tauler[i][j - 1].getColor() != NO_COLOR)
			{
				if (n == 1) // Calcula la posición inicial
				{
					posIn.set(i, j - 1);
				}
				n++;
			}
			else {
				if (n >= 3) // Si hay tres caramelos o mas alineados, se calcula la posición final
				{
					posFin.set(i, posIn.getColumna() + n - 1);
					trobat = true;
				}
				else // Se empieza a contar de nuevo
					n = 1;
			}
			j++;
		}
		i++;
	}
	// Si se encuentra una alineación se guardan los datos del caramelo. Si no se encuentra, las posiciones toman el valor (-1,-1)
	if (trobat)
	{
		c.setColor(m_tauler[posIn.getFila()][posIn.getColumna()].getColor());
		c.setTipus(NORMAL);
		return true;
	}
	else {
		posIn.set(-1, -1);
		posFin.set(-1, -1);
		return false;
	}
}


// Método para generar un caramelo rallado
void Tauler::aparicioRatllat(const Posicio& pos1, const Posicio& pos2, const Posicio& posIn, const Posicio& posFin, 
	const int& n, const Candy& c)
{
	Candy aux;
	if (n >= 4)
	{
		if (buscaPosicio(posIn, posFin, pos1))
		{
			aux.setColor(c.getColor());
			aux.setTipus(tipusMoviment(pos1, pos2));
			m_tauler[pos1.getFila()][pos1.getColumna()] = aux;
		}
		if (buscaPosicio(posIn, posFin, pos2))
		{
			aux.setColor(c.getColor());
			aux.setTipus(tipusMoviment(pos1, pos2));
			m_tauler[pos2.getFila()][pos2.getColumna()] = aux;
		}
	}
}


// Método para calcular la dirección del caramelo rallado despues de un intercambio
TipusCandy Tauler::tipusMoviment(const Posicio& pos1, const Posicio& pos2)
{
	if (pos1.getFila() == pos2.getFila())
	{
		return RATLLAT_HORIZONTAL;
	}
	else
		if (pos1.getColumna() == pos2.getColumna())
		{
			return RATLLAT_VERTICAL;
		}
	return NORMAL;
}


// Método que comprueba si la posición pasada como tercer parámetro pertenece al intervalo entre las posiciones inicial y final
bool Tauler::buscaPosicio(const Posicio& posIn, const Posicio& posFin, const Posicio& pos)
{
	if (posIn.getFila() == posFin.getFila()) // Se comprueba en horizontal
	{
		if (pos.getFila() == posIn.getFila() and pos.getColumna() >= posIn.getColumna() and pos.getColumna() <= posFin.getColumna())
		{
			return true;
		}
	}
	else
		if (posIn.getColumna() == posFin.getColumna()) // Se comprueba en vertical
		{
			if (pos.getColumna() == posIn.getColumna() and pos.getFila() >= posIn.getFila() and pos.getFila() <= posFin.getFila())
			{
				return true;
			}
		}
	return false;
}