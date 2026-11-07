// Inicialização da Raylib e Loop Principal

#include <stdio.h>
#include "player.h"
#include "events.h"
#include "audio.h"
#include "map.h"
#include "game.h"
#include "raylib.h"

// Inicialização da Raylib e Loop Principal

int main()
{
    // Define as constantes de largura e altura da tela
    const int screenWidht = 800;
    const int screenHeight = 600;

    printf("Mapa modelo: \n");
    char mapa[LINHAS][COLUNAS];
    criar_mapa(mapa);
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }

    Jogador jogador; // Definição de jogador
    jogador.energia = MAX_ENERGIA;
    jogador.cristais = 0;
    
    jogador.posicao.x = 50.0f; // Posição inicial no eixo X
    jogador.posicao.y = 50.0f; // Posição inicial no eixo Y

    InitWindow(screenWidht, screenHeight, "Expedicao na ilha dos algoritmos!");

    // Define o framerate do jogo
    SetTargetFPS(30);

    // Loop do jogo
    while (!WindowShouldClose())
    {

        atualizarPosicao(&jogador, mapa);

        BeginDrawing();
        ClearBackground(WHITE);
        
        // Desenha o mapa na janela
        desenha_mapa(mapa);
        DrawRectangleV(jogador.posicao, (Vector2){TILE, TILE}, RED);
        desenharEnergia(&jogador);
        desenharCristais(&jogador);
        usarColetavel(&jogador, mapa);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
