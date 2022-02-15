#include <stdio.h>
#include <string.h>
#include <math.h>

int bin_to_dec(long long);
long long dec_to_bin(int);

int main() {
    char opt1[] = "bin2dec", opt2[] = "dec2bin";
    char ch[7];

    printf("Choose between 'bin2dec' or 'dec2bin': ");
    scanf("%s", ch);

    // bin2dec
    if (strcmp(ch, opt1) == 0) {
        long long n;

        printf("Enter a binary number: ");
        scanf("%lld", &n);
        printf("Output: %d", bin_to_dec(n));

    // dec2bin
    } else if (strcmp(ch, opt2) == 0){
        int n;

        printf("Enter a decimal number: ");
        scanf("%d", &n);
        printf("Output: %lld", dec_to_bin(n));

    // something invalid
    } else {
        printf("Invalid option.");
    }

    return 0;
}

// convert binary numbers to decimal
int bin_to_dec(long long n) {
    int dec = 0, i = 0, rem;

    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }

    return dec;
}

// convert decimal numbers to binary
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