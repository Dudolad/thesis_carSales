#pragma once
#include <vector>
#include <string>
#include "Cars.h"

class CarManager
{
private:
	std::vector<Cars*> cars;
public:
	CarManager();
	~CarManager();

	void addCar(Cars* car);
	void removeByBrand(const std::string& brand);

	void showAll() const;

	std::vector<Cars*> findByBrand(const std::string& brand) const;
	std::vector<Cars*> findByYear(int year) const;

	void sortByPrice();
};

