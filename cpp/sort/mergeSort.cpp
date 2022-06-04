#include <iostream>
#include <string>
#include <vector>

using namespace std;


int partation(vector<int> &nums, int l, int r) {
	int base = nums[l];
	while (l < r) {
		while (l < r && base <= nums[r]) r--;
		nums[l] = nums[r];
		while (l < r && nums[l] <= base) l++;
		nums[r] = nums[l];
	}
	nums[l] = base;
	return l;
}

void quickSort(vector<int> &nums, int l, int r) {
	int mididx = partation(nums, l, r);
	if (l < mididx) quickSort(nums, l, mididx - 1);
	if (mididx < r) quickSort(nums, mididx + 1, r);
}

//void mergeSort(vector<int>& nums, vector<int>& temp, int l, int r) {
//	if (l >= r) return;
//	int mid = (l + r) / 2;
//	mergeSort(nums, temp, l, mid);
//	mergeSort(nums, temp, mid + 1, r);
//	int i = l, j = mid + 1; int t = 0;
//	while (i <= mid && j <= r) {
//		if (nums[i] <= nums[j]) temp[t++] = nums[i++];
//		else temp[t++] = nums[j++];
//	}
//	while (i <= mid) temp[t++] = nums[i++];
//	while (j <= r) temp[t++] = nums[j++];
//
//	for (int i = l, t = 0; i <= r; i++)
//		nums[i] = temp[t++];
//}
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)













void mergeSort(vector<int>& data, vector<int>& temp, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	mergeSort(data, temp, l, mid);
	mergeSort(data, temp, mid + 1, r);
	int left = l, right = mid + 1, k = l;
	while (left <= mid && right <= r) {
		if (data[left] >= data[right]) {
			temp[k++] = data[right++];
		}
		else {
			temp[k++] = data[left++];
		}
	}
	while (left <= mid) {
		temp[k++] = data[left++];
	}
	while (right <= r) {
		temp[k++] = data[right++];
	}


	for (int i = l; i <= r; i++) data[i] = temp[i];



}











int main() {

	vector<int> beforeSort = { 1,5,7,3,8,9,3,6,3,0,5,3 };
	//quickSort(beforeSort, 0, beforeSort.size() - 1);
	vector<int> temp(beforeSort);

	mergeSort(beforeSort, temp, 0, beforeSort.size() - 1);


	for (auto item : beforeSort) {
		cout << item;
	}


	//const char* str = "a b c d e f";

	//char	output[20];

	//sprintf_s(output, "%08s", str);

	//cout << output << endl;


	//stringstream super;
	//super << str;
	//string temp;
	//while (super >> temp) {
	//	cout << temp << endl;
	//}


	system("pause");
	return 0;
}

