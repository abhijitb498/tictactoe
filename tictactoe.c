/* Tic Tac Toe Game
AUTHOR: ABHIJIT BAISHYA
LAST MODIFIED: 06.04.2021 */


#include <stdio.h>
#include <stdbool.h>

extern void get_copy_(char a[3][3], char b[3][3]);
extern void get_initboard_(char arr[3][3]);

void drawBoard(char boardarray[3][3]);
void markBoard(void);
void checkWin(char arr[3][3]);
void checkDraw(char arr[3][3]);
//void initBoard(char arr[3][3]);

char boardarray[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool draw=false;
bool win=false; 
bool play=true;
int pos1 = 0;
int pos2 = 10;

int main() {
    printf("\n\n\t\tWelcome to Two Player Tic Tac Toe Game\n");
    printf("\t\tThe Numbers denote the position you want to place your character in.\n\n\n");
    printf("\t\tPlayer 1: 'x', and Player 2: '0'\n\n\n");
    
    char response;
    bool status = true;

    while(status) {
        drawBoard(boardarray);
        while (!win && !draw) {
            markBoard();
        }
        printf("Want to play again? Y/N?\n");
        scanf(" %c",&response);
        if (response == 'y' || response == 'Y') {
            draw = false;
            win = false;
            pos1 = 0;
            pos2 = 10;
            get_initboard_(boardarray);
        }
        else if (response == 'n' || response == 'N') {
            status = false;
        }
    }

    //return 0;

}

void drawBoard(char boardarray[3][3]) {
    printf("\t\t--------------------------------------\n");
    printf("\t\t\t|\t\t|\t\n");
    printf("\t\t%c\t|\t%c\t|\t%c\n",boardarray[0][0],boardarray[0][1],boardarray[0][2]);
    printf("\t\t--------------------------------------\n");
    printf("\t\t\t|\t\t|\t\n");
    printf("\t\t%c\t|\t%c\t|\t%c\n",boardarray[1][0],boardarray[1][1],boardarray[1][2]);
    printf("\t\t--------------------------------------\n");    
    printf("\t\t\t|\t\t|\t\n");
    printf("\t\t%c\t|\t%c\t|\t%c\n",boardarray[2][0],boardarray[2][1],boardarray[2][2]);
    printf("\t\t--------------------------------------\n");
    
    return;
} 

void markBoard(void) {
    printf("Player 1 Enter:");

    scanf("%d",&pos1);
    while (pos1 < 1 || pos1 > 9 || pos1 == pos2) {
        printf("Invalid Choice, Enter Again: ");
        scanf("%d",&pos1);
    }
    
    if (pos1 >=1 && pos1 <=3) {
        boardarray[0][pos1-1] = 'x';
    }
    else if (pos1 >=4 && pos1 <=6) {
        boardarray[1][pos1-4] = 'x';
    }
    else {
        boardarray[2][pos1-7] = 'x';
    }

    drawBoard(boardarray);

    checkWin(boardarray);
    if (win) return;

    checkDraw(boardarray);
    if (draw) {
        printf("Match Draw!! Play Again.\n");
        return;
    }

    printf("Player 2 Enter:");
    scanf("%d",&pos2);
    while (pos2 < 1 || pos2 > 9 || pos2 == pos1) {
        printf("Invalid Choice, Enter Again: ");
        scanf("%d",&pos2);
    }
    
    if (pos2 >=1 && pos2 <=3) {
        boardarray[0][pos2-1] = '0';
    }
    else if (pos2 >=4 && pos2 <=6) {
        boardarray[1][pos2-4] = '0';
    }
    else {
        boardarray[2][pos2-7] = '0';
    }

    drawBoard(boardarray);

    checkWin(boardarray);
    if (win) return;

    checkDraw(boardarray);
    if (draw) {
        printf("Match Draw!! Play Again.\n");
        return;
    }

    return;
}


void checkWin(char arr[3][3]) {
    /*check for player 1 win*/
    char a[3][3];
    get_copy_(arr,a);

    
    if (a[0][0] + a[0][1] + a[0][2] == 360) {
        win = true;
        printf("Congrats! Player 1, You have Won!!\n");
        return;
    }
    else if (a[0][0] + a[0][1] + a[0][2] == 144) {
        win = true;
        printf("Congrats! Player 2, You have Won!!\n");
        return;
    }

    if (a[0][0] + a[1][0] + a[2][0] == 360) {
        win = true;
        printf("Congrats! Player 1, You have Won!!\n");
        return;
    }
    else if (a[0][0] + a[1][0] + a[2][0] == 144) {
        win = true;
        printf("Congrats! Player 2, You have Won!!\n");
        return;
    }
 
    if (a[0][0] + a[1][1] + a[2][2] == 360) {
        win = true;
        printf("Congrats! Player 1, You have Won!!\n");
        return;
    }
    else if (a[0][0] + a[1][1] + a[2][2] == 144) {
        win = true;
        printf("Congrats! Player 2, You have Won!!\n");
        return;
    }

    if (a[0][2] + a[1][1] + a[2][0] == 360) {
        win = true;
        printf("Congrats! Player 1, You have Won!!\n");
        return;
    }
    else if (a[0][2] + a[1][1] + a[2][0] == 144) {
        win = true;
        printf("Congrats! Player 2, You have Won!!\n");
        return;
    }

    if (a[1][0] + a[1][1] + a[1][2] == 360) {
        win = true;
        printf("Congrats! Player 1, You have Won!!\n");
        return;
    }
    else if (a[1][0] + a[1][1] + a[1][2]  == 144) {
        win = true;
        printf("Congrats! Player 2, You have Won!!\n");
        return;
    }

    if (a[0][1] + a[1][1] + a[2][1] == 360) {
        win = true;
        printf("Congrats! Player 1, You have Won!!\n");
        return;
    }
    else if (a[0][1] + a[1][1] + a[2][1] == 144) {
        win = true;
        printf("Congrats! Player 2, You have Won!!\n");
        return;
    }

    if (a[0][2] + a[1][2] + a[2][2] == 360) {
        win = true;
        printf("Congrats! Player 1, You have Won!!\n");
        return;
    }
    else if (a[0][2] + a[1][2] + a[2][2]  == 144) {
        win = true;
        printf("Congrats! Player 2, You have Won!!\n");
        return;
    }

    if (a[2][0] + a[2][1] + a[2][2] == 360) {
        win = true;
        printf("Congrats! Player 1, You have Won!!\n");
        return;
    }
    else if (a[2][0] + a[2][1] + a[2][2]  == 144) {
        win = true;
        printf("Congrats! Player 2, You have Won!!\n");
        return;
    }
    
    return;

}

void checkDraw(char arr[3][3]) {
    char a[3][3];
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            if (arr[i][j] != 'x' && arr[i][j] != '0') {
                draw = false;
                return;
            }
        }
    }
    draw = true;
    return;
}