#include <iostream>
#include <fstream>
using namespace std;

void insertSort(int a[], int size){
    for(int i; i < size; i++){
        int k = a[i+1];    // holds the next value incase we need to shift something to that index
        int c = i-1;     // v stands for comparison var
        while(c >= 0 && k < a[c]){ // while are not at the first index and our loop
             a[c+1] = a[c];           // indexed var is less than the previous value
             c--;                      // we shift the previous value up and decrease our comparison index var
        }
        a[c+1] = k;     // insert the value at the proper index
    }
}



int main() {
    int numArray[100];
    int inVal;
    int count = 0;
    ifstream file;
    file.open("input.txt");
    while(file >> inVal){
        numArray[count] = inVal;
        //cout << numArray[count] << endl;
        count++;
    }
    insertSort(numArray, count);
    for(int i = 0; i < count; i++){
        cout << numArray[i] << endl;
    }
}