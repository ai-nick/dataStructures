#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


class Heat {

	int numRacers;
	int heatNum;
	bool finished;
	vector <int> racerList;
	public:
	bool getFinished(){
		return this->finished;
	}
	void setFinished(bool f){
		this->finished = f;
	}
	int getNumRacers();
	void setNumRacers(int n);
	vector <int> getRacerList();
	void addRacer(int n);
	int getNum();
	void setNum(int n);
	Heat();
};


int Heat::getNum() {
	return this->heatNum;
}

void Heat::setNum(int n) {
	this->heatNum = n;
}

int Heat::getNumRacers() {
	return this->numRacers;
}

void Heat::setNumRacers(int n) {
	this->numRacers = n;
}

vector<int> Heat::getRacerList() {
	return this->racerList;
}

void Heat::addRacer(int n) {
	this->numRacers += 1;
	this->racerList.push_back(n);
}

Heat::Heat() {

}



class HeatManager {
	vector <Heat> heatList;
	int currentHeat;
	public:
	vector<Heat> getHeats() {
		return this->heatList;
	}
	int getCurrent() {
		return this->currentHeat;
	}
	void setCurrent(int n) {
		if(n<0){
			return;
		}
		if (n < this->heatList.size()){
			cout<<"setting current heat to index "<<n<<" in vector of size "<<this->heatList.size()<<endl;
			this->currentHeat = n;
		}else{
			this->currentHeat = 0;
		}
		
	}
	Heat getHeatbyIndex(int n) {
		if (n<0) return this->heatList.at(0);
		if(n < this->heatList.size()){
		return this->heatList.at(n);
		}else{
			return this->heatList.at(this->getCurrent());
		}
	}
	void setHeats(int numP) {
		int remaining = numP % 16;
		this->setCurrent(1);
		if (numP < 6) {
			return;
		}
		else {
			if (remaining != 0) {
				int heats = (numP / 16) + 1;
				//this->heatList.resize(heats/2);
				int diff = (numP%heats);
				cout<<"number of heats "<<heats<<endl;
				for (int x = 1; x <= heats; x++) {
					Heat *nextHeat = new Heat();
					if (x <= diff) {
						nextHeat->setNumRacers(numP / heats + 1);
						nextHeat->setNum(x);
						cout<<nextHeat->getNum()<<endl;
					}
					else {
						nextHeat->setNumRacers(numP / heats);
						nextHeat->setNum(x);
					}
					cout<<"writing heat number: "<< x <<" with "<<nextHeat->getNumRacers()<<" racers"<<endl;
					this->heatList.push_back( *nextHeat);
					delete nextHeat;
					nextHeat = NULL;
				}
			}
			else {
				int heats = numP / 16;
				this->heatList.resize(heats/2);
				for (int i = 1; i <= heats; i++) {
					Heat *evenHeat = new Heat();
					evenHeat->setNumRacers(16);
					evenHeat->setNum(i);
					this->heatList.insert(this->heatList.begin() + i, *evenHeat);
					cout<<"writing heat number: "<< i <<" with "<<evenHeat->getNumRacers()<<" racers"<<endl;
					delete evenHeat;
					evenHeat = NULL;
				}
			}
		}
	}
	HeatManager() {
	}

};