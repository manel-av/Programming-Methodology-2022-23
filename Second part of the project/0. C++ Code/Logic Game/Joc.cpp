#include "Joc.hpp"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include <iostream>

void Joc::inicialitza(const string& nomFitxer)
{
    m_partida.inicialitza(nomFitxer);
}

void Joc::actualitza(int mousePosX, int mousePosY, bool mouseStatus, double deltaTime)
{
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);
    m_partida.dibuixa();

    switch (m_estat)
    {
    case ESTAT_JOC_ESPERA:
        match = MATCHING_PRIMARI;
        m_continua = false;
        if (mouseStatus)
        {
            if ((mousePosX >= CELL_INIT_X) && (mousePosX <= (CELL_INIT_X + (CELL_W * N_COLS))) &&
                (mousePosY >= CELL_INIT_Y) && (mousePosY <= (CELL_INIT_Y + (CELL_H * N_ROWS))))
            {
                int posX = (mousePosX - CELL_INIT_X) / CELL_W;
                int posY = (mousePosY - CELL_INIT_Y) / CELL_H;
                m_posIn.set(posY, posX);
                m_candyIn = m_partida.getTauler().getCandy(posY, posX);
                m_estat = ESTAT_JOC_INTERCANVI;
            }
        }
        break;
    case ESTAT_JOC_INTERCANVI:
        if (mouseStatus)
        {
            if ((mousePosX >= CELL_INIT_X) && (mousePosX <= (CELL_INIT_X + (CELL_W * N_COLS))) &&
                (mousePosY >= CELL_INIT_Y) && (mousePosY <= (CELL_INIT_Y + (CELL_H * N_ROWS))))
            {
                int posX = (mousePosX - CELL_INIT_X) / CELL_W;
                int posY = (mousePosY - CELL_INIT_Y) / CELL_H;
                m_posFin.set(posY, posX);

                if (m_posIn.getFila() == m_posFin.getFila() and m_posIn.getColumna() == m_posFin.getColumna())
                {
                    GraphicManager::getInstance()->drawSprite(IMAGE_CELDA, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                        CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
                    IMAGE_NAME image = m_candyIn.getImage();
                    GraphicManager::getInstance()->drawSprite(image, mousePosX, mousePosY, true);
                }

                if ((m_posIn.getFila() == m_posFin.getFila() and m_posIn.getColumna() != m_posFin.getColumna()) or
                    (m_posIn.getFila() != m_posFin.getFila() and m_posIn.getColumna() == m_posFin.getColumna()))
                {
                    if (m_partida.iniciaMoviment(m_posIn, m_posFin))
                    {
                        m_estat = ESTAT_JOC_MOVIMENTS;
                    }
                    else
                        if (!mouseStatus)
                            m_estat = ESTAT_JOC_ESPERA;
                }
            }
        }
        else
            m_estat = ESTAT_JOC_ESPERA;
        break;
    case ESTAT_JOC_MOVIMENTS:
        if (m_partida.getQuantitat() <= 0)
            m_partida.setQuantitat(0);
        m_temps += deltaTime;
        if (m_temps > TEMPS_PAUSA)
        {
            m_partida.continuaMoviment(m_posIn, m_posFin, m_paso, m_continua, match);
            if (m_paso < 4)
            {
                m_paso++;
            }
            else
                m_paso = 0;
            m_temps = 0;
        }
        if (!m_continua and m_paso == 4)
        {
            if (m_partida.getMoviments() == 0 or m_partida.getQuantitat() <= 0)
            {
                m_estat = ESTAT_FINAL;
            }
            else
            {
                m_estat = ESTAT_JOC_ESPERA;
                m_paso = 0;
            }
        }
        break;
    case ESTAT_FINAL:
        string msg;
        if (m_partida.getQuantitat() <= 0)
            msg = "FINAL PARTIDA. HAS GUANYAT!";
        else
            msg = "FINAL PARTIDA. HAS PERDUT!";
        GraphicManager::getInstance()->drawFont(FONT_WHITE_30, FINAL_INIT_X, FINAL_INIT_Y, 1.0, msg);
        break;
    }
}

