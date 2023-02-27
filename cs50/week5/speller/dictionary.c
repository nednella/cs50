// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    //unsigned int hash;
    struct node *next;
}
node;

unsigned int wordcount = 0;     // initialise word count for size() function
const unsigned int N = 200000;     // initialise number of buckets in hash table

// hash table
node *table[N];

// function prototypes
void freenode(node *temp);



// Returns true if word is in dictionary, else false
bool check(const char *word) {

    // iterative search method - O(n)
    // to recursively search the linked list, must include a node as an argument in the check() function!

    unsigned int h_val = hash(word);    // hash given word to obtain hash value

    // access linked list at that index in the hash table
    node *cursor = table[h_val];        // set cursor to head of list
    while (cursor != NULL) {            // traverse the list until end


        /*if (cursor->hash != h_val) {
            continue;
        }*/

        if (strcmp(word, cursor->word) == 0) {  // check for match - compare 2 strings case insensitively
            return true;                // match found
        }

        cursor = cursor->next;          // if no match, continue traversing
    }

    // no match found
    return false;
}



// Hashes word to a number
unsigned int hash(const char *word) {

    unsigned int h_val = 0;                             // initialise hash value

    // iterate through each character
    for (int i = 0, n = strlen(word); i < n; i++) {
        h_val = (31 * h_val + tolower(word[i]));        // hash function
    }
    h_val = h_val % N;                                  // ensure hash value is a valid bucket

    return h_val;
}



// Loads dictionary into memory using a data structure, returning true if successful, else false
bool load(const char *dictionary) {

    FILE *file = fopen(dictionary, "r");    // open dictionary text file
    if (file == NULL) {
        printf("Error: file not found.\n");
        fclose(file);
        return false;
    }

    char buffer[LENGTH + 1];    // initialise string buffer

    // read text file 1 string at a time until end of file
    while (fscanf(file, "%s", buffer) == 1) {

        wordcount++;                            // count the word being read - string is buffered whilst evaluating while condition!
        node *temp = malloc(sizeof(node));      // allocate memory for a new node
        if (temp == NULL) {
            printf("Error: not enough memory available.");
            fclose(file);
            return false;
        }

        strcpy(temp->word, buffer);             // write word to new node
        unsigned int index = hash(temp->word);  // obtain a hash value for word

        /*// check if first element in the linked list
        if (table[index] == NULL) {             // if true
            temp->next = NULL;                  // NULL "next" pointer of new node
            table[index] = temp;                // point header to new node
        }*/

        //else {                                  // if false
            temp->next = table[index];          // point "next" pointer of new node to previous node
            table[index] = temp;                // point header to new node (stacked list)
        //}
    }

    // successfully loaded dictionary
    fclose(file);
    return true;
}



// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) {

    return wordcount;
}



// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {

    // iterate through every hash value inside the hash table
    for (int i = 0; i < N; i++) {

        // if header points to any non-NULL elements
        if (table[i] != NULL) {

            // OPTION 1 - recursively free all nodes
            freenode(table[i]);

            // OPTION 2 - iteratively free all nodes
            //node *cursor = table[i];        // point cursor to head of linked list
            //node *temp = cursor;            // create temporary node to allow freeing of memory

            // traverse the list until end
            //while (cursor != NULL) {
                //cursor = cursor->next;      // advance cursor to next node
                //free(temp);                 // free the previous element
                //temp = cursor;              // advance temp to the next node
            //}
        }
    }

    // successfully unloaded dictionary
    return true;
}



// Recursive free() function - used in unload() OPTION 1
void freenode(node *temp) {

    if (temp->next != NULL) {
        freenode(temp->next);
    }
    free(temp);
}