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
    shop.push_back({ "salt",7,30 });
    shop.push_back({ "oil" , 83, 15 });
    shop.push_back({ "bread", 24,48 });

    int wallet = 5000;
    int number;
    int temp;


    while (wallet > 0)
    {
        std::cout << "WALLET" << wallet << "All product" << std::endl;
        std::cout << "Name\t\tPrice\tCount\n" << std::endl;

        for (int i = 0; i < shop.size(); i++)
        {
            std::cout << i + 1 << "\t" << shop[i].name << shop[i].price << "\t" << shop[i].count << std::endl;

        }
        std::cout << "Chouse count\n";
        std::cin >> number;

        if (shop[number - 1].count >= 0) {
            std::cout << "Chouse count\n";
            std::cin >> temp;


            if (shop[number - 1].count >= temp) {
                if (shop[number - 1].price * temp < wallet) {
                    wallet -= temp * (shop[number - 1].price);
                    std::cout << "Buy" << shop[number - 1].name << "\tTotal prise" << temp * shop[number - 1].price << std::endl;
                    shop[number - 1].count -= temp;
                    std::cout << "WALLET" << wallet << std::endl;
                }
                else {
                    std::cout << "NO MONEY\t Total PRICE: " << shop[number - 1].price * temp << ">" << wallet;
                }
            }
            else
            {
                std::cout << "Qantiti is less\n";
            }
        }
        else {
            std::cout << "\nCount 0\n";
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
