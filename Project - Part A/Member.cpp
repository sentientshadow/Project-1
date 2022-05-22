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

#include <iomanip>
#include <iostream>

using namespace std;

void Member::addPoints(int newPoints)
{
	points += newPoints;
}

void Member::setID(int newId)
{
	memberId = newId;
}

string Member::getLastName() const
{
	return lastName;
}

int Member::getID() const
{
	return memberId;
}

int Member::getPoints() const
{
	return points;
}

bool Member::operator<(const Member& aMember) const
{
	return aMember.memberId > this->memberId;
}

void Member::printMember() const
{
	cout << "\n\t" << lastName << ", " << firstName << "\n";
	cout << "\tPoints available: " << points << endl;
}