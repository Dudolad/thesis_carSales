#pragma once
#include <string>
#include "Date.h"
#include <iostream>
#include <fstream>

namespace carshop {

	class Cars
	{
	protected:
		std::string brand;
		int year{};
		float price{};
		std::string equipment;
		std::string country;
		Date saleDate{};
		std::string buyerFullName;
	public:
		Cars() = default;
		Cars(const std::string& brand, int year, float price, const std::string& equipment,
			const std::string& country, Date saleDate, const std::string& buyerFullName);

		virtual ~Cars();

		virtual void show() const;
		virtual std::string getType() const = 0;
		virtual void save(std::ofstream& out) const = 0;

		std::string getBrand() const;
		int getYear() const;
		float getPrice() const;


		bool operator<(const Cars& other) const {
			return price < other.price; 
		}


		friend std::ostream& operator<<(std::ostream& os, const Cars& car) {
			car.show();  
			return os;
		}
	};

}

