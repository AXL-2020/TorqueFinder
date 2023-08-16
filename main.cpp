#include <iostream>
#include <vector>
#include <map>
#include <Windows.h>
#include <mutex>
#include "torque db.hpp"

void findTorque(int& flag) {
    int year = 0, make = 0, model = 0, counter = 1;
    flag = 0;
    system("cls");

    do {
        std::cout << "Vehicle year:";
        std::cin >> year;
        std::cout << std::endl;
    } while (year < 1990 || year > 2023);


    do {
        for (auto makeEntry : torqueDatabase) {
            std::cout << counter << ". " << makeEntry.first << std::endl;
            counter++;
        }

        std::cout << std::endl << "Vehicle make:";
        std::cin >> make;
    } while (!make || make > torqueDatabase.size());

    system("cls");

    auto it = torqueDatabase.begin();
    make--;
    std::advance(it, make);
    std::cout << it->first << std::endl;
    for (auto i : it->second) {
        if (year >= i.second.startYear && year <= i.second.endYear)
            std::cout << i.first << ": " << i.second.torque << " ft/lbs" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleTitle(L"Lug Torque Finder by Aidan Latessa");
    int flag;
    findTorque(flag);
    while (!GetAsyncKeyState(VK_ESCAPE)) {
       if (!flag) 
           std::cout << "Press spacebar to lookup a new torque. " << std::endl;
        
       flag = 1;
        
       if (GetAsyncKeyState(VK_SPACE)) 
            findTorque(flag);
       
        Sleep(100);
    }
}
