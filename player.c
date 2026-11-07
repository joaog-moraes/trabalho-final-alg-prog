// Jogador (Movimentação, Física, Sprites)
#include "player.h"
#include "map.h"
#include "events.h"
#include <math.h>
#include <stdio.h>

void desenharJogador()
{
}

void atualizarPosicao(Jogador *jogador, char mapa[][COLUNAS]) // verifica se a posicao do jogador é valida, se sim, move o jogador
{
    int linha_destino, coluna_destino;
    char retorno_tile;
    Vector2 destino;
    destino = calcularDestino(jogador);
    linha_destino = (int)destino.y / TILE;
    coluna_destino = (int)destino.x / TILE;
    retorno_tile = consulta_tile(mapa, linha_destino, coluna_destino);
    switch (retorno_tile)
    {
    case '\0':
    case '#':
        break;
    default:
        jogador->posicao = destino;
        break;
    }
}

Vector2 calcularDestino(Jogador *jogador) // calcula o valor da posicao do jogador
{
    Vector2 destino = jogador->posicao;
    if (IsKeyPressed(KEY_RIGHT))
    {
        destino.x += TILE;
    }
    else if (IsKeyPressed(KEY_LEFT))
    {
        destino.x -= TILE;
    }
    else if (IsKeyPressed(KEY_UP))
    {
        destino.y -= TILE;
    }
    else if (IsKeyPressed(KEY_DOWN))
    {
        destino.y += TILE;
    }
    return destino;
}
// nao utilizada por enquanto
void moverJogador(Jogador *jogador) // move o jogador
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