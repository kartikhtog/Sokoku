#include <iostream>
#include <stdio.h>
#include "sodoku.h"
#include "SodokuCombinations.cpp"

int main(){
    //Sodoku s;
    //s.printSolvedMatrix(std::cout);//ostream);
    //std::cout << "test";
    SodokuCombinations sc;
    sc.CreateListWithRamdomGenerations();
    return 0;
}