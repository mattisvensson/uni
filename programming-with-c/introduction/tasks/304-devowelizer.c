/* devowelizer / revowelizer 
 TO DO 1: Extend the program such that it replaces all vowels in the text with other vowels.
 TO DO 2: Extend the program such that the replacement vowel is chosen randomly.
          Hint: List the vowels in an additional array ...
                Use rand() to generate random numbers
 TO DO 3: Modify the program such that it removes all vowels (and shortens the text accordingly)
 TO DO 4 (optional): Write an encryption/decryption program which encodes texts by defining
         in a table how each character shall be replaced by another one. 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void replace_vowels(char *txt) {
    char vowels[] = "aeiouAEIOU";
    int num_vowels = strlen(vowels);
    int i = 0;

    while (txt[i] != 0) {
        for (int j = 0; j < num_vowels; j++) {
            if (txt[i] == vowels[j]) {
                txt[i] = vowels[rand() % num_vowels];
                break;
            }
        }
        i++;
    }
}

void remove_vowels(char *txt) {
    char vowels[] = "aeiouAEIOU";
    int i = 0, j = 0;

    while (txt[i] != 0) {
        int is_vowel = 0;
        for (int k = 0; k < strlen(vowels); k++) {
            if (txt[i] == vowels[k]) {
                is_vowel = 1;
                break;
            }
        }
        if (!is_vowel) {
            txt[j++] = txt[i];
        }
        i++;
    }
    txt[j] = 0;
}

void encrypt_decrypt(char *txt, char *table) {
    int i = 0;
    while (txt[i] != 0) {
        txt[i] = table[(unsigned char)txt[i]];
        i++;
    }
}

int main() {
    char txt[1000];
    char table[256];
    int i;

    // Initialize the random number generator
    srand(time(NULL));

    printf("Please enter your text: ");
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = 0; // Remove newline character

    // Task 1 and 2: Replace vowels with random vowels
    replace_vowels(txt);
    printf("Text after replacing vowels: %s\n", txt);

    // Task 3: Remove vowels
    remove_vowels(txt);
    printf("Text after removing vowels: %s\n", txt);

    // Task 4: Encryption/Decryption
    // Initialize the table for encryption/decryption
    for (i = 0; i < 256; i++) {
        table[i] = (char)i;
    }
    // Example: Simple shift cipher (Caesar cipher)
    for (i = 'a'; i <= 'z'; i++) {
        table[i] = (i - 'a' + 3) % 26 + 'a';
    }
    for (i = 'A'; i <= 'Z'; i++) {
        table[i] = (i - 'A' + 3) % 26 + 'A';
    }

    encrypt_decrypt(txt, table);
    printf("Encrypted text: %s\n", txt);

    // Decrypt the text
    // Reverse the table for decryption
    char reverse_table[256];
    for (i = 0; i < 256; i++) {
        reverse_table[(unsigned char)table[i]] = (char)i;
    }
    encrypt_decrypt(txt, reverse_table);
    printf("Decrypted text: %s\n", txt);

    return 0;
}