#include <stdio.h>
#include <stdlib.h>

int main() {

    struct Employee {
        int id;
        char name[50];
        float salary;
    };

    struct Employee *employees;
    int num;

    printf("Enter the number of employees: ");
    scanf("%d", &num);

    employees = (struct Employee *)malloc(num * sizeof(struct Employee));

    for (int i = 0; i < num; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &(employees[i].id));

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Salary: ");
        scanf("%f", &(employees[i].salary));
    }

    float total_salary = 0;
    for (int i = 0; i < num; i++) {
        total_salary += employees[i].salary;
    }

    printf("\nTotal salary of all employees = %.2f\n", total_salary);

    printf("\nEmployee details:\n");

    for (int i = 0; i < num; i++) {

        printf("Employee record %d  Base address: %p\n",
               i, (void *)(employees + i));

        printf("Employee %d - ID: %d, Name: %s, Salary: %.2f\n\n",
               i + 1,
               employees[i].id,
               employees[i].name,
               employees[i].salary);
    }

    free(employees);
    return 0;
}

