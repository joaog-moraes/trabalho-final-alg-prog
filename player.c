// Jogador (Movimentação, Física, Sprites)
#include "raylib.h"
#include <math.h>

typedef struct {
    float posX; 
    float posY;
    int energy;
    int crystals;
} Player;

float move_player()

