#include <stdio.h>
#include <stdbool.h>
#define sz 10
int main(){
    bool *board[sz][sz];
    startBoard(board);
    return 0;
}

void startBoard(bool ** board){
    int i, j;
    for (i = 0; i < sz; i++){
        for (j = 0; j < sz; j++){
            board[i][j] = false;
        }
    }
}