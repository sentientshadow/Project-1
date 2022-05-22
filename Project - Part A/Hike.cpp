/*
	Wizards Team

	Lane, Shadow
	Delgado, Steven
	Vu, Nhi
	Lam, Dat

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Interface.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& hikeObj)
{
	out << "\t" << hikeObj.hike 
		<< " (" << hikeObj.location << ")" 
		<< "\n\t  Difficulty: ";
	if (hikeObj.difficulty == 'e')
	{
		out << "easy";
	}
	else if (hikeObj.difficulty == 'm')
	{
		out << "moderate";
	}
	else
	{
		out << "strenuous";
	}
	out << "\n\t  Duration: " 
		<< hikeObj.duration << " day(s)" << endl;
	return out;
}
	
string Hike::getLocation() const
{
	return location;
}

string Hike::getHike() const
{
	return hike;
}

int Hike::getDuration() const
{
	return duration;
}

char Hike::getDifficulty() const
{
	return difficulty;
}

bool Hike::operator<(const Hike& userHike) const
{
	return userHike.location > this->location;
}