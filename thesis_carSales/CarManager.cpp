#include "CarManager.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

CarManager::CarManager() {}

CarManager::~CarManager()
{
	for (Cars* car : cars)
		delete car;
}

void CarManager::addCar(Cars* car)
{
	cars.push_back(car);
}

void CarManager::removeByBrand(const std::string& brand)
{
	cars.erase(
		std::remove_if(cars.begin(), cars.end(), [&](Cars* car)
			{
				if (car->getBrand() == brand)
				{
					delete car;
					return true;
				}
				return false;
			}),
		cars.end()
	);
}

void CarManager::showAll() const
{
	if (cars.empty())
	{
		std::cout << "No cars available.\n";
		return;
	}

	for (const Cars* car : cars)
	{
		car->Print();   
		std::cout << "------------------\n";
	}
}

std::vector<Cars*> CarManager::findByBrand(const std::string& brand) const
{
	std::vector<Cars*> result;
	for (Cars* car : cars)
	{
		if (car->getBrand() == brand)
			result.push_back(car);
	}
	return result;
}

std::vector<Cars*> CarManager::findByYear(int year) const
{
	std::vector<Cars*> result;
	for (Cars* car : cars)
	{
		if (car->getYear() == year)
			result.push_back(car);
	}
	return result;
}

void CarManager::sortByPrice()
{
	std::sort(cars.begin(), cars.end(),
		[](Cars* a, Cars* b)
		{
			return a->getPrice() < b->getPrice();
		});
}

void CarManager::saveToFile(const std::string& filename) const
{
}

void CarManager::loadFromFile(const std::string& filename)
{
}
