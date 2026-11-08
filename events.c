// Colisão: itens/inimigos, Cristais e Energia, Vitória / Derrota
#include "events.h"


void coletarEnergia(Jogador *jogador)
{
    jogador->energia += 2;
}

void coletarCristais(Jogador *jogador)
{
    jogador->cristais++;
}

void coletarArmadilha(Jogador *jogador)
{
    jogador->energia--;
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
    case 'P':
        mapa[linha_destino][coluna_destino] = '.';
        break;
    }
}