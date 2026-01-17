#pragma once
#include "Cars.h"
#include <string>

namespace carshop {

	class UsedCar
		: public Cars
	{
	protected:
		std::string degreeOfPreservation; //Ступінь збереження
		std::string ownerFullName;
		float mileage;
	public:
		UsedCar() = default;
		UsedCar(const std::string& brand, int year, float price, const std::string& equipment,
			const std::string& country, Date saleDate, const std::string& buyerFullName,
			const std::string& degreeOfPreservation, const std::string& ownerFullName, float mileage);

		std::string getType() const override;
		void show() const override;
		void save(std::ofstream& out) const override;
	};

}