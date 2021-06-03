#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
#include "Position.h"
#include "SodokuDefinations.h"
#include "Sodoku.h"

using namespace std;

bool Sodoku::isValueInsertableIntoSolGridCordinatesx(int value,GridCordinates p) {
    if (!rows[p.location.row][value]){
        if (!columns[p.location.column][value]){
            if (boxes[PositionConversion::calculateBoxFromPosition(p)][value]){
                return true;
            }
        }
    }
    return false;
}

void  Sodoku::generate() {
    do {
        attemptFailed = false;
        //AttemptToGenerate2();
        if (!attemptFailed) {
            cout << "we did it"<<endl;
        }
        //printSolvedMatrix(std::cout);
    } while(attemptFailed && ++generateAttempt < maxGenerations);

}

     
char Sodoku::sodokuValueConverter(const SodokuValue s) const{
    if (s.value.isValid){
        char r ='x';
        switch(s.value.value){
            case 1: r ='1'; break;
            case 2: r ='2'; break;
            case 3: r ='3'; break;
            case 4: r ='4'; break;
            case 5: r ='5'; break;
            case 6: r ='6'; break;
            case 7: r ='7'; break;
            case 8: r ='8'; break;
            case 9: r ='9'; break;
        }
        return r;
    }
    return 'x';
}
        
std::ostream& Sodoku::print(ostream& os,const SodokuValue matrix[][Sodoku_Size]) const
{
    os << endl <<"The sodoku Puzzle" << endl;
    os << " ________________________________"<< endl;
    for (int i = 0;i < Sodoku_Size;i++){
        os << "|";
        os << "  " << sodokuValueConverter(matrix[0][i]);
        os << "  " << sodokuValueConverter(matrix[1][i]);
        os << "  " << sodokuValueConverter(matrix[2][i]);
        os << " |";
        os << "  " << sodokuValueConverter(matrix[3][i]);
        os << "  " << sodokuValueConverter(matrix[4][i]);
        os << "  " << sodokuValueConverter(matrix[5][i]);
        os << " |";
        os << "  " << sodokuValueConverter(matrix[6][i]);
        os << "  " << sodokuValueConverter(matrix[7][i]);
        os << "  " << sodokuValueConverter(matrix[8][i]);
        os << " |" << endl;
        if (i != 2 && i != 5 && i != 8){
            os << "|                                |" << endl;
        } else if (i != 8) {
            os << "| __  __  __  __  __  __  __  __ |"<< endl;
        }
    }
    os << "|________________________________|"<< endl;
    return os;
}
    
Sodoku::Sodoku(){
    generate();
}

Sodoku::~Sodoku(){}

// return 1 if value is wrong or outside of bounds
int Sodoku::insert(unsigned int value,GridCordinates position){
    if ((unsigned int)solved[position.location.column][position.location.row].value.value != value){
        return 1;
    }
    unSolved[position.location.column][position.location.row].value.value = value;
    return 0;
}

std::ostream& Sodoku::printSolvedMatrix(ostream& os) const {
    return print(os,solved);
}

std::ostream& Sodoku::printUnsolvedMatrix(ostream& os) const {
    return print(os,unSolved);
}

std::ostream & operator << (std::ostream & o, const Sodoku & s) {
    return s.printUnsolvedMatrix(o);
}
