#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 200
#define MAX_AUTHOR_LEN 200

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int quantity;
} Book;

Book *library = NULL;
int num_books = 0;
int capacity = 10; // Initial capacity for dynamic array

// Function to resize the library
void resizeLibrary() {
    capacity *= 2; // Double the capacity
    library = realloc(library, capacity * sizeof(Book));
    if (library == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

// User-defined strcspn function using recursion
int my_strcspn(const char *s1, const char *s2) {
    if (*s1 == '\0') return 0;
    if (strchr(s2, *s1)) return 0;
    return 1 + my_strcspn(s1 + 1, s2);
}

// User-defined strcmp function using recursion
int my_strcmp(const char *s1, const char *s2) {
    if (*s1 == '\0' && *s2 == '\0') return 0;
    if (*s1 == *s2) return my_strcmp(s1 + 1, s2 + 1);
    return (*s1 - *s2);
}

void addBook() {
    if (num_books >= capacity) {
        resizeLibrary();
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
    newBook.title[my_strcspn(newBook.title, "\n")] = 0;  // Remove trailing newline

    printf("Enter book author: ");
    fgets(newBook.author, MAX_AUTHOR_LEN, stdin);
    newBook.author[my_strcspn(newBook.author, "\n")] = 0;  // Remove trailing newline

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

void listUpdatedBooks() {
    printf("Updated Books:\n");
    for (int i = 0; i < num_books; i++) {
        if (library[i].quantity > 0) { // Assuming quantity > 0 means updated
            printf("ID: %d, Title: %s, Author: %s, Quantity: %d\n",
                   library[i].id, library[i].title, library[i].author, library[i].quantity);
        }
    }
}

void searchBooksByAuthor() {
    char author[MAX_AUTHOR_LEN];

    printf("Enter author name to search: ");
    getchar();  // Clear the newline character left in the buffer
    fgets(author, MAX_AUTHOR_LEN, stdin);
    author[my_strcspn(author, "\n")] = 0;  // Remove trailing newline

    int found = 0;
    printf("Books by %s:\n", author);

    for (int i = 0; i < num_books; i++) {
        if (my_strcmp(library[i].author, author) == 0) {
            printf("ID: %d, Title: %s, Quantity: %d\n", library[i].id, library[i].title, library[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found by author %s.\n", author);
    }
}

void freeLibrary() {
    free(library);
}

int main() {
    library = malloc(capacity * sizeof(Book));
    if (library == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add New Book\n");
        printf("2. Update Book Quantity\n");
        printf("3. List Updated Books\n");
        printf("4. Search Books by Author\n");
        printf("5. Exit\n");
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
                listUpdatedBooks();
                break;
            case 4:
                searchBooksByAuthor();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    freeLibrary(); // Free allocated memory
    return 0;
}
