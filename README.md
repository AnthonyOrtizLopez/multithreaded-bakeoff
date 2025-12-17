# Multithreaded-bakeoff
A multithreaded bake-off program in C using POSIX threads and semaphores to simulate bakers sharing resources.

## Overview
The program prompts the user for a number of bakers.
Each baker runs as its own thread and completes 5 recipes as quickly as possible while using shared resources.

## Table of contents
- Concepts used
- Resources
- Building/Running
- Example Output

## Concepts used
- POSIX threads
- Counting and binary semaphores
- Shared state using a struct
- Concurrency and nondeterministic execution
- Ramsied: 1 baker may be "Ramsied" and restarts on the current recipe

## Resources
- Pantry: 1
- Refrigerator: 2
- Mixers: 2
- Bowls: 3
- Spoons: 5
- Oven: 1

## Building and Running
- Windows/Linux/MacOS
- gcc bakeoff.c -o bakeoff
- ./bakeoff

## Example Output
Enter number of bakers: 4
Baker is ready to bake
Starting cookies recipe
...
Finished all recipes!!!!
All bakers have finished baking all recipes!
