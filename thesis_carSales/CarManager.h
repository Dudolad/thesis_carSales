#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Cars.h"
#include "UsedCar.h"
#include "SportCar.h"
#include "SpecialVehicle.h"

namespace carshop {

	class CarManager
	{
	private:
		std::vector<std::shared_ptr<Cars>> cars;
	public:

		CarManager() = default;
		~CarManager() = default;

		//manager
		void addCar(const std::shared_ptr<Cars>& car);
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

}