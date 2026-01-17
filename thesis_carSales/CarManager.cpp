#include "CarManager.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include <fstream>
#include <stdexcept>

namespace carshop {

    void CarManager::addCar(const std::shared_ptr<Cars>& car)
    {
        if (!car)
            throw std::invalid_argument("Null pointer passed to addCar");

        cars.push_back(std::move(car));
    }

    void CarManager::removeByBrand(const std::string& brand)
    {
        cars.erase(
            std::remove_if(cars.begin(), cars.end(), [&brand](const std::shared_ptr<Cars>& car)
                {
                    return car->getBrand() == brand;
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

        for (const auto& car : cars)
        {
            car->show();
            std::cout << "------------------\n";
        }
    }

    std::vector<Cars*> CarManager::findByBrand(const std::string& brand) const
    {
        std::vector<Cars*> result;
        for (const auto& car : cars)
        {
            if (car->getBrand() == brand)
                result.push_back(car.get());
        }
        return result;
    }

    std::vector<Cars*> CarManager::findByYear(int year) const
    {
        std::vector<Cars*> result;
        for (const auto& car : cars)
        {
            if (car->getYear() == year)
                result.push_back(car.get());
        }
        return result;
    }

    void CarManager::sortByPrice()
    {
        std::sort(cars.begin(), cars.end(),
            [](const std::shared_ptr<Cars>& a, const std::shared_ptr<Cars>& b)
            {
                return a->getPrice() < b->getPrice();
            });
    }

    void CarManager::saveToFile(const std::string& filename) const
    {
        std::ofstream out(filename);
        if (!out) throw std::runtime_error("Cannot open file for writing");

        for (const auto& car : cars) {
            car->save(out); 
        }
    }

    void CarManager::loadFromFile(const std::string& filename)
    {
        std::ifstream in(filename);
        if (!in) throw std::runtime_error("Cannot open file for reading");

        cars.clear(); 

        std::string type;
        while (std::getline(in, type)) {
            if (type == "UsedCar") {
                std::string brand, equipment, country, buyer, degree, owner;
                int year;
                float price, mileage;
                int day, month, yearSale;

                std::getline(in, brand);
                in >> year >> price; in.ignore();
                std::getline(in, equipment);
                std::getline(in, country);
                in >> day >> month >> yearSale; in.ignore();
                std::getline(in, buyer);
                std::getline(in, degree);
                std::getline(in, owner);
                in >> mileage; in.ignore();

                Date date{ day, month, yearSale };
                cars.push_back(std::make_shared<UsedCar>(
                    brand, year, price, equipment, country, date, buyer, degree, owner, mileage
                ));
            }
            else if (type == "SportCar") {
                std::string brand, equipment, country, buyer;
                int year, power;
                float price, displacement, sek;

                std::getline(in, brand);
                in >> year >> price; in.ignore();
                std::getline(in, equipment);
                std::getline(in, country);
                int day, month, yearSale;
                in >> day >> month >> yearSale; in.ignore();
                std::getline(in, buyer);
                in >> sek >> displacement >> power; in.ignore();

                Date date{ day, month, yearSale };
                cars.push_back(std::make_shared<SportCar>(
                    brand, year, price, equipment, country, date, buyer, sek, displacement, power
                ));
            }
            else if (type == "SpecialVehicle") {
                std::string brand, equipment, country, buyer, category;
                int year;
                float price, weight, length, width, height;

                std::getline(in, brand);
                in >> year >> price; in.ignore();
                std::getline(in, equipment);
                std::getline(in, country);
                int day, month, yearSale;
                in >> day >> month >> yearSale; in.ignore();
                std::getline(in, buyer);
                std::getline(in, category);
                in >> weight >> length >> width >> height; in.ignore();

                Date date{ day, month, yearSale };
                cars.push_back(std::make_shared<SpecialVehicle>(
                    brand, year, price, equipment, country, date, buyer, category, weight, length, width, height
                ));
            }
        }
    }

}