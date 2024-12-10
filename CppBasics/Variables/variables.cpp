#include <iostream>
int main()
{
	const int priceSmallRoom = 25;
	const int priceLargeRoom = 35;
	const float tax = 0.06f;
	
	int smallRooms = 0;

	std::cout << "Number of small rooms: ";
	std::cin >> smallRooms;
	
	int largeRooms = 0;

	std::cout << "Number of large rooms: ";
	std::cin >> largeRooms;

	std::cout << "Price per small room: $" << priceSmallRoom << std::endl;
	std::cout << "Price per large room: $" << priceLargeRoom << std::endl;

	int cost = priceSmallRoom * smallRooms + priceLargeRoom * largeRooms;

	std::cout << "Cost: $" << cost << std::endl;
	std::cout << "Tax: $" << tax * cost << std::endl;
	std::cout << "======================" << std::endl;

	float total = cost * tax + cost;

	std::cout << "Total estimate: $" << total << std::endl;
	std::cout << "This estimate is valid for 30 days" << std::endl;
}