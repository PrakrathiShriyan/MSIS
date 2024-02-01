/*A simple program to generate a Random number : 
(seed initialised to a number, in this case seed 
initialised to current time)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
 // Seed the random number generator with the current 
time
 srand(time(NULL)); // Current time is taken as the 
seed; 
 // Generate a random number and print it
 int randomNumber = rand();
 printf("Random Number: %d\n", randomNumber);
 return 0;
}