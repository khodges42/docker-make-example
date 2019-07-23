#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>

int sz;

int randnum(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void randomColor(){
    char coloruni[12];
    sprintf(coloruni, "\x1B[%dm",  randnum(31,37));
    write(STDOUT_FILENO, coloruni, 6);
}

void populateBoard(bool (*board)[sz]){
    int i, j;
    for (i = 0; i < sz; i++){
        for (j = 0; j < sz; j++){
            board[i][j] = rand() & 1;
        }
    }
}

void displayBoard(bool (*board)[sz]){
    int i, j;
    write(STDOUT_FILENO, "\x33\e[H", 4) ;
    for (i = 0; i < sz; i++){
        for (j = 0; j < sz; j++){
            if (board[i][j]){
                randomColor();
                write(STDOUT_FILENO, "\xE2\xAC\xA4", 6);
            }
            else{
                //write(STDOUT_FILENO, "\xE2\x96\x88", 6);
                write(STDOUT_FILENO, " ", 1);
            }
            
        }
        write(STDOUT_FILENO, "\x0a", 2);
    }
}

void evolve(bool (*board)[sz])
{
	bool (*univ)[sz] = board;
	bool new[sz][sz];
 
	for (int x = 0; x < sz; x++){
        for (int y = 0; y < sz; y++){
            int n = 0;
            for (int y1 = y - 1; y1 <= y + 1; y1++)
                for (int x1 = x - 1; x1 <= x + 1; x1++)
                    if (univ[(y1 + sz) % sz][(x1 + sz) % sz])
                        n++;
    
            if (univ[y][x]) n--;
            new[y][x] = (n == 3 || (n == 2 && univ[y][x]));
        }
    } 
    for (int x = 0; x < sz; x++){
        for (int y = 0; y < sz; y++){
            univ[y][x] = new[y][x];
        }
    } 
}

int main(){
    sz = 40;
    srand(time(0));
    bool board[sz][sz];
    populateBoard(board);
    for(int i = 1000; i > 0; i--){
        evolve(board);
        displayBoard(board);
    }
    return 0;
}

