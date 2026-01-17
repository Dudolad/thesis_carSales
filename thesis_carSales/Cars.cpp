#include "Cars.h"
#include <iostream>

namespace carshop {

	Cars::Cars(const std::string& brand, int year, float price,
		const std::string& equipment, const std::string& country, 
		Date saleDate,const std::string& buyerFullName)
		: brand(brand), year(year), price(price), equipment(equipment), country(country),
		saleDate(saleDate), buyerFullName(buyerFullName)
	{
	}

	Cars::~Cars() = default;

	void Cars::show() const
	{
		std::cout << "Brand: " << brand
			<< " | Year: " << year
			<< " | Price: " << price
			<< " | Equipment: " << equipment
			<< " | Country: " << country
			<< " | Sale date: " << saleDate.day << "." << saleDate.month << "." << saleDate.year
			<< " | Buyer: " << buyerFullName;
	}

	std::string Cars::getBrand() const { return brand; }
	int Cars::getYear() const { return year; }
	float Cars::getPrice() const { return price; }
}

