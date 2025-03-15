#include "candy.h"

// Sobrecarga del operador >>
ifstream& operator>>(ifstream& input, Candy& c)
{
    char lletra;
    input >> lletra;
    switch (lletra) {
    case 'R':
        c.setColor(VERMELL);
        c.setTipus(NORMAL);
        break;
    case 'O':
        c.setColor(TARONJA);
        c.setTipus(NORMAL);
        break;
    case 'Y':
        c.setColor(GROC);
        c.setTipus(NORMAL);
        break;
    case 'B':
        c.setColor(BLAU);
        c.setTipus(NORMAL);
        break;
    case 'G':
        c.setColor(VERD);
        c.setTipus(NORMAL);
        break;
    case 'P':
        c.setColor(LILA);
        c.setTipus(NORMAL);
        break;
    default:
        c.setColor(NO_COLOR);
        c.setTipus(NO_TIPUS);
        break;
    }
    return input;
}


// Sobrecarga del operador <<
ofstream& operator<<(ofstream& output, Candy& c)
{
    char lletra = '\0';
    switch (c.getColor())
    {
    case VERMELL:
        if (c.getTipus() == NORMAL)
        {
            lletra = 'R';
        }
        else
            lletra = 'r';
        break;
    case TARONJA:
        if (c.getTipus() == NORMAL)
        {
            lletra = 'O';
        }
        else
            lletra = 'o';
        break;
    case GROC:
        if (c.getTipus() == NORMAL)
        {
            lletra = 'Y';
        }
        else
            lletra = 'y';
        break;
    case BLAU:
        if (c.getTipus() == NORMAL)
        {
            lletra = 'B';
        }
        else
            lletra = 'b';
        break;
    case VERD:
        if (c.getTipus() == NORMAL)
        {
            lletra = 'G';
        }
        else
            lletra = 'g';
        break;
    case LILA:
        if (c.getTipus() == NORMAL)
        {
            lletra = 'P';
        }
        else
            lletra = 'p';
        break;
    default:
        lletra = '\0';
        break;
    }
    output << lletra;
    return output;
}


// Convierte un numero en una letra
string Candy::conversor(const int& num)
{
    string lletra;
    switch (num)
    {
    case 0:
        lletra = "G";
        break;
    case 1:
        lletra = "P";
        break;
    case 2:
        lletra = "B";
        break;
    case 3:
        lletra = "O";
        break;
    case 4:
        lletra = "R";
        break;
    case 5:
        lletra = "Y";
        break;
    default:
        lletra = " ";
        break;
    }
    return lletra;
}