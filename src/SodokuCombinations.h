#include <time.h>
#include "SodokuDefinations.h"
#include "Managed2DArray.h"

#ifndef SODOKU_COMBINATIONS_H
#define SODOKU_COMBINATIONS_H
#define maxPurmutationToTry 50000

class SodokuCombinations{
    private:
        SodokuValue solved[Sodoku_Size][Sodoku_Size];
        time_t now;
        ///To do: ideally this should be dependency injected but its not a big a deal.
        Managed2DArray<int> managedArray = Managed2DArray<int>(maxPurmutationToTry,Sodoku_Size);
        void createListWithRamdomGenerations(int iteration);
    public:
        SodokuCombinations();
    /**
     * Strategy 
        /// Find all permuation of putting a the same symbol down 9 times.
        /// Output these permuations with 9 number ranging from 1 to 9...
        /// 9 numbers represent the boxes, number represent the position on the box
        /// sort these permuations
        /// remove duplicates
        /// make lists of 9 lists choosing all the subsets  9 C _ : 
        /// may 19: 2021 update though: We only need to generate one... we should just try random 9 at a time
        /// Maybe find a set that is not a valid first
        /// ... for each check if its valid
        /// out put valid list
        /// to check the if its valid 
        /// stage 1 of valid) just check if box set contain unique items only
        /// this will construct a proper solution
        /// output this lists.
     */
        void createListsWithRamdomGenerations();
        void sortTheListOfPurmutations();
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
            