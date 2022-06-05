#include <bits/stdc++.h>
#include <functional>

using namespace std;


/* 直接插入排序
 * 稳定
 * 最好 O(n)
 * 平均 O(n2)
 * 最差 O(n2)
 * 空间 O(1)
 */

template<typename T>
void insert_sort(vector<T>& a, int l, int r, function<bool(T, T)> cmp = [](const T a, const T b){return a < b;}) {
    if (r <= l) return;
    int i, j, key;
    for (i = 1; i <= r; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && cmp(key, a[j])) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

/* 折半插入排序
//  * 稳定
//  * 最好 O(n)
//  * 平均 O(n2)
//  * 最差 O(n2)
 */

/* 冒泡排序
 * 稳定
 * 最好 O(n)
 * 平均 O(n2)
 * 最差 O(n2)
 * 空间 O(1)
 */

template<typename T>
void bubble_sort(vector<T>& a, int l, int r, function<bool(T, T)> cmp = [](const T a, const T b){return a <= b;}) {
    if (r <= l) return;
    int j = r;
    while (l < j) {
        bool flag = true;
        int i = l;
        while (i < j) {
            if (!cmp(a[i], a[i + 1])) {
                swap(a[i], a[i + 1]);
                flag = false;
            }
            i++;
        }
        if (flag) return;
        j--;
    }
}


/* 直接选择排序
 * 不稳定
 * 最好 O(n2)
 * 平均 O(n2)
 * 最差 O(n2)
 * 空间 O(1)
 */
template<typename T>
void select_sort(vector<T>& a, int l, int r, function<bool(T, T)> cmp = [](const T a, const T b){return a < b;}) {
    if (r <= l) return;
    int cur_max_idx = r;
    while (0 < cur_max_idx) {
        int max_idx = 0;
        for (int cur_idx = 0; cur_idx <= cur_max_idx; cur_idx++) {
            if (cmp(a[max_idx], a[cur_idx])) {
                max_idx = cur_idx;
            }
        }
        swap(a[max_idx], a[cur_max_idx]);
        cur_max_idx--;
    }
}




/* 归并排序
 * 稳定
 * 最好 O(nlogn)
 * 平均 O(nlogn)
 * 最差 O(nlogn)
 * 空间 O(n)
 */
template<typename T>
void merge_sort(vector<T>& a, int l, int r, function<bool(T, T)> cmp = [](const T a, const T b){return a <= b;}) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(a, l, m, cmp);
    merge_sort(a, m + 1, r, cmp);
    vector<T> tmp(a);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (cmp(a[i], a[j])) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int i = 0; i < a.size(); i++) a[i] = tmp[i];
}



/* 快速排序
 * 不稳定
 * 最好 O(nlogn)
 * 平均 O(nlogn)
 * 最差 O(n2)
 * 空间 O(logn)
 */
template<typename T>
int partition(vector<T>& a, int l, int r, function<bool(T, T)> cmp = [](const T a, const T b){return a <= b;}) {
    T base = a[l];
    while (l < r) {
        while (l < r && cmp(base, a[r])) r--;
        a[l] = a[r];
        while (l < r && cmp(a[l], base)) l++;
        a[r] = a[l];
    }
    a[l] = base;
    return l;
}

template<typename T>
void quick_sort(vector<T>& a, int l, int r, function<bool(T, T)> cmp = [](const T a, const T b){return a <= b;}) {
    int m = partition(a, l, r, cmp);
    if (l < m) quick_sort(a, l, m - 1, cmp);
    if (m < r) quick_sort(a, m + 1, r, cmp);
}


/* 堆排序
 * 不稳定
 * 最好 O(nlogn)
 * 平均 O(nlogn)
 * 最差 O(nlogn)
 * 空间 O(1)
 * 完全二叉树层次遍历表示
 */
template<typename T>
void heap_adjust(vector<T>& a, int root, int len, function<bool(T, T)> cmp) {
    int l = 2 * root + 1, r = 2 * root + 2, m = root;
    if (l < len && cmp(a[m], a[l])) m = l;
    if (r < len && cmp(a[m], a[r])) m = r;
    if (m != root) {
        swap(a[m], a[root]);
        heap_adjust(a, m, len, cmp);
    }
}

template<typename T>
void heap_sort(vector<T>& a, int len, function<bool(T, T)> cmp = [](const T a, const T b){return a < b;}) {
    //init heap 找到一个树的最后一个非叶节点， 计算公式为 (n-1)/2 -1， 然后遍历树的每个非叶节点，使其符合堆的规则。
    for (int i = len / 2 - 1; i >= 0; i--) heap_adjust(a, i, len, cmp);
    //rebuild heap 将堆的顶部，与最后一个元素交换，然后将数组长度减一，将剩下的元素重新建成一个堆，不断抽取最大的元素到最后。
    for (int i = len - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heap_adjust(a, 0, i, cmp);
    }
}

/* 基数排序
 * 稳定
 * 最好 O(d(n+r))
 * 平均 O(d(n+r))
 * 最差 O(d(n+r))
 * 空间 O(n+r)
 */

/* 希尔排序
 * 不稳定
 * 平均 O(n1.3)
 * 空间 O(1)
 */

/* 打印 */

template<typename T>
void print_vector(const vector<T>& v) {
    for (const auto a : v) {
        cout << a << " ";
    }
    cout << endl;
}

int main () {
    vector<int> arr = {1, 6, 2, 6, 8, 4, 2, 6, 9};
    print_vector(arr);
    // quick_sort(arr, 0, arr.size() - 1);
    // merge_sort(arr, 0, arr.size() - 1);
    // bubble_sort(arr, 0, arr.size() - 1);
    // select_sort(arr, 0, arr.size() - 1);
    // insert_sort<int>(arr, 0, arr.size() - 1, [](const int a, const int b) {return a > b;});
    heap_sort<int>(arr, arr.size());
    print_vector(arr);

    return 0;
}