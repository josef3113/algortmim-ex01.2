#include<iostream>
#include <time.h>
using namespace std;

int MinMax(int* i_Arr, int i_Size)
{
	int min, max;
	int countComp = 0;
	min = max = i_Arr[0];
    
	for (int i = 0; i < i_Size; i++)
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

int* ShafellArr(int* Arr, int i_Size)
{

	for (int i = 0; i < i_Size; i++)
	{
		swap(Arr[i], Arr[rand() % 1000]);
	}
	return Arr;
}

float staticsOfCompRand(int i_NumOfArry, int i_SizeOfArr)
{

	srand(time(0));
	int sumOfComp = 0;
	int* arr = new int[i_SizeOfArr];

	for (int i = 0; i < i_NumOfArry; i++)
	{
		for (int j = 0; j < i_SizeOfArr; j++)
		{
			arr[j] = (rand() % i_SizeOfArr) + 1;
		}

		sumOfComp += MinMax(arr, i_SizeOfArr);

	}

	delete[] arr;
	return sumOfComp / i_NumOfArry;
}
float statisOfCmpShafelArry(int i_TimeToShafell, int i_SizeOfArry)
{
	srand(time(0));
	int sumOfComp = 0;
	int* arr = new int[i_SizeOfArry];
	for (int j = 0; j < i_SizeOfArry; j++)
	{
		arr[j] = (rand() % i_SizeOfArry) + 1;
	}

	for (int i = 0; i < i_TimeToShafell; i++)
	{

		arr = ShafellArr(arr, i_SizeOfArry);
		sumOfComp += MinMax(arr, i_SizeOfArry);

	}

	delete[] arr;
	return sumOfComp / i_TimeToShafell;

}

int main()
{
	int numOfArrys = 100000, sizeOfArry = 1000;

	float avgOfCompDiffrentArrys = staticsOfCompRand(numOfArrys, sizeOfArry);
	float avgOfCompShaffelArry = statisOfCmpShafelArry(numOfArrys, sizeOfArry);

	cout <<"the avg of compers in diffrent arreys is :" << avgOfCompDiffrentArrys<< endl;
	cout << "the avg of comper in shafel arry is : " << avgOfCompShaffelArry << endl;

}
