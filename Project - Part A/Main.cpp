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

#include "HikeReader.h"
#include "ReservationReader.h"
#include "MemberReader.h"
#include "Interface.h"

int main() 
{
	HikeList mainHikeList = HikeList();
	MemberList mainMemberList = MemberList();
	Reservations mainReservations = Reservations();
	getMemberData(mainMemberList);
	getHikeData(mainHikeList);
	getReservationData(mainReservations);
	displayMenu();
	processReservation(mainHikeList, mainMemberList, mainReservations);
	return 0;
}