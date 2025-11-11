#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for club member node
struct Node {
    int prn;
    char name[50];
    char designation[20];
    struct Node *next;
};

struct Node *head = NULL;   // President
struct Node *tail = NULL;   // Secretary

// ---------- Create Club ----------
void createClub() {
    struct Node *newNode;

    // President
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter President PRN: ");
    scanf("%d", &newNode->prn);
    printf("Enter President Name: ");
    scanf("%s", newNode->name);
    strcpy(newNode->designation, "President");
    newNode->next = NULL;
    head = tail = newNode;

    // Secretary
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Secretary PRN: ");
    scanf("%d", &newNode->prn);
    printf("Enter Secretary Name: ");
    scanf("%s", newNode->name);
    strcpy(newNode->designation, "Secretary");
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;

    printf("\n✅ Club created successfully!\n");
}

// ---------- Display Members ----------
void displayClub() {
    if (head == NULL) {
        printf("❌ Club not created yet!\n");
        return;
    }

    struct Node *temp = head;
    printf("\n--- Club Member List ---\n");
    printf("%-10s %-15s %-15s\n", "PRN", "Name", "Designation");
    printf("---------------------------------------\n");

    while (temp != NULL) {
        printf("%-10d %-15s %-15s\n", temp->prn, temp->name, temp->designation);
        temp = temp->next;
    }
}

// ---------- Add Member ----------
void addMember() {
    if (head == NULL || tail == NULL) {
        printf("❌ Create the club first!\n");
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Member PRN: ");
    scanf("%d", &newNode->prn);
    printf("Enter Member Name: ");
    scanf("%s", newNode->name);
    strcpy(newNode->designation, "Member");

    // Insert before secretary
    struct Node *temp = head;
    while (temp->next != tail)
        temp = temp->next;

    newNode->next = tail;
    temp->next = newNode;

    printf("✅ Member added successfully!\n");
}

// ---------- Delete Member ----------
void deleteMember() {
    if (head == NULL || head->next == NULL) {
        printf("❌ No members to delete!\n");
        return;
    }

    int prn;
    printf("Enter PRN to delete: ");
    scanf("%d", &prn);

    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->prn != prn) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Member not found!\n");
        return;
    }

    if (temp == head) {
        printf("❌ President cannot be deleted!\n");
        return;
    }
    if (temp == tail) {
        printf("❌ Secretary cannot be deleted!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("✅ Member deleted successfully!\n");
}

// ---------- MAIN ----------
int main() {
    int choice;

    while (1) {
        printf("\n--- Club Member Management ---\n");
        printf("1. Create Club\n");
        printf("2. Display Members\n");
        printf("3. Add Member\n");
        printf("4. Delete Member\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createClub();
                break;
            case 2:
                displayClub();
                break;
            case 3:
                addMember();
                break;
            case 4:
                deleteMember();
                break;
            case 5:
                printf("👋 Exiting system... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
