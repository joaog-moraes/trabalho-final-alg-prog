// Inicialização da Raylib e Loop Principal

#include <stdio.h>
#include "player.h"
#include "events.h"
#include "game.h"
#include "raylib.h"

// Inicialização da Raylib e Loop Principal

int main()
{
    // Define as constantes de largura e altura da tela
    const int screenWidht = 800;
    const int screenHeight = 600;
    
    Jogador jogador; // Definição de jogador
    Jogo jogo; // Definicao do jogo

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
    
    jogo.turno = 0;
    jogador.energia = MAX_ENERGIA;
    jogador.cristais = 0;
    
    InitWindow(screenWidht, screenHeight, "Expedicao na ilha dos algoritmos!");

    // Define o framerate do jogo
    SetTargetFPS(60);

    // Loop do jogo
    while (!WindowShouldClose())
    {
        determinarPosicao(&jogador, mapa);
        usarColetavel(&jogador, mapa);
        atualizarPosicao(&jogador, &jogo, mapa);
        BeginDrawing();
        ClearBackground(WHITE);
        
        // Desenha o mapa na janela
        desenha_mapa(mapa);
        desenharHUD(&jogador, &jogo);
        desenharJogador(&jogador);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
