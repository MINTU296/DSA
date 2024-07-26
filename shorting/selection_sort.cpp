#include <iostream>
#include <vector>
using namespace std;

void selection_Short(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Finding the index of the minimum element in the remaining array
        int minIndex = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swapping the found minimum element with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> array = {3, 4, 5, 2, 1};

    selection_Short(array);

    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }

    return 0;
}
