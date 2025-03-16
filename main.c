#include <stdio.h>
#include <ctype.h>

void capFirstLetter(char *name) {
    if (name != NULL && name[0] != '\0') {
        name[0] = toupper(name[0]);
        for (int i = 1; name[i] != '\0'; i++) {
            name[i] = tolower(name[i]);
        }
    }
}

float avg(int result[]) {
    int sum = 0;
    for (int i = 0; i < 13; i++) {
        sum += result[i];
    }
    return (float)sum / 13;
}

int main() {
    // array for students names
    char name[5][50];
    // array for test results
    int result[5][13];
    float total_avg = 0.0;

    // main loop to read input
    for (int i = 0; i < 5; i++) {
        scanf("%s", name[i]);
        capFirstLetter(name[i]);

        // inner loop to read test results per student
        for (int j = 0; j < 13; j++) {
            scanf("%d", &result[i][j]);
        }
    }

    // calculate total average
    for (int i = 0; i < 5; i++) {
        total_avg += avg(result[i]);
    }
    total_avg /= 5;

    // array to store the average score of each student
    float avg_student[5];
    float top_points = avg(result[0]);
    char *top_student = name[0];

    // calc each students average and find the top student
    for (int i = 0; i < 5; i++) {
        avg_student[i] = avg(result[i]);
        if (avg_student[i] > top_points) {
            top_points = avg_student[i];
            top_student = name[i];
        }
    }

    // print top student
    printf("%s\n", top_student);

    // print students with averages below the total average
    for (int i = 0; i < 5; i++) {
        if (avg_student[i] < total_avg) {
            printf("%s\n", name[i]);
        }
    }

    return 0;
}
