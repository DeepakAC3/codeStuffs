#include <iostream>
#include <algorithm>

void insertionSort(int numbers[], int size, bool isNegative = false) {
    for (int i = 1; i < size; i++) {
        int key = numbers[i];
        int j = i - 1;

        // If isNegative is true, sort in reverse order
        while (j >= 0 && ((isNegative && numbers[j] < key) || (!isNegative && numbers[j] > key))) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

void sortNumbers(int numbers[], int size) {
    int negativeNumbers[size];
    int zero[size];
    int positiveNumbers[size];
    int negativeCount = 0;
    int zeroCount = 0;
    int positiveCount = 0;

    for (int i = 0; i < size; i++) {
        if (numbers[i] < 0) {
            negativeNumbers[negativeCount++] = numbers[i];
        } else if (numbers[i] == 0) {
            zero[zeroCount++] = numbers[i];
        } else {
            positiveNumbers[positiveCount++] = numbers[i];
        }
    }

    insertionSort(negativeNumbers, negativeCount, true);
    insertionSort(positiveNumbers, positiveCount);

    int arrangedNumbers[size];
    int arrangedCount = 0;

    for (int i = 0; i < negativeCount; i++) {
        arrangedNumbers[arrangedCount++] = negativeNumbers[i];
    }
    for (int i = 0; i < zeroCount; i++) {
        arrangedNumbers[arrangedCount++] = zero[i];
    }
    for (int i = 0; i < positiveCount; i++) {
        arrangedNumbers[arrangedCount++] = positiveNumbers[i];
    }

    for (int i = 0; i < size; i++) {
        std::cout << arrangedNumbers[i] << " ";
    }
}

int main() {
    int numbers[] = {-7, -3, 2, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    sortNumbers(numbers, size);

    return 0;
}
