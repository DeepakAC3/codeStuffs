#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

int main() {
    std::vector<std::pair<int, int>> pairs = {
        std::make_pair(11, 10),
        std::make_pair(3, 4),
        std::make_pair(5, 6)
    };
    
    // Insertion sort the pairs based on their distance from the origin
    for (int i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        
        double distanceKey = std::sqrt(key.first * key.first + key.second * key.second);
        
        while (j >= 0 && std::sqrt(pairs[j].first * pairs[j].first + pairs[j].second * pairs[j].second) > distanceKey) {
            pairs[j + 1] = pairs[j];
            --j;
        }
        
        pairs[j + 1] = key;
    }
    
    for (const auto& pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    return 0;
}
