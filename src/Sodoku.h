#include <iostream>
#include "Position.h"
#include "SodokuDefinations.h"

#ifndef SODOKU_H
#define SODOKU_H

//#include <cstdarg> // s standard arg

/// 1 2 3 4 5 6 7 8 9 //  a row
/// 1
/// 2 
/// 3
/// 4 
/// ... column
using namespace std;
class Sodoku{
    private:
        SodokuValue unSolved[Sodoku_Size][Sodoku_Size];// [column][row]
        SodokuValue solved[Sodoku_Size][Sodoku_Size];
        // no repeat in box
        // no repeats in column
        // no repeats in row
        bool rows[Sodoku_Size][Sodoku_Size+1]; // true means filled into solved matrix // sort of like a hash
        bool columns[Sodoku_Size][Sodoku_Size+1];
        bool boxes[Sodoku_Size][Sodoku_Size+1];

        bool isValueInsertableIntoSolGridCordinatesx(int value,GridCordinates p);
        int maxGenerations = 0;
        int generateAttempt = 0;
        bool attemptFailed = false;

        void generate();

        char SodokuValueConverter(const SodokuValue s) const;
        std::ostream& print(ostream& os,const SodokuValue matrix[][Sodoku_Size]) const;
    public:
    Sodoku();
    ~Sodoku();
    // return 1 if value is wrong or outside of bounds
    int insert(unsigned int value,GridCordinates position);
    std::ostream& printSolvedMatrix(ostream& os) const;
    std::ostream& printUnsolvedMatrix(ostream& os) const ;
};
std::ostream & operator << (std::ostream & o, const Sodoku & s);

#endif