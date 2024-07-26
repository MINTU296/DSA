#include <iostream>
#include <vector>
using namespace std;

void Bubble_sort(vector<int> &array) {
    for (int i = 0; i < array.size() - 1; i++) {  // n-1 passes
        // traverse
        bool flag = true; // array sorted

        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                flag = false; // array not sorted
            }
        }
        if (flag == true) {
            break;
        }
    }
}

int main() {
    vector<int> arr;
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    Bubble_sort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
