#include <iostream>
#include <vector>
using namespace std;

int Binary_Search(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2; // Update mid inside the loop
        if (arr[mid] == target) {
            return mid; // target found at index mid
        } else if (arr[mid] > target) {
            // target will be found on the left side of mid
            high = mid - 1;
        } else {
            // target will be found on the right side of mid
            low = mid + 1; // Update low to mid + 1
        }
    }
    return -1; // target not found   
}

int main() {
    vector<int> array = {3, 4, 5, 12, 13, 19};
    cout << Binary_Search(array, 3) << endl; // Should print 0 (index of target 3)
    cout << Binary_Search(array, 12) << endl; // Should print 3 (index of target 12)
    cout << Binary_Search(array, 19) << endl; // Should print 5 (index of target 19)
    cout << Binary_Search(array, 7) << endl; // Should print -1 (target 7 not found)
}
