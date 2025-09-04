#include <iostream>
#include <vector>
#include <string>
#include <map>   // äîáàâëÿåì äëÿ õðàíåíèÿ èñòîðèè ïîêóïîê

struct product
{
    std::string name;
    int price;
    int count;
};

std::vector<product> shop;


void Merch() {

    shop.push_back({ "Salt\t",50,30 });
    shop.push_back({ "Oil\t",830,25 });
    shop.push_back({ "Bread\t",248,48 });

    int wallet = 5000;
    int number;
    int temp;

    int totalSpent = 0;   // îáùàÿ ñóììà ïîòðà÷åííûõ äåíåã
    int totalItems = 0;   // îáùåå êîëè÷åñòâî êóïëåííûõ òîâàðîâ

    // íîâàÿ ïåðåìåííàÿ: èñòîðèÿ ïîêóïîê
    std::map<std::string, int> purchaseHistory;

    while (wallet > 0)
    {
        std::cout << "WALLET: " << wallet << "\n\nAll products:" << std::endl;
        std::cout << "No\tName\tPrice\tQuantity\n" << std::endl;

        for (int i = 0; i < shop.size(); i++) {
            std::cout << i + 1 << "\t" << shop[i].name
                << shop[i].price << "\t" << shop[i].count << std::endl;
        }

        std::cout << "\nEnter product number:\n";
        std::cin >> number;

        if (shop[number - 1].count >= 0) {
            std::cout << "Select product quantity:\n";
            std::cin >> temp;

            if (shop[number - 1].count >= temp) {
                if (shop[number - 1].price * temp < wallet) {
                    int purchaseCost = temp * shop[number - 1].price;

                    wallet -= purchaseCost;
                    totalSpent += purchaseCost;  // óâåëè÷èâàåì çàòðàòû
                    totalItems += temp;          // óâåëè÷èâàåì îáùåå êîëè÷åñòâî òîâàðîâ

                    // ñîõðàíÿåì ïîêóïêó â èñòîðèþ
                    purchaseHistory[shop[number - 1].name] += temp;

                    std::cout << "Buy\t" << shop[number - 1].name
                        << "\tTotal price:\t" << purchaseCost << std::endl;

                    shop[number - 1].count -= temp;

                    std::cout << "Left in your wallet: " << wallet << std::endl;
                    std::cout << "Total spent so far: " << totalSpent << std::endl;
                    std::cout << "Total items bought: " << totalItems << std::endl;

                    // âûâîäèì êðàòêóþ èñòîðèþ
                    std::cout << "Your purchases so far:\n";
                    for (const auto& entry : purchaseHistory) {
                        std::cout << " - " << entry.first << ": " << entry.second << " pcs\n";
                    }

                    std::cout << "______________________\n";
                }
                else {
                    std::cout << "NO MONEY\t Total PRICE: "
                        << shop[number - 1].price * temp << " > " << wallet;
                }
            }
            else {
                std::cout << "\nInsufficient amount of product!\n";
            }
        }
        else {
            std::cout << "\nCount 0\n";
        }
    }

    std::cout << "\nShopping finished. Total money spent: " << totalSpent
        << ", total items bought: " << totalItems << std::endl;

    std::cout << "Final purchase history:\n";
    for (const auto& entry : purchaseHistory) {
        std::cout << " - " << entry.first << ": " << entry.second << " pcs\n";
    }

}

int test(int b) {


    if (b < 10) {

        return true;
    }
    else {

        return false;

    }
    std::cout << "DONE\n";
}

int main()
{
    int mas[5]{ 7, -2, 1, -9, 5 };

    // вывести одну позицую, любую(-9)
    // вывести весь массив, перебор массивов, почитать как работает цикл for
    // вывести только отрицательные числа используя перебор массивов.
    // сделать чтобы все числа в массиве были положительными
}

