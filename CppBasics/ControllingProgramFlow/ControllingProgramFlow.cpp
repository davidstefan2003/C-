#include <iostream>
#include <string>

void print(int* sir, int dimensiune)
{

	if (dimensiune == 0 || sir == nullptr)
	{
		std::cout << "[] - the list is empty" << std::endl;
		return;
	}
	std::cout << "[ ";
	for (int i = 0; i < dimensiune; ++i)
	{
		std::cout << sir[i] << " ";
	}
	std::cout << "]" << std::endl;
}

int* add(int*& sir, int& dimensiune, int elemNou)
{
	int* sirAdd = new int[dimensiune + 1];

	for (int i = 0; i < dimensiune; ++i)
	{
		sirAdd[i] = sir[i];
	}
	sirAdd[dimensiune] = elemNou;
	std::cout << elemNou << " added." << std::endl;
	delete[] sir;
	dimensiune++;
	return sirAdd;
}
void mean(int* sir, int dimensiune) {
	if (sir == nullptr || dimensiune == 0) {
		std::cout << "Unable to calculate mean - no data" << std::endl;
		return;
	}
	int suma = 0;
	for (int i = 0; i < dimensiune; ++i) {
		suma += sir[i];
	}
	double media = suma / (1.0 * dimensiune);
	std::cout << "The mean is: " << media << std::endl;
}


void smallest(int* sir, int dimensiune)
{
	if (sir == nullptr || dimensiune == 0)
	{
		std::cout << "Unable to determine the smallest number - list is empty" << std::endl;
		return;
	}
	int smallestNr = sir[0];
	for (int i = 0; i < dimensiune; ++i)
	{
		if (smallestNr > sir[i])
		{
			smallestNr = sir[i];
		}

	}
	std::cout << "The smallest number is " << smallestNr << std::endl;
}

void largest(int* sir, int dimensiune)
{
	if (sir == nullptr || dimensiune == 0)
	{
		std::cout << "Unable to determine the largest number - list is empty" << std::endl;
		return;
	}
	int largestNr = sir[0];
	for (int i = 0; i < dimensiune; ++i)
	{
		if (largestNr < sir[i])
		{
			largestNr = sir[i];
		}

	}
	std::cout << "The largest number is " << largestNr << std::endl;
}

int main()
{
	char option = ' ';
	int* sir = nullptr;
	int dimensiune = 0;
	do
	{
		std::cout << "P - Print numbers" << std::endl;
		std::cout << "A - Add a number" << std::endl;
		std::cout << "M - Display mean of the numbers" << std::endl;
		std::cout << "S - Display the smallest number" << std::endl;
		std::cout << "L - Display the largest number" << std::endl;
		std::cout << "Q - Quit" << std::endl << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> option;

		int elemNou = 0;
		switch (option)
		{
		case 'p':
		case 'P':
			std::cout << "sir = ";
			print(sir, dimensiune);
			break;
		case 'a':
		case 'A':
			std::cout << "Enter an integer: ";
			std::cin >> elemNou;

			sir = add(sir, dimensiune, elemNou);
			break;
		case 'm':
		case 'M':
			mean(sir, dimensiune);
			break;
		case 's':
		case 'S':
			smallest(sir, dimensiune);
			break;
		case 'l':
		case 'L':
			largest(sir, dimensiune);
			break;
		case 'q':
		case 'Q':
			std::cout << "Goodbye" << std::endl;
			break;
		default:
			std::cout << "Unknown selection, please try again" << std::endl;
			break;
		}
	} while (option != 'q' && option != 'Q');
}