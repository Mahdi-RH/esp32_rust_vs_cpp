#include "student.h"
#include <stdio.h>

void print_student(Student s) {
    printf("Name: %s, Age: %d, Score: %.2f\n", s.name, s.age, s.score);
}
