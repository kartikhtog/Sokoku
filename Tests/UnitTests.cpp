#include <assert.h>
#include "../src/Position.h"
#include "../src/SodokuDefinations.h"

void Test_PositionConversion_calculateBoxFromPosition();
void Test_PositionConversion_calculateBoxFromPosition_Point(int column, int row, int result);

int main(){
    Test_PositionConversion_calculateBoxFromPosition();
}

void Test_PositionConversion_calculateBoxFromPosition(){
    /// first 3 boxes
    Test_PositionConversion_calculateBoxFromPosition_Point(0,0,0);
    Test_PositionConversion_calculateBoxFromPosition_Point(0,1,0);
    Test_PositionConversion_calculateBoxFromPosition_Point(0,2,0);

    Test_PositionConversion_calculateBoxFromPosition_Point(1,0,0);
    Test_PositionConversion_calculateBoxFromPosition_Point(1,1,0);
    Test_PositionConversion_calculateBoxFromPosition_Point(1,2,0);

    Test_PositionConversion_calculateBoxFromPosition_Point(2,0,0);
    Test_PositionConversion_calculateBoxFromPosition_Point(2,1,0);
    Test_PositionConversion_calculateBoxFromPosition_Point(2,2,0);

    Test_PositionConversion_calculateBoxFromPosition_Point(3,0,1);
    Test_PositionConversion_calculateBoxFromPosition_Point(3,1,1);
    Test_PositionConversion_calculateBoxFromPosition_Point(3,2,1);

    Test_PositionConversion_calculateBoxFromPosition_Point(4,0,1);
    Test_PositionConversion_calculateBoxFromPosition_Point(4,1,1);
    Test_PositionConversion_calculateBoxFromPosition_Point(4,2,1);

    Test_PositionConversion_calculateBoxFromPosition_Point(5,0,1);
    Test_PositionConversion_calculateBoxFromPosition_Point(5,1,1);
    Test_PositionConversion_calculateBoxFromPosition_Point(5,2,1);

    Test_PositionConversion_calculateBoxFromPosition_Point(6,0,2);
    Test_PositionConversion_calculateBoxFromPosition_Point(6,1,2);
    Test_PositionConversion_calculateBoxFromPosition_Point(6,2,2);

    Test_PositionConversion_calculateBoxFromPosition_Point(7,0,2);
    Test_PositionConversion_calculateBoxFromPosition_Point(7,1,2);
    Test_PositionConversion_calculateBoxFromPosition_Point(7,2,2);

    Test_PositionConversion_calculateBoxFromPosition_Point(8,0,2);
    Test_PositionConversion_calculateBoxFromPosition_Point(8,1,2);
    Test_PositionConversion_calculateBoxFromPosition_Point(8,2,2);

    /// Next 3 boxes (3-5)

    Test_PositionConversion_calculateBoxFromPosition_Point(0,3,3);
    Test_PositionConversion_calculateBoxFromPosition_Point(0,4,3);
    Test_PositionConversion_calculateBoxFromPosition_Point(0,5,3);

    Test_PositionConversion_calculateBoxFromPosition_Point(1,3,3);
    Test_PositionConversion_calculateBoxFromPosition_Point(1,4,3);
    Test_PositionConversion_calculateBoxFromPosition_Point(1,5,3);

    Test_PositionConversion_calculateBoxFromPosition_Point(2,3,3);
    Test_PositionConversion_calculateBoxFromPosition_Point(2,4,3);
    Test_PositionConversion_calculateBoxFromPosition_Point(2,5,3);

    Test_PositionConversion_calculateBoxFromPosition_Point(3,3,4);
    Test_PositionConversion_calculateBoxFromPosition_Point(3,4,4);
    Test_PositionConversion_calculateBoxFromPosition_Point(3,5,4);

    Test_PositionConversion_calculateBoxFromPosition_Point(4,3,4);
    Test_PositionConversion_calculateBoxFromPosition_Point(4,4,4);
    Test_PositionConversion_calculateBoxFromPosition_Point(4,5,4);

    Test_PositionConversion_calculateBoxFromPosition_Point(5,3,4);
    Test_PositionConversion_calculateBoxFromPosition_Point(5,4,4);
    Test_PositionConversion_calculateBoxFromPosition_Point(5,5,4);

    Test_PositionConversion_calculateBoxFromPosition_Point(6,3,5);
    Test_PositionConversion_calculateBoxFromPosition_Point(6,4,5);
    Test_PositionConversion_calculateBoxFromPosition_Point(6,5,5);

    Test_PositionConversion_calculateBoxFromPosition_Point(7,3,5);
    Test_PositionConversion_calculateBoxFromPosition_Point(7,4,5);
    Test_PositionConversion_calculateBoxFromPosition_Point(7,5,5);

    Test_PositionConversion_calculateBoxFromPosition_Point(8,3,5);
    Test_PositionConversion_calculateBoxFromPosition_Point(8,4,5);
    Test_PositionConversion_calculateBoxFromPosition_Point(8,5,5);

    /// Next 3 boxes (6-8)

    Test_PositionConversion_calculateBoxFromPosition_Point(0,6,6);
    Test_PositionConversion_calculateBoxFromPosition_Point(0,7,6);
    Test_PositionConversion_calculateBoxFromPosition_Point(0,8,6);

    Test_PositionConversion_calculateBoxFromPosition_Point(1,6,6);
    Test_PositionConversion_calculateBoxFromPosition_Point(1,7,6);
    Test_PositionConversion_calculateBoxFromPosition_Point(1,8,6);

    Test_PositionConversion_calculateBoxFromPosition_Point(2,6,6);
    Test_PositionConversion_calculateBoxFromPosition_Point(2,7,6);
    Test_PositionConversion_calculateBoxFromPosition_Point(2,8,6);

    Test_PositionConversion_calculateBoxFromPosition_Point(3,6,7);
    Test_PositionConversion_calculateBoxFromPosition_Point(3,7,7);
    Test_PositionConversion_calculateBoxFromPosition_Point(3,8,7);

    Test_PositionConversion_calculateBoxFromPosition_Point(4,6,7);
    Test_PositionConversion_calculateBoxFromPosition_Point(4,7,7);
    Test_PositionConversion_calculateBoxFromPosition_Point(4,8,7);

    Test_PositionConversion_calculateBoxFromPosition_Point(5,6,7);
    Test_PositionConversion_calculateBoxFromPosition_Point(5,7,7);
    Test_PositionConversion_calculateBoxFromPosition_Point(5,8,7);

    Test_PositionConversion_calculateBoxFromPosition_Point(6,6,8);
    Test_PositionConversion_calculateBoxFromPosition_Point(6,7,8);
    Test_PositionConversion_calculateBoxFromPosition_Point(6,8,8);

    Test_PositionConversion_calculateBoxFromPosition_Point(7,6,8);
    Test_PositionConversion_calculateBoxFromPosition_Point(7,7,8);
    Test_PositionConversion_calculateBoxFromPosition_Point(7,8,8);

    Test_PositionConversion_calculateBoxFromPosition_Point(8,6,8);
    Test_PositionConversion_calculateBoxFromPosition_Point(8,7,8);
    Test_PositionConversion_calculateBoxFromPosition_Point(8,8,8);
}

void Test_PositionConversion_calculateBoxFromPosition_Point(int column, int row, int result){
    GridCordinates g;
    g.location.column=column;
    g.location.row=row;
    int returnValue = PositionConversion::calculateBoxFromPosition(g);
    assert(returnValue == result);
}
