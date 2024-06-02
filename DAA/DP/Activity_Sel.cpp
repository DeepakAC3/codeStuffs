#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start;
    int finish;
};

bool compareActivities(Activity& a1,Activity& a2) {
    return (a1.finish < a2.finish);
}

void printMaxActivities(std::vector<Activity>& activities) {
    std::vector<Activity> selectedActivities;
    selectedActivities.push_back(activities[0]);
    int lastSelected = 0;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= activities[lastSelected].finish) {
            selectedActivities.push_back(activities[i]);
            lastSelected = i;
        }
    }

    std::cout << "Selected Activities: ";
    for (auto& activity : selectedActivities) {
        std::cout << "(" << activity.start << ", " << activity.finish << ") ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Activity> activities = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

    std::sort(activities.begin(), activities.end(), compareActivities);

    printMaxActivities(activities);

    return 0;
}