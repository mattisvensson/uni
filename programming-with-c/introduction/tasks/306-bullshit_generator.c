// Generate 'bullshit sentences'
// TO DO 1: In lines v=, n=, a=, ... rand%12? Why always 12?   --> Becaus there are 12 elements in the array
// TO DO 2: Create more complex sentences e.g. by using more adjectives together or by concatenating several phrases.
// TO DO 3: Generalize the 'You should' by allowing other random introductions, e.g. "we have to", "our company must"
// TO DO 4: Don't write the output to the screen but copy the whole phrase into a separate string (without using library functions)
// Source of words see: http://dack.com/web/bullshit.html
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char verbs[][20] = { "benchmark", "exploit", "facilitate", "generate", "implement", "leverage", "maximize",
        "mesh", "monetize", "optimize", "orchestrate", "redefine" };
    char nouns[][20] = { "action-items", "applications", "bandwidth", "communities", "e-business", "experiences", 
        "infrastructures", "methodologies", "partnerships", "synergies", "solutions", "technologies" };
    char adjectives[][20] = { "bleeding-edge", "collaborative", "cross-platform", "distributed", "efficient",
        "global", "holistic", "innovative", "mission-critical", "next-generation", "out-of-the-box", "user-centric" };
    char conjunctions[][20] = { "but", "and", "or", "so", "because", "although", "since", "unless", "while", "whereas", "if", "when" };
    char who[][20] = { "You should", "We have to", "Our company must", "It is necessary to", "It is important to", "It is crucial to", "It is vital to", "It is essential to", "It is imperative to", "It is required to", "It is obligatory to", "It is mandatory to" };
    int number, v1, v2, n1, n2, a1, a2, c, w;

    srand(time(0));
    printf("How much bullshit do you need?");
    scanf("%d", &number);

    while (number > 0) {
        v1 = rand() % 12;
        v2 = rand() % 12;
        n1 = rand() % 12;
        n2 = rand() % 12;
        a1 = rand() % 12;
        a2 = rand() % 12;
        c = rand() % 12;
        w = rand() % 12;

        char str[255];
        
        str[0] = 0;
        int len = 0;
        int i = 0;

        while(who[w][i] != 0) {
          str[len++] = who[w][i++];
        }

        str[len++] = ' ';

        i = 0;
        while(verbs[v1][i] != 0) {
          str[len++] = verbs[v1][i++];
        }

        str[len] = 0;

        printf("Your boss says: %s\n", str);
        number--;
    }

    return 0;
}