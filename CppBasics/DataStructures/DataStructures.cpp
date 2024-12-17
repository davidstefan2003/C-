#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyVector.h"
struct Caine
{
	char* nume;
	int varsta;
	int numarVaccine;
	float* pretVaccine;
	bool arePedigree;
};
void afiseaza(Caine c)
{
	std::cout << "Nume = " << c.nume << std::endl;
	std::cout << "Varsta = " << c.varsta << " ani" << std::endl;
	std::cout << "Numarul de vaccine este = " << c.numarVaccine << std::endl;
	std::cout << "Pretul fiecarui vaccin este = ";
	for (int i = 0; i < c.numarVaccine; ++i)
	{
		std::cout << c.pretVaccine[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << "Are pedigree = " << c.arePedigree << std::endl;
}

Caine* creeazaCaine(const char* nume, int varsta, int numarVaccine, std::initializer_list<float> pretVaccine, bool arePedigree)
{
	Caine* cnou = new Caine;
	cnou->nume = new char[strlen(nume) + 1];
	strcpy(cnou->nume, nume);
	cnou->varsta = varsta;
	cnou->numarVaccine = numarVaccine;
	cnou->pretVaccine = new float[cnou->numarVaccine];
	int i = 0;
	for (const float val : pretVaccine)
	{
		cnou->pretVaccine[i] = val;
		i++;
	}
	cnou->arePedigree = arePedigree;
	return cnou;
}
void stergeCaine(Caine*& c)
{
	delete[] c->nume;
	delete[] c->pretVaccine;
	delete c;
	c = nullptr;
}
int main()
{
	Caine dalmatian;
	dalmatian.nume = new char[strlen("Rex") + 1];
	strcpy(dalmatian.nume, "Rex");
	dalmatian.varsta = 4;
	dalmatian.numarVaccine = 2;
	dalmatian.pretVaccine = new float[dalmatian.numarVaccine] {50.45, 100.65};
	dalmatian.arePedigree = false;

	Caine bulldog;
	bulldog.nume = new char[strlen("Sparky") + 1];
	strcpy(bulldog.nume, "Sparky");
	bulldog.varsta = 3;
	bulldog.numarVaccine = 2;
	bulldog.pretVaccine = new float[bulldog.numarVaccine] {30.90, 76.33};
	bulldog.arePedigree = true;

	afiseaza(dalmatian);
	afiseaza(bulldog);

	delete[] dalmatian.nume;
	delete[] bulldog.nume;
	delete[] dalmatian.pretVaccine;
	delete[] bulldog.pretVaccine;

	Caine* husky = creeazaCaine("Azorel", 5, 3, {30.99, 100.45, 20.89}, true);

	afiseaza(*husky);
	stergeCaine(husky);

	if (husky == nullptr)
	{
		std::cout << "Cainele a fost sters cu succes.";
	}
	std::cout << "\n\n\n\n\nvector\n\n\n";
	MyVector* v1 = createVector({});
	MyVector* v2 = createVector({ 1,2,3 });
	MyVector* v3 = createVector({ 1,2,3 }, 5);

	print(*v1);
	print(*v2);
	print(*v3);

	pushBack(v1, 10);
	pushBack(v1, 20);
	pushBack(v1, 30);
	pushBack(v1, 40);
	pushBack(v1, 50);
	pushBack(v1, 50);
	pushBack(v1, 50);
	pushBack(v1, 50);
	pushBack(v1, 50);
	std::cout << "Cap of v1 is: " << v1->capacity << std::endl;
	print(*v1);

	removeAllInstancesOf(v1, 50);
	print(*v1);

	int it = findElement(v1, 90);
	if (it != -1)
	{
		std::cout << "Element was found at index: " << it << "\n";
	}
	else
	{
		std::cout << "Element was not found\n";
	}

	deleteVector(v1);
	if (v1 == nullptr)
	{
		std::cout << "Vector was successfully released from the memory\n";
	}

}
