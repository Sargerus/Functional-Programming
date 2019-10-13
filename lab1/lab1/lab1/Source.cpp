#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

int NUMBER_OF_NUMBERS = 0;
int NUMBER_TO_FIND = 0;
vector< vector<int> > globalVector;
vector< vector<int> > outputVector;

string sumString = " ";

int factorial(int i) {
	if (i > 0) {
		return i * factorial(i - 1);
	} else {
		return 1;
	}
}

void findSum(int array[], int number, int sum, vector<int> result, int start = 0) {

	for (int i = start; i < NUMBER_OF_NUMBERS; i++) {

		if (array[i] == 0)
			return;

		if (sum + array[i] < number) {
			
			sum += array[i];
			//result += to_string(array[i]) + " + ";
			result.push_back(array[i]);
			findSum(array, number, sum, result, 0);
			continue;
		}

		if (sum + array[i] == number) {
			sum += array[i];
			result.push_back(array[i]);
			globalVector.push_back(result);
			continue;
		}

		if (sum + array[i] > number) {
			continue;
		}
	}

}

void findall(int array[], int number) {

	for (int i = 0; i < NUMBER_OF_NUMBERS; i++) {
		findSum(array, number, array[i], vector<int>{array[i]}, i);
		}

}

int main() {

	////begin of pascal
	//int n, k = 0;

	//cout << "Pascal triangle\n";
	//cout << "Enter k(number),n(row)\n";

	//cin >> k >> n;

	//cout << factorial(n) / (factorial(k) * (factorial(n - k)));

	////end of pascal

	////begin of #2


	int number = 0;
	int *abArray;

	cout << "Enter number\n";

	cin >> number;

	cout << "Enter number of numbers\n";
	cin >> NUMBER_OF_NUMBERS;
	abArray = new (nothrow) int[NUMBER_OF_NUMBERS];

	cout << "Enter " + to_string(NUMBER_OF_NUMBERS) << " numbers\n";
	for (int i = 0; i < NUMBER_OF_NUMBERS; i++)
	{
		cin >> abArray[i];
	}
	cout << endl;

	for (int i = 0; i < NUMBER_OF_NUMBERS / 2; i++) {
		findall(abArray, number);
	}

	for (auto i = globalVector.begin(); i < globalVector.end(); ++i) {
		sort((*i).begin(),(*i).end());
	}

	bool common = false;

	for (auto i = globalVector.begin(); i < globalVector.end(); ++i) {
		common = false;
		auto y = i;
		for (auto j = ++y; j < globalVector.end(); ++j) {
			if ((*i) == (*j)) {
				common = true;
				break;
			}
		}
		if (!common) {
			outputVector.push_back((*i));
		}
	}

	for (auto i = outputVector.begin(); i < outputVector.end(); ++i) {
		for (auto g = (*i).begin(); g < (*i).end(); ++g) {
			cout << *g << " + ";
		}
		cout << endl;
	}

	//end of #2


	return 0;
}