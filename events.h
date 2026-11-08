//Cabeçalho: estados do jogo (Menu, Telas, Placar, energia)
#ifndef EVENTS_H
#define EVENTS_H
#include "raylib.h"
#include "player.h"

#define MAX_ENERGIA 35
#define MAX_CRISTAIS 5
#define ROLANDO 0
#define VITORIA 1
#define DERROTA 2
#define DESISTIR 3

void desenharJogo(); //
void coletarCristal(); // 
void eventoAleatorio(); // 
void entrarArmadilha(); // 
void coletarEnergia(Jogador *jogador); //
void usarColetavel(Jogador *jogador, char mapa[][COLUNAS]);
void coletarCristais(Jogador *jogador);
void coletarArmadilha(Jogador *jogador);

#endif