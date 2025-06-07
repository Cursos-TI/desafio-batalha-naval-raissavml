#include <stdio.h>
#include <string.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

// Print field and ship function
int printFieldAndShip(int rows, int columns, int field[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

// Verify ship position
int verifyShipPosition(int rows, int columns, int field[rows][columns], int startShipRow, int startShipCol, int shipNumber)
{

    if (shipNumber == 2)
    {
        if (field[startShipRow - 1][startShipCol] == 0 && field[startShipRow][startShipCol] == 0 && field[startShipRow + 1][startShipCol] == 0)
        {
            if (startShipRow < 9)
            {
                printf("\nObrigada, capitão! Iremos manobrar a embarcação!\n");
                field[startShipRow - 1][startShipCol - 1] = 2;
                field[startShipRow][startShipCol - 1] = 2;
                field[startShipRow + 1][startShipCol - 1] = 2;
                printf("Embarcação posicionada, Capitão!\n");
                printf("\n");
                printFieldAndShip(10, 10, field);
            }
            else
            {
                printf("\nCapitão, a embarcação está se direcionando para território inimigo! \nPrecisamos alertar a tripulação para retroceder ao Km 8.\n");
                if (field[7][startShipCol - 1] == 0 && field[8][startShipCol - 1] == 0 && field[9][startShipCol - 1] == 0)
                {
                    field[7][startShipCol - 1] = 2;
                    field[8][startShipCol - 1] = 2;
                    field[9][startShipCol - 1] = 2;
                    printf("Embarcação em segurança, Capitão!\n");
                    printf("\n");
                    printFieldAndShip(10, 10, field);
                }
                else
                {
                    printf("Esta coordenada causará colisão dos navios.\n  Conforme protocolo, precisamos de uma nova coordenada para a embarcação, capitão.\n");
                    printf("Reanalise o campo de batalha, a posição do contratorpedeiro, e considerando a frente do navio como a casa superior e que o submarino não pode passar por baixo do contratorpedeiro, selecione:\n");
                    printFieldAndShip(10, 10, field);
                    printf("- A linha em que  estará a frente do submarino: \n");
                    scanf("%d", &startShipRow);
                    printf("- A coluna em que o submarino se posicionará: \n");
                    scanf("%d", &startShipCol);
                    printf("\nObrigada, capitão! Iremos manobrar a embarcação!\n");
                    verifyShipPosition(10, 10, field, startShipRow, startShipCol, 2);
                }
                printf("\n");
            }
        } else{
            printf("Esta coordenada causará colisão dos navios.\n  Conforme protocolo, precisamos de uma nova coordenada para a embarcação, capitão.\n");
                    printf("Reanalise o campo de batalha, a posição do contratorpedeiro, e considerando a frente do navio como a casa superior e que o submarino não pode passar por baixo do contratorpedeiro, selecione:\n");
                    printFieldAndShip(10, 10, field);
                    printf("- A linha em que  estará a frente do submarino: \n");
                    scanf("%d", &startShipRow);
                    printf("- A coluna em que o submarino se posicionará: \n");
                    scanf("%d", &startShipCol);
                    printf("\nObrigada, capitão! Iremos manobrar a embarcação!\n");
                    verifyShipPosition(10, 10, field, startShipRow, startShipCol, 2);
        }
    }
    return 0;
};

// Place Ship Function
void placeShip(int rows, int columns, int field[rows][columns])
{
    // Set ship type to visually distinguish them and improve the gameplay experience
    int ship1[1][3] = { {1, 1, 1} };
    int ship2[3][1] = { {2}, {2}, {2} };
    int startShipRow;
    int startShipCol;

    printf("Esse é o seu campo de batalha:\n");
    printf("\n");
    printFieldAndShip(10, 10, field);
    printf("Vamos ocupá-lo com seus navios?\n");
    printf("Conheça sua frota:\n");
    printf("\n");
    printf("Contratorpedeiro: \n");
    printFieldAndShip(1, 3, ship1);
    printf("Submarino:\n");
    printFieldAndShip(3, 1, ship2);
    printf("Analise o campo de batalha e, considerando que a frente do navio é a casa mais a esquerda, selecione:\n");
    printf("- A linha em que o contratorpedeiro se posicionará: \n");
    scanf("%d", &startShipRow);
    printf("- A coluna em que estará a frente do contratorpedeiro: \n");
    scanf("%d", &startShipCol);
    if (startShipCol < 9)
    {
        printf("\nObrigada, capitão! Iremos manobrar a embarcação!\n");
        field[startShipRow - 1][startShipCol - 1] = 1;
        field[startShipRow - 1][startShipCol] = 1;
        field[startShipRow - 1][startShipCol + 1] = 1;
        printf("Embarcação posicionada, Capitão!\n");
        printf("\n");
        printFieldAndShip(10, 10, field);
    }
    else
    {
        printf("\nCapitão, a embarcação está se direcionando para território inimigo! \nPrecisamos alertar a tripulação oara retroceder ao Km 8.\n");
        field[startShipRow - 1][7] = 1;
        field[startShipRow - 1][8] = 1;
        field[startShipRow - 1][9] = 1;
        printf("Embarcação em segurança, Capitão!\n");
        printf("\n");
        printFieldAndShip(10, 10, field);
    }

    printf("Analise o campo de batalha, a posição do contratorpedeiro, e considerando que a frente do submarino é a casa superior e ele não pode passar por baixo do contratorpedeiro, selecione:\n");
    printf("- A linha em que  estará a frente do submarino: \n");
    scanf("%d", &startShipRow);
    printf("- A coluna em que o submarino se posicionará: \n");
    scanf("%d", &startShipCol);
    verifyShipPosition(10, 10, field, startShipRow, startShipCol, 2);
}

// Menu Function
void menu(int rows, int columns, int field[rows][columns])
{
    int option;

    printf("Menu Principal\n");
    printf("1. Ver as regras\n");
    printf("2. Iniciar o jogo\n");
    printf("3. Sair\n");
    printf("Escolha uma opção digitando o número: \n");
    scanf("%d", &option);

    switch (option)
    {
    char saida;
    case 1:
        // Rulles
        printf("Você possui um tabuleiro de 10 x 10, onde deve posicionar seus navios para a batalha.\n Você receberá uma frota de 4 navios do mesmo tamanho (3 casas), para posicionar na sua área de combate. \n");
        printf("Um navio deve ser posicionado na vertical, um na horizontal e dois na diagonal. \n Mas dois navios não podem ocupar a mesma casa do tabuleiro ao mesmo tempo. \n");
        printf("Pronto para posicionar sua frota?\n");
        placeShip(10, 10, field);

        break;
    case 2:
        // Play
        printf("Pronto para posicionar os seus navios?\n");
        placeShip(10, 10, field);
        break;
    case 3:
        // End game
        printf("Já vai? Digite s para sim e n para não. \n");
        scanf(" %c", &saida);
        (saida == 'n' || saida == 'N') ? placeShip(10, 10, field) : printf("Foi bom te ter por aqui! Volte logo!\n");
        break;
    default:
        printf("Opção inválida, tente novamente.\n");
        menu(10, 10, field);
    }
}

int main()
{
    int field[10][10] = {0};

    menu(10, 10, field);
}
