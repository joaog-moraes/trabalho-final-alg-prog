                       Trabalho final Alg. Prog (2026/2)
                                 Grupo - B
```text
=============================================================================
                       ARQUITETURA E DIVISÃO DE MÓDULOS
=============================================================================

                     +---------------------------------+
                     |              main.c             |
                     |   Ponto de integração (A + B)   |
                     +---------------------------------+
                                      |
                     +---------------------------------+
                     |              game.h             |
                     |   Constantes, enum de estados   |
                     |     e structs comuns (A + B)    |
                     +---------------------------------+
                                      |
               +----------------------+----------------------+
               |                                             |
               v                                             v
+-----------------------------+               +-----------------------------+
|      INTEGRANTE A: JOÃO     |               |     INTEGRANTE B: BRYAN     |
|      (Jogador e Regras)     |               |    (Mundo e Experiência)    |
|                             |               |                             |
| * player.h / player.c       |               | * map.h / map.c             |
|   - struct Player           |[Tiles e sons] |   - Leitura dos mapas .txt  |
|   - Movimento e física      |==============>|   - Renderização da fase    |
|   - Colisão Jogador x Mapa  |  (A chama B)  |   - MapaTileSolido()        |
|   - Animação de sprites     |               |                             |
|                             | B não conhece | * game.c (usa o game.h)     |
| * events.h / events.c       |   o Player    |   - Máquina de estados      |
|   - Colisão: itens/inimigos |               |   - Menu, HUD e placar      |
|   - Pontuação e vidas       |               |                             |
|   - Vitória / Derrota       |               | * audio.h / audio.c         |
|                             |               |   - Música em loop/efeitos  |
+-----------------------------+               +-----------------------------+
               |                                             |
               +----------------------+----------------------+
                                      v
                     +---------------------------------+
                     |             assets/             |
                     | audio/  fonts/  maps/  sprites/ |
                     +---------------------------------+