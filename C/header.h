//upper to lower
char upper_to_lower(char ch);
//area of circle
float area_of_circle(float radius);
//celsius to fahrenheit
float C_to_F(float celsius);
//no of char btw two char eg: A and E => 3
int no_btw(char ch1, char ch2);
//number even or odd
unsigned int odd_even(int num);
//leap year or not
int leap_year(int year);
//power of 2^N using left shift operator
int power_of2(int raise);
//check if given input is integer or character
int char_or_int(char ch);
//generate two random no and sum of it, use rand() from stdlib.h
unsigned int add_rand(unsigned int x, unsigned int y);
//Enter 5 digit number and find the sum of its digits
unsigned int sum_digits(unsigned int input);
//reverse a number
unsigned int reverse(unsigned int input);
//count digits of occurance 
unsigned int occurance_digits(unsigned int input, unsigned digit);
//given number is palindrome
unsigned int palindrome_or_not(unsigned int input);
//generate the first 'N' prime numbers
unsigned int N_prime_number(unsigned int input);
//display and sum of series 1+11+111+..+111up to n, given input n; n=4, 1+11+111+1111
//A number is called an Armstrong number if the sum of the cubes of the digits of the
// number is equal to the number. For example 153 = 1^3 + 5^3 + 3^3. Write a C
// program that asks the user to enter a number and returns if it is Armstrong or not.
unsigned int check_if_armstrong(unsigned int num);