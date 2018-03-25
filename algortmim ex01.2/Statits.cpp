#include<iostream>
#include <time.h>
using namespace std;

int MinMax(int* i_Arr, int i_size)
{
	int min, max;
	int countComp = 0;
	min = max = i_Arr[0];
    
	for (int i = 0; i < i_size; i++)
	{
		countComp++;
		if (i_Arr[i] < min)
		{
			min = i_Arr[i];
			
		}
		else
		{
			countComp++;
			if (i_Arr[i] > max)
			{
				max = i_Arr[i];
				
			}
		}
	}
	return countComp;
}

int* ShafellArr(int* Arr, int i_size)
{

	for (int i = 0; i < i_size; i++)
	{
		swap(Arr[i], Arr[rand() % 1000]);
	}
	return Arr;
}

float staticsOfCompRand(int i_numOfArry, int i_sizeOfArr)
{

	srand(time(0));
	int sumOfComp = 0;
	int* arr = new int[i_sizeOfArr];

	for (int i = 0; i < i_numOfArry; i++)
	{
		for (int j = 0; j < i_sizeOfArr; j++)
		{
			arr[j] = (rand() % i_sizeOfArr) + 1;
		}

		sumOfComp += MinMax(arr, i_sizeOfArr);

	}

	delete[] arr;
	return sumOfComp / i_numOfArry;
}
float statisOfCmpShafelArry(int i_timeToShafell, int i_sizeOfArry)
{
	srand(time(0));
	int sumOfComp = 0;
	int* arr = new int[i_sizeOfArry];
	for (int j = 0; j < i_sizeOfArry; j++)
	{
		arr[j] = (rand() % i_sizeOfArry) + 1;
	}

	for (int i = 0; i < i_timeToShafell; i++)
	{

		arr = ShafellArr(arr, i_sizeOfArry);
		sumOfComp += MinMax(arr, i_sizeOfArry);

	}

	delete[] arr;
	return sumOfComp / i_timeToShafell;

}

int main()
{
	int numOfArrys = 100000, sizeOfArry = 1000;

	float avgOfCompDiffrentArrys = staticsOfCompRand(numOfArrys, sizeOfArry);
	float avgOfCompShaffelArry = statisOfCmpShafelArry(numOfArrys, sizeOfArry);

	cout <<"the avg of compers in diffrent arreys is :" << avgOfCompDiffrentArrys<< endl;
	cout << "the avg of comper in shafel arry is : " << avgOfCompShaffelArry << endl;

}
