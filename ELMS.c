// Employee Leave Management System Project

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Preprocessor Directives

// Function Prototypes
void applyLeave();
void viewStatus();
void leaveApproval();
void addEmployee();

// User-defined Functions
//Function to apply for leave
void applyLeave()
{

}

//Function to view employee details and leave status
void viewStatus()
{

}

//Function to apply or reject leave application
void leaveApproval()
{

}

//Function to add a new Employee
void addEmployee()
{

}

// Main function
int main()
{
    char password[20], username[20];
    int choice;
    printf("Enter Your User Name:");
    scanf("%s", &username);
    printf("Enter Your Password:");
    scanf("%s", &password);
    if (strcmp("employee",username) && strcmp("123",password))
    {
        while (1)
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
    }
    else if (strcmp("manager",username) && strcmp("12345",password))
    {
        while (1)
        {
            printf("1.Accept or Reject Leave Application.\n2.View Leave Status.\n3.Add New Employees.4.Exit.\n");
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
                printf("Invalid choice!!!");
            }
        }
    }
    else
    {
        printf("Invalid Username or Password.Unable to Login!!!");
    }
}
