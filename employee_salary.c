#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float hra, da, pf, netSalary;
};

int main() {
    struct Employee emp[10];
    int choice, count = 0, i, searchId;
    
    do {
        printf("\n================================\n");
        printf(" EMPLOYEE SALARY MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Employee\n");
        printf("2. View All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count < 10) {
                    printf("\nEnter Employee ID: ");
                    scanf("%d", &emp[count].id);

                    printf("Enter Employee Name: ");
                    scanf(" %[^\n]", emp[count].name);

                    printf("Enter Basic Salary: ");
                    scanf("%f", &emp[count].basicSalary);

                    emp[count].hra = emp[count].basicSalary * 10 / 100;
                    emp[count].da = emp[count].basicSalary * 5 / 100;
                    emp[count].pf = emp[count].basicSalary * 12 / 100;

                    emp[count].netSalary = emp[count].basicSalary
                                         + emp[count].hra
                                         + emp[count].da
                                         - emp[count].pf;

                    count++;
                    printf("\nEmployee Added Successfully!\n");
                } else {
                    printf("\nEmployee Limit Reached!\n");
                }
                break;

            case 2:
                if(count == 0) {
                    printf("\nNo Employee Records Found!\n");
                } else {
                    printf("\n--- Employee Records ---\n");

                    for(i = 0; i < count; i++) {
                        printf("\nID: %d", emp[i].id);
                        printf("\nName: %s", emp[i].name);
                        printf("\nBasic Salary: %.2f", emp[i].basicSalary);
                        printf("\nNet Salary: %.2f\n", emp[i].netSalary);
                    }
                }
                break;

            case 3:
                printf("\nEnter Employee ID to Search: ");
                scanf("%d", &searchId);

                for(i = 0; i < count; i++) {
                    if(emp[i].id == searchId) {
                        printf("\nEmployee Found!");
                        printf("\nID: %d", emp[i].id);
                        printf("\nName: %s", emp[i].name);
                        printf("\nBasic Salary: %.2f\n", emp[i].basicSalary);
                        break;
                    }
                }

                if(i == count) {
                    printf("\nEmployee Not Found!\n");
                }
                break;

            case 4:
                printf("\n--- Salary Details ---\n");

                for(i = 0; i < count; i++) {
                    printf("\nEmployee: %s", emp[i].name);
                    printf("\nBasic Salary: %.2f", emp[i].basicSalary);
                    printf("\nHRA: %.2f", emp[i].hra);
                    printf("\nDA: %.2f", emp[i].da);
                    printf("\nPF: %.2f", emp[i].pf);
                    printf("\nNet Salary: %.2f\n", emp[i].netSalary);
                }
                break;

            case 5:
                printf("\nThank You! Program Closed.\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while(choice != 5);

    return 0;
}
