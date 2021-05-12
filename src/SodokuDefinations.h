#ifndef SODOKU_DEFINATIONS_H
#define SODOKU_DEFINATIONS_H

union SodokuValue{
    struct {
        unsigned int value : 4;
        unsigned isValid : 4;
    } value;
    unsigned char storage;
};
#endif


#ifndef Sodoku_Size
#define Sodoku_Size 9
#endif