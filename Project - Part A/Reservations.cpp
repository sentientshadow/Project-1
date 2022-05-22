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

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Reservations.h"

const int RESERVATION_NUMBER = 50001;

int Reservations::addReservation(int memberId, std::string& hikeName)
{
	if (size == 0) {
		first = new Node(RESERVATION_NUMBER, memberId, hikeName, nullptr, last);
		last = first;
		size++;
	}
	else 
	{
		last->setNext(new Node(RESERVATION_NUMBER + size, memberId,
			hikeName, last, nullptr));
		last = last->getNext();
		size++;
	}
	return last->getReservationNumber();
}

void Reservations::cancelReservation(int reservNum)
{
	if (size == 1)
	{
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else
	{
		auto canceledRes = findReservation(reservNum);
		if (canceledRes == first)
		{
			first = first->getNext();
			first->getPrev()->setNext(nullptr);
			delete canceledRes;
			canceledRes = nullptr;
		}	
		else if	(canceledRes != last)
		{
			canceledRes->getPrev()->setNext(canceledRes->getNext());
			canceledRes->getNext()->setPrev(canceledRes->getPrev());
			delete canceledRes;
			canceledRes = nullptr;
		}
		else 
		{
			last = last->getPrev();
			last->setNext(nullptr);
			delete canceledRes;
			canceledRes = nullptr;
		}
	}
	size--;
}

void Reservations::printReservation(int reservNum, HikeList& listOfHikes,
	MemberList& listOfMembers)
{
	auto iterRes = findReservation(reservNum);
	listOfHikes.printByHikeName(iterRes->getHikeName());

	int membPoints = listOfMembers.getPoints(iterRes->getMemberID());
	double hikePrice = listOfHikes.getPrice(iterRes->getHikeName());
	cout <<  "\n" << "\t" << "Discounted price using points : " << fixed 
		<< setprecision(2) << (hikePrice - (membPoints / 100));
}

void Reservations::clearList()
{
	auto iterList = first;
	while (first != nullptr) 
	{
		first = first->getNext();
		delete iterList;
		iterList = first;
	}
	size = 0;
	last = nullptr;
}

Node* Reservations::findReservation(int reservNum)
{
	auto iter = first;
	while (iter->getReservationNumber() != reservNum)
	{
		iter = iter->getNext();
	}
	return iter;
}

Reservations::~Reservations() {
	clearList();
}