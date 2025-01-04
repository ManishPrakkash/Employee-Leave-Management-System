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
    //character arrays to store user name and password
    char password[20], username[20];
    //variable to store the user's choice
    int choice;
    printf("Enter Your User Name:");
    scanf("%s", &username);
    printf("Enter Your Password:");
    scanf("%s", &password);
    //Functionalities for Employees
    if (strcmp("employee",username)==0 && strcmp("123",password)==0)
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
    //Functionalities for the manager 
    else if (strcmp("manager",username)==0 && strcmp("12345",password)==0)
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
    return 0;
}
