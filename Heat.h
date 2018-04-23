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
	vector <int> racerList;
public:
	int getNumRacers();
	void setNumRacers(int n);
	vector <int> getRacerList();
	void addRacer(int n);
	int getNum();
	void setNum(int n);
	Heat();
	~Heat();
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

Heat::~Heat() {
	delete this;
}

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
		int remainder = numP % 16;
		if (numP < 6) {
			return;
		}
		else {
			if (remainder != 0) {
				int heats = (numP / 16) + 1;
				int diff = (numP%heats);
				for (int x = 1; x <= heats; x++) {
					Heat *nextHeat = new Heat();
					if (x <= diff) {
						nextHeat->setNumRacers(numP / heats + 1);
					}
					else {
						nextHeat->setNumRacers(numP / heats);
					}
					this->heatList.insert(this->heatList.begin() + x, *nextHeat);
				}
			}
			else {
				int heats = numP / 16;
				for (int i = 1; i <= heats; i++) {
					Heat *evenHeat = new Heat();
					evenHeat->setNumRacers(16);
					this->heatList.insert(this->heatList.begin() + i, *evenHeat);
				}
			}
		}
	}
	HeatManager() {
		return;
	}
};