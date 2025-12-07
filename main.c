#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    struct Patient *next;
};

struct Patient *front = NULL, *rear = NULL;

// Add patient (Normal)
void insertRear(int id, char name[]) {
    struct Patient newnode = (struct Patient)malloc(sizeof(struct Patient));
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("? Patient Added Successfully!\n");
}

// Emergency patient (Priority)
void insertFront(int id, char name[]) {
    struct Patient newnode = (struct Patient)malloc(sizeof(struct Patient));
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->next = front;
    front = newnode;

    if (rear == NULL)
        rear = newnode;

    printf("?? Emergency Patient Added at Front!\n");
}

// Call patient
void deleteFront() {
    if (front == NULL) {
        printf("? No Patients in Queue!\n");
        return;
    }

    struct Patient *temp = front;
    printf("?? Calling Patient: %s (ID: %d)\n", temp->name, temp->id);

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Display waiting list
void display() {
    if (front == NULL) {
        printf("?? Queue is Empty.\n");
        return;
    }

    struct Patient *temp = front;
    printf("\n?? Waiting List:\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice, id;
    char name[50];

    while (1) {
        printf("\n====== HOSPITAL MANAGEMENT SYSTEM ======\n");
        printf("1. Add Patient\n");
        printf("2. Emergency Patient\n");
        printf("3. Call Patient\n");
        printf("4. Display Patients\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &id);
                printf("Enter Patient Name: ");
                scanf(" %[^\n]", name);
                insertRear(id, name);
                break;

            case 2:
                printf("Enter Emergency Patient ID: ");
                scanf("%d", &id);
                printf("Enter Patient Name: ");
                scanf(" %[^\n]", name);
                insertFront(id, name);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("? Program Ended.\n");
                exit(0);

            default:
                printf("? Invalid Choice!\n");
        }
    }
}
