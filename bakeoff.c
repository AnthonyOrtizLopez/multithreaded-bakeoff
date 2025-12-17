#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

// defining colors
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"

struct Kitchen {
        int mixers;
        int pantry;
        int fridge;
        int bowls;
        int spoons;
        int oven;
};

struct Ramsy {
        int baker;
        int active;
};

// Shared kitchen
struct Kitchen kitchen;

// ramsy struct to identify baker to be ramsied
struct Ramsy ramsy;

// POSIX semaphores
sem_t pantrySem;
sem_t fridgeSem;
sem_t mixerSem;
sem_t bowlSem;
sem_t spoonSem;
sem_t ovenSem;

// Pantry ingredients
void getFlour(char *color) {
        sem_wait(&pantrySem);
        printf("%sGoing to pantry for flour%s\n", color, COLOR_RESET);
        sem_post(&pantrySem);
}

void getSugar(char *color) {
        sem_wait(&pantrySem);
        printf("%sGoing to pantry for sugar%s\n", color, COLOR_RESET);
        sem_post(&pantrySem);
}

void getYeast(char *color) {
        sem_wait(&pantrySem);
        printf("%sGoing to pantry for yeast%s\n", color, COLOR_RESET);
        sem_post(&pantrySem);
}

void getBakingSoda(char *color) {
        sem_wait(&pantrySem);
        printf("%sGoing to pantry for baking Soda%s\n", color, COLOR_RESET);
        sem_post(&pantrySem);
}

void getSalt(char *color) {
        sem_wait(&pantrySem);
        printf("%sGoing to pantry for salt%s\n", color, COLOR_RESET);
        sem_post(&pantrySem);
}

void getCinnamon(char *color) {
        sem_wait(&pantrySem);
        printf("%sGoing to pantry for cinnamon%s\n", color, COLOR_RESET);
        sem_post(&pantrySem);
}

// Fridge ingredients
void getEggs(char *color) {
        sem_wait(&fridgeSem);
        printf("%sGoing to fridge for eggs%s\n", color, COLOR_RESET);
        sem_post(&fridgeSem);
}

void getMilk(char *color) {
        sem_wait(&fridgeSem);
        printf("%sGoing to fridge for milk%s\n", color, COLOR_RESET);
        sem_post(&fridgeSem);
}

void getButter(char *color) {
        sem_wait(&fridgeSem);
        printf("%sGoing to fridge for butter%s\n", color, COLOR_RESET);
        sem_post(&fridgeSem);
}

void mix(char *color) {
        // get tools
        sem_wait(&bowlSem);
        printf("%sGetting a bowl%s\n", color, COLOR_RESET);

        sem_wait(&spoonSem);
        printf("%sGetting a spoon%s\n", color, COLOR_RESET);

        sem_wait(&mixerSem);
        printf("%sGetting a mixer%s\n", color, COLOR_RESET);

        printf("%sMixing ingredients together%s\n", color, COLOR_RESET);

        // returned tools
        sem_post(&mixerSem);
        sem_post(&spoonSem);
        sem_post(&bowlSem);

        printf("%sReturned mixer, spoon, and bowl%s\n", color, COLOR_RESET);
}

void makeCookies(char *color) {
        printf("%sStarting cookies recipe%s\n", color, COLOR_RESET);
        getFlour(color);
        getSugar(color);
        getMilk(color);
        getButter(color);
        printf("%sFinished gathering ingredients for cookies%s\n", color, COLOR_RESET);

        // baking time
        mix(color);
        sem_wait(&ovenSem);
        printf("%sPutting cookie ingredients in the oven%s\n", color, COLOR_RESET);
        sem_post(&ovenSem);
        printf("%sTaking cookies out of oven%s\n", color, COLOR_RESET);
        printf("%sFinished baking cookies%s\n", color, COLOR_RESET);
}

void makePancakes(char *color) {
        printf("%sStarting pancakes recipe%s\n", color, COLOR_RESET);
        getFlour(color);
        getSugar(color);
        getBakingSoda(color);
        getSalt(color);
        getEggs(color);
        getMilk(color);
        getButter(color);
        printf("%sFinished gathering ingredients for pancakes%s\n", color, COLOR_RESET);

        // baking time
        mix(color);
        sem_wait(&ovenSem);
        printf("%sPutting pancake ingredients in the oven%s\n", color, COLOR_RESET);
        sem_post(&ovenSem);
        printf("%sTaking pancakes out of oven%s\n", color, COLOR_RESET);
        printf("%sFinished baking pancakes%s\n", color, COLOR_RESET);
}

void makeHomemadePizzaDough(char *color) {
        printf("%sStarting homemade pizza Dough recipe%s\n", color, COLOR_RESET);
        getYeast(color);
        getSugar(color);
        getSalt(color);
        printf("%sFinished gathering ingredients for homemade pizza dough%s\n", color, COLOR_RESET);

        mix(color);
        sem_wait(&ovenSem);
        printf("%sPutting homemade pizza dough ingredients in the oven%s\n", color, COLOR_RESET);
        sem_post(&ovenSem);
        printf("%sTaking homemade pizza dough out of oven%s\n", color, COLOR_RESET);
        printf("%sFinished baking homemade pizza dough%s\n", color, COLOR_RESET);
}

void makeSoftPretzels(char *color) {
        printf("%sStarting soft pretzels recipe%s\n", color, COLOR_RESET);
        getFlour(color);
        getSugar(color);
        getSalt(color);
        getYeast(color);
        getBakingSoda(color);
        getEggs(color);
        printf("%sFinished gathering ingredients for soft pretzels%s\n", color, COLOR_RESET);

        mix(color);
        sem_wait(&ovenSem);
        printf("%sPutting soft pretzels ingredients in the oven%s\n", color, COLOR_RESET);
        sem_post(&ovenSem);
        printf("%sTaking soft pretzels out of oven%s\n", color, COLOR_RESET);
        printf("%sFinished baking soft pretzels%s\n", color, COLOR_RESET);
}

void makeCinnamonRolls(char *color) {
        printf("%sStarting cinnamon rolls recipe%s\n", color, COLOR_RESET);
        getFlour(color);
        getSugar(color);
        getSalt(color);
        getButter(color);
        getEggs(color);
        getCinnamon(color);
        printf("%sFinished gathering ingredients for cinnamon rolls%s\n", color, COLOR_RESET);

        mix(color);
        sem_wait(&ovenSem);
        printf("%sPutting cinnamon roll ingredients in the oven%s\n", color, COLOR_RESET);
        sem_post(&ovenSem);
        printf("%sTaking cinnamon rolls out of oven%s\n", color, COLOR_RESET);
        printf("%sFinished baking cinnamon Rolls%s\n", color, COLOR_RESET);
}

// This is where each baker thread runs
void* bakerThread(void* arg)
{
        int id = *(int*)arg;
        int ramsiedOnce = 0;
        char *color;

        if ((id % 6) == 1) {
                color = COLOR_RED;
        } else if ((id % 6) == 2) {
                color = COLOR_GREEN;
        } else if ((id % 6) == 3) {
                color = COLOR_YELLOW;
        } else if ((id % 6) == 4) {
                color = COLOR_BLUE;
        } else if ((id % 6) == 5) {
                color = COLOR_MAGENTA;
        } else {
                color = COLOR_CYAN;
}


        printf("%sBaker is ready to bake%s\n", color, COLOR_RESET);

        makeCookies(color);
        makePancakes(color);
        makeHomemadePizzaDough(color);
        makeSoftPretzels(color);

        // Where ramsy could happen
        if (ramsy.active && !ramsiedOnce && id == ramsy.baker) {
                // first attempt
                printf("%sStarting cinnamon rolls recipe%s\n", color, COLOR_RESET);
                getFlour(color);
                getSugar(color);
                getSalt(color);
                getButter(color);
                getEggs(color);
                getCinnamon(color);
                printf("%sYou have been RAMSIED!!!! Go back and get the same ingredients lil man%s\n", color, COLOR_RESET);
                // Mark that this baker has been ramsied
                ramsiedOnce = 1;

                // Restart the same recipe :)
                makeCinnamonRolls(color);
        } else {
                // Normal case, doing it once
                makeCinnamonRolls(color);
        }

        printf("%sFinished all recipes!!!!%s\n", color, COLOR_RESET);
        return NULL;
}

int main() {
        char userInput[100];
        int num_bakers;
        int prob;
        srand(time(NULL));
        kitchen.mixers = 2;
        kitchen.pantry = 1;
        kitchen.fridge = 2;
        kitchen.bowls = 3;
        kitchen.spoons = 5;
        kitchen.oven = 1;

        // intialize semaphores
        sem_init(&pantrySem, 0, kitchen.pantry);

        if (sem_init(&fridgeSem, 0, kitchen.fridge) != 0) {
                printf("Failed to initialize fridge semaphore\n");
                return 1;
        }

        if (sem_init(&mixerSem, 0, kitchen.mixers) != 0) {
                printf("Failed to initialize mixer semaphore\n");
                return 1;
        }

        if (sem_init(&bowlSem, 0, kitchen.bowls) != 0) {
                printf("Failed to initialize bowl semaphores\n");
                return 1;
        }

        if (sem_init(&spoonSem, 0, kitchen.spoons) != 0) {
                printf("Failed to initialize spoon semaphore\n");
                return 1;
        }

        if (sem_init(&ovenSem, 0, kitchen.oven) != 0) {
                printf("Failed to initialize oven semaphore\n");
                return 1;
        }

        printf("Enter number of bakers: ");

        // Read user input as a line
        if (fgets(userInput, sizeof(userInput), stdin) == NULL) {
                printf("Error reading input.\n");
                return 1;
        }

        // Convert the string to an int
        num_bakers = atoi(userInput);

        // Check that the number of bakers is valid
        if (num_bakers <= 0) {
                printf("Invalid number of bakers, must be at least 1.\n");
                return 1;
        }

        // 35% chance that a baker gets ramsied this run
        prob = rand() % 100;
        if (prob < 35) {
                ramsy.active = 1;
        } else {
                ramsy.active = 0;
        }

        if (ramsy.active) {
                // Pick a baker from 1 to num_bakers
                ramsy.baker = (rand() % num_bakers) + 1;
        } else {
                ramsy.baker = -1;       // no ramsy
        }


        pthread_t threadIds[num_bakers];        // Array to keep the num of bakers
        int bakerIds[num_bakers];
        int threadStatus;

        // Create one thread per baker
        for (int i = 0; i < num_bakers; i++) {
                bakerIds[i] = i + 1;  // Baker IDs

                threadStatus = pthread_create(&threadIds[i],
                                              NULL,
                                              bakerThread,
                                              &bakerIds[i]);

                if (threadStatus != 0) {
                        printf("Thread creation error %d\n", threadStatus);
                        return 1;
                }
        }

        // Wait for all bakers to finish before main exits
        for (int i = 0; i < num_bakers; i++) {
                pthread_join(threadIds[i], NULL);
        }

        sem_destroy(&pantrySem);
        sem_destroy(&fridgeSem);
        sem_destroy(&mixerSem);
        sem_destroy(&bowlSem);
        sem_destroy(&spoonSem);
        sem_destroy(&ovenSem);

        printf("All bakers have finished baking all recipes!\n");

        return 0;
}
