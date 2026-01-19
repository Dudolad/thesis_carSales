#include <iostream>
#include <memory>
#include "CarManager.h"
#include "UsedCar.h"
#include "SportCar.h"
#include "SpecialVehicle.h"

using namespace carshop;
using namespace std;

int main()
{
	CarManager manager;
	int choice;

    do {
        cout << "=== Car Manager ===\n";
        cout << "1. Add Used Car\n";
        cout << "2. Add Sport Car\n";
        cout << "3. Add Special Vehicle\n";
        cout << "4. Remove car by brand\n";
        cout << "5. Sort cars by price\n";
        cout << "6. Save to file\n";
        cout << "7. Load from file\n";
        cout << "8. Show all cars\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: { 
            string brand, equipment, country, buyerName, ownerName, degree;
            int year;
            float price, mileage;

            cout << "Brand: "; getline(cin, brand);
            cout << "Year: "; cin >> year;
            cout << "Price: "; cin >> price; cin.ignore();
            cout << "Equipment: "; getline(cin, equipment);
            cout << "Country: "; getline(cin, country);
            cout << "Buyer name: "; getline(cin, buyerName);
            cout << "Owner name: "; getline(cin, ownerName);
            cout << "Degree of preservation: "; getline(cin, degree);
            cout << "Mileage: "; cin >> mileage; cin.ignore();

            auto car = make_shared<UsedCar>(brand, year, price, equipment, country, Date{ 0,0,0 }, buyerName, degree, ownerName, mileage);
            manager.addCar(car);
            cout << "Used car added!\n";
            break;
        }
        case 2: { 
            string brand, equipment, country, buyerName;
            int year, power;
            float price, secTo100, displacement;

            cout << "Brand: "; getline(cin, brand);
            cout << "Year: "; cin >> year;
            cout << "Price: "; cin >> price; cin.ignore();
            cout << "Equipment: "; getline(cin, equipment);
            cout << "Country: "; getline(cin, country);
            cout << "Buyer name: "; getline(cin, buyerName);
            cout << "0-100 km/h (sec): "; cin >> secTo100;
            cout << "Engine displacement: "; cin >> displacement;
            cout << "Engine power: "; cin >> power; cin.ignore();

            auto car = make_shared<SportCar>(brand, year, price, equipment, country, Date{ 0,0,0 }, buyerName, secTo100, displacement, power);
            manager.addCar(car);
            cout << "Sport car added!\n";
            break;
        }
        case 3: { 
            string brand, equipment, country, buyerName, vehicleType;
            int year;
            float price, weight, length, width, height;

            cout << "Brand: "; getline(cin, brand);
            cout << "Year: "; cin >> year;
            cout << "Price: "; cin >> price; cin.ignore();
            cout << "Equipment: "; getline(cin, equipment);
            cout << "Country: "; getline(cin, country);
            cout << "Buyer name: "; getline(cin, buyerName);
            cout << "Vehicle type: "; getline(cin, vehicleType);
            cout << "Weight (kg): "; cin >> weight;
            cout << "Length (m): "; cin >> length;
            cout << "Width (m): "; cin >> width;
            cout << "Height (m): "; cin >> height; cin.ignore();

            auto car = make_shared<SpecialVehicle>(brand, year, price, equipment, country, Date{ 0,0,0 }, buyerName, vehicleType, weight, length, width, height);
            manager.addCar(car);
            cout << "Special vehicle added!\n";
            break;
        }
        case 4: { 
            string brand;
            cout << "Brand to remove: "; getline(cin, brand);
            manager.removeByBrand(brand);
            break;
        }

        case 5: 
            manager.sortByPrice();
            cout << "Cars sorted by price.\n";
            break;

        case 6: { 
            string filename;
            cout << "Filename: "; getline(cin, filename);
            manager.saveToFile(filename);
            cout << "Saved to file.\n";
            break;
        }
        case 7: { 
            string filename;
            cout << "Filename: "; getline(cin, filename);
            manager.loadFromFile(filename);
            cout << "Loaded from file.\n";
            break;
        }
        case 8: 
            manager.showAll();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}