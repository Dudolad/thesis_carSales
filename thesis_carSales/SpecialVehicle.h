#pragma once
#include "Cars.h"
#include <string>
#include <iostream>

class SpecialVehicle :
    public Cars
{
protected:
    std::string vehicleCategory;
    float weight;
    float length, width, height;
public:
    SpecialVehicle(std::string brand, int year, float price, std::string equipment,
        std::string country, Date saleDate, std::string buyerFullName,
        std::string vehicleCategory, float weight, float length, float width, float height);

    std::string getVehicleCategory() const;
    float getWeight() const;
    float getLength() const;
    float getWidth() const;
    float getHeight() const;
    std::string getType() const override;

    void Print() const override;
};

