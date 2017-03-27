#include <iostream>
#include <string>
#include <time.h>
#include "Sortirovki.h"

using namespace std;
using Prog::Sort;
using Prog::Bublle;
using Prog::Insertion;

int main()
{
	setlocale(LC_ALL, "Rus");
	try{
		srand((unsigned)time(NULL));
		int size, n;
		cout << "Введите размер массива: ";
		if (!(cin >> size) || size == 0)
		{
			throw string("Некорректные данные!");
		}
		cout << "Введите диапазон чисел: ";
		if (!(cin>>n) || n==0 )
		{
			throw string("Некорректные значения!");
		}

		int* arr1 = new int[size];
		int *arr2 = new int[size];
		cout << "Исходный массив: ";
		for (int i = 0; i < size; ++i)
		{
			arr1[i] = 1 + rand() % n;
			arr2[i] = arr1[i]; // копирование массива для другой сортировки
			cout << arr1[i] << " ";
		}

		cout << endl;
		cout << endl;

		Bublle el1;
		Insertion el2;

		Sort *pr1 = &el1;
		Sort *pr2 = &el2;

		cout << "ПУЗЫРЬКОВАЯ СОРТИРОВКА" << endl;
		pr1->sort(arr1, size);
		cout << endl;

		cout << "СОРТИРОВКА ВСТАВКАМИ" << endl;
		pr2->sort(arr2, size);

	}

	catch (const string e)
	{
		cout << e << endl;
	}

	system("pause");
	return 0;
}