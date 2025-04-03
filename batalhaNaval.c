#include <stdio.h>

#define LINHA 10
#define COLUNA 10

int main(){
    //vetor que define cada coluna por letra
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //matriz tabuleiro imprimi 10x10
    int tabuleiro[LINHA][COLUNA];
    

    for (int i = 0; i < LINHA; i++) {//imprimi o tabuleiro em 0.
        for (int j = 0; j < COLUNA; j++){
            tabuleiro[i][j] = 0;
        }
    }
    /*Cruz, Cone e octaedro foram feito por aninhamento, mais flexiveis para futura adições, como o exemplo que dei
    na parte do octaedro*/
    //variaveis para cruz
    int cruz1 = 1, cruz2 = 1;
    //utilizei for's aninhados para iniciar uma cruz.   
    for (int i = cruz1 - 1; i <= cruz1 + 1; i++) {
        tabuleiro[i][cruz2] = 1;

            for (int j = cruz2 - 1; j <= cruz2 + 1; j++) {
                tabuleiro[cruz1][j] = 1;
            }
    }
    //variaveis para o cone.
    int cone1 = 6, cone2 = 3;
    //utilizei o limite de for's aninhados para iniciar um cone.
    for (int i = cone1; i <= cone1 + 2; i++) {
        tabuleiro[i][cone2] = 1;

            for (int j = cone2 - 1; j <= cone2 + 1; j++) {
                tabuleiro[cone1 + 1][j] = 1;

                    for (int j = cone2 - 2; j <= cone2 +2; j++){
                        tabuleiro[cone1 + 2][j] = 1;
                    }
            }
    }
    //variaveis para octaedro.
    int octaedro1 = 1, octaedro2 = 6;
/*ultrapassei o limite recomendado para aninhamentos pois achei mais flexivel assim,
mesmo sendo um pouco mais dificil de entender, pois posso mudar a posição do mesmo mexendo nas variaveis,
é complicado o codigo... mas achei eficiente para talvez colocar scanf para modificar posições de cada ataque,
pois só baste mexer nas variaveis*/
    for (int i = octaedro1; i <= octaedro1 + 4; i++) {//primeiro for ira inicar o octaedro na celula linha[2]coluna[7]
        tabuleiro[i][octaedro2] = 1;

            for (int j = octaedro2 - 1; j <= octaedro2 + 1; j++) {
                tabuleiro[octaedro1 + 1][j] = 1;

                    for (int j = octaedro2 - 2; j <= octaedro2 + 2; j++){
                        tabuleiro[octaedro1 + 2][j] = 1;

                        for (int j = octaedro2 - 1; j <= octaedro2 + 1; j++) {
                            tabuleiro[octaedro1 + 3][j] = 1;
                        }
                    }
            }
    }
    
    printf("  "); //imprimi espaços para alinhas as letras com as colunas.

    for (int i = 0; i < 10; i++) {
        printf(" %c", linha[i]);
    }

    printf("\n"); //pula uma linha para iniciar o segundo loop

    for (int i = 0; i < LINHA; i++) {
        printf("%2d", i + 1);

            for (int j = 0; j < COLUNA; j++) {
                printf(" %d", tabuleiro[i][j]);
            }
        printf("\n"); //pula uma linha a cada loop do for aninhado
    }

    return 0;
}