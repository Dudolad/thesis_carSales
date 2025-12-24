#include "Cars.h"
#include <iostream>

Cars::Cars()
{
	brand = "Undefined";
	year = 0;
	price = 0.0;
	equipment = "None";
	country = "Undefined";
	saleDate = { 0, 0, 0 };
	fullName = "Undefined";
}

Cars::Cars(std::string brand, int year, float price, std::string equipment, std::string country, Date saleDate, std::string fullName)
{
	this->brand = brand;
	this->year = year;
	this->price = price;
	this->equipment = equipment;
	this->country = country;
	this->saleDate = saleDate;
	this->fullName = fullName;
}

Cars::~Cars() {}

void Cars::Print()
{
	std::cout << "Brand: " << brand << std::endl;;
	std::cout << "Year: " << year << std::endl;;
	std::cout << "Price: " << price << std::endl;;
	std::cout << "Equipment: " << equipment << std::endl;;
	std::cout << "Country: " << country << std::endl;;
	std::cout << "Sale date: " << saleDate.saleDay << saleDate.saleMonth
		<< saleDate.saleYear << std::endl;
	std::cout << "Buyer: " << fullName << std::endl;
}
