// Class file for Database class

#include "Database.h"

using std::string, std::vector;

Database::Database() : statestationList({}),riderList({}) {

}

Database::~Database() {
	for (unsigned int i = 0; i < statestationList.size(); ++i) {
		delete statestationList.at(i);
	}
	
	for (unsigned int i = 0; i < riderList.size(); ++i) {
		delete riderList.at(i);
	}
}

void Database::addStatestation(string stationName, double entranceFee, double trailMiles) {
	INFO(stationName)
	INFO(entranceFee)
	INFO(trailMiles)
	statestationList.push_back(new Statestation(stationName,entranceFee,trailMiles));//? idk
	return;
}

void Database::addticket(string riderName, bool isJuniorticket) {
	INFO(riderName)
	INFO(isJuniorticket)
	riderList.push_back(new ticket(riderName,isJuniorticket));
}

void Database::addstationToticket(string riderName, string stationName) {
	bool riderTrue = false;
	bool stationTrue = false;
	ticket *rider;
	Statestation *stationy;
	for (int i = 0; i < (int)(statestationList.size());++i) {
		if (stationName == statestationList.at(i)->getstationName()) {
			stationTrue = true;
			stationy = statestationList.at(i);
		}
	}
	for (int i = 0; i < (int)(riderList.size());++i) {
		if (riderName == riderList.at(i)->getriderName()) {
			riderTrue = true;
			rider = riderList.at(i);
		}
	}
	if (stationTrue && riderTrue) {
		rider->addstationVisited(stationy);
	}
	return;
}
