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
public:
	vector <Heat> heatList;
	int currentHeat;
	vector<Heat> getHeats() {
		return this->heatList;
	}
	Heat getCurrent() {
		return this->heatList.at(this->currentHeat);
	}
	void setCurrent(int n) {
		this->currentHeat = n;
	}
	Heat getNext() {
		return this->heatList.at(this->currentHeat + 1);
	}
	void setHeats(int numP) {
		int remaining = numP % 16;
		this->heatList.resize(numP/16);
		if (numP < 6) {
			return;
		}
		else {
			if (remaining != 0) {
				int heats = (numP / 16) + 1;
				int diff = (numP%heats);
				cout<<"number of heats "<<heats<<endl;
				for (int x = 1; x <= heats; x++) {
					Heat *nextHeat = new Heat();
					if (x <= diff) {
						nextHeat->setNumRacers(numP / heats + 1);
					}
					else {
						nextHeat->setNumRacers(numP / heats);
					}
					cout<<"writing heat number: "<< x <<" with "<<nextHeat->getNumRacers()<<" racers"<<endl;
					this->heatList.insert(this->heatList.begin() + x, *nextHeat);
					delete nextHeat;
					nextHeat = NULL;
				}
			}
			else {
				int heats = numP / 16;
				for (int i = 1; i <= heats; i++) {
					Heat *evenHeat = new Heat();
					evenHeat->setNumRacers(16);
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