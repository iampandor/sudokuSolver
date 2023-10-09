#include <iostream>

int main(){
    std::cout << "Please write the values of the sudoku board: ";
    bool* sudokuLine=new bool[9];
    
    short** sudokuBoard = new short*[3];
    
    for(int i=0;i<3;i++){
        sudokuBoard[i]=new short[3];
        for(int j=0;j<3;j++){
            std::cin >> sudokuBoard[i][j];
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char value = sudokuBoard[i][j]==0 ? '*' : sudokuBoard[i][j]+48;
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }

    for (short i=1;i<10;i++){
        sudokuLine[i-1] = false;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudokuBoard[i][j]!=0){
                sudokuLine[sudokuBoard[i][j]-1] = true;
            }
        }
    }

    for (short i=1;i<10;i++){
        std::cout<<sudokuLine[i]<<std::endl;
    }
}

