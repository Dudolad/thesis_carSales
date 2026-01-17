#pragma once
#include "Cars.h"
#include <string>

namespace carshop {

    class SportCar :
        public Cars
    {
    protected:
        float sekTo100km;
        float displacement;
        int enginePower;
    public:
        SportCar(const std::string& brand, int year, float price, const std::string& equipment,
            const std::string& country, Date saleDate,const std::string& buyerFullName,
            float sekTo100km, float displacement, int enginePower);

        
        std::string getType() const override;
        void show() const override;
        void save(std::ofstream& out) const override;

    };

}