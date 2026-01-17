#include "SportCar.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

namespace carshop {

    SportCar::SportCar(const std::string& brand, int year, float price,
        const std::string& equipment, const std::string& country, Date saleDate,
        const std::string& buyerFullName, float sekTo100km, float displacement, int enginePower)
        :Cars(brand, year, price, equipment, country, saleDate, buyerFullName),
        sekTo100km(sekTo100km), displacement(displacement), enginePower(enginePower)
    {
        if (sekTo100km <= 0)
            throw std::invalid_argument("Time to 100km/h must be positive");
        if (displacement <= 0)
            throw std::invalid_argument("Engine displacement must be positive");
        if (enginePower <= 0)
            throw std::invalid_argument("Engine power must be positive");
    }

    std::string SportCar::getType() const { return "SportCar"; }


    void SportCar::save(std::ofstream& out) const {
        out << getType() << "\n"
            << brand << "\n"
            << year << "\n"
            << price << "\n"
            << equipment << "\n"
            << country << "\n"
            << saleDate.day << " " << saleDate.month << " " << saleDate.year << "\n"
            << buyerFullName << "\n"
            << sekTo100km << "\n"
            << displacement << "\n"
            << enginePower << "\n";
    }

    void SportCar::show() const
    {
        Cars::show();
        std::cout << "Time to 100 km/h: " << sekTo100km << " sec" 
                  << "Engine displacement: " << displacement << " L" 
                  << "Engine power: " << enginePower << " HP" << std::endl;
    }

}