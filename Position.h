#ifndef POSITION_H
#define POSITION_H
union GridCordinates{
    struct {
    unsigned column : 4;
    unsigned row : 4;
    } location;
    unsigned char storage;
};

union BoxCordinates {
    struct {
        unsigned box:4;
        unsigned positionInBox : 4;
    } location;
    unsigned char storage;
};

class PositionConversion {
    public:
        /// Returns box cor
        BoxCordinates* convertTPositionInBox(GridCordinates p, BoxCordinates* b);
        int calculateBoxFromPosition(GridCordinates p);
};

#endif
/*
    // position test
    Position a;// = new Position[sizeof(Position)];
    a.location.row = 2;
    a.location.column =1;
    std::cout << a.location.row << std::endl;
    std::cout << a.location.column << std::endl;
    std::cout << (int)a.storage << std::endl;
*/
