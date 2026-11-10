// Jogador (Movimentação, Física, Sprites)
#include "jogo.h"

void desenharJogador(Jogador *jogador)
{
    DrawCircleV((Vector2){jogador->posicao.x + TILE / 2.0, jogador->posicao.y + TILE / 2.0}, 0.3 * TILE, ORANGE);
}

void determinarPosicao(Jogador *jogador, char mapa[][COLUNAS]) // determina a posicao inicial do jogador
{
    int i, j;
    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (mapa[i][j] == 'P')
            {
                jogador->posicao.y = i * TILE;
                jogador->posicao.x = j * TILE;
            }
        }
    }
}

void atualizarPosicao(Jogador *jogador, Jogo *jogo, char mapa[][COLUNAS]) // verifica se a posicao do jogador é valida, se sim, move o jogador
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
        if (testarMovimento())
        {
            jogo->turno++;
            if (jogador->energia > 0) // verifica se energia é maior que zero
            {
                jogador->energia--;
            }
            else // se for negativa, a energia do player = 0
            {
                jogador->energia = 0;
            }
        }
        break;
    }
}

Vector2 calcularDestino(Jogador *jogador) // calcula o valor da posicao do jogador
{
    Vector2 destino = jogador->posicao;
    if (IsKeyPressed(KEY_RIGHT)) // Setas
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
    else if (IsKeyPressed(KEY_D)) // WASD
    {
        destino.x += TILE;
    }
    else if (IsKeyPressed(KEY_A))
    {
        destino.x -= TILE;
    }
    else if (IsKeyPressed(KEY_W))
    {
        destino.y -= TILE;
    }
    else if (IsKeyPressed(KEY_S))
    {
        destino.y += TILE;
    }
    return destino;
}

bool testarMovimento() // verifica se alguma tecla de movimento esta pressionada 
{
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_S))
        return true;
    else
        return false;
}