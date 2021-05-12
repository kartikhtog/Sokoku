./makefile.sh
#-o location of the output file
g++ -c -Wall Tests/UnitTests.cpp -o Output/UnitTests.o
g++ -o Output/UnitTests.exe Output/SodokuCombinations.o Output/Sodoku.o Output/Position.o Output/UnitTests.o
Output/UnitTests.exe