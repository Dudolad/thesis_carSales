#include "SpecialVehicle.h"
#include <stdexcept>

SpecialVehicle::SpecialVehicle(std::string brand, int year, float price, std::string equipment, std::string country, Date saleDate, std::string buyerFullName, std::string vehicleCategory, float weight, float length, float width, float height)
    : Cars(brand, year, price, equipment, country, saleDate, buyerFullName),
    vehicleCategory(vehicleCategory), weight(weight), length(length), width(width), height(height)
{
    if (weight <= 0) throw std::invalid_argument("Weight must be positive");
    if (length <= 0 || width <= 0 || height <= 0)
        throw std::invalid_argument("All dimensions must be positive");
}

std::string SpecialVehicle::getVehicleCategory() const
{
    return vehicleCategory;
}

float SpecialVehicle::getWeight() const
{
    return weight;
}

float SpecialVehicle::getLength() const
{
    return length;
}

float SpecialVehicle::getWidth() const
{
    return width;
}

float SpecialVehicle::getHeight() const
{
    return height;
}

std::string SpecialVehicle::getType() const
{
    return "SpecialVehicle";
}

void SpecialVehicle::Print() const
{
    Cars::Print();
    std::cout << "Type: " << vehicleCategory << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
    std::cout << "Dimensions (L x W x H): "
        << length << " * " << width << " * " << height << " m" << std::endl;
}
