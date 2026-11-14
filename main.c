// Inicialização da Raylib e Loop Principal

#include <stdio.h>
#include "jogo.h"

// Inicialização da Raylib e Loop Principal

int main()
{
    // Define as constantes de largura e altura da tela
    const int screenWidht = 800;
    const int screenHeight = 600;

    Jogador jogador; // Definição de jogador
    Textura textura;
    Jogo jogo;       // Definicao do jogo

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
    jogador.angulo = 180;

    InitWindow(screenWidht, screenHeight, "Expedicao na ilha dos algoritmos!");
    SetTargetFPS(60);
    
    textura.texturaJogador = LoadTexture("assets/sprites/pato-jogador.png");
    textura.texturaChao = LoadTexture("assets/sprites/agua-chao.png");
    textura.texturaParede = LoadTexture("assets/sprites/areia-parede.png");
    textura.texturaCristal = LoadTexture("assets/sprites/ovo-cristal-transparente.png");
    textura.texturaEvento = LoadTexture("assets/sprites/bola-evento.png");
    textura.texturaArmadilha = LoadTexture("assets/sprites/barbatana-armadilha.png");
    textura.texturaEnergia = LoadTexture("assets/sprites/peixe-energia.png");
    textura.texturaSaida = LoadTexture("assets/sprites/boia-saida.png");

    while (!WindowShouldClose())
    {
        determinarPosicao(&jogador, mapa);
        usarColetavel(&jogador, mapa);
        atualizarPosicao(&jogador, &jogo, mapa);
        BeginDrawing();
        ClearBackground(WHITE);

        // Desenha o mapa na janela
        desenha_mapa(mapa, &textura);
        desenharHUD(&jogador, &jogo);
        desenharJogador(&jogador, &textura);

        EndDrawing();
    }
   
    UnloadTexture(textura.texturaJogador);
    UnloadTexture(textura.texturaChao);
    UnloadTexture(textura.texturaParede);
    UnloadTexture(textura.texturaCristal);
    UnloadTexture(textura.texturaEvento);
    UnloadTexture(textura.texturaArmadilha);
    UnloadTexture(textura.texturaSaida);
    CloseWindow();
    return 0;
}
