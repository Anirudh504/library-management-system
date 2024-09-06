#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
struct Book {
    int id;
    char title[100];
    char author[100];
};
void addBook(struct Book books[], int *count);
void displayBooks(struct Book books[], int count);
int searchBook(struct Book books[], int count, int id);

int main() {
    struct Book books[MAX_BOOKS];
    int count = 0;
    int choice, id, index;  
    while (1) {
        printf("\nCenturion Library Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                index = searchBook(books, count, id); 
                if (index != -1) {
                    printf("Book found: ID: %d, Title: %s, Author: %s\n", books[index].id, books[index].title, books[index].author);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
void addBook(struct Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full, can't add more books.\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &books[*count].id);
    printf("Enter book title: ");
    scanf(" %[^\n]%*c", books[*count].title); 
    printf("Enter book author: ");
    scanf(" %[^\n]%*c", books[*count].author);
    (*count)++;
    printf("Book added successfully.\n");
}
void displayBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }
    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
    }
}
int searchBook(struct Book books[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            return i; 
        }
    }
    return -1; 
}

