General Notes:
The .vscode is not part of the project. I prefer to keep so that I don't have to re-create it.
Should work on linux or macOS but was only tested on windows with gcc using c++14.

1) To build : ./makefile.sh

2) To Run : Output/a.exe

or) build and run:  ./makefile.sh && Output/a.exe

3) Run test: ./runTests.sh

Improvements: There is a bug in Managed2DArray removing duplicate which can cause seg fault.

To do: 
1)
To Finish Generation 
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
2) Complete the interactive part of game