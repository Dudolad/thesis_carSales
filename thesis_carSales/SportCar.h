#pragma once
#include "Cars.h"
#include <string>
class SportCar :
    public Cars
{
protected:
    float sekTo100km;
    float displacement;
    int enginePower;
public:
    SportCar(std::string brand, int year, float price, std::string equipment,
        std::string country, Date saleDate, std::string buyerFullName,
        float sekTo100km, float displacement, int enginePower);

    float getSekTo100km() const;
    float getDisplacement() const;
    int getEnginePower() const;
    std::string getType() const override;

    void Print() const override;

};

