#include <iostream>
#include <fstream>
using namespace std;

void selectSort(int a[], int size){
    int smalltemp;             // inititialize our temp var 
    for(int x = 0; x < size-1; x++){ // loop through whole list
        int smallestIdx = x;
        for(int h = smallestIdx+1; h<size; h++){ // compare the first element of our small index to all remaining values
            if (a[h] < a[smallestIdx]){ // check if its smaller, if not reset small index to current loop value
                smallestIdx = h;
            }
        }
        smalltemp = a[x]; // set temp var to current indexed valuee
        a[x] = a[smallestIdx]; //set current index to value of smallest indexed value in remaining array
        a[smallestIdx] = smalltemp; // set temp to the value for smallest index
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
    selectSort(numArray, count);
    for(int i = 0; i < count; i++){
        cout << numArray[i] << endl;
    }
}