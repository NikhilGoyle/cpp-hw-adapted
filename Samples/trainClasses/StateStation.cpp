#include "ticket.h"

using std::string, std::vector;

Statestation::Statestation(string stationName, double entranceFee, double trailMiles) : stationName(stationName),entranceFee(entranceFee),trailMiles(trailMiles),riderLog({}) {

}

string Statestation::getstationName() {
	return stationName;
}

double Statestation::getEntranceFee() {
	return entranceFee;
}

double Statestation::getTrailMiles() {
	return trailMiles;
}

void Statestation::addrider(ticket* rider) {
	INFO(rider)
	riderLog.push_back(rider);
	return;
}