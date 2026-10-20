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

                     =============================================================================
                        ESTRUTURA DE PASTAS E MÓDULOS
=============================================================================
```text
jogo-raylib/
├── assets/
│   ├── audio/          <-- Músicas e efeitos (.wav/.ogg)            [B]
│   ├── fonts/          <-- Fontes do jogo (.ttf)                    [A + B]
│   ├── maps/           <-- Mapas em texto (.txt)                    [B]
│   └── sprites/        <-- Imagens e animações (.png)               [A]
│
├── .gitignore          <-- Regras do Git
├── Makefile            <-- Compilação
├── README.md           <-- Documentação
│
├── main.c              <-- Loop principal e integração              [A + B]
├── game.h              <-- Constantes, estados e structs            [A + B]
│
├── INTEGRANTE A: JOÃO (Jogador e Regras)
│   ├── player.h / player.c
│   │    - struct Player
│   │    - Movimento e física (pulo, gravidade)
│   │    - Colisão Jogador x Mapa (usa MapaTileSolido)
│   │    - Animação de sprites
│   └── events.h / events.c
│        - Colisão com itens e inimigos
│        - Pontuação e vidas
│        - Regras de vitória / derrota
│
└── INTEGRANTE B: BRYAN (Mundo e Experiência)
    ├── map.h / map.c
    │    - Leitura dos mapas .txt
    │    - Renderização da fase
    │    - Função MapaTileSolido()
    ├── game.c
    │    - Máquina de estados (Menu/Game/Pause/GameOver)
    │    - HUD e placar de pontos
    └── audio.h / audio.c
         - Música de fundo em loop
         - Efeitos sonoros (pulo, coleta, dano)