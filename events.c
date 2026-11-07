// Colisão: itens/inimigos, Cristais e Energia, Vitória / Derrota
#include "events.h" 
#include "player.h"


void coletarEnergia(Jogador *jogador){
    jogador->energia++;
}

void coletarCristais(Jogador *jogador){
    jogador->cristais++;
}

void coletarArmadilha(Jogador *jogador){
    jogador->energia--;
}

void desenharEnergia(Jogador *jogador){
    DrawText(TextFormat("Energia: %d", jogador->energia), 100, 400, 50, BLACK);
} 
void desenharCristais(Jogador *jogador){
    DrawText(TextFormat("Cristais: %d/%d", jogador->cristais, MAX_CRISTAIS), 100, 300, 50, BLACK);
} 

void usarColetavel(Jogador *jogador, char mapa[][COLUNAS])
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
        case 'R':
        coletarEnergia(jogador);
        mapa[linha_destino][coluna_destino] = '.';
        break;
        case 'C':
        coletarCristais(jogador);
        mapa[linha_destino][coluna_destino] = '.';
        break;
        case 'A':
        coletarArmadilha(jogador);
        mapa[linha_destino][coluna_destino] = '.';
        break;
        default:
        jogador->energia--;
        break;
    }   
}