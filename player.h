//Cabeçalho: jogador (Movimentação, Física, Sprites)

#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

typedef struct {  
    Vector2 posicao;
    int energia;
    int cristais;
} Jogador;

void moverJogador(Jogador *jogador);

#endif