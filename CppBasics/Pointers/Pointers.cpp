#include <iostream>

void print(int* array, int marime)
{
	for (int i = 0; i < marime; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int* apply_all(int* array1, int marime1, int* array2, int marime2)
{
	int* arrayNew = new int[marime1 * marime2];
	int k = 0;
	for (int i = 0; i < marime2; ++i)
	{
		for (int j = 0; j < marime1; ++j)
		{
			arrayNew[k++] = array2[i] * array1[j];
		}

	}
	return arrayNew;
}
int main()
{
	int array1[]{ 1,2,3,4,5 };
	int array2[]{ 10,20,30 };

	std::cout << "Array 1: ";
	print(array1, 5);

	std::cout << "Array 2: ";
	print(array2, 3);

	int* results = apply_all(array1, 5, array2, 3);
	std::cout << "Result: ";
	print(results, 15);
}