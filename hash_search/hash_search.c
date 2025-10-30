#include <stdio.h>

#define TABLE_SIZE 11
#define EMPTY -1

int table[TABLE_SIZE];

// (1) Hash function: Convert key to table index
int hash(int key)
{
    // TODO: Implement including handling negative values
    // Hint: (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

// (2) Insert key using linear probing
// Return 1 on success, 0 if table is full or key is already present
int insert(int key)
{
    int idx = hash(key);
    // TODO: Try up to TABLE_SIZE times, inserting into the first empty slot (EMPTY) found
    // If the key already exists, do not insert and return 0
    for (int step = 0; step < TABLE_SIZE; step++)
    {
        int cur = (idx + step) % TABLE_SIZE;
        if (table[cur] == EMPTY)
        { // Insert into empty slot
            table[cur] = key;
            return 1;
        }
        else if (table[cur] == key)
        { // Prevent duplicate
            return 0;
        }
        // If collision, move one space forward (linear probe)
    }
    return 0; // Table is full
}

// (3) Search for key using linear probe (return index if found, -1 if not)
int search(int key)
{
    int idx = hash(key);
    // TODO: Search TABLE_SIZE times; return index if key is found
    // If an empty cell (EMPTY) is encountered, stop searching and return -1 (no more keys due to linear search nature)
    for (int step = 0; step < TABLE_SIZE; step++)
    {
        int cur = (idx + step) % TABLE_SIZE;
        if (table[cur] == EMPTY)
            return -1; // No more
        if (table[cur] == key)
            return cur;
    }
    return -1;
}

int main(void)
{
    // Initialize the table
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;

    // Simple test
    int keys[] = {22, 1, 13, 11, 24, 33, 12, 23};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        insert(keys[i]);

    // Print state
    printf("Hash table state:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] == EMPTY)
            printf("[%2d]: .\n", i);
        else
            printf("[%2d]: %d\n", i, table[i]);
    }

    // Search test
    int q;
    printf("\nEnter value to search: ");
    if (scanf("%d", &q) == 1)
    {
        int pos = search(q);
        if (pos == -1)
            printf("Search failed\n");
        else
            printf("%d is at index %d\n", q, pos);
    }
    return 0;
}
