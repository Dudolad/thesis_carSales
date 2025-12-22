#pragma once
#include <string>

class Cars
{
protected: 
	std::string brand;
	int year;
	float price;
	std::string equipment;
	std::string country;
	struct Date
	{
		int saleDay;
		int saleMonth;
		int saleYear;
	};
	Date saleDate;
	std::string fullName;
public:
	Cars();
	Cars(std::string brand, int year, float price, std::string equipment,
		std::string country, Date saleDate, std::string fullName);

	virtual ~Cars();
	virtual void Print();
};

