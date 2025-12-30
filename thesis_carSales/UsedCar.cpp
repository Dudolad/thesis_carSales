#include "UsedCar.h"
#include <iostream>

UsedCar::UsedCar(std::string brand, int year, float price, std::string equipment, std::string country, Date saleDate, std::string buyerFullName, std::string degreeOfPreservation, std::string ownerFullName, float mileage)
	:Cars(brand, year, price, equipment, country, saleDate, buyerFullName),
	degreeOfPreservation(degreeOfPreservation), ownerFullName(ownerFullName), mileage(mileage)
{
}

void UsedCar::Print() const
{
	Cars::Print();
	std::cout << "Degree of preservation: " << degreeOfPreservation << std::endl;
	std::cout << "Owner full name: " << ownerFullName << std::endl;
	std::cout << "Milleage: " << mileage << std::endl;
}
