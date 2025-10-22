#include <iostream>
#include <vector>
#include <memory>
#include "include/Figures.h"
#include "include/Pentagon.h"
#include "include/Hexagon.h" 
#include "include/Octagon.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    
    int choice;
    do {
        std::cout << "\n1. Add Pentagon\n";
        std::cout << "2. Add Hexagon\n";
        std::cout << "3. Add Octagon\n";
        std::cout << "4. Print all figures\n";
        std::cout << "5. Calculate total area\n";
        std::cout << "6. Delete figure by index\n";
        std::cout << "7. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1: {
                auto pentagon = std::make_unique<Pentagon>();
                std::cout << "Enter 5 points (x y) for Pentagon:\n";
                std::cin >> *pentagon;
                figures.push_back(std::move(pentagon));
                break;
            }
            case 2: {
                auto hexagon = std::make_unique<Hexagon>();
                std::cout << "Enter 6 points (x y) for Hexagon:\n";
                std::cin >> *hexagon;
                figures.push_back(std::move(hexagon));
                break;
            }
            case 3: {
                auto octagon = std::make_unique<Octagon>();
                std::cout << "Enter 8 points (x y) for Octagon:\n";
                std::cin >> *octagon;
                figures.push_back(std::move(octagon));
                break;
            }
            case 4: {
                std::cout << "\nAll figures:\n";
                for (size_t i = 0; i < figures.size(); ++i) {
                    std::cout << i << ": " << *figures[i] << std::endl;
                    std::cout << "Center: (" << figures[i]->get_center().x 
                              << ", " << figures[i]->get_center().y << ")\n";
                    std::cout << "Area: " << figures[i]->area() << "\n\n";
                }
                break;
            }
            case 5: {
                double total_area = 0;
                for (const auto& fig : figures) {
                    total_area += fig->area();
                }
                std::cout << "Total area: " << total_area << std::endl;
                break;
            }
            case 6: {
                size_t index;
                std::cout << "Enter index to delete: ";
                std::cin >> index;
                if (index < figures.size()) {
                    figures.erase(figures.begin() + index);
                    std::cout << "Figure deleted.\n";
                } else {
                    std::cout << "Invalid index.\n";
                }
                break;
            }
        }
    } while (choice != 7);
    
    return 0;
}