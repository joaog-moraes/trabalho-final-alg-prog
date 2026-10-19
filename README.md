                       Trabalho final Alg. Prog (2026/2)
                                 Grupo - B

```text
===================================================================================
                       ARQUITETURA E DIVISÃO DE MÓDULOS
===================================================================================

                            +----------------------+
                            |        main.c        |
                            | (Ponto de Integração |
                            |   desenvolvido por   |
                            |    JOÃO e BRYAN)     |
                            +----------+-----------+
                                       |
         +-----------------------------+-----------------------------+
         |                                                           |
         v                                                           v
+-------------------------------+                           +-------------------------------+
|    INTEGRANTE A: JOÃO         |                           |    INTEGRANTE B: BRYAN        |
|    (Jogador e Regras)         |                           |    (Mundo e Experiência)      |
+-------------------------------+                           +-------------------------------+
|                               |                           |                               |
| • player.h / player.c         |                           | • map.h / map.c               |
|   - struct Player             |                           |   - Leitura de mapas .txt     |
|   - Movimentação e física     |   [Consulta de Tiles]     |   - Renderização da fase      |
|     (pulo e gravidade)        | <=======================> |   - Função MapaTileSolido()   |
|   - Colisão Jogador x Mapa    |   (Sem conhecer Player)   |                               |
|   - Animação de sprites       |                           | • game.h / game.c             |
|                               |                           |   - Máquina de Estados        |
| • events.h / events.c         |                           |     (Menu/Game/Pause/GameOver)|
|   - Colisão Jogador x Itens/  |                           |   - HUD e Placar de Pontos    |
|     Inimigos                  |                           |                               |
|   - Pontuação e Vidas         |                           | • audio.h / audio.c           |
|   - Regras de Vitória/Derrota |                           |   - Música em loop e efeitos  |
+---------------+---------------+                           +---------------+---------------+
                |                                                           |
                +-----------------------------+-----------------------------+
                                              |
                                              v
                               +-----------------------------+
                               |           assets/           |
                               |  audio/  fonts/  maps/      |
                               |  sprites/                   |
                               +-----------------------------+
