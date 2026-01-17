#include <iostream>
#include <memory>
#include "CarManager.h"
#include "UsedCar.h"
#include "SportCar.h"
#include "SpecialVehicle.h"

using namespace carshop;

int main()
{
	CarManager manager;

	try {
		manager.addCar(std::make_shared<UsedCar>(
			"Toyota", 2015, 12000, "Basic", "Japan", Date{ 12, 5, 2015 },
			"John Doe", "Good", "Alice Smith", 75000));

		manager.addCar(std::make_shared<SportCar>(
			"Ferrari", 2020, 250000, "Premium", "Italy", Date{ 1, 3, 220 },
			"John Doe", 3.5f, 3.9f, 720));
		
        manager.addCar(std::make_shared<SpecialVehicle>(
            "Caterpillar", 2018, 90000.0f, "Heavy Duty", "USA", Date{ 10, 7, 2018 },
            "Bob Builder", "Construction", 15000.0f, 10.0f, 3.5f, 4.0f));
	}
	catch (const std::exception& e) {
		std::cout << "Error adding car: " << e.what() << std::endl;
	}

    
    std::cout << "All cars:\n";
    manager.showAll();

    manager.sortByPrice();
    std::cout << "\nCars sorted by price:\n";
    manager.showAll();

    std::string searchBrand = "Toyota";
    auto foundCars = manager.findByBrand(searchBrand);
    std::cout << "\nCars with brand \"" << searchBrand << "\":\n";
    for (auto car : foundCars) {
        car->show();
        std::cout << "------------------\n";
    }

    try {
        manager.saveToFile("cars.txt");
        std::cout << "\nCars saved to file.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error saving to file: " << e.what() << std::endl;
    }

    CarManager loadedManager;
    try {
        loadedManager.loadFromFile("cars.txt");
        std::cout << "\nCars loaded from file:\n";
        loadedManager.showAll();
    }
    catch (const std::exception& e) {
        std::cout << "Error loading from file: " << e.what() << std::endl;
    }

    return 0;
}