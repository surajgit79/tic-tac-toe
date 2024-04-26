#include <stdio.h>

void displayBoard(char board[3][3])
{
    printf("  1 2 3\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("%c", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("  -+-+-\n");
    }
}

// Function to check if a player has won
int checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1; // Row win

        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1; // Column win

    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1; // Diagonal win (top-left to bottom-right)

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1; // Diagonal win (top-right to bottom-left)

    return 0;
}

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Initialize an empty board
    char player = 'X'; // Player 'X' goes first
    int row, col;
    int moves = 0;

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 'X' goes first.\n");

    while (1)
    {
        displayBoard(board);

        printf("Player '%c', enter row (1-3) and column (1-3): ", player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row - 1][col - 1] = player;
        moves++;

        if (checkWin(board, player))
        {
            displayBoard(board);
            printf("Player '%c' wins!\n", player);
            break;
        }
        else if (moves == 9)
        {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X'; // Switch player
    }

    return 0;
}
