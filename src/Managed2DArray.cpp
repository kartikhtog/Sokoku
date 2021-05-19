#include <iostream>
/*To do: create a .h file*/
template <typename t>
class Managed2DArray{
    private:
        t** array = nullptr;
        int numberOfArrays;
        int sizeOfArray;
        void printArray(t* innderArray){
            for(int j = 0; j < sizeOfArray;j++){
                std::cout << innderArray[j];
            }
        }
        
        int ComparePurmutation(int indexOfFirst, int indexOfSecond,t** array){
            t* firstArray = array[indexOfFirst];
            t* secondArray = array[indexOfSecond];
            int index = 0;
            while (true) {
                if (firstArray[index] > secondArray[index]){
                    return 1;
                } else if (firstArray[index] < secondArray[index]) {
                    return -1;
                } else {
                    if (index == sizeOfArray -1){
                        return 0;
                    }
                    index++;
                }
            }
            return 0;
        }
        t** returnArray(){
            return array;
        }
        void MergeSort(int beginIndex, int endIndex){
            if (beginIndex != endIndex) {
                int splitIndex = ((endIndex -beginIndex)/2) + beginIndex;
                MergeSort(beginIndex,splitIndex);
                MergeSort(splitIndex + 1, endIndex);

                t** copyArray = new t*[endIndex-beginIndex+1];

                int i = 0;
                int j = splitIndex +1 -beginIndex;
                int k = beginIndex;
                for(int l = 0;l<=endIndex-beginIndex;l++){
                    copyArray[l] = array[l+beginIndex];
                } 
                while(k <= endIndex){
                    if (i > splitIndex -beginIndex) {
                        array[k++] = copyArray[j++];
                    }
                    else if (j > endIndex -beginIndex) {
                        array[k++] = copyArray[i++];
                    }
                    else if ( ComparePurmutation(i,j,copyArray)>=0){
                        array[k++] = copyArray[j++];
                    } else {
                        array[k++] = copyArray[i++];
                    }
                }
                delete []copyArray;
                copyArray = nullptr;
            }
        }
    public:
        Managed2DArray(int numberOfArrays, int sizeOfArray) {
            this->numberOfArrays = numberOfArrays;
            this->sizeOfArray = sizeOfArray;
            array = new t*[numberOfArrays];
            for (int i = 0; i < numberOfArrays; i++){
                array[i] = new t[sizeOfArray];
                for(int j = 0;j < sizeOfArray;j++){
                    array[i][j] = j;
                }
            }
        }
        void print()
        {
            for(int i = 0;i<numberOfArrays;i++){
                for(int j =0; j< sizeOfArray;j++){
                    std::cout << array[i][j];
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        ~Managed2DArray() {
            for (int i = 0; i < numberOfArrays; i++){
                delete []array[i];
                array[i] = nullptr;
            }
            delete []array;
            array = nullptr;
        }
        t elementAt(int positionOfArray, int elementInInnerArray){
            return array[positionOfArray][elementInInnerArray];
        }
        int insert(t element, int arrayPosition, int innerArrayPosition) {
            array[arrayPosition][innerArrayPosition] = element;
            return 0;
        }
        void sortListOfArray(){
            MergeSort(0,numberOfArrays-1);
        }
        // requires the list to be sorted
        void RemoveDuplicates(){
            std::cout << "removing duplicates" << std::endl;
            int indexOfCurrentArray = 0;
            int numOfOrginials = 0;
            int comparingIndex = 1;
            if (numberOfArrays>1) {
                while(indexOfCurrentArray != numberOfArrays -1){
                    // std::cout << "iterating through outer array" << std::endl;
                    numOfOrginials++;
                    //int* currentArray =  array[indexOfCurrentArray];
                    // bool deletedPurmutation = false;
                    while (ComparePurmutation(indexOfCurrentArray,comparingIndex,array)==0) {// currentArray == array[comparingIndex]) {
                        // std::cout << "going to delete an array" << std::endl;
                        delete []array[comparingIndex];
                        // std::cout << "part 1" << std::endl;
                        array[comparingIndex] = nullptr;
                        // std::cout << "part 2" << std::endl;
                        comparingIndex++; // need to increase outside of loop as well
                        // std::cout << "part 3" << std::endl;
                        // deletedPurmutation = true;
                        // std::cout << "part 4" << std::endl;
                    }
                    // if (deletedPurmutation) {
                    //     std::cout << "part 5" << std::endl;
                    // }
                    // if (!deletedPurmutation) {
                        
                    // }
                    indexOfCurrentArray = comparingIndex;
                    comparingIndex++;
                   // comparingIndex;
                }
            }
            std::cout << "going to copy to new array" << std::endl;
            /// copy to new array
            t** newArray = new t*[numOfOrginials];
            std::cout << "numOfOrginals is " << numOfOrginials << std::endl;
            int indexForNewArray = 0;
            int indexForOriginalArray = 0;
            while(indexForNewArray < numOfOrginials) {
                // std::cout << "1) Outerloop: ";
                newArray[indexForNewArray] = new t[sizeOfArray];
                // std::cout << " inner array allocation done" << std::endl;
                for(int i = 0; i < sizeOfArray; i++) {
                    // std::cout << "coping inner array";
                    newArray[indexForNewArray][i] = array[indexForOriginalArray][i];
                    // std::cout << "done" << std::endl;
                }

                // std::cout << "2) Deleting ";
                delete []array[indexForOriginalArray];
                array[indexForOriginalArray] = nullptr;
                // std::cout << " done" << std::endl;
                indexForOriginalArray++;
                while(indexForOriginalArray < numberOfArrays && array[indexForOriginalArray]==nullptr){indexForOriginalArray++;};
                indexForNewArray++;
                // std::cout << "Forwarding index" << std::endl;
            }
            std::cout << "coping done" << std::endl;
            delete []array;
            array = nullptr;
            array = newArray;
            numberOfArrays = numOfOrginials;

            /// store current array
            /// compare current array to next
            /// if current array is same array delete next array ... and set as null
            /// count not delete array
            /// if next array is not deleted move to next array
            /// at the end, copy element to new array.

        }
        int getNumberOfArrays() {
            return numberOfArrays;
        }
        int getSizeOfArrays() {
            return sizeOfArray;
        }
};

/*
Using this table as a guide. merge sort seems the most sensiable here
	Time	
Sort	Average	Best	Worst	Space	Stability	Remarks
Bubble sort	O(n^2)	O(n^2)	O(n^2)	Constant	Stable	Always use a modified bubble sort
Modified Bubble sort	O(n^2)	O(n)	O(n^2)	Constant	Stable	Stops after reaching a sorted array
Selection Sort	O(n^2)	O(n^2)	O(n^2)	Constant	Stable	Even a perfectly sorted input requires scanning the entire array
Insertion Sort	O(n^2)	O(n)	O(n^2)	Constant	Stable	In the best case (already sorted), every insert requires constant time
Heap Sort	O(n*log(n))	O(n*log(n))	O(n*log(n))	Constant	Instable	By using input array as storage for the heap, it is possible to achieve constant space
Merge Sort	O(n*log(n))	O(n*log(n))	O(n*log(n))	Depends	Stable	On arrays, merge sort requires O(n) space; on linked lists, merge sort requires constant space
Quicksort	O(n*log(n))	O(n*log(n))	O(n^2)	Constant	Stable	Randomly picking a pivot value (or shuffling the array prior to sorting) can help avoid worst case scenarios such as a perfectly sorted array.

*/