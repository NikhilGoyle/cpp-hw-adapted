// Header file for ticket class

#ifndef _TICKET_H
#define _TICKET_H

#include "Statestation.h"

// Class definition for ticket class
class ticket {
	std::string riderName;
	bool isJuniorticket;
	std::vector<Statestation*> stationsVisited;
	
	double getMilesHiked();
public:
	ticket(std::string riderName, bool isJuniorticket);
	std::string getriderName();
	bool checkJuniorticket();
	void addstationVisited(Statestation* station);
	int getHikerLevel();
};

#endif