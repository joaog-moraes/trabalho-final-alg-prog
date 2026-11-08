//Máquina de estados, menu, HUD e placar
#include "game.h"

void desenharHUD(Jogador *jogador, Jogo *jogo)
{
    DrawText(TextFormat("Energia: %d", jogador->energia), TILE / 4.0, 8.5 * TILE, TILE / 1.25, BLACK);
    DrawText(TextFormat("Cristais: %d/%d", jogador->cristais, MAX_CRISTAIS), TILE / 4.0, 9.5 * TILE, TILE/1.25, BLACK);
    DrawText(TextFormat("Turno: %d", jogo->turno), TILE / 4.0,  10.5 * TILE, TILE/1.25, BLACK);
}