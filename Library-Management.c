#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 100
typedef struct {
    int id;
    char name[50];
    char author[50];
} Book;
Book books[MAX_BOOKS];
int numBooks = 0;
int addBook();
int deleteBook();
void viewBooks();
int searchBook(int id);
int main()
{
    int choice;
    printf("\n\t\t\t\t\t\t*************** MAIN MENU ***************\n");
    printf("\n\t\t\t\t\t\t1. Add Books");
    printf("\n\t\t\t\t\t\t2. Delete Books");
    printf("\n\t\t\t\t\t\t3. View Books");
    printf("\n\t\t\t\t\t\t4. Search Book");
    printf("\n\t\t\t\t\t\t5. Close Application");
    printf("\n\t\t\t\t\t\t******************************************\n");
    while (1) {
        printf("\n\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (addBook()) {
                printf("Book added successfully.\n");
                }
            break;
        case 2:
            if (deleteBook()) {
                printf("Book deleted successfully.\n");
                }
            break;
        case 3:
            viewBooks();
            break;
        case 4: {
            int id;
            printf("Enter Book ID to search: ");
            scanf("%d", &id);
            if (searchBook(id)) {
                printf("Book found!\n");
            } else {
                printf("Book not found.\n");
                }
            break;
            }
        case 5:
            printf("Closing application.\n");
            exit(0);
        default:
            printf("Invalid input\n");
            break;
            }
            }
            return 0;
}
int addBook() {
    int id;
    char name[50];
    char author[50];
    if (numBooks == MAX_BOOKS) {
        printf("Cannot add more books. Library is full.\n");
        return 0; // Unsuccessful
        }
        printf("Book ID: ");
        scanf("%d", &id);
        // Check if the book with given ID already exists
    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == id) {
            printf("Book with ID %d already exists.\n", id);
            return 0; // Unsuccessful
            }
            }
            printf("Book Name: ");
            scanf(" %[^\n]", name);
            printf("Author Name: ");
            scanf(" %[^\n]", author);
            books[numBooks].id = id;
            strcpy(books[numBooks].name, name);
            strcpy(books[numBooks].author, author);
            numBooks++;
            return 1; // Successful
            }
            int deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < numBooks - 1; j++) {
                books[j] = books[j + 1];
                }
            numBooks--;
            return 1; // Successful
            }
            }
            if (!found) {
        printf("Book with ID %d not found.\n", id);
        return 0; // Unsuccessful
        }
        return 0; // Unsuccessful
}
void viewBooks() {
    if (numBooks == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\n%-10s %-30s %-30s\n", "Book ID", "Name", "Author");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%-10d %-30s %-30s\n", books[i].id, books[i].name, books[i].author);
    }
}
int searchBook(int id) {
    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == id) {
            printf("\n%-10s %-30s %-30s\n", "Book ID", "Name", "Author");
            printf("-----------------------------------------------------------\n");
            printf("%-10d %-30s %-30s\n", books[i].id, books[i].name, books[i].author);
            return 1; // Book found
        }
    }
    return 0; // Book not found
}
