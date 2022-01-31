// Header file for Database class

#ifndef _DATABASE_H
#define _DATABASE_H

#include "ticket.h"

// Class definition for Database class
class Database {
	std::vector<Statestation*> statestationList;
	std::vector<ticket*> riderList;
	
public:
	Database();
	~Database();
	void addStatestation(std::string stationName, double entranceFee, double trailMiles);
	void addticket(std::string riderName, bool isJuniorticket);
	void addstationToticket(std::string riderName, std::string stationName);
	std::vector<std::string> getstationsInRevenueRange(double lowerBound, double upperBound);
	std::vector<std::string> getHikersAtLeastLevel(int level);
};

#endif