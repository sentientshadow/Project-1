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

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
	Member() : memberId(0), points(0) {}
	Member(const std::string& firstName, const std::string& lastName) :
		firstName(firstName), lastName(lastName),
		memberId(0), points(0) {}
	
	void addPoints(int newPoints);
	void setID(int newId);

	std::string getLastName() const;
	int getID() const;
	int getPoints() const;
	
	bool operator<(const Member& aMember) const;

	void printMember() const;

	~Member() {};
private:
	int memberId; 
	std::string firstName; 
	std::string lastName; 
	int points; 
};
#endif