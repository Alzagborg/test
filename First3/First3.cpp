// First3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

struct product
{
    std::string name;
    int price;
    int count;

};



std::vector<product> shop;




int main()
{
    shop.push_back({ "salt\t",7,30 });
    shop.push_back({ "oil\t" , 83, 15 });
    shop.push_back({ "bread\t", 24,48 });

    int wallet = 5000;
    int number;
    int temp;


    while (wallet > 0)
    {
        std::cout << "WALLET " << wallet << "\n\nAll product:" << std::endl;
        std::cout << "Name\t\tPrice\tCount\n" << std::endl;

        for (int i = 0; i < shop.size(); i++)
        {
            std::cout << i + 1 << "\t" << shop[i].name << shop[i].price << "\t" << shop[i].count << std::endl;

        }
        std::cout << "\nChouse number\n";
        std::cin >> number;

        if (shop[number - 1].count >= 0) {
            std::cout << "Chouse count\n";
            std::cin >> temp;


            if (shop[number - 1].count >= temp) {
                if (shop[number - 1].price * temp < wallet) {
                    wallet -= temp * (shop[number - 1].price);
                    std::cout << "Buy\t" << shop[number - 1].name << "\tTotal prise" << temp * shop[number - 1].price << std::endl;
                    shop[number - 1].count -= temp;
                    std::cout << "WALLET" << wallet << std::endl;
                    std::cout << "_______\n";
                }
                else {
                    std::cout << "NO MONEY\t Total PRICE: " << shop[number - 1].price * temp << ">" << wallet;
                }
            }
            else
            {
                std::cout << "\nQantiti is less\n";
            }
        }
        else {
            std::cout << "\nCount 0\n";
        }
    }


}


