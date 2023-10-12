#include <stdio.h>
#include <string.h>

// Define a struct to store user information
struct User {
    char username[50];
    char password[50];
};

// Function to register a new user
void registerUser(struct User users[], int *userCount) {
    printf("Enter username: ");
    scanf("%s", users[*userCount].username);
    printf("Enter password: ");
    scanf("%s", users[*userCount].password);
    (*userCount)++;
    printf("Registration successful!\n");
}

// Function to check if a user can log in
int loginUser(struct User users[], int userCount, char username[], char password[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;  // Successful login
        }
    }
    return 0;  // Login failed
}

int main() {
    struct User users[100];
    int userCount = 0;

    int choice;
    char username[50];
    char password[50];

    do {
        // Display the menu options
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(users, &userCount); // Call the registration function
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                if (loginUser(users, userCount, username, password)) {
                    printf("Login successful!\n"); // Print login success
                } else {
                    printf("Login failed. Invalid username or password.\n"); // Print login failure
                }
                break;
            case 3:
                printf("Exiting program. Goodbye!\n"); // Exit the program
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // Display an error message for an invalid choice
        }
    } while (choice != 3);

    return 0;
}
