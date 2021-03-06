// PigBank.cpp : Defines the entry polong for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <limits.h>
using namespace std;

long findMinValue(long fit_weight, long num_item, long value[], long weight[])
{
	long* result = new long[fit_weight+1];
	//base case
	result[0] = 0;

	for (long w = 1; w < fit_weight+1; w++)
	{
		// Used as Infinity
		result[w] = 1000000000;

		for (long i = 0; i < num_item; i++)
		{
			if (w >= weight[i])
			{
				if ((result[w - weight[i]] + value[i]) < result[w])
				{
					result[w] = result[w - weight[i]] + value[i];
				}
			}
		}
	}
	return result[fit_weight];
}

int main()
{
	long* weights;
	long* values;
	long empty_pig_wt, filled_pig_wt, num_coins;
	bool correct_input = false;

	while (!correct_input)
	{
		while (!correct_input)
		{
			cout << "Enter weight of [empty pig] <=10g: \n";
			cin >> empty_pig_wt;
			if (empty_pig_wt > 10 || empty_pig_wt < 0)
			{
				cout << "ERROR: Weight of [empty pig] < 0 or > 10\n\n";
				cin.clear();
				continue;
			}
			correct_input = true;
		}

		correct_input = false;

		while (!correct_input)
		{
			cout << "Enter weight of [filled pig] <= 10000g: \n";
			cin >> filled_pig_wt;
			if (filled_pig_wt > 10000 || filled_pig_wt < 0)
			{
				cout << "ERROR: Weight of [filled pig] < 0 or > 10000\n\n";
				cin.clear();
				continue;
			}
			correct_input = true;
		}

		if (empty_pig_wt > filled_pig_wt)
		{
			correct_input = false;
			cout << "ERROR: [empty pig] > [filled pig]\n\n";
			continue;
		}
	}

	while(correct_input)
	{
		cout << "Enter the [number of various coins] used: \n";
		cin >> num_coins;
		if (num_coins < 0)
		{
			cout << "[Number of various coins] must be positive\n\n";
			cin.clear();
			continue;
		}
		break;
	}

	weights = new long[num_coins];
	values = new long[num_coins];

	for (long i = 0; i < num_coins; i++)
	{
		cout << "Enter the 'value' and 'weight' of coin #" << i + 1 << " in the format [Value Weight]:\n";
		cin >> values[i] >> weights[i];
	}
	
	long result = findMinValue(filled_pig_wt - empty_pig_wt, num_coins, values, weights);
	
	if (result == 1000000000) { cout << "This is impossible.\n"; }
	else if (result > 1000000000 || result < 0) { cout << "Values of coins too large. \n"; }
	else { cout << "The minimum amount of money in the piggy-bank is " << result << ".\n"; }
	return 0;
}