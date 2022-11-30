#include<cs50.h>
#include <stdio.h>

int main(void)
{
    char ch = get_char("Are you gay? y/n: ");

    switch(ch)
    {
    case 'y':
    printf("I knew you were gay\n");
    break;

    case 'n':
    printf("Liar, you're mega gay\n");
    break;

    default:
    printf("Can't get out of this one, you're so gay\n");
    break;
    }
}