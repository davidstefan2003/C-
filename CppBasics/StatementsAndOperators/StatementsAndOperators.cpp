#include <iostream>
int main()
{
    int cents = 0;
    std::cout << "Enter an amount in cents : ";
    std::cin >> cents;

    std::cout << "You can provide this change as follows: " << std::endl;

    int dollars = 0;
    const int dollarValue = 100;
    dollars = cents / dollarValue;
    cents = cents - dollars * dollarValue;
    std::cout << "dollars : " << dollars << std::endl;

    int quarter = 0;
    quarter = cents / 25;
    cents = cents - quarter * 25;
    std::cout << "quarters : " << quarter << std::endl;

    int dime = 0;
    dime = cents / 10;
    cents = cents - dime * 10;
    std::cout << "dimes : " << dime << std::endl;

    int nickel = 0;
    nickel = cents / 5;
    cents = cents - nickel * 5;
    std::cout << "nickels : " << nickel << std::endl;

    int penny = 0;
    penny = cents;
    std::cout << "pennies : " << penny << std::endl;

}