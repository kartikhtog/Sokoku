#include <time.h>
#include "SodokuDefinations.h"

#ifndef SODOKU_COMBINATIONS_H
#define SODOKU_COMBINATIONS_H

class SodokuCombinations{
    private:
        SodokuValue solved[Sodoku_Size][Sodoku_Size];
        time_t now;
        void CreateListWithRamdomGenerations();
    public:
        SodokuCombinations();
    /**
     * Strategy 
        /// Find all permuation of putting a the same symbol down 9 times.
        /// Output these permuations with 9 number ranging from 1 to 9...
        /// 9 numbers represent the boxes, number represent the position on the box
        /// sort these permuations
        /// remove duplicates
        /// make lists of 9 lists choosing all the subsets  9 C _
        /// ... for each check if its valid
        /// out put valid list
        /// to check the if its valid 
        /// stage 1 of valid) just check if box set contain unique items only
        /// this will construct a proper solution
        /// output this lists.
     */
        void CreateListsWithRamdomGenerations();
        void deleteMeLater();
};

#endif


/// 5
/// 3
/// 123,132,213,232,312,321
/// 124
/// 134
/// 234
//4*3*2
//24    
/// 123
/// 124
/// 125
/// 134
/// 135
/// 145

/// 234
/// 235
/// 245

/// 345
//10
            