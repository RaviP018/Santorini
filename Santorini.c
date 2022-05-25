#include <stdio.h>

int gameBoard[6][6];
int tempBoard[6][6];
int playerX, playerY;
int aiX, aiY;
int playerWin, aiWin;
int winner;
int count0;
int count4;


void reset() {
    for (int i = 0; i < 6; i++) {
        for (int j  = 0; j < 6; j++) {
            gameBoard[i][j] = 2;
            tempBoard[i][j] = 2;
        }        
    }
    playerX = -1;
    playerY = -1;
    aiX = -1;
    aiY = -1;
    playerWin = 0;
    aiWin = 0;
    winner = 0;
    count0 = 0;
    count4 = 0; 
}
    
void printBoard() {
    int counter = 1;
    int counter2 = 1;
    
    printf("\n");
    printf("  ");
    //Printing the Number label row at the top in the beginning
    for (int k = 1; k < 7; k++){
        printf("%i ", counter2);
        counter2++;
    }
    printf("\n");
    for (int i = 0; i < 6; i++) {
        //Printing the Number label column at the beginning
        printf("%i ", counter);  
        counter++;
        for (int j  = 0; j < 6; j++) {
            if (i == playerX && j == playerY) {
                printf("P ");
            }
            else if (i == aiX && j == aiY) {
                printf("A ");
                
            }
            else {
                printf("%i ", gameBoard[i][j]);    
            }
        }   
        printf("\n");
    }
}

void chooseX() {
    printf("Choose Builder's X position (1-6) \n");
    scanf("%d", &playerX);
    printf("\n");
}
    
void chooseY() {
    printf("Choose Builder's Y position (1-6) \n");
    scanf("%d", &playerY);
}
//Use chooseX and chooseY within ChoosePosition to get the Player's input    
void choosePosition() {
    printf("Choose Builder's X position (1-6) \n");
    scanf("%d", &playerX);
    while (playerX < 1 || playerX > 6) {
        chooseX();
    }
    printf("Choose Builder's Y position (1-6) \n");
    scanf("%d", &playerY);
    while (playerY < 1 || playerY > 6) {
        chooseY();
    }
    playerY = playerY - 1;
    playerX = playerX - 1;
}
    
void makePlayerMove() {
    int currPlayerX = playerX;
    int currPlayerY = playerY;
    
    printf("\n");
    printf("NEXT TURN: \n");
    choosePosition();
    
    //check for a vaild move
    while ((currPlayerX == playerX && currPlayerY == playerY) || (playerX == aiX && playerY == aiY) || currPlayerX - playerX > 1 || playerX - currPlayerX > 1 || currPlayerY - playerY > 1 || playerY - currPlayerY > 1){
        if (currPlayerX == playerX && currPlayerY == playerY){
            printf("You can not choose the position where your current builder is located \n");
        }
        if (playerX == aiX && playerY == aiY) {
            printf("You can not choose the position where the AI is located \n");
        }
        if (currPlayerX - playerX > 1 || playerX - currPlayerX > 1 || currPlayerY - playerY > 1 || playerY - currPlayerY > 1){
            printf("You can not choose that position, please choose a position adjacent to your current position \n");
        }
        choosePosition();
        
    }
    playerX = playerX;
    playerX = playerX;
}
void addAiMove() {
    //Minus 1 from every spot in the array unless it is the Ai's position, player's position, 
    for (int i = aiY-1; i > -1; i--){
        if(aiX == playerX && aiY == i){
            break;
        }
        // else if(gameBoard[aiX][i] == 4){
        //     gameBoard[aiX][i] = 4;
        // }
        else if(gameBoard[aiX][i] == 0){
            gameBoard[aiX][i] = 0;
        }
        else {
            gameBoard[aiX][i] -= 1;
        }
    }
    for(int i = aiY+1; i < 6; i++){
        if(aiX == playerX && aiY == i){
            break;
        }
        // else if(gameBoard[aiX][i] == 4){
        //     gameBoard[aiX][i] = 4;
        // }
        else if(gameBoard[aiX][i] == 0){
            gameBoard[aiX][i] = 0;
        }
        else {
            gameBoard[aiX][i] -= 1;
        }
    }
    for(int i = aiX-1; i > -1; i--){
        if(aiX == playerX && aiY == i){
            break;
        }
        // else if(gameBoard[i][aiY] == 4){
        //     gameBoard[i][aiY] = 4;
        // }
        else if(gameBoard[i][aiY] == 0){
            gameBoard[i][aiY] = 0;
        }
        else {
            gameBoard[i][aiY] -= 1;
        }
    }
    for(int i = aiX+1; i < 6; i++){
        if(aiX == playerX && aiY == i){
            break;
        }
        // else if(gameBoard[i][aiY] == 4){
        //     gameBoard[i][aiY] = 4;
        // }
        else if(gameBoard[i][aiY] == 0){
            gameBoard[i][aiY] = 0;
        }
        else {
            gameBoard[i][aiY] -= 1;
        }
    }
    for(int i = aiX-1, j = aiY-1; i > -1 && j > -1; i--, j-- ){
        if (i == playerX && j == playerY){
            break;
        }
        // else if(gameBoard[i][j] == 4){
        //     gameBoard[i][j] = 4;
        // }
        else if(gameBoard[i][j] == 0){
            gameBoard[i][j] = 0;
        }
        else{
            gameBoard[i][j] -= 1;
        }
    }
    for(int i = aiX-1, j = aiY+1; i > -1 && j < 6; i--, j++){
        if (i == playerX && j == playerY){
            break;
        }
        // else if(gameBoard[i][j] == 4){
        //     gameBoard[i][j] = 4;
        // }
        else if(gameBoard[i][j] == 0){
            gameBoard[i][j] = 0;
        }
        else{
            gameBoard[i][j] -= 1;
        }
    }
    for(int i = aiX+1, j = aiY-1; i < 6 && j > -1; i++, j--){
        if (i == playerX && j == playerY){
            break;
        }
        // else if(gameBoard[i][j] == 4){
        //     gameBoard[i][j] = 4;
        // }
        else if(gameBoard[i][j] == 0){
            gameBoard[i][j] = 0;
        }
        else{
            gameBoard[i][j] -= 1;
        }
    } 
    for(int i = aiX+1, j = aiY+1; i < 6 && j < 6; i++, j++){
        if (i == playerX && j == playerY){
            break;
        }
        // else if(gameBoard[i][j] == 4){
        //     gameBoard[i][j] = 4;
        // }
        else if(gameBoard[i][j] == 0){
            gameBoard[i][j] = 0;
        }
        else{
            gameBoard[i][j] -= 1;
        }
    } 
}

void addPlayerMove() {
    //Plus 1 from every spot in the array unless it is the Ai's position, player's position, 
    for(int i = playerY -1; i > -1; i--){
        if(aiX == playerX && aiY == i){
            break;
        }
        else if(gameBoard[playerX][i] == 4){
            gameBoard[playerX][i] = 4;
        }
        // else if (gameBoard[playerX][i] == 0) {
        //     gameBoard[playerX][i] = 0;
        // }
        else {
            gameBoard[playerX][i] += 1;
        }
    }
    for(int i = playerY +1; i < 6; i++) {
        if(aiX == playerX && aiY == i){
            break;
        }
        else if(gameBoard[playerX][i] == 4){
            gameBoard[playerX][i] = 4;
        }
        // else if (gameBoard[playerX][i] == 0) {
        //     gameBoard[playerX][i] = 0;
        // }
        else {
            gameBoard[playerX][i] += 1;
        }
    }
    for(int i = playerX -1; i > -1; i--){
        if(aiY == playerY && aiX == i){
            break;
        }
        else if(gameBoard[i][playerY] == 4){
            gameBoard[i][playerY] = 4;
        }
        // else if (gameBoard[playerX][i] == 0) {
        //     gameBoard[i][playerY] = 0;
        // }
        else {
            gameBoard[i][playerY] += 1;
        }
    }
    for(int i = playerX +1; i < 6; i++){
        if(aiY == playerY && aiX == i){
            break;
        }
        else if(gameBoard[i][playerY] == 4){
            gameBoard[i][playerY] = 4;
        }
        // else if (gameBoard[playerX][i] == 0) {
        //     gameBoard[i][playerY] = 0;
        // }
        else {
            gameBoard[i][playerY] += 1;
        }
    }
    for(int i = playerX-1, j = playerY-1; i > -1 && j > -1; i--, j--){
        if (i == aiX && j == aiY){
            break;
        }
        else if (gameBoard[i][j] == 4){
            gameBoard[i][j] = 4;
        }
        // else if (gameBoard[i][j] == 0){
        //     gameBoard[i][j] = 0;
        // }
        else{
            gameBoard[i][j] += 1;
        }
    }
    for(int i = playerX-1, j = playerY+1; i > -1 && j < 6; i--, j++){
        if (i == aiX && j == aiY){
            break;
        }
        else if (gameBoard[i][j] == 4){
            gameBoard[i][j] = 4;
        }
        // else if (gameBoard[i][j] == 0){
        //     gameBoard[i][j] = 0;
        // }
        else{
            gameBoard[i][j] += 1;
        }
    }
    for(int i = playerX+1, j = playerY-1; i < 6 && j > -1; i++, j--){
        if (i == aiX && j == aiY){
            break;
        }
        else if (gameBoard[i][j] == 4){
            gameBoard[i][j] = 4;
        }
        // else if (gameBoard[i][j] == 0){
        //     gameBoard[i][j] = 0;
        // }
        else{
            gameBoard[i][j] += 1;
        }
    } 
    for(int i = playerX+1, j = playerY+1; i < 6 && j < 6; i++, j++){
        if (i == aiX && j == aiY){
            break;
        }
        else if (gameBoard[i][j] == 4){
            gameBoard[i][j] = 4;
        }
        // else if (gameBoard[i][j] == 0){
        //     gameBoard[i][j] = 0;
        // }
        else{
            gameBoard[i][j] += 1;
        }
    }  
} 
//used to help choose the AI's next move
void copyBoard() {
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            tempBoard[i][j] = gameBoard[i][j];            
        }
    }
}
//ALL CHECK moves are to see if that adjacent spot of the AI is a good spot to move (checks the difference between 0's and 4's and the one with the highest positive difference is the best possible move for the AI)
int checkLeft(int board[6][6]){
    int check0 = 0;
    int check4 = 0;
    int tempaiX = aiX;
    int tempaiY = aiY-1;
    int diff = 0;

    if (tempaiY < 0 ) {
        return -100;
    }  
    else{
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == 0 && i != playerX && j != playerY && i != tempaiX && j != tempaiY){
                    check0 += 1;
                }
                if(board[i][j] == 4 && i != playerX && j != playerY && i != tempaiX && j != tempaiY){
                    check4 += 1;
                }
            }
        }
        diff = check0 - check4; 

        return diff;
    }
}
int checkDiagonalUpLeft(int board[6][6]) {
    int check0 = 0;
    int check4 = 0;
    int tempaiY = aiY-1;
    int tempaiX = aiX-1;
    int diff = 0;

    if(tempaiY < 0 || tempaiX < 0) {
        return -100;
    }
    else{
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == 0 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check0 += 1;
                }
                if(board[i][j] == 4 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check4 += 1;
                }
            }
        }
        diff = check0 - check4; 
        return diff;
    }
}
int checkUp(int board[6][6]){
    int check0 = 0;
    int check4 = 0;
    int tempaiY = aiY;
    int tempaiX = aiX-1;
    int diff = 0;

    if(tempaiX < 0){
        return -100;
    }
    else{
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == 0 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check0 += 1;
                }
                if(board[i][j] == 4 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check4 += 1;
                }
            }
        }
        diff = check0 - check4; 
        return diff;
    }

}
int checkDiagonalUpRight(int board[6][6]){
    int check0 = 0;
    int check4 = 0;
    int tempaiY = aiY+1;
    int tempaiX = aiX-1;
    int diff = 0;

    if(tempaiX < 0 || tempaiY > 5){
        return -100;
    }
    else{
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == 0 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check0 += 1;
                }
                if(board[i][j] == 4 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check4 += 1;
                }
            }
        }
        diff = check0 - check4; 
        return diff;
    }
}
int checkRight(int board[6][6]){
    int check0 = 0;
    int check4 = 0;
    int tempaiY = aiY + 1;
    int tempaiX = aiX;
    int diff = 0;

    if(tempaiY > 5){
        return -100;
    }
    else{
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == 0 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check0 += 1;
                }
                if(board[i][j] == 4 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check4 += 1;
                }
            }
        }
        diff = check0 - check4; 
        return diff;
    }
}
int checkDiagonalRightDown(int board[6][6]){
    int check0 = 0;
    int check4 = 0;
    int tempaiY = aiY + 1;
    int tempaiX = aiX + 1;
    int diff = 0;

    if(tempaiX > 5 || tempaiY > 5){
        return -100;
    }
    else{
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == 0 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check0 += 1;
                }
                if(board[i][j] == 4 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check4 += 1;
                }
            }
        }
        diff = check0 - check4;
        return diff;
    }
}
int checkDown(int board[6][6]){
    int check0 = 0;
    int check4 = 0;
    int tempaiY = aiY;
    int tempaiX = aiX + 1;
    int diff = 0;

    if(tempaiX > 5){
        return -100;
    }
    else{
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == 0 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check0 += 1;
                }
                if(board[i][j] == 4 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check4 += 1;
                }
            }
        }
        diff = check0 - check4; 
        return diff;
    }
}
int checkDiagonalDownLeft(int board[6][6]){
    int check0 = 0;
    int check4 = 0;
    int tempaiY = aiY - 1;
    int tempaiX = aiX + 1;
    int diff = 0;

    if(tempaiX < 0 || tempaiY > 5) {
        return -100;
    }
    else {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j] == 0 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check0 += 1;
                }
                if(board[i][j] == 4 && i != playerX && i != tempaiX && j != playerY && j != tempaiY){
                    check4 += 1;
                }
            }
        }
        diff = check0 - check4; 
        return diff;
    }
}


void makeAiMove() {
    copyBoard();
    int leftTotal;
    int upLeftTotal;
    int upTotal;
    int upRightTotal;
    int rightTotal;
    int downRightTotal;
    int downTotal;
    int downLeftTotal;
    int highestTotal;

    //Initializing int's that will help check which move has the highestTotal
    leftTotal = checkLeft(tempBoard);
    upLeftTotal = checkDiagonalUpLeft(tempBoard);
    upTotal = checkUp(tempBoard);
    upRightTotal = checkDiagonalUpRight(tempBoard);
    rightTotal = checkRight(tempBoard);
    downRightTotal = checkDiagonalRightDown(tempBoard);
    downTotal = checkDown(tempBoard);
    downLeftTotal = checkDiagonalDownLeft(tempBoard);

    //Check Which is the max highestTotal
    if (leftTotal >= upLeftTotal && leftTotal >= upTotal && leftTotal >= upRightTotal && leftTotal >= rightTotal && leftTotal >= downRightTotal && leftTotal >= downTotal && leftTotal >= downLeftTotal){
        highestTotal = leftTotal;
    }
    else if(upLeftTotal >= upTotal && upLeftTotal >= upRightTotal && upLeftTotal >= rightTotal && upLeftTotal >= downRightTotal && upLeftTotal >= downTotal && upLeftTotal >=downLeftTotal) {
        highestTotal = upLeftTotal;
    }
    else if(upTotal >= upRightTotal && upTotal >= rightTotal && upTotal >= downRightTotal && upTotal >= downTotal && upTotal >= downLeftTotal){
        highestTotal = upTotal;        
    }
    else if(upRightTotal >= rightTotal && upRightTotal >= downRightTotal && upRightTotal >= downTotal && upRightTotal >= downLeftTotal){
        highestTotal = upRightTotal;
    }
    else if(rightTotal >= downRightTotal && rightTotal >= downTotal && rightTotal >= downLeftTotal){
        highestTotal = rightTotal;
    }
    else if(downRightTotal >= downTotal && downRightTotal >= downLeftTotal) {
        highestTotal = downRightTotal;
    }
    else if(downTotal >= downLeftTotal){
        highestTotal = downTotal;
    }
    else{
        highestTotal = downLeftTotal;
    }
    
    //Place the Ai's Location

    if (highestTotal == leftTotal){
        aiY = aiY - 1;
    }
    else if(highestTotal == upLeftTotal){
        aiY = aiY - 1;
        aiX = aiX - 1;
    }
    else if(highestTotal == upTotal){
        aiX = aiX - 1;
    }
    else if(highestTotal == upRightTotal){
        aiX = aiX - 1;
        aiY = aiY + 1;
    }
    else if(highestTotal == rightTotal){
        aiY = aiY + 1;
    }
    else if(highestTotal == downRightTotal){
        aiX = aiX + 1;
        aiY = aiY + 1;
    }
    else if(highestTotal == downTotal){
        aiX = aiX + 1;
    }
    else if(highestTotal == downLeftTotal){
        aiX = aiX + 1;
        aiY = aiY - 1;
    }
    else if(aiX+1 < 6 && aiY < 6){
        aiX = aiX + 1;
        aiY = aiY;
    }
    else{
        aiX = aiX - 1;
        aiY = aiY;
    }
}
void checkBoardForWinner(){
    int tempCount = 0;
    int tempCount1 = 0;
    for (int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(gameBoard[i][j] == 0){
                tempCount += 1;
            }
            if(gameBoard[i][j] == 4){
                tempCount1 += 1;
            }
        }
    }
    count0 = tempCount;
    count4 = tempCount1;
}


void playGame() {
    reset();
    choosePosition();
    printBoard();

    if(playerY-1 >= 0) {
        aiX = playerX;
        aiY = playerY - 1;
    }
    else if (playerY-1 < 0) {
        aiX = playerX;
        aiY = playerY + 1; 
    }
    printBoard();
    checkBoardForWinner();
    while(count0 < 10 || count4 < 10){
        makePlayerMove();
        addPlayerMove();
        printBoard();
        checkBoardForWinner();
        if(count0 >= 10 || count4 >= 10){
            break;
        }
        printf("\n");
        makeAiMove();
        addAiMove();
        printBoard();
        checkBoardForWinner();
    }
    printf("\n");
    printf("GAME OVER");
    printf("\n");
    if(count4 >= 10){
        printf("YOU WON!!!");
        printf("\n");
    }
    if(count0 >= 10){
        printf("YOU LOST :(");
        printf("\n");
    }
}
int main() {
    int again = 1;
    reset();
    while(again == 1){
        printf("START GAME: \n");
        playGame();
        printf("Would you like to play again? \n");
        printf("Press 1 to play again OR any other number to stop");
        printf("\n");
        scanf("%d", &again);
    }
}