#include "ticket.h"

using std::string, std::vector;

ticket::ticket(string riderName,bool isJuniorticket) : riderName(riderName), isJuniorticket(isJuniorticket),stationsVisited({}) {
}

string ticket::getriderName() {
	return riderName;
}

bool ticket::checkJuniorticket() {
	return isJuniorticket;
}

void ticket::addstationVisited(Statestation* station) {
	INFO(station)
	stationsVisited.push_back(station);
	station->addrider(this);
}