#include <stdio.h>

#include <string.h>
 
#define MAX_BOOKS 200

#define MAX_TITLE_LEN 200

#define MAX_AUTHOR_LEN 200
 
typedef struct {

    int id;

    char title[MAX_TITLE_LEN];

    char author[MAX_AUTHOR_LEN];

    int quantity;

} Book;
 
Book library[MAX_BOOKS];

int num_books = 0;
 
void addBook() {

    if (num_books >= MAX_BOOKS) {

        printf("Library is full, cannot add more books.\n");

        return;

    }
 
    Book newBook;

    printf("Enter book ID: ");

    scanf("%d", &newBook.id);

    getchar();  // Clear the newline character left in the buffer
 
    // Check if book ID already exists

    for (int i = 0; i < num_books; i++) {

        if (library[i].id == newBook.id) {

            printf("Book with ID %d already exists.\n", newBook.id);

            return;

        }

    }
 
    printf("Enter book title: ");

    fgets(newBook.title, MAX_TITLE_LEN, stdin);

    newBook.title[strcspn(newBook.title, "\n")] = 0;  // Remove trailing newline
 
    printf("Enter book author: ");

    fgets(newBook.author, MAX_AUTHOR_LEN, stdin);

    newBook.author[strcspn(newBook.author, "\n")] = 0;  // Remove trailing newline
 
    printf("Enter book quantity: ");

    scanf("%d", &newBook.quantity);
 
    library[num_books] = newBook;

    num_books++;

    printf("Book added successfully.\n");

}
 
void updateBookQuantity() {

    int id, quantity;

    printf("Enter book ID to update: ");

    scanf("%d", &id);
 
    for (int i = 0; i < num_books; i++) {

        if (library[i].id == id) {

            printf("Enter new quantity: ");

            scanf("%d", &quantity);

            library[i].quantity = quantity;

            printf("Quantity updated successfully.\n");

            return;

        }

    }

    printf("Book with ID %d not found.\n", id);

}
 
void searchBooksByAuthor() {

    char author[MAX_AUTHOR_LEN];

    printf("Enter author name to search: ");

    getchar();  // Clear the newline character left in the buffer

    fgets(author, MAX_AUTHOR_LEN, stdin);

    author[strcspn(author, "\n")] = 0;  // Remove trailing newline
 
    int found = 0;

    printf("Books by %s:\n", author);

    for (int i = 0; i < num_books; i++) {

        if (strcmp(library[i].author, author) == 0) {

            printf("ID: %d, Title: %s, Quantity: %d\n", library[i].id, library[i].title, library[i].quantity);

            found = 1;

        }

    }

    if (!found) {

        printf("No books found by author %s.\n", author);

    }

}
 
int main() {

    int choice;

    do {

        printf("\nLibrary Management System\n");

        printf("1. Add New Book\n");

        printf("2. Update Book Quantity\n");

        printf("3. Search Books by Author\n");

        printf("4. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);
 
        switch (choice) {

            case 1:

                addBook();

                break;

            case 2:

                updateBookQuantity();

                break;

            case 3:

                searchBooksByAuthor();

                break;

            case 4:

                printf("Exiting the program.\n");

                break;

            default:

                printf("Invalid choice. Please enter a number between 1 and 4.\n");

        }

    } while (choice != 4);
 
    return 0;

}

  
