#include "Heat.h"
using namespace std;

int main(void){
    HeatManager *hm = new HeatManager();
    hm->setHeats(1024);
    hm->setCurrent(3);
    cout<<hm->getNext().getNumRacers()<<endl;
    delete hm;
    hm = NULL;
    return 0;
}