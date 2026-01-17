#pragma once
#include "Cars.h"
#include <string>
#include <stdexcept>
#include <iostream>

namespace carshop {

    class SpecialVehicle :
        public Cars
    {
    protected:
        std::string vehicleCategory;
        float weight{};
        float length{}, width{}, height{};
    public:
        SpecialVehicle() = default;
        SpecialVehicle(const std::string& brand, int year, float price,
            const std::string& equipment, const std::string& country, Date saleDate,
            const std::string& buyerFullName, const std::string& vehicleCategory, float weight, float length, float width, float height);

        void save(std::ofstream& out) const override;
        std::string getType() const override;

        void show() const override;
    };

}
