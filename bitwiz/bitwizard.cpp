#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class BitWizard{
    public:
    bitset<16> fizz;
    bitset<16> buzz;
    int size;
    BitWizard(int r);
    BitWizard();
    void wizshits(){
        this->fizz[3] = 1;
        this->buzz[5] = 1;
        this->fizz[15] = 1;
        this->buzz[15] = 1;
        int index = 0;
        int passes = 0;
        while (passes <= this->size){
            if (this->fizz[index] ==1 && this->buzz[index] == 1){
                cout<<passes<<"fizz buzz"<<endl;
                index = 1;
                passes++;
            }else if (this->fizz[index] == 1){
                cout<<passes<<"fizz"<<endl;
                index ++;
                passes++;
            } else if (this->buzz[index] == 1){
                cout<<passes<<"buzz"<<endl;
                index ++;
                passes++;
            } else {
            index++;
            passes++;
            }
        }
        cout<<index<<" "<<passes<<" "<<this->size<<endl;
    };
};

BitWizard::BitWizard(){
    this->size = 100;
}

BitWizard::BitWizard(int r){
    if(r>0){
        this->size = r;
    } else {
        size = 100;
    }
}



int main(void){
    BitWizard wiz = BitWizard(45);
    wiz.wizshits();
    return 0;
}