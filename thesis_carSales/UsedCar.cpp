#include "UsedCar.h"
#include <iostream>
#include <stdexcept>

UsedCar::UsedCar(std::string brand, int year, float price, std::string equipment, std::string country, Date saleDate, std::string buyerFullName, std::string degreeOfPreservation, std::string ownerFullName, float mileage)
	:Cars(brand, year, price, equipment, country, saleDate, buyerFullName),
	degreeOfPreservation(degreeOfPreservation), ownerFullName(ownerFullName)
{
	setMileage(mileage);
}

void UsedCar::setMileage(float mileage)
{
	if(mileage < 0)
		throw std::invalid_argument("Mileage cannot be negative");
	this->mileage = mileage;
}

void UsedCar::Print() const
{
	Cars::Print();
	std::cout << "Degree of preservation: " << degreeOfPreservation << std::endl;
	std::cout << "Owner full name: " << ownerFullName << std::endl;
	std::cout << "Mileage: " << mileage << std::endl;
}
