// Cabeçalho: jogador (Movimentação, Física, Sprites)
#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <stdio.h>
#include "raylib.h"
#include "map.h"

typedef struct
{
    Vector2 posicao;
    int energia;
    int cristais;
} Jogador;

typedef struct
{
    int turno;
} Jogo;

void atualizarPosicao(Jogador *jogador, Jogo* jogo, char mapa[][COLUNAS]);
Vector2 calcularDestino(Jogador *jogador); 
bool testarMovimento();
void desenharJogador(Jogador *jogador);
void determinarPosicao(Jogador *jogador, char mapa[][COLUNAS]);

#endif