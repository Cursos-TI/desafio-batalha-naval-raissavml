#include <stdio.h>
#include <string.h>

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
                    printf("\n");
                }
            }
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
            printf("\n");
        }
    }
    else if (shipNumber == 3)
    {
        if (field[startShipRow - 1][startShipCol - 1] == 0 && field[startShipRow][startShipCol] == 0 && field[startShipRow + 1][startShipCol + 1] == 0)
        {
            if (startShipRow < 9 && startShipCol < 9)
            {
                printf("\nObrigada, capitão! Iremos manobrar a embarcação!\n");
                field[startShipRow - 1][startShipCol - 1] = 3;
                field[startShipRow][startShipCol] = 3;
                field[startShipRow + 1][startShipCol + 1] = 3;
                printf("Embarcação posicionada, Capitão!\n");
                printf("\n");
                printFieldAndShip(10, 10, field);
            }
            else
            {
                printf("Esta coordenada causará colisão dos navios.\n  Conforme protocolo, precisamos de uma nova coordenada para a embarcação, capitão.\n");
                printf("Reanalise no campo de batalha a posição das embarcações presentes, e considerando que a frente do porta-aviões se encontra-se na casa superior à esquerda e ele não pode ocupar nenhuma casa em que já estejam presentes embarcações, selecione:\n");
                printf("- A linha em que  estará a frente do porta-aviões: \n");
                scanf("%d", &startShipRow);
                printf("- A coluna em que o porta-aviões se posicionará: \n");
                scanf("%d", &startShipCol);
                verifyShipPosition(10, 10, field, startShipRow, startShipCol, 3);
                printf("\n");
            }
        }
        else
        {
            printf("Esta coordenada causará colisão dos navios.\n  Conforme protocolo, precisamos de uma nova coordenada para a embarcação, capitão.\n");
            printf("Reanalise no campo de batalha a posição das embarcações presentes, e considerando que a frente do porta-aviões se encontra-se na casa superior à esquerda e ele não pode ocupar nenhuma casa em que já estejam presentes embarcações, selecione:\n");
            printf("- A linha em que  estará a frente do porta-aviões: \n");
            scanf("%d", &startShipRow);
            printf("- A coluna em que o porta-aviões se posicionará: \n");
            scanf("%d", &startShipCol);
            verifyShipPosition(10, 10, field, startShipRow, startShipCol, 3);
            printf("\n");
        }
    }
    else if (shipNumber == 4)
    {
        if (field[startShipRow - 1][startShipCol + 1] == 0 && field[startShipRow][startShipCol] == 0 && field[startShipRow + 1][startShipCol - 1] == 0)
        {
            if (startShipRow < 9 && startShipCol < 9)
            {
                printf("\nObrigada, capitão! Iremos manobrar a embarcação!\n");
                field[startShipRow - 1][startShipCol + 1] = 4;
                field[startShipRow][startShipCol] = 4;
                field[startShipRow + 1][startShipCol - 1] = 4;
                printf("Embarcação posicionada, Capitão!\n");
                printf("\n");
                printFieldAndShip(10, 10, field);
            }
            else
            {
                printf("Esta coordenada causará colisão dos navios.\n  Conforme protocolo, precisamos de uma nova coordenada para a embarcação, capitão.\n");
                printf("Reanalise no campo de batalha a posição das embarcações presentes, e considerando que a frente do encouraçado se encontra-se na casa superior à direita e ele não pode ocupar nenhuma casa em que já estejam presentes embarcações, selecione:\n");
                printf("- A linha em que  estará a frente do encouraçado: \n");
                scanf("%d", &startShipRow);
                printf("- A coluna em que o encouraçado se posicionará: \n");
                scanf("%d", &startShipCol);
                verifyShipPosition(10, 10, field, startShipRow, startShipCol, 4);
                printf("\n");
            }
        }
        else
        {
            printf("Esta coordenada causará colisão dos navios.\n  Conforme protocolo, precisamos de uma nova coordenada para a embarcação, capitão.\n");
            printf("Reanalise no campo de batalha a posição das embarcações presentes, e considerando que a frente do encouraçado se encontra-se na casa superior à direita e ele não pode ocupar nenhuma casa em que já estejam presentes embarcações, selecione:\n");
            printf("- A linha em que  estará a frente do encouraçado: \n");
            scanf("%d", &startShipRow);
            printf("- A coluna em que o encouraçado se posicionará: \n");
            scanf("%d", &startShipCol);
            verifyShipPosition(10, 10, field, startShipRow, startShipCol, 4);
            printf("\n");
        }
    }

    return 0;
};

// Place Ship Function
void placeShip(int rows, int columns, int field[rows][columns])
{
    // Set ship type to visually distinguish them and improve the gameplay experience
    int ship1[1][3] = {{1, 1, 1}};
    int ship2[3][1] = {{2}, {2}, {2}};
    int ship3[3][3] = {{3, 0, 0}, {0, 3, 0}, {0, 0, 3}};
    int ship4[3][3] = {{0, 0, 4}, {0, 4, 0}, {4, 0, 0}};
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
    printf("Porta-aviões: \n");
    printFieldAndShip(1, 3, ship1);
    printf("Encouraçado:\n");
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

    printf("Analise no campo de batalha a posição das embarcações presentes, e considerando que a frente do porta-aviões se encontra-se na casa superior à esquerda e ele não pode ocupar nenhuma casa em que já estejam presentes embarcações, selecione:\n");
    printf("- A linha em que  estará a frente do porta-aviões: \n");
    scanf("%d", &startShipRow);
    printf("- A coluna em que o porta-aviões se posicionará: \n");
    scanf("%d", &startShipCol);
    verifyShipPosition(10, 10, field, startShipRow, startShipCol, 3);

    printf("Analise no campo de batalha a posição das embarcações presentes, e considerando que a frente do encouraçado se encontra-se na casa superior à direita e ele não pode ocupar nenhuma casa em que já estejam presentes embarcações, selecione:\n");
    printf("- A linha em que  estará a frente do encouraçado: \n");
    scanf("%d", &startShipRow);
    printf("- A coluna em que o encouraçado se posicionará: \n");
    scanf("%d", &startShipCol);
    verifyShipPosition(10, 10, field, startShipRow, startShipCol, 4);
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
