#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[32];
    int age;
    float score;
} Student;

void print_student(Student s);

#endif
