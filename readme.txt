================================================
Computação Gráfica (DCC027) - Trabalho Prático 1
Professor: Renato Antônio Celso Ferreira
Aluno: Caio Guedes de Azevedo Mota
Matrícula: 2018054990
================================================
------------------------------------------------
CONTROLES

Mouse (Movimento): movimentação do paddle
Mouse (Botão esquerdo): pausa/retomada do jogo
Mouse (Botão direito): pausa + mostrar estados dos objetos do jogo no console.
Barra de Espaço: relançar a bola (apenas após perder uma vida)
Q: fechar jogo
R: reiniciar jogo

------------------------------------------------
COMPILAÇÃO E EXECUÇÃO

O jogo deve ser compilado em sistema Linux (foi testado em distribuição manjaro, mas funciona em qualquer desde que
as bibliotecas corretas estejam instaladas).

É importante que estejam instalados os pacotes:
   > freeglut (biblioteca OpenGL que mantém o GLUT atualizado até hoje)
        em ubuntu/debian: sudo apt-get install freeglut3 freeglut3-dev libglew-dev
   > sdl2 (caso deseja testar com música e efeitos sonoros)
        em ubuntu/debian: sudo apt install libsdl2-dev libsdl2-2.2-0 -y
   > sdl2_mixer (caso deseja testar com música e efeitos sonoros)
        em ubuntu/debian: sudo apt install libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y

Para compilar, abra um terminal na pasta onde está esse arquivo de texto e execute o comando:
    make
Caso o SDL2 e SLD2_mixer estejam instalados, o jogo pode ser compilado com som, com o comando:
    make SOUND=1
Ambos os comandos gerarão um executável chamado "breakout", que inicia o jogo com o comando:
    ./breakout

Caso haja alguma dúvida ou a compilação não seja bem sucedida, por favor entre em contato comigo
por algum veículo da UFMG ou por e-mail.

------------------------------------------------
INFORMAÇÕES GERAIS

O seguinte trabalho prático é uma adaptação do jogo breakout de Atari 2600, feito usando OpenGL legado.
Algumas decisões de implementação:
   > O jogo está quase inteiro na classe Game, que contém métodos básicos de:
        - Inicialização
        - Desenho na tela do estado atual do jogo
        - Receber e processar entrada do teclado/mouse
   > Além disso, é calculada a lógica do jogo em cada frame do loop principal no main em glutMainLoop()
    (Seguindo uma ideia de padrão update, comum em programação de jogos e descrito melhor em https://gameprogrammingpatterns.com/update-method.html).
    Nesse esquema estão incluídos métodos para:
        - Calcular movimento e colisões
        - Mudança de estado do jogo
        - Realizar um desenho por frame
        - etc.
   > Os 3 elementos principais do jogo foram separados em suas próprias classes (Paddle, Ball e Brick) e contém toda a lógica individual
   em métodos internos, como atualização de estado ou informações de desenho.
   > O nível é uma matriz de inteiros, e cada inteiro corresponde a um tijolo, podendo ser ou não um tijolo especial, e tendo uma HP própria.
   > Optei pela movimentação do paddle seguindo o cursor do mouse ao invés do esquema detalhado no enunciado, por achar que
   simplifica a usabilidade.
   > O jogo tem uma contagem de vidas. Quando se perde uma vida, a bola é reposicionada em cima do paddle para o jogador
   lançá-la novamente. Isso é feito pressionando barra de espaço.

------------------------------------------------
FUNCIONALIDADES ADICIONAIS

Para a nota do trabalho, além das funcionalidades obrigatórias que foram implementadas, era necessário outras funcionalidades
a critério do aluno, então deixo aqui listado algumas coisas que eu implementei:

   > A posição que a bola acerta no paddle influencia sua velocidade: quanto mais nas bordas, mais é aumentada até um limite máximo,
   e vice-versa (com o limite mínimo).
   > Alguns tijolos contém modificadores de dificuldade ao acertá-los (tijolos verdes/vermelhos). Os verdes aumentam o tamanho do
   paddle em 25%, e os vermelhos o reduzem em 25%.
   > Os tijolos comuns contém HP, determinada pela sua cor. Os tijolos mais à frente são derrubados com 1 acerto, enquanto os mais posteriores
   são derrubados com 2, 3 ou até 4 acertos.
   > À medida que o jogo progride, a velocidade da bola aumenta gradualmente, para dificultar a progressão do jogador.
   > Quando a bola acerta um tijolo ou uma parede, a câmera sente um impacto e treme, para dar um polimento adicional ao jogo.
   > Som! O jogo possui música de fundo e sons quando a bola acerta parede, tijolos e o paddle (Só é acessível ao compilar se
   houver o SDL2 e o SDL2_mixer instalados).

------------------------------------------------