#include "Position.h"
BoxCordinates* PositionConversion::convertTPositionInBox(GridCordinates p, BoxCordinates* b) {
    int boxColumnLocation = 0;
    int boxRowLocation = 0;
    if (p.location.column == 0 || p.location.column == 3 || p.location.column == 6 ){
        boxColumnLocation = 1;
    } else if (p.location.column == 1 || p.location.column == 4 || p.location.column == 7 ){
        boxColumnLocation = 2;
    } else {
        boxColumnLocation = 3;
    }
    if (p.location.row == 0 || p.location.row == 3 || p.location.row == 6 ){
        boxRowLocation = 1;
    } else if (p.location.row == 1 || p.location.row == 4 || p.location.row == 7 ){
        boxRowLocation = 2;
    } else {
        boxRowLocation = 3;
    }
    int positionInBox = 0;
    if (boxRowLocation == 1){
        positionInBox = boxColumnLocation;
    } else if (boxRowLocation ==2){
        positionInBox = boxColumnLocation  +3;
    } else {
        positionInBox = boxColumnLocation + 6;
    }
    // b = new BoxPosition;
    if (b != nullptr) {
        b -> location.positionInBox = positionInBox;
        b -> location.box = calculateBoxFromPosition(p);
    }
    return b;

    ///  1 2 3
    // 1 1 2 3
    // 2 4 5 6
    // 3 7 8 9
    //int box = calculateBoxFromPosition(Position);
};

int PositionConversion::calculateBoxFromPosition(GridCordinates p){
    if (p.location.column <= 2){
        if (p.location.row <= 2){
            return 0;
        } else if (p.location.row <= 5){
            return 3;
        }
        else {
            return 6;
        }
    } else if (p.location.column <= 5){
        if (p.location.row <= 2){
            return 1;
        } else if (p.location.row <= 5){
            return 4;
        }
        else {
            return 7;
        }
    } else {
        if (p.location.row <= 2){
            return 2;
        } else if (p.location.row <= 5){
            return 5;
        }
        else {
            return 8;
        }
    }
};

