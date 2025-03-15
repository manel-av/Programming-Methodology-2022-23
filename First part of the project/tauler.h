#ifndef TAULER_H
#define TAULER_H
#include "candy.h"
#include "posicio.h"

using namespace std;

class Tauler
{
public:
	Tauler();
	Candy getCandy(int fila, int columna);
	void setCandy(Candy c, int fila, int columna) { m_tauler[fila][columna] = c; }
	void setProximCandy(const int& num) { nProximCandy = num; }

	void intercanviaCaramel(const Posicio& pos1, const Posicio& pos2);
	bool cercaPosVertical(Posicio& posIn, Posicio& posFin, int& n, Candy& c);
	bool cercaPosHoritzontal(Posicio& posIn, Posicio& posFin, int& n, Candy& c);
	void eliminaCaramel(const Posicio& posIn, const Posicio& posFin, const Direccio& direccio);
	void desplaçaCaramel();
	void generaCaramel();
	void aparicioRatllat(const Posicio& pos1, const Posicio& pos2, const Posicio& posIn, const Posicio& posFin, 
		const int& n, const Candy& c);

private:
	Candy m_tauler[MAX_FILES][MAX_COLUMNES];
	int nProximCandy;
	bool buscaPosicio(const Posicio& posIn, const Posicio& posFin, const Posicio& pos);
	TipusCandy tipusMoviment(const Posicio& pos1, const Posicio& pos2);
 };

#endif