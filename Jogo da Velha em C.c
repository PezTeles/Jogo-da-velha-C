#include <stdio.h>


char jogo[3][3];
char jogador1[50], jogador2[50];

int main() {
    int i, j, posicao, x, y, jogadas, ganhou, ordem, op;

    printf("Jogador 1 digite seu nome: ");
    fgets(jogador1, 50, stdin);
    printf("Jogador 2 digite seu nome: ");
    fgets(jogador2, 50, stdin);

    do {
        // Inicializar matriz
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                jogo[i][j] = ' ';
            }
        }

        jogadas = 0;
        ganhou = 0;
        ordem = 1;

        do {
            // Imprimir o tabuleiro com posições numéricas
            printf("\n");
            for(i = 0; i < 3; i++) {
                printf("\t");
                for(j = 0; j < 3; j++) {
                    int num_pos = i * 3 + j + 1;
                    if(jogo[i][j] == ' ')
                        printf(" %d ", num_pos);
                    else
                        printf(" %c ", jogo[i][j]);
                    if(j < 2)
                        printf("|");
                }
                if(i < 2)
                    printf("\n\t-----------\n");
            }

            // Mostrar quem vai jogar
            printf("\n\nVez de %s", (ordem == 1) ? jogador1 : jogador2);

            // Solicitar posição válida (1 a 9)
            do {
                printf("Digite a posição (1 a 9) onde deseja jogar: ");
                scanf("%d", &posicao);
                while(getchar() != '\n');

                x = (posicao - 1) / 3;
                y = (posicao - 1) % 3;
            } while(posicao < 1 || posicao > 9 || jogo[x][y] != ' ');

            // Marcar jogada
            jogo[x][y] = (ordem == 1) ? 'x' : '0';
            jogadas++;
            ordem = (ordem == 1) ? 2 : 1;

            // Verificar ganhador
            for(i = 0; i < 3; i++) {
                if((jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2] && jogo[i][0] != ' ') ||
                   (jogo[0][i] == jogo[1][i] && jogo[1][i] == jogo[2][i] && jogo[0][i] != ' ')) {
                    ganhou = 1;
                    break;
                }
            }
            if(!ganhou) {
                if((jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[0][0] != ' ') ||
                   (jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[0][2] != ' ')) {
                    ganhou = 1;
                }
            }
        } while(ganhou == 0 && jogadas < 9);

        if(ganhou) {
            printf("\nParabens. Voce venceu %s\n", (ordem == 1) ? jogador2 : jogador1);
        } else {
            printf("\nQue feio. Ninguem venceu!\n\n");
        }

        printf("Deseja jogar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &op);
        while(getchar() != '\n');
    } while(op == 1);

    return 0;
}
