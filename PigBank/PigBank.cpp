// PigBank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
using namespace std;

int main()
{
	int* weights;
	int* values;
	int empty_pig_wt, filled_pig_wt, num_coins;

	cout << "Enter weight of empty pig: \n";
	cin >> empty_pig_wt;
	cout << "Enter weight of filled pig: \n";
	cin >> filled_pig_wt;
	cout << "Enter the number of various coins used: \n";
	cin >> num_coins;

	if (num_coins < 0)
	{
		cout << "Number of various coins must be positive\n";
		return 0; 
	}

	weights = new int[num_coins];
	values = new int[num_coins];

	for (int i = 0; i < num_coins; i++)
	{
		cout << "Enter the weight and value of coin #" << i + 1 << " in the format: W V\n";
		cin >> weights[i] >> values[i];
	}

	return 0;
}