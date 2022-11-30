#include<cs50.h>
#include <stdio.h>

int main(void)
{
    string response = get_string("Are you gay? ");

    switch(response)
    case 'yes';
    printf("I knew you were gay/n");

    case 'no';
    printf("Liar, you're mega gay/n");

    default
    printf("Definitely gay/n");
}