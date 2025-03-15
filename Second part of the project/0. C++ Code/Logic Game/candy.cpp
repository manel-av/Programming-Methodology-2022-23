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

void Candy::dibuixaCaramel(const int& posX, const int& posY)
{
    switch (getColor())
    {
    case VERD:
        switch (getTipus())
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        }
        break;
    case LILA:
        switch (getTipus())
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        }
        break;
    case BLAU:
        switch (getTipus())
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        }
        break;
    case TARONJA:
        switch (getTipus())
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        }
        break;
    case VERMELL:
        switch (getTipus())
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        }
        break;
    case GROC:
        switch (getTipus())
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        }
        break;
    default:
        break;
    }
}

bool Candy::operator==(const Candy& c)
{
    return (m_color == c.getColor() and m_tipus == c.getTipus());
}

IMAGE_NAME Candy::getImage()
{
    switch (getColor())
    {
    case VERD:
        switch (getTipus())
        {
        case NORMAL:
            return IMAGE_PIECE_GREEN;
            break;
        case RATLLAT_HORIZONTAL:
            return IMAGE_PIECE_GREEN_HORIZONTAL;
            break;
        case RATLLAT_VERTICAL:
            return IMAGE_PIECE_GREEN_VERTICAL;
            break;
        }
        break;
    case LILA:
        switch (getTipus())
        {
        case NORMAL:
            return IMAGE_PIECE_PURPLE;
            break;
        case RATLLAT_HORIZONTAL:
            return IMAGE_PIECE_PURPLE_HORIZONTAL;
            break;
        case RATLLAT_VERTICAL:
            return IMAGE_PIECE_PURPLE_VERTICAL;
            break;
        }
        break;
    case BLAU:
        switch (getTipus())
        {
        case NORMAL:
            return IMAGE_PIECE_BLUE;
            break;
        case RATLLAT_HORIZONTAL:
            return IMAGE_PIECE_BLUE_HORIZONTAL;
            break;
        case RATLLAT_VERTICAL:
            return IMAGE_PIECE_BLUE_VERTICAL;
            break;
        }
        break;
    case TARONJA:
        switch (getTipus())
        {
        case NORMAL:
            return IMAGE_PIECE_ORANGE;
            break;
        case RATLLAT_HORIZONTAL:
            return IMAGE_PIECE_ORANGE_HORIZONTAL;
            break;
        case RATLLAT_VERTICAL:
            return IMAGE_PIECE_ORANGE_VERTICAL;
            break;
        }
        break;
    case VERMELL:
        switch (getTipus())
        {
        case NORMAL:
            return IMAGE_PIECE_RED;
            break;
        case RATLLAT_HORIZONTAL:
            return IMAGE_PIECE_RED_HORIZONTAL;
            break;
        case RATLLAT_VERTICAL:
            return IMAGE_PIECE_RED_VERTICAL;
            break;
        }
        break;
    case GROC:
        switch (getTipus())
        {
        case NORMAL:
            return IMAGE_PIECE_YELLOW;
            break;
        case RATLLAT_HORIZONTAL:
            return IMAGE_PIECE_YELLOW_HORIZONTAL;
            break;
        case RATLLAT_VERTICAL:
            return IMAGE_PIECE_YELLOW_VERTICAL;
            break;
        }
        break;
    default:
        break;
    }
}