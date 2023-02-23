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

// Word count for size()
unsigned int wordcount = 0;





// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO #4
    // return true if word is in dictionary

    // hash word to obtain hash value
    unsigned int INDEX = hash(word);

    // access linked list at that index in the hash table
    table[INDEX]


    // traverse linked list, looking for the word (strcasecmp)





    // otherwise return false
    return false;
}





// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO #2: Improve this hash function

    // input a word, with alphabetical characters and (possibly) apostrophes
    // output a numerical index value between 0 and N-1 (where N is the number of buckets in the hash table)

    // initially build with just 26 buckets, using the 1st letter of the word
    return toupper(word[0]) - 'A'; // returns a hash value between 0 and 25
}













// Loads dictionary into memory using a data structure, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictonary file
    FILE *file = fopen(dictionaries/large, "r");
    if (file == NULL) {
        printf("Error: file not found.");
        return false;
    }

    // read strings from file 1 at a time, until the end of the file is reached
    do {

        // allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (*n == NULL) {
            printf("Error: not enough memory available.");
            return false;
        }

        // initialise a character array for storing a word temporarily
        char word[LENGTH];

        // read a word from the opened file using the "string" conversion, storing it in a character array
        // (safe to do so as the word has a finite length, capped at 45)
        fscanf(file, "%s", word);

        // count each word as it loads
        size();

        // copy word into new node
        strcpy(n->word, word);

        // hash the word in the new node to obtain a hash value
        unsigned int INDEX = hash(n->word);

        // insert the node into the hash table at that hash location...
        // stitch the new nodes' "next" pointer to point at the first node in the linked list
        n->next = table[INDEX];
        // re-point the linked list to the new node, thereby stacking it into the linked list
        table[INDEX] = n;

        // success
        return true;
    }
    while (!(fscanf == EOF));
}





















// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    wordcount++;
    return wordcount;
}





// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO #5
    return false;
}




