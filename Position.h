#ifndef POSITION_H
#define POSITION_H
union GridCordinates{
    struct {
    unsigned column : 4;
    /// 0 1 2 3 4 5 6 7 8 , going down
    unsigned row : 4;
    /// 0
    /// 1
    /// 2
    /// 3
    /// 4
    /// 5
    /// 6
    /// 7
    /// 8
    /// going across
    } location;
    unsigned char storage;
};

union BoxCordinates {
    struct {
        unsigned box:4;
        /// 0 1 2
        /// 3 4 5
        /// 6 7 8
        unsigned positionInBox : 4;
        /// 0 1 2
        /// 3 4 5
        /// 6 7 8
    } location;
    unsigned char storage;
};

class PositionConversion {
    public:
        /// Returns box cor
        static BoxCordinates* convertToPositionInBox(GridCordinates p, BoxCordinates* b);
        static int calculateBoxFromPosition(GridCordinates p);
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
