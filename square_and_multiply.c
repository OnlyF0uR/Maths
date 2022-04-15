// Based of off https://www.youtube.com/watch?v=cbGB__V8MNk
// Compile: gcc square_and_multiply.c -o build
// Run: ./build
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check the bin_and_dec.c file
long long dec_to_bin(int n) {
    long long bin = 0;
    int rem, i = 1;

    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

// Little function for getting the character length of a long long
int get_long_length(long long value){
    int l = !value;
    while(value) {
        l++; value /= 10;
    }
    return l;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
      fprintf(stderr, "Usage: %s <Base> <Square> <Modulo>\n", argv[0]);
      exit(1);
    }

    int exp = strtol(argv[2], (char **)NULL, 10);
    long long bin_exp = dec_to_bin(exp);

    // Get the binary exponent as cstring
    char *str_bin_exp = malloc((get_long_length(bin_exp) + 1) * sizeof(char));
    if (str_bin_exp == NULL) {
        fprintf(stderr, "Could not allocate memory for binary exponent cstring.");
        exit(1);
    }
    sprintf(str_bin_exp, "%lld", bin_exp);

    // We know that if we encounter a 0 we must SQUARE
    // If we however encounter a 1 we must SQUARE and MULTIPLY afterwards
    char *ptr = str_bin_exp;
    int i = 0;

    // Define the base
    int b = strtol(argv[1], (char **)NULL, 10);
    // Copy the base since this is our start value
    int n = b;
    // Define the module param
    int mod = strtol(argv[3], (char **)NULL, 10);
    // Loop through the cstring
    while(*ptr != '\0') {
        // Skip the first step   
        if (i > 0) {
            char s = *ptr;
            // Define the decimal digit
            int d = strtol(&s, (char **)NULL, 10);

            // Check if it's naught
            if (d == 0) {
                // If so we square
                printf("S");
                n = n*n % mod;
            } else { // Else it must be 1 (multiplication)
                printf("SM");
                // First square than multiply, bcs 1 = 0+1
                n = (n*n % mod)*b % mod;
            }
        }

        ptr++;
        i++;
    }

    printf("\nResult: %d\n", n);
    return 0;
}
