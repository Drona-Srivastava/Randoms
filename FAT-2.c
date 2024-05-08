#include <stdio.h>
#include <string.h>
struct EmployeeInfo{
    char name[100];
    int id;
    char designation[100];
    int yr;
    int salary;
};

int salary_increement(struct EmployeeInfo *emp){
    if (emp->yr>=5){
        emp->salary +=(emp->salary*12)/100;
    }
    else{
        emp->salary = emp->salary;
    }
}

void displayInfo(struct EmployeeInfo emp){
    printf("Name: %s\n", emp.name);
    printf("ID: %d\n", emp.id);
    printf("Designation: %s\n", emp.designation);
    printf("Year of Experience: %d\n", emp.yr);
    printf("Salary: %d\n", emp.salary);
}

int main(){
    struct EmployeeInfo emp;
    printf("Enter the name of the employee: ");
    scanf("%[^\n]s", emp.name);
    printf("Enter the ID of the employee: ");
    scanf("%d", &emp.id);
    printf("Enter the Designation of the employee: ");
    scanf("%s",emp.designation);
    printf("Enter the year of experience of the employee: ");
    scanf("%d", &emp.yr);
    printf("Enter the salary of the employee: ");
    scanf("%d", &emp.salary);
    salary_increement(&emp);
    displayInfo(emp);
}
