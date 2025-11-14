#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct Book {
    int id;
    char title[50];
    char author[50];
};


void addBook() {
    FILE *fp = fopen("books.txt", "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    struct Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    getchar();

    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    fprintf(fp, "%d,%s,%s\n", b.id, b.title, b.author);
    fclose(fp);

    printf("\nBook added successfully!\n");
}


void viewBooks() {
    FILE *fp = fopen("books.txt", "r");
    if (!fp) {
        printf("\nNo books found!\n");
        return;
    }

    struct Book b;
    char line[150];

    printf("\n--- List of All Books ---\n");
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d,%49[^,],%49[^\n]", &b.id, b.title, b.author);
        printf("\nID: %d\nTitle: %s\nAuthor: %s\n", b.id, b.title, b.author);
    }

    fclose(fp);
}


void searchBook() {
    FILE *fp = fopen("books.txt", "r");
    if (!fp) {
        printf("\nNo books found!\n");
        return;
    }

    int id;
    struct Book b;
    char line[150];
    int found = 0;

    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d,%49[^,],%49[^\n]", &b.id, b.title, b.author);
        if (b.id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n", b.id, b.title, b.author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        clearScreen();
        printf("=====================================\n");
        printf("   LIBRARY BOOK MANAGEMENT SYSTEM    \n");
        printf("=====================================\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        clearScreen();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("\nDeveloped by MD NAZMUL HASAN\n");
                return 0;
            default:
                printf("\nInvalid choice, try again!\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}
