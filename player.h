// Cabeçalho: jogador (Movimentação, Física, Sprites)

#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "map.h"


typedef struct
{
    Vector2 posicao;
    int energia;
    int cristais;
} Jogador;

void atualizarPosicao(Jogador *jogador, char mapa[][COLUNAS]);
Vector2 calcularDestino(Jogador *jogador); 
void moverJogador(Jogador *jogador);
void desenharJogador(Jogador *jogador);
void determinarPosicao(Jogador *jogador, char mapa[][COLUNAS]);

#endif