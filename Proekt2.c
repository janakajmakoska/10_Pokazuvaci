#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_HAND_CARDS 5

int main(void)
{
    int in_hand[NUM_HAND_CARDS];
    int card, rank, suit;
    char *rank_code[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10",
                         "J", "Q", "K", "A"};
    char *suit_code[] = {"C", "D", "H", "S"};
    bool have_pair = false;
    bool have_two_pair = false;
    bool have_triple = false;
    bool have_four = false;
    bool have_flush = false;
    bool have_straight = false;
    int pairs = 0;
    int triples = 0;
    int four = 0;

    srand((unsigned) time(NULL));

    printf("Mashing cards...\n");

    for (int i = 0; i < NUM_HAND_CARDS; i++) {
        do {
            card = rand() % NUM_CARDS;
        } while (in_hand[card] == 1);
        in_hand[card] = 1;
        rank = card % NUM_RANKS;
        suit = card / NUM_RANKS;
        printf("%s%s ", rank_code[rank], suit_code[suit]);
    }

    printf("\n\n");

    // check for pairs, triples and four of a kind
    for (int i = 0; i < NUM_RANKS; i++) {
        int count = 0;
        for (int j = 0; j < NUM_HAND_CARDS; j++) {
            if (in_hand[i + j * NUM_RANKS] == 1) {
                count++;
            }
        }
        if (count == 2) {
            pairs++;
            have_pair = true;
        } else if (count == 3) {
            triples++;
            have_triple = true;
        } else if (count == 4) {
            four++;
            have_four = true;
        }
    }

    // check for two pairs
    if (pairs == 2) {
        have_two_pair = true;
    }

    // check for flush
    for (int i = 0; i < NUM_SUITS; i++) {
        int count = 0;
        for (int j = 0; j < NUM_HAND_CARDS; j++) {
            if (in_hand[NUM_RANKS * i + j] == 1) {
                count++;
            }
        }
        if (count == NUM_HAND_CARDS) {
            have_flush = true;
            break;
        }
    }

    // check for straight
    for (int i = 0; i < NUM_RANKS - NUM_HAND_CARDS + 1; i++) {
        int count = 0;
        for (int j = 0; j < NUM_HAND_CARDS; j++) {
            if (in_hand[i + j * NUM_RANKS] == 1) {
                count++;
            }
        }
        if (count == NUM_HAND_CARDS) {
            have_straight = true;
            break;
        }
    }

    // print results
    if (have_pair) {
        printf("You have a pair!\n");
    }
    if (have_two_pair) {
        printf("You have two pairs!\n");
    }
    if (have_triple) {
        printf("You have a triple!\n");
    }
        
    if (have_four) {
        printf("You have four of a kind!\n");
    }
    if (have_flush) {
        printf("You have a flush!\n");
    }
    if (have_straight) {
        printf("You have a straight!\n");
    }

    // print default message if no winning hand
    if (!have_pair && !have_two_pair && !have_triple && !have_four &&
        !have_flush && !have_straight) {
        printf("Sorry, you didn't win this time.\n");
    }

    return 0;
}

