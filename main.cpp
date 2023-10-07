#include <iostream>

int main(){
    std::cout << "Please write the values of the sudoku board: ";
    short* sudokuLine=new short[3];
    
    short** sudokuBoard = new short*[3];
    
    for(int i=0;i<3;i++){
    	sudokuBoard[i]=new short[3];//1
    	for(int j=0;j<3;j++){
    		std::cin>>sudokuBoard[i][j];
    	}
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<sudokuBoard[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }
}

