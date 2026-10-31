//Cabeçalho: fases, Leitura de Mapas e Matrizes

#ifndef MAP_H
#define MAP_H
#define LINHAS 8
#define COLUNAS 16
#define CRISTAIS 3
#define ENERGIA 35

void criar_mapa(char mapa[][COLUNAS]);

char consulta_tile(char mapa[][COLUNAS], int linha, int coluna);

void desenha_mapa(char mapa[][COLUNAS]);

#endif
