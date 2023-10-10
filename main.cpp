#include <iostream>

#define SQUARE_SIZE

bool* sudokuRow=new bool[9];
bool* sudokuCol=new bool[9];
bool* sudokuSqr=new bool[9];

void initializeSquare(short** sudokuSquare){
    for(int i=0;i<3;i++){
        sudokuSquare[i]=new short[3];
        for(int j=0;j<3;j++){
            std::cin >> sudokuSquare[i][j];
        }
    }
}

void printSquare(short** sudokuSquare){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char value = sudokuSquare[i][j]==0 ? '*' : sudokuSquare[i][j]+48;
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
}

void checkSquare(short** sudokuSquare){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudokuSquare[i][j]!=0){
                sudokuSqr[sudokuSquare[i][j]-1] = true;
            }
        }
    }
}

void checkRow(short** sudokuSquare){
    for(int i=0;i<3;i++){
        if(sudokuSquare[0][i]!=0){
            sudokuCol[sudokuSquare[0][i]-1] = true;
        }
    }
}

void checkColumn(short** sudokuSquare){
    for(int i=0;i<3;i++){
        if(sudokuSquare[0][i]!=0){
            sudokuRow[sudokuSquare[i][0]-1] = true;
        }
    }
}

void printRowStats(){
    std::cout<<"Filas: ";
    for (short i=0;i<9;i++){
        std::cout<<sudokuRow[i];
    }
    std::cout<<std::endl;
}

void printColStats(){
    std::cout<<"Columnas: ";
    for (short i=0;i<9;i++){
        std::cout<<sudokuCol[i];
    }
    std::cout<<std::endl;
}

void printSqrStats(){
    std::cout<<"Cuadrado: ";
    for (short i=0;i<9;i++){
        std::cout<<sudokuSqr[i];
    }
    std::cout<<std::endl;
}

int main(){
    std::cout << "Please write the values of the sudoku board: ";
    
    short** sudokuSquare = new short*[3];
    
    initializeSquare(sudokuSquare);
    
    printSquare(sudokuSquare);

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