#pragma once
#include <iostream>
#include <algorithm>
#include <initializer_list>

struct MyVector
{
	int capacity;
	int size;
	int* elements;
};

MyVector* createVector(std::initializer_list<int> elementsIn, const int& sizeIn = 0)
{
	if (sizeIn < elementsIn.size() && sizeIn != 0)
	{
		throw std::runtime_error("Bad size exception");
	}

	MyVector* newVec = new MyVector;

	if (sizeIn == 0)
	{
		if (elementsIn.size() == 0)
		{
			newVec->size = 0;
			newVec->capacity = 4;
			newVec->elements = new int[4] {};
			return newVec;
		}

		newVec->size = elementsIn.size();
		newVec->capacity = newVec->size;

		newVec->elements = new int[newVec->capacity];

		int i = 0;
		for (const int& elem : elementsIn)
		{
			newVec->elements[i] = elem;
			++i;
		}

		return newVec;
	}

	newVec->size = elementsIn.size();
	newVec->capacity = sizeIn;

	newVec->elements = new int[newVec->capacity] {};

	int i = 0;
	for (const int& elem : elementsIn)
	{
		newVec->elements[i] = elem;
		++i;
	}

	return newVec;
}

void print(const MyVector& vec)
{
	std::cout << "[ ";
	for (int i = 0; i < vec.size; ++i)
	{
		std::cout << vec.elements[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void pushBack(MyVector*& vec, int elemIn)
{
	if (vec->size + 1 > vec->capacity)
	{
		vec->capacity *= 2;

		int* newVector = new int[vec->capacity] {};
		for (int i = 0; i < vec->size; ++i)
		{
			newVector[i] = vec->elements[i];
		}

		newVector[vec->size] = elemIn;
		++vec->size;

		delete[] vec->elements;
		vec->elements = newVector;
	}
	else
	{
		vec->elements[vec->size] = elemIn;
		++vec->size;
	}
}

void removeElement(MyVector*& vec, const int& elemIn)
{
	int foundIndex = -1;
	for (int i = 0; i < vec->size; ++i)
	{
		if (elemIn == vec->elements[i])
		{
			foundIndex = i;
		}
	}

	if (foundIndex == -1)
	{
		std::cout << "The element does not exist in the container\n";
		return;
	}

	int* newVec = new int[vec->size - 1];

	for (int i = 0; i < foundIndex; ++i)
	{
		newVec[i] = vec->elements[i];
	}

	for (int i = foundIndex + 1; i < vec->size; ++i)
	{
		newVec[i - 1] = vec->elements[i];
	}

	delete[] vec->elements;
	--vec->size;

	vec->elements = newVec;
}

void removeAllInstancesOf(MyVector*& vec, const int& elemIn)
{
	int count = 0;
	for (int i = 0; i < vec->size; ++i)
	{
		if (vec->elements[i] == elemIn)
		{
			count++;
		}
	}

	if (count == 0)
	{
		return;
	}

	int* newVec = new int[vec->size - count];

	int k = 0;
	for (int i = 0; i < vec->size; ++i)
	{
		if (vec->elements[i] != elemIn)
		{
			newVec[k] = vec->elements[i];
			++k;
		}
	}

	delete[] vec->elements;
	vec->size -= count;

	vec->elements = newVec;
}

int findElement(MyVector*& vec, const int& elemIn)
{
	int foundIndex = -1;
	for (int i = 0; i < vec->size; ++i)
	{
		if (elemIn == vec->elements[i])
		{
			foundIndex = i;
		}
	}

	return foundIndex;
}

void deleteVector(MyVector*& vec)
{
	delete[] vec->elements;
	delete vec;
	vec = nullptr;
}


