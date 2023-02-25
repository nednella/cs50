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
    unsigned int index = hash(word);

    // access linked list at that index in the hash table
    node *cursor = table[index]; // create a node pointer (a cursor!) to the first element in the linked list

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
    FILE *file = fopen("./dictionaries/small", "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
        fclose(file);
        return false;
    }

    // initialise a character array for storing a word temporarily
    char buffer[LENGTH + 1];

    // read strings from file 1 at a time, until the end of the file is reached
    while (fscanf(file, "%s", buffer) != EOF) {

        node *temp = malloc(sizeof(node));      // allocate memory for a new node
        if (temp == NULL) {
            printf("Error: not enough memory available.");
            fclose(file);
            return false;
        }

        // read a word from the opened fileusing the "string" conversion, counting as it loads
        fscanf(file, "%s", buffer);
        size();

        strcpy(temp->word, buffer);             // copy word into newly created temp node

        unsigned int index = hash(temp->word);  // obtain a hash value for the given word

        if (table[index] == NULL) {         // check if this is the first element in the list or not
            temp->next = NULL;              // if true, point temp node to NULL
        }
        else {
            temp->next = table[index];      // else, point temp to the first node of the linked list
        }

        table[index] = temp;                // point the header back to temp
    }




    // load function test
    for (int i = 0; i < N; i++)    // Check all "buckets"
    {
        node *cursor = table[i];   // Set cursor to head of list
        while (cursor != NULL)     // Check the list until end
        {
            printf("Hash %i: %s\n", i, cursor->word);
            cursor = cursor->next;     // Advance cursor to next node
        }
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
    // iterate through every hash value inside the hash table
    for (int i = 0; i < N; i++) {

        node *cursor = table[i];        // point cursor to head of linked list
        node *temp = cursor;            // create temporary node to allow freeing of memory

        while (cursor != NULL) {        // traverse the list until end
            cursor = cursor->next;  // advance cursor to next node
            free(temp);             // free the previous element
            temp = cursor;          // advance temp to the next node
        }

        // successfully unloaded dictionary
        return true;
    }

    // else unsuccessful
    return false;
}




