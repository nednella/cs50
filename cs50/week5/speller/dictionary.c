// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


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
    // iterative search method - O(n)
    // to recursively search the linked list, must include a node as an argument in the check() function!

    // hash word to obtain hash value
    unsigned int INDEX = hash(word);

    // access linked list at that index in the hash table
    node *cursor = table[INDEX]; // create a node pointer (a cursor!) to the first element in the linked list

    // traverse linked list, looking for the word (strcasecmp)
    while (cursor != NULL) {

        // check for match
        if (strcasecmp(word, cursor->word) == 0) { // compare 2 strings, ignoring case (case insensitive), 0 = match

            // match found
            return true;
        }

        // if no match, traverse the list
        cursor = cursor->next;
    }

    // no match found
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
    FILE *file = fopen("./dictionaries/large", "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
        return false;
    }

    // initialise a character array for storing a word temporarily
    char buffer[LENGTH + 1];

    // read strings from file 1 at a time, until the end of the file is reached
    while (fscanf(file, "%s", buffer) != EOF) {

        // allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("Error: not enough memory available.");
            fclose(file);
            return false;
        }

        // read a word from the opened file using the "string" conversion, storing it in a character array
        // (safe to do so as the word has a finite length, capped at 45)
        fscanf(file, "%s", buffer);

        // count each word as it loads
        size();

        // copy word into new node
        strcpy(n->word, buffer);

        // hash the word in the new node to obtain a hash value
        unsigned int index = hash(n->word);

        // check if there are any elements in the linked list
        if (table[index] == NULL) {
            // if true, point temp node to NULL
            temp->next = NULL;
        }

        // else, point temp to the first node of the linked list
        else {
            temp->next = table[INDEX];
        }

        // point the header back to temp
        table[index] = temp;
    }

    // successfully loaded dictionary
    fclose(file);
    return true;
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
    // iterate through every hash value inside the hash table
    for (int i = 0; i < N; i++) {

        // point a cursor at the first node in the linked list
        node *cursor = table[i];

        // create a temporary node to allow for freeing of memory
        node *temp = cursor;

        // traverse through each linked list for each hash value until NULL is reached
        while (cursor != NULL) {

            // point cursor to next element in the list
            cursor = cursor->next;

            // free the first element
            free(temp);

            // point temp to the same element as cursor
            temp = cursor;
        }

        // successfully unloaded dictionary
        return true;
    }

    // else unsuccessful
    return false;
}




