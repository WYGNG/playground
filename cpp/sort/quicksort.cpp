#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);

int main() {
	vector<int> waitToSort = { 1, 3, 5, 7, 8, 5, 4, 3, 6, 7, 8, 9, 2, 0, 4 };
	quickSort(waitToSort, 0, waitToSort.size() - 1);
	for (auto item : waitToSort) cout << item << " ";
	cout << endl;
	system("pause");
	return 0;
}

void quickSort(vector<int> &arr, int low, int high) {
	int mid = partition(arr, low, high);
	if (low < mid) quickSort(arr, low, mid - 1);
	if (mid < high) quickSort(arr, mid + 1, high);
}

int partition(vector<int> &arr, int low, int high) {
	int base = arr[low];
	while (low < high) {
		while (low < high && base <= arr[high]) high--;
		arr[low] = arr[high];
		while (low < high && arr[low] <= base) low++;
		arr[high] = arr[low];
	}
	arr[low] = base;
	return low;
}