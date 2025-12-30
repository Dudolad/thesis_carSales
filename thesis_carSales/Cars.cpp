#include "Cars.h"
#include <iostream>
#include <stdexcept>

Cars::Cars()
{
	brand = "Undefined";
	year = 0;
	price = 0.0;
	equipment = "None";
	country = "Undefined";
	saleDate = { 0, 0, 0 };
	buyerFullName = "Undefined";
}

Cars::Cars(std::string brand, int year, float price, std::string equipment, std::string country, Date saleDate, std::string buyerFullName)
{
	this->brand = brand;
	this->year = year;
	this->price = price;
	this->equipment = equipment;
	this->country = country;
	this->saleDate = saleDate;
	this->buyerFullName = buyerFullName;
}

Cars::~Cars() {}

void Cars::Print() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Equipment: " << equipment << std::endl;
	std::cout << "Country: " << country << std::endl;
	std::cout << "Sale date: "
		<< saleDate.saleDay << "."
		<< saleDate.saleMonth << "."
		<< saleDate.saleYear << std::endl;
	std::cout << "Buyer: " << buyerFullName << std::endl;
}

std::string Cars::getBrand() const
{
	return brand;
}

int Cars::getYear() const
{
	return year;
}

float Cars::getPrice() const
{
	return price;
}

void Cars::setYear(int year)
{
	if (year < 1886) //first car
	{
		throw std::invalid_argument("Invalid year!");
	}
	this->year = year;
}

void Cars::setPrice(float price)
{
	if (price < 0)
	{
		throw std::invalid_argument("Price can be only positive!");
	}
	this->price = price;
}


