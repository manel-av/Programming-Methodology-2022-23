#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include "tauler.h"

using namespace std;

class Partida
{
public:
    Partida() { moviments = -1; quantitat = -1; puntuacio = -1; }
    void inicialitza(const string& nomFitxer);
    void escriuTauler(const string& nomFitxer);
    void dibuixa();
    bool iniciaMoviment(const Posicio& pos1, const Posicio& pos2);
    void continuaMoviment(const Posicio& pos1, const Posicio& pos2, const int& paso, bool& continua, TipusMatch& match);
    Tauler getTauler() { return m_tauler; }
    int getMoviments() { return moviments; }
    int getQuantitat() { return quantitat; }
    void setQuantitat(const int& num) { quantitat = num; }

private:
	Tauler m_tauler;
    int moviments;
    Candy caramel;
    int quantitat;
    int puntuacio;
};

#endif