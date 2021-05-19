#include <iostream>
#include <math.h>
#include <time.h>
#include "Position.h"
#include "SodokuDefinations.h"
#include "SodokuCombinations.h"
#include "Managed2DArray.cpp"

SodokuCombinations::SodokuCombinations(){
    time(&now);//the number of seconds elapsed since January 1, 1970
    srand(now);// set seed
}
   
void SodokuCombinations::CreateListsWithRamdomGenerations() {
    for (int i = 0;i < maxPurmutationToTry; i++){
        CreateListWithRamdomGenerations(i);
    }
};

void SodokuCombinations::CreateListWithRamdomGenerations(int iteration){
    // rows
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;  
    int h;
    int i;
    //columns
    int j;int k;int l; int m;int n;int o; int p;int q;int r;
        /// one list
    GridCordinates grid0;
    GridCordinates grid1;
    GridCordinates grid2;
    GridCordinates grid3;
    GridCordinates grid4;
    GridCordinates grid5;
    GridCordinates grid6;
    GridCordinates grid7;
    GridCordinates grid8;

    a = (rand()%3); grid0.location.row = a; // row 0 -2
    b = (rand()%3)+3; grid3.location.row = b; // row 3 -5
    c = (rand()%3)+6; grid6.location.row = c; // row 6 -8
    
    while((d = ((rand()%3)  ))==a){}; grid1.location.row = d; // row 0 -2
    while((e = ((rand()%3)+3))==b){}; grid4.location.row = e; // row 3 -5
    while((f = ((rand()%3)+6))==c){}; grid7.location.row = f; // row 6 -8

    g=-1; while(++g == a || g == d){}; grid2.location.row = g; // row 0 -2
    h=2; while(++h == b || h == e){}; grid5.location.row = h; // row 3 -5
    i=5; while(++i == c || i == f){}; grid8.location.row = i; // row 6 -8
    
    j = (rand()%3); grid0.location.column = j; // column 0 -2
    while((k = ((rand()%3)  ))==j){}; grid3.location.column = k; // column 0 -2
    l=-1; while(++l == j || l == k){}; grid6.location.column = l;  // column 0 -2
    
    m = (rand()%3)+3; grid1.location.column = m; // column 3 -5
    while((n = ((rand()%3)+3))==m){}; grid4.location.column = n; // column 3 -5
    o=2; while(++o == n || o == m){}; grid7.location.column = o; // column 3 -5
    
    p = (rand()%3)+6; grid2.location.column = p; // column 6 -8
    while((q = ((rand()%3)+6))==p){}; grid5.location.column = q; // column 6 -8
    r=5; while(++r == q || r == p){}; grid8.location.column = r; // column 6 -8


    BoxCordinates* box0 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid0,box0);
    BoxCordinates* box1 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid1,box1);
    BoxCordinates* box2 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid2,box2);
    BoxCordinates* box3 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid3,box3);
    BoxCordinates* box4 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid4,box4);
    BoxCordinates* box5 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid5,box5);
    BoxCordinates* box6 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid6,box6);
    BoxCordinates* box7 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid7,box7);
    BoxCordinates* box8 = new BoxCordinates; PositionConversion::convertToPositionInBox(grid8,box8);



    /// debug 
    
    // std::cout << box0->location.box;
    // std::cout << box1->location.box;
    // std::cout << box2->location.box;
    // std::cout << box3->location.box;
    // std::cout << box4->location.box;
    // std::cout << box5->location.box;
    // std::cout << box6->location.box;
    // std::cout << box7->location.box;
    // std::cout << box8->location.box;
    // std::cout << " " ;
    // std::cout << box0->location.positionInBox;
    // std::cout << box1->location.positionInBox;
    // std::cout << box2->location.positionInBox;
    // std::cout << box3->location.positionInBox;
    // std::cout << box4->location.positionInBox;
    // std::cout << box5->location.positionInBox;
    // std::cout << box6->location.positionInBox;
    // std::cout << box7->location.positionInBox;
    // std::cout << box8->location.positionInBox;
    // std::cout << std::endl;
    
    allPurmutations[iteration][0] = box0->location.positionInBox;
    allPurmutations[iteration][1] = box1->location.positionInBox;
    allPurmutations[iteration][2] = box2->location.positionInBox;
    allPurmutations[iteration][3] = box3->location.positionInBox;
    allPurmutations[iteration][4] = box4->location.positionInBox;
    allPurmutations[iteration][5] = box5->location.positionInBox;
    allPurmutations[iteration][6] = box6->location.positionInBox;
    allPurmutations[iteration][7] = box7->location.positionInBox;
    allPurmutations[iteration][8] = box8->location.positionInBox;

    delete box0;
    delete box1;
    delete box2;
    delete box3;
    delete box4;
    delete box5;
    delete box6;
    delete box7;
    delete box8;
}

void SodokuCombinations::SortTheListOfPurmutations() {
    Managed2DArray<int> m = Managed2DArray<int>(maxPurmutationToTry,Sodoku_Size);
    for(int i = 0;i<maxPurmutationToTry;i++){
        for(int j =0; j< Sodoku_Size;j++){
            m.insert(allPurmutations[i][j],i,j);
        }
    }
    m.sortListOfArray();
    //m.print();
    m.RemoveDuplicates();
    // m.print();
}
