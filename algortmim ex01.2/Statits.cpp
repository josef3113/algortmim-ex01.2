#include<iostream>
using namespace std;

int MinMax(int* i_Arr, int i_size)
{
	int min, max;
	int countComp = 0;
	min = max = i_Arr[0];
    
	for (int i = 0; i < i_size; i++)
	{
		if (i_Arr[i] > max)
		{
			max = i_Arr[i];
			countComp++;
		}
		else
		{
			if (i_Arr[i] < min)
			{
				min = i_Arr[i];
				countComp++;
			}
		}
	}
	return countComp;
}


int main()
{
	int sumOfComp = 0;
	int numOfArrys = 10000, sizeOfArry = 1000;
	
	int* arr = new int [sizeOfArry] ;

	for (int i = 0; i < numOfArrys; i++)
	{
		for (int j = 0; j < sizeOfArry; j++)
		{
			arr[j] = rand() % sizeOfArry;
		}

		sumOfComp += MinMax(arr, sizeOfArry);

	}

	cout << " the avg of compers is :" << sumOfComp / numOfArrys << endl;

}
