#include <iostream>
#include <ctime>

using namespace std;

//Напишите программу для нахождения минимального из чисел,
//являющихся максимальными в каждой из строк заданной прямоугольной матрицы.

const int arrayWidth = 10;
const int arrayLength = 10;

int findMinOfMax(int maxValue, int array[arrayWidth][arrayLength], int row) {
	
	int maxInRow = array[row][0];
	
	for (int j = 0; j < arrayLength; j++) {
		if (array[row][j] > maxInRow) {
			maxInRow = array[row][j];
		}
	}
	
	if (row + 1 > arrayWidth) {
		return maxInRow > maxValue ? maxValue : maxInRow;
	}

	int minResult = findMinOfMax(maxInRow, array, row + 1);

	return maxInRow > minResult ? minResult : maxInRow;
	
}

int main() {

	srand(time(NULL));

	int array[arrayWidth][arrayLength];

	for (int i = 0; i < arrayWidth; i++) {
		for (int j = 0; j < arrayLength; j++) {
			array[i][j] = rand() % 100;
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	//imperative style
	int arrayOfMax[arrayWidth];
	int maxValue = 0;

	for (int i = 0; i < arrayWidth; i++) {
		maxValue = array[i][0];
		for (int j = 0; j < arrayLength; j++) {
			if (array[i][j] > maxValue) {
				maxValue = array[i][j];
			}
		}
		arrayOfMax[i] = maxValue;
	}

	int minValue = arrayOfMax[0];
	for (int i = 0; i < arrayWidth; i++) {
		if (arrayOfMax[i] < minValue) {
			minValue = arrayOfMax[i];
		}
	}

	cout << "Result of imperative calculations is " << minValue << endl;

	//functional
	cout << "Result of functional style is " << findMinOfMax(array[0][0],array,0);

	return 0;
}