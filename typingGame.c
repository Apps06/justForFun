#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char w[15];

    printf("Enter a word (limit 15 chars): \n");
    scanf("%s", w);

    char q;
    printf("Press 'q' to start the time\n");
    scanf("%s", &q);

    if (q == 'q')
    {
        printf("Type this word: %s", w);
        time_t start = time(NULL);
        char nw[15];
        scanf("%s", nw);

        time_t end = time(NULL);
        float sec = (float)(end - start) / CLOCKS_PER_SEC;
        printf("Time: %lf", sec);
    }
    return 0;
}

// take the string from the user, measure the time when the user starts the time and then display the time
/**
time measured when space ba clicked

 */

//not yet completed, will be soon
