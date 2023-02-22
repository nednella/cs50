// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];





// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO #4
    return false;
}





// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO #2: Improve this hash function
    return toupper(word[0]) - 'A';
}













// Loads dictionary into memory using a data structure, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO #1

    // open dictonary file
    FILE *file = fopen(dictionaries/large, "r");
    if (file == NULL) {
        printf("Error: file not found.");
    }

    // read strings from file 1 at a time, until the end of the file is reached
    do {

        // allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (*n == NULL) {
            printf("Error: not enough memory available.");
        }

        // initialise a character array for storing a word temporarily
        char tmpword[LENGTH];

        // read a word from the opened file using the "string" conversion, storing it in a character array
        // (safe to do so as the word has a finite length, capped at 45)
        fscanf(file, "%s", tmpword);

        // copy word into new node
        strcpy(*n->word, tmpword);

        // hash the word in the new node (assign it an integer value)
        int index = hash(*n->word);

        // insert the node into the hash table
        table(index)
    }

    while (!(fscanf == EOF));

    // create a new node for each word

    // hash word to obtain a hash value

    // insert node into hash table at that location





    return false;
}





















// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO #3
    return 0;
}





// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO #5
    return false;
}




