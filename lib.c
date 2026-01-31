#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int quantity;
};

void addBook() {
    FILE *fp = fopen("library.dat", "ab");
    struct Book b;

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b.name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp = fopen("library.dat", "rb");
    struct Book b;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("\nID\tName\t\tAuthor\t\tQty\n");
    printf("------------------------------------------\n");

    while (fread(&b, sizeof(b), 1, fp)) {
        printf("%d\t%s\t%s\t%d\n", b.id, b.name, b.author, b.quantity);
    }

    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("library.dat", "rb");
    struct

