/* A simple card counting application.
 * Terminates if the user types 'X'.
 */
#include <stdio.h>
#include <stdlib.h>

/* Prompts the user for input and puts it in the given buffer.
 * Input is truncated to the first two characters.
 *
 * card_name: buffer where result is stored
 */
void get_card_name(char *card_name)
{
    puts("Enter the card name: ");
    scanf("%2s", card_name);
}

/* Takes the input char array and returns the card's value.
 *
 * card_name: input string of card name
 *
 * returns: value of the card, or -1 if invalid input
 */
int get_card_value(char *card_name)
{
    int val;
    switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            return 10;
        case 'A':
            return 11;
        case 'X':
            return 0;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)) {
                return -1;
            }
            return val;
    }
}

/* Perform one iteration of the main program loop.
 * (Prompt the user to enter a card and process the response.)
 *
 * card_name: the char array that stores the current card name
 * count: the current card counter
 */
void run_card_loop(char *card_name, int *count)
{
    int val;
    get_card_name(card_name);
    val = get_card_value(card_name);
    if (val == -1) {
        puts("I don't understand that value!");
    } else if ((val > 2) && (val < 7)) {
        (*count)++;
    } else if (val == 10) {
        (*count)--;
    }
    printf("Current count: %i\n", *count);
}

int main()
{
    char card_name[3];
    int count = 0;
    while (card_name[0] != 'X') {
        run_card_loop(card_name, &count);
    }
    return 0;
}
