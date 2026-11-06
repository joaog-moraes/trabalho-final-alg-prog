// Jogador (Movimentação, Física, Sprites)
#include "player.h"
#include "map.h"
#include <math.h>

void desenhaJogador()
{

}

void moverJogador(Jogador *jogador)
{
    if (IsKeyPressed(KEY_RIGHT))
    {
        jogador->posicao.x += TILE;
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        jogador->posicao.x -= TILE;
    }
    if (IsKeyPressed(KEY_UP))
    {
        jogador->posicao.y -= TILE;
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        jogador->posicao.y += TILE;
    }
}