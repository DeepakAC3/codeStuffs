#include <iostream>
#include <vector>

int insertionSort(std::vector<int>& nums, int k) {
    int position = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == k) {
            position = i + 1;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }

    return position;
}

int main() {
    std::vector<int> nums = {2, -1, 3, 0, 7, 3};
    int k = 3;

    int position = insertionSort(nums, k);

    std::cout << "Position of " << k << " in the sorted order: " << position << std::endl;

    return 0;
}
