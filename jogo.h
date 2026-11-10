#ifndef JOGO_H 
#define JOGO_H 
#include <stdbool.h>
#include "raylib.h"


//map 
#define LINHAS 8
#define COLUNAS 16
#define CRISTAIS 5
#define ENERGIA 35
#define TILE 50 // define o que é um tile

void criar_mapa(char mapa[][COLUNAS]);

char consulta_tile(char mapa[][COLUNAS], int linha, int coluna);

void desenha_mapa(char mapa[][COLUNAS]);

//player 
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



//eventos 


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




//game 
void desenharHUD(Jogador *jogador, Jogo *jogo);




#endif