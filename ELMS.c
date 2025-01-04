// Employee Leave Management System Project

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Preprocessor Directives
#define MAX_EMPLOYEE 50
#define MAX_LEAVE 20

// Function Prototypes
void applyLeave();
void viewStatus();
void leaveApproval();
void addEmployee();
void writeLeaveApplication();

// Structure to hold employee details
struct Employee
{
    int id;
    char name[50];
    int leaveDays;
};

// User-defined Functions
// Function to apply for leave
void applyLeave()
{
    struct Employee emp;
    int leaveDays;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    printf("Enter number of leave days: ");
    scanf("%d", &leaveDays);

    emp.leaveDays = leaveDays;

    printf("Leave applied successfully for %s (%d) for %d days.\n", emp.name, emp.id, emp.leaveDays);
    writeLeaveApplication();
}

// Function to view employee details and leave status
void viewStatus()
{
    struct Employee emp;
    FILE *file;
    file = fopen("employee.txt", "r");
    if (file == NULL)
    {
        printf("File not found");
        exit(1);
    }
    else
    {
        while (fscanf(file, "Employee ID:%d\nEmployee Name: %s\nLeave Days: %d\nBalance Leave Available: %d\n", &emp.id, emp.name, &emp.leaveDays, &emp.leaveDays) != EOF)
        {
            printf("Employee ID: %d\n", emp.id);
            printf("Employee Name: %s\n", emp.name);
            printf("Leave Days: %d\n", emp.leaveDays);
            printf("Balance Leave Available: %d\n", MAX_LEAVE - emp.leaveDays);
            fclose(file);
            break;
        }
    }
}

// Function to apply or reject leave application
void leaveApproval()
{
    struct Employee emp;
    FILE *file;
    file = fopen("leaveapplication.txt", "r");
    if (file == NULL)
    {
        printf("File not found");
        exit(1);
    }
    else
    {
        while (fscanf(file, "Employee ID:%d\nEmployee Name:%s\nLeave Days:%d\n", &emp.id, emp.name, &emp.leaveDays) != EOF)
        {
            printf("Employee ID: %d\n", emp.id);
            printf("Employee Name: %s\n", emp.name);
            printf("Employee Leave Days: %d\n", emp.leaveDays);
            printf("Balance Leave Available: %d\n", MAX_LEAVE - emp.leaveDays);
            printf("1. Accept Leave\n2. Reject Leave\n");
            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Leave accepted for %s (%d).\n", emp.name, emp.id);
                break;
            case 2:
                printf("Leave rejected for %s (%d).\n", emp.name, emp.id);
                break;
            default:
                printf("Invalid choice.\n");
            }
        }
        fclose(file);
    }
}

// Function to add a new Employee
void addEmployee()
{
    struct Employee emp;
    FILE *file;
    file = fopen("employee.txt", "a");
    if (file == NULL)
    {
        printf("File not found");
        exit(1);
    }
    else
    {
        printf("Enter Employee ID: ");
        scanf("%d", &emp.id);
        printf("Enter Employee Name: ");
        scanf("%s", emp.name);
        emp.leaveDays = 0; // Initialize leave days to 0

        fprintf(file, "Employee ID:%d\n", emp.id);
        fprintf(file, "Employee Name: %s\n", emp.name);
        fprintf(file, "Leave Days: %d\n", emp.leaveDays);
        fprintf(file, "Balance Leave Available: %d\n", MAX_LEAVE - emp.leaveDays);
        fclose(file);
        printf("Employee added successfully.\n");
    }
}

// Function to write leave application
void writeLeaveApplication()
{
    struct Employee emp;
    FILE *file;
    file = fopen("leaveapplication.txt", "a");
    if (file == NULL)
    {
        printf("File not found");
        exit(1);
    }
    else
    {
        fprintf(file, "Employee ID:%d\n", emp.id);
        fprintf(file, "Employee Name: %s\n", emp.name);
        fprintf(file, "Leave Days: %d\n", emp.leaveDays);
        fclose(file);
        printf("Leave application written to file successfully.\n");
    }
}

// Main function
int main()
{
    // character arrays to store user name and password
    char password[20], username[20];
    // variable to store the user's choice
    int choice;
    // Functionalities for Employees
    while (1)
    {
        printf("Enter Your User Name:");
        scanf("%s", &username);
        printf("Enter Your Password:");
        scanf("%s", &password);
        if (strcmp("e", username) == 0 && strcmp("1", password) == 0)
        {

            printf("1.Apply for Leave.\n2.View Leave Status.\n3.Exit.\n");
            printf("Enter your choice:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                applyLeave();
                break;
            case 2:
                viewStatus();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice!!!");
            }
        }
        // Functionalities for the manager
        else if (strcmp("m", username) == 0 && strcmp("1", password) == 0)
        {

            printf("1.Accept or Reject Leave Application.\n2.View Leave Status.\n3.Add New Employees.\n4.Exit.\n");
            printf("Enter your choice:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                leaveApproval();
                break;
            case 2:
                viewStatus();
                break;
            case 3:
                addEmployee();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!!!\n");
            }
        }
        else
        {
            printf("Invalid Username or Password.Unable to Login!!!\n");
        }
    }
    return 0;
}
