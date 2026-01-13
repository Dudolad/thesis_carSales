#include "SportCar.h"
#include <stdexcept>
#include <iostream>

SportCar::SportCar(std::string brand, int year, float price, std::string equipment, std::string country, Date saleDate, std::string buyerFullName, float sekTo100km, float displacement, int enginePower)
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

float SportCar::getSekTo100km() const
{
    return sekTo100km;
}

float SportCar::getDisplacement() const
{
    return displacement;
}

int SportCar::getEnginePower() const
{
    return enginePower;
}

std::string SportCar::getType() const
{
    return "SportCar";
}

void SportCar::Print() const
{
    Cars::Print(); 
    std::cout << "Time to 100 km/h: " << sekTo100km << " sec" << std::endl;
    std::cout << "Engine displacement: " << displacement << " L" << std::endl;
    std::cout << "Engine power: " << enginePower << " HP" << std::endl;
}
