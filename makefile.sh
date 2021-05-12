echo "Not a real makefile, just builds this porject with g++. Starting to fake make .."
echo ""
g++ -c SodokuCombinations.cpp
g++ -c Sodoku.cpp
g++ -c Position.cpp
g++ -c main.cpp
g++ -o a.exe SodokuCombinations.o Sodoku.o Position.o main.o
echo "done"