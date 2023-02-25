// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    // TODO
    return false;
}





// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}





// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictonary file
    FILE *dictionary = fopen("./dictionaries/small", "r");
    if (dictionary == NULL) {
        printf("Error: file not found.\n");
        return false;
    }

    // initialise string buffer for temporarily storing each word
    char buffer[LENGTH + 1];

    // read strings from the opened file 1 at a time until the end of the file is reached
    while (fscanf(dictionary, "%s", buffer) != EOF) {

        // allocate memory for a new node
        node *temp = malloc(sizeof(node));
        if (temp == NULL) {
            printf("Error: not enough memory available.");
            return false;
        }

        // read a word from the opened fileusing the "string" conversion, counting as it loads
        fscanf(dictionary, "%s", buffer);
        size();

        // copy word into newly created node
        strcpy(temp->word, buffer);

        // use the hash function to obtain a hash value for this word
        unsigned int index = hash(temp->word);

        // check if this is the first element in the list or not
        if (table[index] == NULL) {
            // if true, point temp node to NULL
            temp->next = NULL;
        }

        // else, point temp to the first node of the linked list
        else {
            temp->next = table[index];
        }

        // point header to temp
        table[index] = temp;

        // insert the node into the hash table as per the assigned hash value
        //temp->next = table[index];

        // re-point the linked list to the new node, thereby creating a stacked linked list
        //table[index] = temp;
    }

    // successfully loaded file
    fclose(dictionary);
    return true;
}





// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}





// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
