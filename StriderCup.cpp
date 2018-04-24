#include "Heat.h"
using namespace std;

int main(void){
    HeatManager *hm = new HeatManager();
    hm->setHeats(151);
    hm->setCurrent(9);
    int firstHeatID = hm->getHeatbyIndex(hm->getCurrent()).getNum();
    cout<<firstHeatID<<endl;
    delete hm;
    hm = NULL;
    return 0;
}