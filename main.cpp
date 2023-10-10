#include <iostream>

#define SQUARE_SIZE 3
#define BOARD_SIZE 9

bool* sudokuRow=new bool[BOARD_SIZE];
bool* sudokuCol=new bool[BOARD_SIZE];
bool* sudokuSqr=new bool[BOARD_SIZE];

void initializeSquare(short** sudokuSquare){
    for(int i=0;i<SQUARE_SIZE;i++){
        sudokuSquare[i]=new short[SQUARE_SIZE];
        for(int j=0;j<SQUARE_SIZE;j++){
            std::cin >> sudokuSquare[i][j];
        }
    }
}

void initializeBoard(short** sudokuBoard){
    for(int i=0;i<BOARD_SIZE;i++){
        sudokuBoard[i]=new short[BOARD_SIZE];
        for(int j=0;j<BOARD_SIZE;j++){
            std::cin >> sudokuBoard[i][j];
        }
    }
}

void printSquare(short** sudokuSquare){
    for(int i=0;i<SQUARE_SIZE;i++){
        for(int j=0;j<SQUARE_SIZE;j++){
            char value = sudokuSquare[i][j]==0 ? '*' : sudokuSquare[i][j]+48;
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
}

void printBoard(short** sudokuBoard){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            char value = sudokuBoard[i][j]==0 ? '*' : sudokuBoard[i][j]+48;
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
}

void checkSquare(short** sudokuSquare){
    for(int i=0;i<SQUARE_SIZE;i++){
        for(int j=0;j<SQUARE_SIZE;j++){
            if(sudokuSquare[i][j]!=0){
                sudokuSqr[sudokuSquare[i][j]-1] = true;
            }
        }
    }
}

void checkRow(short** sudokuSquare){
    for(int i=0;i<SQUARE_SIZE;i++){
        if(sudokuSquare[0][i]!=0){
            sudokuCol[sudokuSquare[0][i]-1] = true;
        }
    }
}

void checkColumn(short** sudokuSquare){
    for(int i=0;i<SQUARE_SIZE;i++){
        if(sudokuSquare[0][i]!=0){
            sudokuRow[sudokuSquare[i][0]-1] = true;
        }
    }
}

void printRowStats(){
    std::cout<<"Filas: ";
    for (short i=0;i<BOARD_SIZE;i++){
        std::cout<<sudokuRow[i];
    }
    std::cout<<std::endl;
}

void printColStats(){
    std::cout<<"Columnas: ";
    for (short i=0;i<BOARD_SIZE;i++){
        std::cout<<sudokuCol[i];
    }
    std::cout<<std::endl;
}

void printSqrStats(){
    std::cout<<"Cuadrado: ";
    for (short i=0;i<BOARD_SIZE;i++){
        std::cout<<sudokuSqr[i];
    }
    std::cout<<std::endl;
}

int main(){
    std::cout << "Please write the values of the sudoku board: ";
    
    short** sudokuSquare = new short*[SQUARE_SIZE];
    short** sudokuBoard = new short*[BOARD_SIZE];
    
    //initializeSquare(sudokuSquare);
    initializeBoard(sudokuBoard);
    
    printSquare(sudokuSquare);
    printBoard(sudokuBoard);

    checkSquare(sudokuSquare);
    checkRow(sudokuSquare);
    checkColumn(sudokuSquare);
    
    printSqrStats();
    printColStats();
    printRowStats();
}

/* Sudoku sample

4 1 3  8 2 5  6 7 9
5 6 7  1 4 9  8 3 2
2 8 9  7 3 6  1 4 5

1 9 5  4 6 2  7 8 3
7 2 6  9 8 3  5 1 4
3 4 8  5 1 7  2 9 6

8 5 1  6 9 4  3 2 7
9 7 2  3 5 8  4 6 1
6 3 4  2 7 1  9 5 8

*/