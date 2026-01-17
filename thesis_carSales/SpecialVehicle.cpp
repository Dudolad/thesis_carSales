#include "SpecialVehicle.h"
#include <stdexcept>
#include <fstream>


namespace carshop {

    SpecialVehicle::SpecialVehicle(const std::string& brand, int year, float price,
        const std::string& equipment, const std::string& country, Date saleDate,
        const std::string& buyerFullName,const std::string& vehicleCategory, float weight, float length, float width, float height)
        : Cars(brand, year, price, equipment, country, saleDate, buyerFullName),
        vehicleCategory(vehicleCategory), weight(weight), length(length), width(width), height(height)
    {
        if (weight <= 0) throw std::invalid_argument("Weight must be positive");
        if (length <= 0 || width <= 0 || height <= 0)
            throw std::invalid_argument("All dimensions must be positive");
    }


    std::string SpecialVehicle::getType() const
    {
        return "SpecialVehicle";
    }

    void SpecialVehicle::show() const
    {
        Cars::show();
        std::cout << "Type: " << vehicleCategory 
                  << "Weight: " << weight << " kg"
        << "Dimensions (L x W x H): " << length << " * " << width << " * " << height << " m" << std::endl;
    }

    void SpecialVehicle::save(std::ofstream& out) const {
        out << getType() << "\n"
            << brand << "\n"
            << year << "\n"
            << price << "\n"
            << equipment << "\n"
            << country << "\n"
            << saleDate.day << " " << saleDate.month << " " << saleDate.year << "\n"
            << buyerFullName << "\n"
            << vehicleCategory << "\n"
            << weight << "\n"
            << length << "\n"
            << width << "\n"
            << height << "\n";
    }
}