#include <iostream>

using namespace std;

enum enPrimeOrNotPrime{Prime = 1 , NotPrime = 2};

enPrimeOrNotPrime CheckPrime(int Num)
{
	int M = round(Num / 2);

	for (int i = 2; i < Num; i++)
	{
		if (Num % i == 0)
		{
			return enPrimeOrNotPrime::NotPrime;
		}
	}
	return enPrimeOrNotPrime::Prime;

}

int ReadNumber()
{

	int Number = 0;
	cout << "Please enter a number\n";
	cin >> Number;

	return Number;
}

int RandomNumber(int From, int To)
{

	int RandomNum = rand() % (To - From + 1) + From;

	return RandomNum;
}

void FillArrayWithRandomNumbers(int Arr[], int& ArrayLength)
{

	cout << "Enter number of elements you want to fill the array with\n";
	cin >> ArrayLength;

	for (int i = 0; i <= ArrayLength - 1; i++)
	{
		Arr[i] = RandomNumber(1, 10);
	}

}

void AddArrayElement(int Arr[100], int Number, int& ArrayLength)
{
	ArrayLength++;
	Arr[ArrayLength - 1] = Number;
}

void CopyOnlyPrimeNumbersElementsUsingAddArrayElements(int Arr1[], int Arr2[], int Array1Length, int& Array2Length)
{

	for (int i = 0; i <= Array1Length - 1; i++)
	{
		if (CheckPrime(Arr1[i]) == enPrimeOrNotPrime::Prime)
		{
			AddArrayElement(Arr2, Arr1[i], Array2Length);

		}
	}

}

void PrintArray(int Arr[100], int ArrayLength)
{

	for (int i = 0; i <= ArrayLength - 1; i++)
		cout << Arr[i] << " ";

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Arr2[100], Length = 0, Length2 = 0;

	FillArrayWithRandomNumbers(Arr, Length);

	cout << "Array 1 elements : ";
	PrintArray(Arr, Length);

	CopyOnlyPrimeNumbersElementsUsingAddArrayElements(Arr, Arr2, Length, Length2);

	cout << "\nArray 2 Elements : ";
	PrintArray(Arr2, Length2);



}