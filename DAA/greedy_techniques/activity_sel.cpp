#include <bits/stdc++.h> 
using namespace std; 
  
// A job has a start time, finish time and profit. 
struct Activity { 
    int start, finish; 
    string name = "a";
}; 
  
// A utility function that is used for sorting 
// activities according to finish time 
bool activityCompare(Activity s1, Activity s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  
// Returns count of the maximum set of activities that can 
// be done by a single person, one at a time. 
void printMaxActivities(Activity arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr + n, activityCompare); 
  
    cout << "Following activities are selected :\n"; 
  
    // The first activity always gets selected 
    int i = 0; 
    cout << "(" << arr[i].start << ", " << arr[i].finish <<", " <<arr[i].name
         << ")"; 
  
    // Consider rest of the activities 
    for (int j = 1; j < n; j++) { 
        // If this activity has start time greater than or 
        // equal to the finish time of previously selected 
        // activity, then select it 
        if (arr[j].start >= arr[i].finish) { 
            cout << ", (" << arr[j].start << ", "
                 << arr[j].finish <<", " <<arr[j].name<<")"; 
            i = j; 
        } 
    } 
} 
  
// Driver code 
int main() 
{ 
    Activity arr[] = { { 5, 9}, { 1, 2}, { 3, 4 }, 
                        { 0, 6 }, { 5, 7 }, { 8, 9 } }; 
    int i=0;
    for(auto &c:arr){
        c.name = c.name + to_string(i);
        i++;
    }
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function call 
    printMaxActivities(arr, n); 
    return 0; 
}