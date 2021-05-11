#include <iostream>
#include "Position.h"
#include "SodokuDefinations.h"
#include <math.h>
#include <time.h>

class SodokuCombinations{
    public:
        void AppemptToGenerate3() {
            // fill in numbers by array
            // 5,1,9,2,8,3,7,4,6
            time_t now;
            time(&now);//the number of seconds elapsed since January 1, 1970
            srand(now);// set seed
            // setup
            for (int i =0; i< Sodoku_Size ; i++) {
                for (int j =0; j< Sodoku_Size;j++){
                    rows[i][j+1] = false;
                    columns[i][j+1] = false;
                    boxes[i][j] = false;
                    solved[i][j].value.value = 0;
                    solved[i][j].value.isValid = 0;
                }
            }

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
            
            


        }
};

  