#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


class Race {
public:
	int numRacers;
	int heatNum;
	vector <int> racerList;
	int getNumRacers();
	void setNumRacers(int n);
	vector <int> getRacerList();
	void addRacer(int n);
	int getNum();
	void setNum(int n);
	Race();
};


int Race::getNum() {
	return this->heatNum;
}

void Race::setNum(int n) {
	this->heatNum = n;
}

int Race::getNumRacers() {
	return this->numRacers;
}

void Race::setNumRacers(int n) {
	this->numRacers = n;
}

vector<int> Race::getRacerList() {
	return this->racerList;
}

void Race::addRacer(int n) {
	this->numRacers += 1;
	this->racerList.push_back(n);
}

Race::Race() {

}
class Heat: public Race {
	
};
class Main: public Race {
	string mainIDs;
	public:
	Main(){
		this->mainIDs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	}
	char get_MainID(){
		return this->mainIDs.at(this->heatNum);
	}
};

class HeatManager {
	vector <Heat> heatList;
	int currentHeat;
public:
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

class MainManager{
	int currentMain;
	vector <Main> mains;
	public:
	Main getCurrent(){
		return this->mains.at(this->currentMain);
	}
	void setCurrent(int c){
		this->currentMain = c;
	}
	void addRace(Main r){
		r.heatNum = this->mains.size() + 1;
		this->mains.push_back(r);
	}
};
