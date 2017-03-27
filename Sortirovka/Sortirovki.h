#pragma once
#include <time.h>

using namespace std;

namespace Prog
{
	class Sort //абстрактный класс
	{
	public:
		virtual void sort(int arr[], int size) = 0;
	};

	class Bublle : public Sort
	{
	public:
		Bublle() : arr(0), N(0), K(0), time(0)
		{
		}

		virtual void sort(int arr[], int size)
		{
			int x;
			time = clock();
			for (int k = 0; k < size - 1; ++k)
			{
				for (int j = 0; j < size - 1; ++j)
				{
					K++;
					if (arr[j + 1] < arr[j])
					{
						x = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = x;
						N++;
					}
				}
			}
			time = clock() - time;
			cout << "Пузырьковая сортировка: ";
			for (int i = 0; i < size; ++i)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			cout << "Количества сравнений и перестановок: " << K << " " << N << endl;
			cout << "Время сортировки: " << (double)time / CLOCKS_PER_SEC << endl;

			cout << endl;
			delete[] arr;
		}

	private:
		clock_t time; //время сортировки
		int N; // Количество перестановок
		int K; //Количество сравнений
		int* arr;
	};

	class Insertion : public Sort
	{
	public:
		Insertion() : arr(0), N(0), K(0), time(0)
		{
		}

		virtual void sort(int arr[], int size)
		{
			int x;
			time = clock();
			for (int i = 1; i < size; i++)
			{
				x = arr[i];
				K++;
				for (int j = i - 1; j >= 0; --j)
				{
					K++;
					if (arr[j] > x)
					{
						arr[j + 1] = arr[j];
						arr[j] = x;
						N++;
					}
				}
			}
			time = clock() - time;

			cout << "Сортировка вставками: ";
			for (int i = 0; i < size; ++i)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			cout << "Количество сравнений и перестановок: " << K << " " << N <<endl;
			cout << "Время сортировки: " << (double)time / CLOCKS_PER_SEC << endl;

			cout << endl;
			delete[] arr;
		}

	private:
		clock_t time; //время сортировки
		int N; // Количество перестановок
		int K; //Количество сравнений
		int* arr;
	};
}
