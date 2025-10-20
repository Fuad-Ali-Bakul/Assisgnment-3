#include <stdio.h>

#define STUDENT_COUNT 3
#define SUBJECT_COUNT 3

// Function to calculate total marks of a student
int calculateTotal(int marks[SUBJECT_COUNT]) {
    int sum = 0;
    for (int i = 0; i < SUBJECT_COUNT; i++) {
        // Ignore invalid negative marks
        if (marks[i] < 0) marks[i] = 0;
        sum += marks[i];
    }
    return sum;
}

// Function to calculate average marks
float calculateAverage(int total) {
    return total / (float)SUBJECT_COUNT;
}

// Function to determine grade based on average
char determineGrade(float average) {
    if (average >= 80)
        return 'A';
    else if (average >= 60)
        return 'B';
    else if (average >= 40)
        return 'C';
    else
        return 'F'; // Fail
}

// Function to print student report in formatted manner
void printStudentReport(const char* name, int total, float average) {
    char grade = determineGrade(average);
    if (grade == 'F') {
        printf("%-10s | Total: %3d | Average: %5.2f | Status: Fail\n", name, total, average);
    } else {
        printf("%-10s | Total: %3d | Average: %5.2f | Grade: %c\n", name, total, average, grade);
    }
}

int main() {
    const char students[STUDENT_COUNT][10] = {"Ali", "Bob", "Cat"};
    int marks[STUDENT_COUNT][SUBJECT_COUNT] = {
        {50, 60, 70},
        {80, 90, 100},
        {30, 40, 50}
    };

    int maxTotal = 0;
    int topperIndex = 0;

    printf("Student Report:\n");
    printf("===============================\n");

    for (int i = 0; i < STUDENT_COUNT; i++) {
        int total = calculateTotal(marks[i]);
        float average = calculateAverage(total);

        printStudentReport(students[i], total, average);

        // Track topper
        if (total > maxTotal) {
            maxTotal = total;
            topperIndex = i;
        }
    }

    printf("\nTopper: %s with total marks %d\n", students[topperIndex], maxTotal);

    return 0;
}
