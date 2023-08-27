#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void linearProbingInsert(int arr[], int key) {
    int index = hash1(key);
    while (arr[index] != -1) {
        index = (index + 1) % SIZE;
    }
    arr[index] = key;
}

bool linearProbingSearch(int arr[], int key) {
    int index = hash1(key);
    while (arr[index] != -1) {
        if (arr[index] == key) {
            return true;
        }
        index = (index + 1) % SIZE;
    }
    return false;
}

void quadraticProbingInsert(int arr[], int key) {
    int index = hash1(key);
    int i = 0;
    while (arr[index] != -1) {
        index = (hash1(key) + (i * i)) % SIZE;
        i++;
    }
    arr[index] = key;
}

bool quadraticProbingSearch(int arr[], int key) {
    int index = hash1(key);
    int i = 0;
    while (arr[index] != -1) {
        if (arr[index] == key) {
            return true;
        }
        index = (hash1(key) + (i * i)) % SIZE;
        i++;
    }
    return false;
}

void doubleHashingInsert(int arr[], int key) {
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;
    while (arr[index] != -1) {
        index = (index + (i * stepSize)) % SIZE;
        i++;
    }
    arr[index] = key;
}

bool doubleHashingSearch(int arr[], int key) {
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;
    while (arr[index] != -1) {
        if (arr[index] == key) {
            return true;
        }
        index = (index + (i * stepSize)) % SIZE;
        i++;
    }
    return false;
}

int main() {
     int arr[SIZE];
        for (int i = 0; i < SIZE; i++) {
            arr[i] = -1;
        }
     int choice, key;
     do {
         printf("\nMenu:\n");
         printf("1. Insert a key using Linear Probing\n");
         printf("2. Insert a key using Quadratic Probing\n");
         printf("3. Insert a key using Double Hashing\n");
         printf("4. Search for a key using Linear Probing\n");
         printf("5. Search for a key using Quadratic Probing\n");
         printf("6. Search for a key using Double Hashing\n");
         printf("7. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
         switch (choice) {
             case 1:
             printf("Enter the key to insert: ");
             scanf("%d", &key);
             linearProbingInsert(arr, key);
             break;
             
             case 2:
             printf("Enter the key to insert: ");
             scanf("%d", &key);
             quadraticProbingInsert(arr, key);
             break;
             
             case 3:
             printf("Enter the key to insert: ");
             scanf("%d", &key);
             doubleHashingInsert(arr, key);
             break;
             
             case 4:
             printf("Enter the key to search: ");
             scanf("%d", &key);
             if (linearProbingSearch(arr, key))
             printf("Key found!\n");
             else
             printf("Key not found!\n");
             break;
             
             case 5:
             printf("Enter the key to search: ");
             scanf("%d", &key);
             if (quadraticProbingSearch(arr, key))
             printf("Key found!\n");
             else
             printf("Key not found!\n");
             break;
             
             case 6:
             printf("Enter the key to search: ");
             scanf("%d", &key);
             if (doubleHashingSearch(arr, key))
             printf("Key found!\n");
             else
             printf("Key not found!\n");
             break;
             
             case 7:
             printf("Exiting the program...\n");
             break;
             default:
             printf("Invalid choice! Please try again.\n");
             break;
             }
         } while (choice != 7);
     return 0;
}

