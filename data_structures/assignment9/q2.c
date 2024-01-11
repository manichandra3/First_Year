//
// Created by Mani Chandra Ganapathri on 13/06/23.
//
/*
In a hospital’s emergency department, the system uses a Binary Heap to manage the
priority of patients waiting for treatment. Each patient is assigned a priority value, where
a lower value indicates a higher priority. The Binary Heap is a min-heap, where the
patient with the highest priority has the smallest priority value.
Write a C program that implements the following operations for managing the patient
queue:
(a)Add a Patient
Hint: Prompt the user to enter the patient ID, name and priority of a patient. Create a
new patient node with the provided information and add it to the Binary Heap based
on the priority value.
(b) Treat a Patient
Hint: Remove and retrieve the patient with the highest priority (the root of the Binary
Heap). Display the patient ID, name and priority of the treated patient.
(c) Display Waiting Queue
Hint: Traverse the Binary Heap and display the names and priorities of all patients
in the waiting queue.

(d) Check Patient Count:
Hint: Calculate and display the total number of patients currently in the waiting
queue.
(e) Update Patient Priority
Hint: Prompt the user to enter the patient ID of a patient whose priority needs to be
updated. Retrieve the patient from the Binary Heap and prompt the user to enter a
new priority. Update the patient’s priority in the Binary Heap accordingly. Display
a message indicating that the patient’s priority has been updated.
(f) Clear Waiting Queue
Hint: Remove all patients from the Binary Heap and display a message indicating
that the waiting queue has been cleared.
 */
// Max-Heap data structure in C

#include <stdio.h>
#include <stdlib.h>

typedef struct patient
{
    int id;
    char name[100];
    int priority;
} patients;

int size = 0;
patients *waitingQueue;

void swap(patients *a, patients *b)
{
    patients temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(patients array[], int s, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < s && array[left].priority < array[smallest].priority)
    {
        smallest = left;
    }

    if (right < s && array[right].priority < array[smallest].priority)
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(&array[i], &array[smallest]);
        heapify(array, s, smallest);
    }
}

void insert(patients array[], patients newPatient)
{
    size++;
    int i = size - 1;
    array[i] = newPatient;

    while (i > 0 && array[(i - 1) / 2].priority > array[i].priority)
    {
        swap(&array[i], &array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

patients extractMin(patients array[])
{
    if (size <= 0)
    {
        patients nullPatient;
        nullPatient.id = -1;
        return nullPatient;
    }

    if (size == 1)
    {
        size--;
        return array[0];
    }

    patients root = array[0];
    array[0] = array[size - 1];
    size--;
    heapify(array, size, 0);

    return root;
}

void displayQueue(patients array[])
{
    if (size <= 0)
    {
        printf("Waiting queue is empty.\n");
        return;
    }

    printf("Waiting queue:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Patient ID: %d\n", array[i].id);
        printf("Patient name: %s\n", array[i].name);
        printf("Patient priority: %d\n", array[i].priority);
        printf("------------------------\n");
    }
}

int main()
{
    waitingQueue = (patients *) malloc(sizeof(patients) * 100);

    int choice;
    while (1) {
        printf("Menu\n");
        printf("1. Add a patient\n");
        printf("2. Treat a patient\n");
        printf("3. Display waiting queue\n");
        printf("4. Check patient count\n");
        printf("5. Update patient priority\n");
        printf("6. Clear waiting queue\n");
        printf("7. Quit\n");

        printf("Enter your action: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1: {
                patients newPatient;
                printf("Enter patient ID: ");
                scanf("%d", &newPatient.id);

                printf("Enter patient name: ");
                scanf("%s", newPatient.name);

                printf("Enter patient priority: ");
                scanf("%d", &newPatient.priority);

                insert(waitingQueue, newPatient);
                printf("Patient added successfully.\n");
                printf("------------------------\n");
                break;
            }
            case 2:
            {
                patients treatedPatient = extractMin(waitingQueue);
                if (treatedPatient.id != -1) {
                    printf("Treated patient ID: %d\n", treatedPatient.id);
                    printf("Treated patient name: %s\n", treatedPatient.name);
                    printf("Treated patient priority: %d\n", treatedPatient.priority);
                } else {
                    printf("No patients in the waiting queue.\n");
                }
                printf("------------------------\n");
                break;
            }
            case 3:
            {
                displayQueue(waitingQueue);
                printf("------------------------\n");
                break;
            }
            case 4:
            {
                printf("Patient count: %d\n", size);
                printf("------------------------\n");
                break;
            }
            case 5:
            {
                int patientID;
                printf("Enter patient ID to update priority: ");
                scanf("%d", &patientID);

                int found = 0;
                for (int i = 0; i < size; i++)
                {
                    if (waitingQueue[i].id == patientID) {
                        found = 1;
                        printf("Enter new priority for the patient: ");
                        scanf("%d", &waitingQueue[i].priority);
                        printf("------------------------\n");
                        break;
                    }
                }

                if (found)
                {
                    printf("Patient's priority has been updated.\n");
                    printf("------------------------\n");
                }
                else
                {
                    printf("Patient with ID %d not found in the waiting queue.\n", patientID);
                    printf("------------------------\n");
                }
                break;
            }
            case 6:
            {
                size = 0;
                printf("Waiting queue has been cleared.\n");
                printf("------------------------\n");
                break;
            }
            case 7:
            {
                free(waitingQueue);
                printf("Exiting the program.\n");
                exit(0);
            }
            default:
            {
                printf("Invalid choice. Please enter a valid option.\n");
                break;
            }
        }
    }
}