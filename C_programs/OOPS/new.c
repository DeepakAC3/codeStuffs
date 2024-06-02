#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

 

struct Student { 
    char name[50]; 
    int *grades; 
    int numGrades; 
}; 

struct Student* readData(int* numStudents); 
double calculateAverage(struct Student student); 
void printData(struct Student* students, int numStudents); 

int main() { 
    int numStudents; 
    struct Student* students = readData(&numStudents); 

    if (students == NULL) { 
        printf("Error: could not read data.\n"); 
        return 1; 
    } 
    printData(students, numStudents); 

  // free dynamically allocated memory 

    for (int i = 0; i < numStudents; i++) { 
        free(students[i].grades); 
    } 

    free(students); 
    return 0;

} 

struct Student* readData(int* numStudents) { 
    printf("Enter the number of students: "); 
    scanf("%d", numStudents); 
    struct Student* students = (struct Student*) malloc((*numStudents) * sizeof(struct Student)); 

    for (int i = 0; i < (*numStudents); i++) { 
        char name[50]; 
        printf("Enter name of student %d: ", i+1); 
        scanf("%s", name); 
        int numGrades; 
        printf("Enter the number of grades for student %d: ", i+1); 
        scanf("%d", &numGrades); 
        int* grades = (int*) malloc(numGrades * sizeof(int)); 
        printf("Enter %d grades separated by spaces: ", numGrades); 

        for (int j = 0; j < numGrades; j++) { 
            scanf("%d", &grades[j]); 
        } 

        struct Student student; 
        strcpy(student.name, name); 
        student.numGrades = numGrades; 
        student.grades = grades; 
        students[i] = student; 
    } 
    return students; 
} 

 

double calculateAverage(struct Student student) {
    double sum = 0.0; 
    for (int i = 0; i < student.numGrades; i++) { 
        sum += student.grades[i]; 
    } 
    return sum / student.numGrades; 
} 

 

void printData(struct Student* students, int numStudents) { 
    for (int i = 0; i < numStudents; i++) { 
        printf("Name of Student %d: %s, Average Grade: %.2f\n", i, students[i].name, calculateAverage(students[i])); 
    } 
} 