// Header file for Statestation class

#ifndef _STATESTATION_H
#define _STATESTATION_H

#include <string>
#include <vector>
#include <iostream>

#define INFO(X) std::cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << std::endl;

// Need to forward declare ticket class
class ticket;

// Class definition for Statestation class
class Statestation {
	std::string stationName;
	double entranceFee;
	double trailMiles;
	std::vector<ticket*> riderLog;
public:
	Statestation(std::string stationName, double entranceFee, double trailMiles);
	std::string getstationName();
	double getEntranceFee();
	double getTrailMiles();
	void addrider(ticket* rider);
	double getRevenue();
};

#endif