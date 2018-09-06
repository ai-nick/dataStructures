#include <iostream>
#include <fstream>
using namespace std;
//youll notice being the lazy programmer I am did the easy sift :)
//this depends on the heap being built adding on node then sifting 
// adding another sifting, and so on 
void siftUp(int a[], int size){
    int temp = a[size]; // store the last leaf
    int c = size; 
    int p = c/2;    //location of temp variables parent node
    while (p > 0){
        if (temp <= a[p]){
            break; // break if sorted
        }
        a[c] = a[p];
        c = p; // traverse to parent
        p = c/2; // make the rent the g-rent
    }
    a[c] = temp;
}
void siftDown(int newVal, int a[], int r, int l){
    int b = 2*r;
    while(b <= l){
        if(b < l){
            if(a[b+1] > a[b]) b++;
        }
        if(newVal >= a[b])break;
        a[r] = a[b];
        r = b;
        b = 2* r; // traverse if not in heap
        a[r] = newVal;
    }
}
void heapyBoy(int a[], int size){
    for(int x = 2; x <= size; x++) siftUp(a, x); // convert to MAX(as in maximum) heap
    for(int i = size; i > 1; i--){ // start loop at last index
        int temp = a[i]; // store the indexed value, will swap with what is in root
        a[i] = a[1];
        siftDown(temp, a, 1, i-1); // sift the temp var back down the try 
    }
}

int main() {
    int numArray[100];
    int inVal;
    int count = 0;
    ifstream file;
    file.open("input.txt");
    while(file >> inVal){
        numArray[++count] = inVal;
        //siftUp(numArray, count);
        //count++;
    }
    heapyBoy(numArray, count);
    for(int i = 0; i < count; i++){
        cout << numArray[i] << endl;
    }
}