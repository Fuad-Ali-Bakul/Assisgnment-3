#include <stdio.h>

int main() {
    int marks[3][3] = {
        {50, 60, 70},
        {80, 90, 100},
        {30, 40, 50}
    };
    
    char students[3][10] = {"Ali", "Bob", "Cat"};
    int studentIndex, subjectIndex, total;
    float average;

    for (studentIndex = 0; studentIndex < 3; studentIndex++) {
        total = 0;
        for (subjectIndex = 0; subjectIndex < 3; subjectIndex++) {
            total += marks[studentIndex][subjectIndex];
        }
        average = total / 3.0;

        if (average >= 80)
            printf("%s Grade A avg=%.2f\n", students[studentIndex], average);
        else if (average >= 60)
            printf("%s Grade B avg=%.2f\n", students[studentIndex], average);
        else if (average >= 40)
            printf("%s Grade C avg=%.2f\n", students[studentIndex], average);
        else
            printf("%s Fail avg=%.2f\n", students[studentIndex], average);
    }

    int maxTotal = 0, topperIndex = 0;
    for (studentIndex = 0; studentIndex < 3; studentIndex++) {
        total = 0;
        for (subjectIndex = 0; subjectIndex < 3; subjectIndex++) {
            total += marks[studentIndex][subjectIndex];
        }
        if (total > maxTotal) {
            maxTotal = total;
            topperIndex = studentIndex;
        }
    }

    printf("Topper: %s with total %d\n", students[topperIndex], maxTotal);

    return 0;
}
