//Inicialização da Raylib e Loop Principal


#include <stdio.h>
#include "map.h"
#include <raylib.h>


//Inicialização da Raylib e Loop Principal

int main (){

    //Define as constantes de largura e altura da tela
    const int screenWidht = 800;
    const int screenHeight = 450;

    printf("Mapa modelo: \n");

    char mapa[LINHAS][COLUNAS];

    criar_mapa(mapa);

    for(int i=0; i<LINHAS; i++) {
        for(int j=0; j<COLUNAS; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }

    InitWindow(screenWidht, screenHeight, "Tela do jogo");

    //Define o framerate do jogo
    SetTargetFPS(60);

    //Loop do jogo
    while(!WindowShouldClose()){

        BeginDrawing();
            ClearBackground(WHITE);

            //Desenha o mapa na janela
            desenha_mapa(mapa);

            DrawText("Teste", 10, 410, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
