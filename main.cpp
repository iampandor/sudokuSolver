#include <iostream>

int main(){
    std::cout << "Please write the values of the sudoku board: ";
    bool* sudokuRow=new bool[9];
    bool* sudokuCol=new bool[9];
    bool* sudokuSqr=new bool[9];
    
    short** sudokuSquare = new short*[3];
    
    for(int i=0;i<3;i++){
        sudokuSquare[i]=new short[3];
        for(int j=0;j<3;j++){
            std::cin >> sudokuSquare[i][j];
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char value = sudokuSquare[i][j]==0 ? '*' : sudokuSquare[i][j]+48;
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }

    for (short i=1;i<10;i++){
        sudokuSqr[i-1] = false;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudokuSquare[i][j]!=0){
                sudokuSqr[sudokuSquare[i][j]-1] = true;
            }
        }
        if(sudokuSquare[0][i]!=0){
            sudokuCol[sudokuSquare[0][i]-1] = true;
        }
        if(sudokuSquare[0][i]!=0){
            sudokuRow[sudokuSquare[i][0]-1] = true;
        }
    }
    std::cout<<"Cuadrado: ";
    for (short i=0;i<9;i++){
        std::cout<<sudokuSqr[i];
    }
    std::cout<<std::endl<<"Columnas: ";
    for (short i=0;i<9;i++){
        std::cout<<sudokuCol[i];
    }
    std::cout<<std::endl<<"Filas: ";
    for (short i=0;i<9;i++){
        std::cout<<sudokuRow[i];
    }
    std::cout<<std::endl;
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