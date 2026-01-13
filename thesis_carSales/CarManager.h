#pragma once
#include <vector>
#include <string>
#include "Cars.h"
#include "UsedCar.h"
#include "SportCar.h"
#include "SpecialVehicle.h"

class CarManager
{
private:
	std::vector<Cars*> cars;
public:
	CarManager();
	~CarManager();

	//manager
	void addCar(Cars* car);
	void removeByBrand(const std::string& brand);
	void showAll() const;

	//search
	std::vector<Cars*> findByBrand(const std::string& brand) const;
	std::vector<Cars*> findByYear(int year) const;

	//sort
	void sortByPrice();

	//file
	void saveToFile(const std::string& filename) const;
	void loadFromFile(const std::string& filename);
};

