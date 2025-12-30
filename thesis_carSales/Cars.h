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
	std::string buyerFullName;
public:
	Cars();
	Cars(std::string brand, int year, float price, std::string equipment,
		std::string country, Date saleDate, std::string buyerFullName);

	virtual ~Cars();
	virtual void Print() const;

	std::string getBrand() const; //search
	int getYear() const; //filtration
	float getPrice() const; //sort

	void setYear(int year);
	void setPrice(float price);


};

