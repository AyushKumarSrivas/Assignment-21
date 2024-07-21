Structure

1. Define a structure Employee with member variables id, name, salary
2. Write a function to take input employee data from the user. [ Refer structure from
question 1 ]
3. Write a function to display employee data. [ Refer structure from question 1 ]
4. Write a function to find the highest salary employee from a given array of 10
employees. [ Refer structure from question 1]
5. Write a function to sort employees according to their salaries [ refer structure from
question 1]
6. Write a function to sort employees according to their names [refer structure from
question 1]
7. Write a program to calculate the difference between two time periods.
8. Write a program to store information of 10 students and display them using structure.
9. Write a program to store information of n students and display them using structure
10. Write a program to enter the marks of 5 students in Chemistry, Mathematics and
Physics (each out of 100) using a structure named Marks having elements roll no.,
name, chem_marks, maths_marks and phy_marks and then display the percentage
of each student.

Solution:-

1. #include <stdio.h>

struct Employee {
    int id;
    char name[100];
    float salary;
};

2. void inputEmployeeData(struct Employee *emp) {
    printf("Enter Employee ID: ");
    scanf("%d", &emp->id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp->name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp->salary);
}

3. void displayEmployeeData(struct Employee emp) {
    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Employee Salary: %.2f\n", emp.salary);
}

4. struct Employee highestSalaryEmployee(struct Employee emp[], int size) {
    struct Employee highest = emp[0];
    for (int i = 1; i < size; i++) {
        if (emp[i].salary > highest.salary) {
            highest = emp[i];
        }
    }
    return highest;
}

5. void sortEmployeesBySalary(struct Employee emp[], int size) {
    struct Employee temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (emp[i].salary > emp[j].salary) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

6. #include <string.h>

void sortEmployeesByName(struct Employee emp[], int size) {
    struct Employee temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(emp[i].name, emp[j].name) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

7. #include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time difference(struct Time start, struct Time stop) {
    struct Time diff;
    if (stop.seconds > start.seconds) {
        --start.minutes;
        start.seconds += 60;
    }
    diff.seconds = start.seconds - stop.seconds;

    if (stop.minutes > start.minutes) {
        --start.hours;
        start.minutes += 60;
    }
    diff.minutes = start.minutes - stop.minutes;
    diff.hours = start.hours - stop.hours;

    return diff;
}

int main() {
    struct Time start, stop, diff;
    printf("Enter start time (hh mm ss): ");
    scanf("%d %d %d", &start.hours, &start.minutes, &start.seconds);
    printf("Enter stop time (hh mm ss): ");
    scanf("%d %d %d", &stop.hours, &stop.minutes, &stop.seconds);

    diff = difference(start, stop);

    printf("Time Difference: %02d:%02d:%02d\n", diff.hours, diff.minutes, diff.seconds);
    return 0;
}

8. #include <stdio.h>

struct Student {
    int roll_no;
    char name[100];
    int age;
};

void inputStudentData(struct Student *stu) {
    printf("Enter Roll No: ");
    scanf("%d", &stu->roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", stu->name);
    printf("Enter Age: ");
    scanf("%d", &stu->age);
}

void displayStudentData(struct Student stu) {
    printf("Roll No: %d\n", stu.roll_no);
    printf("Name: %s\n", stu.name);
    printf("Age: %d\n", stu.age);
}

int main() {
    struct Student students[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter details for student %d:\n", i + 1);
        inputStudentData(&students[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("\nDetails of student %d:\n", i + 1);
        displayStudentData(students[i]);
    }

    return 0;
}

9. #include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[100];
    int age;
};

void inputStudentData(struct Student *stu) {
    printf("Enter Roll No: ");
    scanf("%d", &stu->roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", stu->name);
    printf("Enter Age: ");
    scanf("%d", &stu->age);
}

void displayStudentData(struct Student stu) {
    printf("Roll No: %d\n", stu.roll_no);
    printf("Name: %s\n", stu.name);
    printf("Age: %d\n", stu.age);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        inputStudentData(&students[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("\nDetails of student %d:\n", i + 1);
        displayStudentData(students[i]);
    }

    free(students);
    return 0;
}

10. #include <stdio.h>

struct Marks {
    int roll_no;
    char name[100];
    int chem_marks;
    int maths_marks;
    int phy_marks;
};

void inputMarks(struct Marks *m) {
    printf("Enter Roll No: ");
    scanf("%d", &m->roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", m->name);
    printf("Enter Chemistry Marks: ");
    scanf("%d", &m->chem_marks);
    printf("Enter Mathematics Marks: ");
    scanf("%d", &m->maths_marks);
    printf("Enter Physics Marks: ");
    scanf("%d", &m->phy_marks);
}

void displayPercentage(struct Marks m) {
    float percentage = (m.chem_marks + m.maths_marks + m.phy_marks) / 3.0;
    printf("Roll No: %d\n", m.roll_no);
    printf("Name: %s\n", m.name);
    printf("Percentage: %.2f%%\n", percentage);
}

int main() {
    struct Marks students[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        inputMarks(&students[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("\nDetails of student %d:\n", i + 1);
        displayPercentage(students[i]);
    }

    return 0;
}
