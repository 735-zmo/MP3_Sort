#include <iostream>
#include <time.h>

using namespace std;

//class Sort
//{
//public:
//	virtual void sort() = 0;
//};

class Bublle
{
public:
	void sort(int size, int n)
	{
		srand(time(NULL));
		Max = size;
		int *arr = new int[Max];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = 1 + rand() % n;
			cout << arr[i] << " ";
		}
		cout << endl;
		int x;
		for (int k = 0; k < size - 1; ++k)
		{
			for (int j = 0; j < size - 1; ++j)
			{
				if (arr[j+1] < arr[j])
				{
					x = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = x;
				}
				
			}
			
		}
		for (int i = 0; i < size - 1; ++i)
		{
			cout << arr[i] << " ";
		}

		delete [] arr;
	}

private:
	int Max;
	int* arr;

};

int main()
{
	Bublle pr;
	int n, x;
	cin >> n >> x;
	pr.sort(n, x);
	system("pause");
	return 0;
}