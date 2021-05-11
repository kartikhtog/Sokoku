#define Sodoku_Size 9

union SodokuValue{
    struct {
        unsigned int value : 4;
        unsigned isValid : 4;
    } value;
    unsigned char storage;
};