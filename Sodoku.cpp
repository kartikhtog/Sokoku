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
            if (boxes[calculateBoxFromPosition(p)][value]){
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

     
char Sokoku::SodokuValueConverter(const SodokuValue s)const{
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
        os << "  " << SodokuValueConverter(matrix[0][i]);
        os << "  " << SodokuValueConverter(matrix[1][i]);
        os << "  " << SodokuValueConverter(matrix[2][i]);
        os << " |";
        os << "  " << SodokuValueConverter(matrix[3][i]);
        os << "  " << SodokuValueConverter(matrix[4][i]);
        os << "  " << SodokuValueConverter(matrix[5][i]);
        os << " |";
        os << "  " << SoGridCordinateseConverter(matrix[6][i]);
        os << "  " << SodokuValueConverter(matrix[7][i]);
        os << "  " << SodokuValueConverter(matrix[8][i]);
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


/*remove lagacy code in later commit*/
void Sodoku::FailedLegacyGeneration2() {
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
//            for (int z : {5,1,9,2,8,3,7,4,6}) {
//            for (int z : {1,2,3,4,5,6,7,8,9}) {
    for (int z : {1}) {

        /// rows

        //
        // int a = (rand()%3); Position aa; aa.location.row = a; aa.location.column = 0;
        // int b = (rand()%3)+3; Position bb; bb.location.row = b; bb.location.column = 1;
        // int c = (rand()%3)+6; Position cc; cc.location.row = c; cc.location.column = 2;
        // int d = (rand()%3); Position dd; dd.location.row = d; dd.location.column = 3;
        // int e = (rand()%3)+3; Position ee; ee.location.row = e; ee.location.column = 4;
        // int f = (rand()%3)+6; Position ff; ff.location.row = f; ff.location.column = 5;
        // int g = (rand()%3); Position gg; gg.location.row = g; gg.location.column = 6;
        // int h = (rand()%3)+3; Position hh; hh.location.row = h; hh.location.column = 7;
        // int i = (rand()%3)+6; Position ii; ii.location.row = i; ii.location.column = 8;
        // aa.location.column = 0;
        // bb.location.column = 1;
        // cc.location.column = 2;
        // dd.location.column = 3;
        // ee.location.column = 4;
        // ff.location.column = 5;
        // gg.location.column = 6;
        // hh.location.column = 7;
        // ii.location.column = 8;
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
        int j;
        int k;
        int l;
        int m;
        int n;
        int o;
        int p;
        int q;
        int r;

        int tries = 0;
        int maxTries = 200;
        do {
            a = (rand()%3); //aa.location.row = a; 
            b = (rand()%3)+3; //bb.location.row = b;
            c = (rand()%3)+6; //cc.location.row = c;
            while((d = ((rand()%3)  ))==a); //dd.location.row = d;
            while((e = ((rand()%3)+3))==b); //ee.location.row = e;
            while((f = ((rand()%3)+6))==c); //ff.location.row = f;
            g=-1; while(++g == a || g == d); //gg.location.row = g;
            h=2; while(++h == b || h == e); //hh.location.row = h;
            i=5; while(++i == c || i == f); //ii.location.row = i;
            
            j = (rand()%3); //aa.location.row = a; 
            while((k = ((rand()%3)  ))==j); //dd.location.row = d;
            l=-1; while(++l == j || l == k); //gg.location.row = g;
            
            m = (rand()%3)+3;// bb.location.row = b;
            while((n = ((rand()%3)+3))==m); //ee.location.row = e;
            o=2; while(++o == n || o == m); //hh.location.row = h;
            
            p = (rand()%3)+6; //cc.location.row = c;
            while((q = ((rand()%3)+6))==p); //ff.location.row = f;
            r=5; while(++r == q || r == p); //ii.location.row = i;
            
            tries++;
        } while ( // (3*3 + 3*2  + 3*1) + (3*3 , 2*2 ,1*1) ,(1*3 1*2 1*1) // 18 + 14 + 6 // 38
        ( // only 38 posibilites
        // might as well find these posibilities
        // calculateBoxFromPosition(aa)!=0 || 
        // calculateBoxFromPosition(bb)!=3 || 
        // calculateBoxFromPosition(cc)!=6 ||
        // calculateBoxFromPosition(dd)!=1 ||
        // calculateBoxFromPosition(ee)!=4 ||
        // calculateBoxFromPosition(ff)!=7 ||
        // calculateBoxFromPosition(gg)!=2 ||
        // calculateBoxFromPosition(hh)!=5 ||
        // calculateBoxFromPosition(ii)!=8 ||
        solved[j][a].value.isValid ||
        solved[k][b].value.isValid ||
        solved[l][c].value.isValid ||
        solved[m][d].value.isValid ||
        solved[n][e].value.isValid ||
        solved[o][f].value.isValid ||
        solved[p][g].value.isValid ||
        solved[q][h].value.isValid ||
        solved[r][i].value.isValid) &&
        (tries < maxTries)
        );
        solved[j][a].value.isValid = 1; solved[j][a].value.value = z;
        solved[k][b].value.isValid = 1; solved[k][b].value.value = z;
        solved[l][c].value.isValid = 1; solved[l][c].value.value = z;
        solved[m][d].value.isValid = 1; solved[m][d].value.value = z;
        solved[n][e].value.isValid = 1; solved[n][e].value.value = z;
        solved[o][f].value.isValid = 1; solved[o][f].value.value = z;
        solved[p][g].value.isValid = 1; solved[p][g].value.value = z;
        solved[q][h].value.isValid = 1; solved[q][h].value.value = z;
        solved[r][i].value.isValid = 1; solved[r][i].value.value = z;
        if (tries>=maxTries){
            attemptFailed = true;
        }
        //printSolvedMatrix(std::cout);
    }
    // for (int i = 1; i < Sodoku_Size + 1; i++) {
    //     while(columns[])
    //     Position p;
    //     int column = (rand() % 9);
    //     int row = (rand() % 9);
    //     p.location.column = column;
    //     p.location.row = row;
    // }
}

void Sodoku::failedLagacyGeneration() {
    // for now create a false generate
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
    for (int i =0; i< Sodoku_Size ; i++) {
        for (int j =0; j< Sodoku_Size;j++){
            while(solved[i][j].value.isValid==0) {
                
                GridCordinates p;
                p.location.column = i;
                p.location.row = j;
                int r = (rand() % 9) +1;
                int tries = 0;
                int maxTries = 30;
                while((solved[i][j].value.isValid || rows[j][r] || columns[i][r] || boxes[calculateBoxFromPosition(p)][r]) && tries < maxTries){
                        r = (rand() % 9) +1;
                        tries++;
                    //  if (tries> (maxTries*2/3)){
                    //      cout << r;
                    //  }
                }
                if (tries == maxTries){
                    attemptFailed = true;
                    // cout << " why ?";
                    // cout << " rows[j][r] "<< rows[j][r];
                    // cout << " columns[i][r]  "<< columns[i][r];
                    // cout << " boxes[calculateBoxFromPosition(p)][r] "<< boxes[calculateBoxFromPosition(p)][r] << endl;
                }
                columns[i][r] = true;
                rows[j][r] = true;
                boxes[calculateBoxFromPosition(p)][r] = true;
                solved[i][j].value.value = r;
                solved[i][j].value.isValid = 1;

                int complementValue = 10 - r;
                //cout <<"inserting " << r << " to position "<< i << j << " and complement Value is: " << complementValue << endl;

                // using complement is way to make sure the sum do not become unbalanced
                // find 3 complement location,one with same row, same column and same box. 
                // one of first two complement can be in box, in that case... we don't need to add it to box
                bool CannotBeAddedTobox = false;
                // 1 2 3 4 5 6 7 8 9
                // 1 9 , 2 8, 37, 4,6 5
                if (complementValue != 5){
                    // same column, different and random row and box
                    int randomRow = (rand()%9);
                    GridCordinates firstcomplement;
                    firstcomplement.location.column = i;
                    firstcomplement.location.row = randomRow;
                    tries = 0;
                    while ((solved[i][randomRow].value.isValid || randomRow == j
                    || rows[randomRow][complementValue] || boxes[calculateBoxFromPosition(firstcomplement)][complementValue]) && tries < maxTries ){
                        randomRow = (rand()%9);
                        firstcomplement.location.row = randomRow;
                        tries++;
                    }
                    if (tries < maxTries){
                        if (calculateBoxFromPosition(p)==calculateBoxFromPosition(firstcomplement)){
                            CannotBeAddedTobox = true;
                        }
                        rows[randomRow][complementValue] = true;
                        columns[i][complementValue] = true;
                        boxes[calculateBoxFromPosition(firstcomplement)][complementValue] = true;
                        solved[i][randomRow].value.value = complementValue;   
                        solved[i][randomRow].value.isValid = 1;
                        //cout << "Inserting "<< complementValue << " at "<< i << randomRow << endl;
                    }
                    else {

                        //cout << "cannot add compliement to random row. " ;
                        //cout << "cannot add: " << complementValue << " at "<< i << randomRow << endl;
                    }
                    //printSolvedMatrix(std::cout);
                    // same row, different and random column and box
                    int randomColumn = (rand()%9);
                    GridCordinates secondcomplement;
                    secondcomplement.location.column = randomColumn;
                    secondcomplement.location.row = j;
                    tries = 0;
                    while ((solved[randomColumn][j].value.isValid || randomColumn == i || (CannotBeAddedTobox && calculateBoxFromPosition(p)==calculateBoxFromPosition(secondcomplement))
                    || columns[randomColumn][complementValue] || boxes[calculateBoxFromPosition(secondcomplement)][complementValue]) && (tries < maxTries) )
                    {
                        randomColumn = (rand()%9);
                        secondcomplement.location.column = randomColumn;
                        tries++;
                    }
                    if (tries < maxTries){
                        if (calculateBoxFromPosition(p)==calculateBoxFromPosition(secondcomplement)){
                            CannotBeAddedTobox = true;
                        }
                        rows[j][complementValue] = true;
                        columns[randomColumn][complementValue] = true;
                        boxes[calculateBoxFromPosition(secondcomplement)][complementValue] = true;
                        solved[randomColumn][j].value.value = complementValue;   
                        solved[randomColumn][j].value.isValid = 1;
                        //cout << " inserting "<< complementValue << " at "<< randomColumn << j << endl;
                    }
                    else {
                        //cout << "cannot add compliement to random column.";
                        //cout << complementValue << " at "<< randomColumn << j << endl;
                    }
                    //printSolvedMatrix(std::cout);



                    GridCordinatesbox, different and random column and row
                    if (!CannotBeAddedTobox){
                        randomColumn = (rand()%9);
                        randomRow = (rand()%9);
                        GridCordinates thirdcomplement;
                        thirdcomplement.location.column = randomColumn;
                        thirdcomplement.location.row = randomRow;
                        tries = 0;
                        while ((solved[randomColumn][randomRow].value.isValid || randomColumn == i || randomRow == j|| calculateBoxFromPosition(p)!=calculateBoxFromPosition(thirdcomplement)
                        || columns[randomColumn][complementValue] ||rows[randomRow][complementValue]|| boxes[calculateBoxFromPosition(thirdcomplement)][complementValue]) && tries < maxTries )
                        {
                            randomColumn = (rand()%9);
                            randomRow = (rand()%9);
                            thirdcomplement.location.column = randomColumn;
                            thirdcomplement.location.row = randomRow;
                            tries++;
                        }
                        if (tries < maxTries){
                            rows[randomRow][complementValue] = true;
                            columns[randomColumn][complementValue] = true;
                            boxes[calculateBoxFromPosition(thirdcomplement)][complementValue] = true;
                            solved[randomColumn][randomRow].value.value = complementValue;   
                            solved[randomColumn][randomRow].value.isValid = 1;
                            //cout << " inserting "<< complementValue << " at "<< randomColumn << randomRow << endl;
                        }
                        else {
                            //cout << "cannot add compliement to same box. " ;
                            //cout << "cannot add: " << complementValue << " at "<< randomColumn << randomRow << endl;
                        }
                        //printSolvedMatrix(std::cout);

                    }
                }
            }
        }
    }
}
   