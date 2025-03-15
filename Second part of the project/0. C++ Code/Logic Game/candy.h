#ifndef CANDY_H
#define CANDY_H


#include "definicions.h"
#include <string>
#include <fstream>
#include "InfoJoc.h"
#include "GraphicManager.h"

using namespace std;

class Candy
{
public:
	Candy() { m_color = NO_COLOR; m_tipus = NO_TIPUS; }
	Candy(ColorCandy color, TipusCandy tipus) { m_color = color; m_tipus = tipus; }
	ColorCandy getColor() const { return m_color; }
	TipusCandy getTipus() const { return m_tipus; }
	void setColor(const ColorCandy& color) { m_color = color; }
	void setTipus(const TipusCandy& tipus) { m_tipus = tipus; }
	bool compatibles(const Candy& c) { return m_color == c.getColor(); }
	string conversor(const int& num);
	void dibuixaCaramel(const int& posX, const int& posY);
	bool operator==(const Candy& c); 
	IMAGE_NAME getImage();

private:
	ColorCandy m_color;
	TipusCandy m_tipus;
};

ifstream& operator>>(ifstream& input, Candy& c);
ofstream& operator<<(ofstream& output, Candy& c);

#endif