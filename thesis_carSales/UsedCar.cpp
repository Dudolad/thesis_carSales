#include "UsedCar.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

namespace carshop {

	UsedCar::UsedCar(const std::string& brand, int year, float price,
		const std::string& equipment, const std::string& country,
		Date saleDate, const std::string& buyerFullName,
		const std::string& degreeOfPreservation, const std::string& ownerFullName,
		float mileage)
		: Cars(brand, year, price, equipment, country, saleDate, buyerFullName),
		degreeOfPreservation(degreeOfPreservation), ownerFullName(ownerFullName)
	{
		if (mileage < 0) throw std::invalid_argument("Mileage cannot be negative");
		this->mileage = mileage;
	}

	std::string UsedCar::getType() const
	{
		return "UsedCar";
	}


	void UsedCar::show() const
	{
		Cars::show();
		std::cout << "Degree of preservation: " << degreeOfPreservation
			<< "Owner full name: " << ownerFullName
			<< "Mileage: " << mileage << std::endl;
	}


	void UsedCar::save(std::ofstream& out) const {
		out << getType() << "\n"
			<< brand << "\n"
			<< year << "\n"
			<< price << "\n"
			<< equipment << "\n"
			<< country << "\n"
			<< saleDate.day << " " << saleDate.month << " " << saleDate.year << "\n"
			<< buyerFullName << "\n"
			<< degreeOfPreservation << "\n"
			<< ownerFullName << "\n"
			<< mileage << "\n";
	}
}