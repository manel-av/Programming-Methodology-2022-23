#ifndef Joc_hpp
#define Joc_hpp

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "partida.h"

using namespace std;

typedef enum
{
    ESTAT_JOC_ESPERA,
    ESTAT_JOC_INTERCANVI,
    ESTAT_JOC_MOVIMENTS,
    ESTAT_FINAL
} EstatJoc;


class Joc 
{
public:
    Joc() : m_temps(0), m_visible(true), m_estat(ESTAT_JOC_ESPERA), m_paso(0), match(MATCHING_PRIMARI), m_continua(false) {};
    
    void inicialitza(const string& nomFitxerInicial);
    void actualitza(int mousePosX, int mousePosY, bool mouseStatus, double deltaTime);
private:
    double m_temps;
    bool m_visible, m_continua;
    Partida m_partida;
    EstatJoc m_estat;
    Posicio m_posIn, m_posFin;
    Candy m_candyIn, m_candyFin;
    int m_paso;
    TipusMatch match;
};

#endif /* Joc_hpp */
