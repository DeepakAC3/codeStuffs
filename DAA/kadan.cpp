#include <iostream>
#include <vector>

using namespace std;

int kadaneAlgorithm(vector<int> nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    int start = 0, end = 0;
    int tempStart = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > currentSum + nums[i]) {
            tempStart = i;
            currentSum = nums[i];
        } else {
            currentSum += nums[i];
        }

        if (currentSum > maxSum) {
            start = tempStart;
            end = i;
            maxSum = currentSum;
        }
    }

    cout << "Subarray with maximum sum: ";
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return maxSum;
}

int main() {
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int maxSum = kadaneAlgorithm(nums);
    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}