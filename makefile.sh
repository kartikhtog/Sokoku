echo "Not a real makefile, just builds this porject with g++. Starting to fake make .."
echo ""
#-c compline into object file
#-s assembly code
#-Wall generate warning during assembly
#g++ -c -Wall src/Managed2DArray.cpp -o Output/Managed2DArray.o
g++ -c -Wall src/SodokuCombinations.cpp -o Output/SodokuCombinations.o
g++ -c -Wall src/Sodoku.cpp -o Output/Sodoku.o
g++ -c -Wall src/Position.cpp -o Output/Position.o
g++ -c -Wall src/main.cpp -o Output/main.o
# links all the files together
#-o location and name of output file
#g++ -o Output/a.exe Output/Managed2DArray.o Output/SodokuCombinations.o Output/Sodoku.o Output/Position.o  Output/main.o
g++ -o Output/a.exe Output/SodokuCombinations.o Output/Sodoku.o Output/Position.o  Output/main.o
echo "done"