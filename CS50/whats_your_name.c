#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string response = get_string("What's your name? ");
    printf("Hello, %s, this is my second ever program in VSCode! (I lied, it's actually my third)\n", response);
}