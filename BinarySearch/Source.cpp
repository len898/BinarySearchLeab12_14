#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int recursions = 0;
int comparisons = 0;

// Read integers from input and store them in a vector.
// Return the vector.
vector<int> ReadIntegers() {
	int size;
	cin >> size;
	vector<int> integers(size);
	for (int i = 0; i < size; ++i) {               // Read the numbers
		cin >> integers.at(i);
	}
	sort(integers.begin(), integers.end());
	return integers;
}

int BinarySearch(int target, vector<int> integers, int lower, int upper) {
	int middle = (upper + lower) / 2;
	cout << middle;
	recursions++;
	if (integers.at(middle) == target) {
		comparisons += 1;
		return middle;
	}
	if (lower == upper) {
		comparisons++;
		return -1;
	}
	if (integers.at(middle) < target) {
		comparisons += 2;
		return BinarySearch(target, integers, middle + 1, upper);
	}
	if (integers.at(middle) > target) {
		comparisons += 2;
		return BinarySearch(target, integers, lower, middle - 1);
	}
}

int main() {
	int target;
	int index;

	vector<int> integers = ReadIntegers();

	cin >> target;

	index = BinarySearch(target, integers, 0, integers.size() - 1);
	printf("index: %d, recursions: %d, comparisons: %d\n",
		index, recursions, comparisons);

	return 0;
}
