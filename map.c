#include <stdio.h>
#include "jogo.h"
#include "raylib.h"

void leitura_arq(void)
{
}

void criar_mapa(char mapa[][COLUNAS])
{
    int i, j;

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            mapa[i][j] = '.';

            if (i == 0 || i == LINHAS - 1 || j == 0 || j == COLUNAS - 1 || (j == 5 && i != 4))
            {
                mapa[i][j] = '#';
            };
        };
    };
    mapa[1][1] = 'P'; // POSICAO INICIAL JOGADOR
    mapa[4][5] = 'C'; // CRISTAIS
    mapa[1][9] = 'C';
    mapa[3][11] = 'C';
    mapa[5][1] = 'C';
    mapa[5][11] = 'C';
    mapa[6][10] = 'S';
    mapa[2][2] = 'A';
    mapa[3][3] = 'R'; // RECUPERACAO (+ENERGIA)
    mapa[3][6] = 'A'; // ARMADILHA (-ENERGIA)
    mapa[4][8] = 'E';
}

// consulta posicao

char consulta_tile(char mapa[][COLUNAS], int linha, int coluna)
{

    // Verifica se a posição está dentro dos limites do mapa
    if (linha < 0 || linha >= LINHAS ||
        coluna < 0 || coluna >= COLUNAS)
    {
        return '\0';
    }

    // Retorna o conteúdo da posição consultada
    return mapa[linha][coluna];
}

// Desenha o mapa na tela utilizando a matriz

void desenha_mapa(char mapa[][COLUNAS], Textura *textura)
{
    int i, j;
    int tamanho = TILE;
    
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {

            int x = j * tamanho;
            int y = i * tamanho;

            // Define o desenho de cada tile
            switch (mapa[i][j])
            {

            case '#':
                // Obstáculo
                DrawTexturePro(textura->texturaParede, (Rectangle){0, 0, textura->texturaParede.width, textura->texturaParede.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                break;

            case '.':
                // Caminho livre
                DrawTexturePro(textura->texturaChao, (Rectangle){0, 0, textura->texturaChao.width, textura->texturaChao.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                break;

            case 'C':
                // Desenha o piso e depois o cristal
                DrawTexturePro(textura->texturaChao, (Rectangle){0, 0, textura->texturaChao.width, textura->texturaCristal.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                DrawTexturePro(textura->texturaCristal, (Rectangle){0, 0, textura->texturaCristal.width, textura->texturaCristal.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                break;

            case 'R':
                // Recuperação (+energia)
                DrawTexturePro(textura->texturaEnergia, (Rectangle){0, 0, textura->texturaEnergia.width, textura->texturaEnergia.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                break;

            case 'A':
                // Armadilha (-energia)
                DrawTexturePro(textura->texturaArmadilha, (Rectangle){0, 0, textura->texturaArmadilha.width, textura->texturaArmadilha.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                break;

            case 'E':
                // Evento aleatório (definido pela dupla)
                DrawTexturePro(textura->texturaEvento, (Rectangle){0, 0, textura->texturaEvento.width, textura->texturaEvento.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                break;

            case 'S':
                // Saída
                DrawTexturePro(textura->texturaSaida, (Rectangle){0, 0, textura->texturaSaida.width, textura->texturaSaida.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                break;

            //case 'P':
                // Representação visual do jogador
                //DrawRectangle(x, y, tamanho, tamanho, LIGHTGRAY);
               //DrawCircle(x + tamanho / 2, y + tamanho / 2, 0.3 * tamanho , ORANGE);
                //break;

            default:
                DrawTexturePro(textura->texturaChao, (Rectangle){0, 0, textura->texturaChao.width, textura->texturaChao.height}, (Rectangle){x, y, TILE, TILE}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
                break;
            }
            //Contorno dos tiles para visualizar a divisão da matriz
            //DrawRectangleLines(x, y, tamanho, tamanho, DARKGRAY);
        }
    }
}
