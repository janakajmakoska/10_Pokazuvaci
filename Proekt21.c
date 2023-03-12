#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to shuffle the deck
void shuffle_deck(char (*deck)[3], int num_cards) {
    srand(time(NULL));
    for (int i = 0; i < num_cards; i++) {
        int j = rand() % num_cards;
        char temp[3];
        strcpy(temp, deck[i]);
        strcpy(deck[i], deck[j]);
        strcpy(deck[j], temp);
    }
}

// function to print a hand
void print_hand(char (*hand)[3], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        printf("%s ", hand[i]);
    }
    printf("\n");
}

// function to determine the type of hand
char* get_hand_type(char (*hand)[3], int num_cards) {
    char ranks[num_cards][2];
    char suits[num_cards];
    for (int i = 0; i < num_cards; i++) {
        strncpy(ranks[i], hand[i], 1);
        ranks[i][1] = '\0';
        suits[i] = hand[i][1];
    }
    int pairs[num_cards];
    memset(pairs, 0, sizeof(pairs));
    int num_pairs = 0;
    int triples[num_cards];
    memset(triples, 0, sizeof(triples));
    int num_triples = 0;
    int fours[num_cards];
    memset(fours, 0, sizeof(fours));
    int num_fours = 0;
    int flush = 1;
    int straight = 1;
    for (int i = 0; i < num_cards - 1; i++) {
        if (suits[i] != suits[i+1]) {
            flush = 0;
        }
        if (strcmp(ranks[i], "2") != 0 && strcmp(ranks[i+1], "2") != 0 && strcmp(ranks[i], "A") != 0 && strcmp(ranks[i+1], "A") != 0) {
            if (atoi(ranks[i]) + 1 != atoi(ranks[i+1])) {
                straight = 0;
            }
        }
    }
    if (strcmp(ranks[num_cards-2], "2") != 0 || strcmp(ranks[num_cards-1], "A") != 0) {
        if (atoi(ranks[num_cards-2]) + 1 != atoi(ranks[num_cards-1])) {
            straight = 0;
        }
    }
    for (int i = 0; i < num_cards; i++) {
        int count = 0;
        for (int j = 0; j < num_cards; j++) {
            if (strcmp(ranks[i], ranks[j]) == 0) {
                count++;
            }
        }
        if (count == 2) {
            pairs[num_pairs++] = i;
        }
        if (count == 3) {
            triples[num_triples++] = i;
        }
        if (count == 4) {
            fours[num_fours++] = i;
        }
    }
    if (flush && straight) {
        return "kenta";
    } else if (num_fours > 0) {
        return "cetiri od isto";
    } else if (num_triples > 0 && num_pairs > 0) {
        return "full house";
    } else if (flush) {
        return "boja";
    } else if (straight) {
        return "skala";
    } else if (num_triples > 0) {
        return "triling";
    } else if (num_pairs > 1) {
        return "dva para";
    } else if (num_pairs > 0) {
        return "par";
    } else {
        return "nisto";
    }
}

int main() {
    char deck[52][3] = {"2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD", "AD",
                        "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC", "AC",
                        "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH", "AH",
                        "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS", "AS"};
    shuffle_deck(deck, 52);
    char hand1[5][3];
    char hand2[5][3];
    for (int i = 0; i < 5; i++) {
        strcpy(hand1[i], deck[i]);
        strcpy(hand2[i], deck[i+5]);
    }
    printf("Raka 1: ");
    print_hand(hand1, 5);
    printf("Tip na raka: %s\n", get_hand_type(hand1, 5));
    printf("\nRaka 2: ");
    print_hand(hand2, 5);
    printf("Tip na raka: %s\n", get_hand_type(hand2, 5));
    char* hand1_type = get_hand_type(hand1, 5);
    char* hand2_type = get_hand_type(hand2, 5);
    if (strcmp(hand1_type, hand2_type) == 0) {
        printf("Nereseno.\n");
    } else if (strcmp(hand1_type, "nisto") == 0) {
        printf("Raka 2 pobeduva.\n");
    } else if (strcmp(hand2_type, "nisto") == 0) {
        printf("Raka 1 pobeduva.\n");
    } else if (strcmp(hand1_type, "kenta") == 0) {
        printf("Raka 1 pobeduva.\n");
    } else if (strcmp(hand2_type, "kenta") == 0) {
        printf("Raka 2 pobeduva.\n");
    } else if (strcmp(hand1_type, "cetiri od isto") == 0) {
        printf("Raka 1 pobeduva.\n");
    } else if (strcmp(hand2_type, "cetiri od isto") == 0) {
        printf("Raka 2 pobeduva.\n");
    } else if (strcmp(hand1_type, "boja") == 0) {
        printf("Raka 1 pobeduva.\n");
    } else if (strcmp(hand2_type, "boja") == 0) {
        printf("Raka 2 pobeduva.\n");
    } else if (strcmp(hand1_type, "triling") == 0) {
        } else if (strcmp(hand2_type, "triling") == 0) {
        printf("Raka 2 pobeduva.\n");
    } else if (strcmp(hand1_type, "dva para") == 0 && strcmp(hand2_type, "par") == 0) {
        printf("Raka 1 pobeduva.\n");
    } else if (strcmp(hand2_type, "dva para") == 0 && strcmp(hand1_type, "par") == 0) {
        printf("Raka 2 pobeduva.\n");
    } else if (strcmp(hand1_type, "dva para") == 0 && strcmp(hand2_type, "nisto") == 0) {
        printf("Raka 1 pobeduva.\n");
    } else if (strcmp(hand2_type, "dva para") == 0 && strcmp(hand1_type, "nisto") == 0) {
        printf("Raka 2 pobeduva.\n");
    } else if (strcmp(hand1_type, "par") == 0 && strcmp(hand2_type, "nisto") == 0) {
        printf("Raka 1 pobeduva.\n");
    } else if (strcmp(hand2_type, "par") == 0 && strcmp(hand1_type, "nisto") == 0) {
        printf("Raka 2 pobeduva.\n");
    } else {
        printf("Nepoznat sluchaj.\n");
    }
    return 0;
}
