// Jogador (Movimentação, Física, Sprites)
#include "player.h"
#include "map.h"
#include <math.h>
#include <stdio.h>

void desenharJogador()
{
}

void verificarDestino(Jogador *jogador, char mapa[][COLUNAS]) // verifica se a posicao do jogador é valida
{
    int coluna_destino, linha_destino;
    char retorno_tile;
    linha_destino = jogador->posicao.y;
    coluna_destino = jogador->posicao.x;
    retorno_tile = consulta_tile(mapa, linha_destino, coluna_destino);
    if (retorno_tile != '\0')
    {
        moverJogador(jogador);
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