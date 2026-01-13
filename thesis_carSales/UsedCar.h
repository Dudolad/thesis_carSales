#pragma once
#include "Cars.h"
#include <string>

class UsedCar
	: public Cars
{
protected:
	std::string degreeOfPreservation; //Ступінь збереження
	std::string ownerFullName;
	float mileage;
public:
	UsedCar(std::string brand, int year, float price, std::string equipment,
		std::string country, Date saleDate, std::string buyerFullName,
		std::string degreeOfPreservation, std::string ownerFullName, float mileage);

	std::string getType() const override;
	void setMileage(float mileage);
	void Print() const override;
};

