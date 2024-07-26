#include<iostream>
#include<vector>
using namespace std;

// Function to perform selection sort on a vector of integers
void selection_sort(vector<int>& arr) {
    int n = arr.size();
    // Iterate through the array
    for (int i = 1; i < n; i++) {
        // Start from the current position and move backwards
        for (int j = i; j > 0; j--) {
            // If the current element is smaller than the 
            //previous element, swap them
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                // If the current element is greater than or equal 
                //to the previous element, break the loop
                break;
            }
        }
    }
}

int main() {
    // Create a vector of integers
    vector<int> array = {3, 4, 0, 9, 1, 0};
    // Sort the vector using selection sort
    selection_sort(array);
    // Print the sorted array
    for (int ele : array) {
        cout << ele << " ";
    }
    return 0;
}
