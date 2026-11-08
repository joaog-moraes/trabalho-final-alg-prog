// Cabeçalho: jogador (Movimentação, Física, Sprites)
#ifndef PLAYER_H
#define PLAYER_H
#include <math.h>
#include <stdio.h>
#include "raylib.h"
#include "map.h"

#define TAM_MSG 80

typedef struct
{
    Vector2 posicao;
    int energia;
    int cristais;
    int cristaisMin;
} Jogador;

typedef struct // coloquei a struct jogo aqui, pois esta dando problemas de ciclo na biblioteca. Mudar depois
{
    int turno;
    int linhas, colunas;
    char mensagem[TAM_MSG];
} Jogo;


void atualizarPosicao(Jogador *jogador, Jogo* jogo, char mapa[][COLUNAS]);
Vector2 calcularDestino(Jogador *jogador); 
bool testarMovimento();
void desenharJogador(Jogador *jogador);
void determinarPosicao(Jogador *jogador, char mapa[][COLUNAS]);

#endif