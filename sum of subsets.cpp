#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int set[MAX_SIZE];
int subset[MAX_SIZE];
int n;
int targetSum;
int sumSoFar = 0;

void printSubset(int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void findSubsets(int index, int size) {
    if (sumSoFar == targetSum) {
        printSubset(size);
        return;
    }

    for (int i = index; i < n; i++) {
        if (sumSoFar + set[i] <= targetSum) {
            subset[size] = set[i];
            sumSoFar += set[i];
            findSubsets(i + 1, size + 1);
            sumSoFar -= set[i];
        }
    }
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum %d:\n", targetSum);
    findSubsets(0, 0);

    return 0;
}
