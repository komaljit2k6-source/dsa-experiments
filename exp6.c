#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

// Function Prototypes
void readStrings(char str[], char pat[], char rep[]);
int stringLength(char s[]);
int compareStrings(char str[], char pat[], int pos);
void replacePattern(char str[], char pat[], char rep[]);
int main() {
    char str[MAX], pat[MAX], rep[MAX];
    // Read strings
    readStrings(str, pat, rep);
    // Perform find and replace
    replacePattern(str, pat, rep);
    return 0;
}
// Function to read main string, pattern, and replacement
void readStrings(char str[], char pat[], char rep[]) {
    printf("Enter main string: ");
    fgets(str, MAX, stdin);
    str[stringLength(str)-1] = '\0'; // remove newline
    printf("Enter pattern string: ");
    fgets(pat, MAX, stdin);
    pat[stringLength(pat)-1] = '\0';
    printf("Enter replacement string: ");
    fgets(rep, MAX, stdin);
    rep[stringLength(rep)-1] = '\0';
}
// Function to find string length
int stringLength(char s[]) {
    int i = 0;
    while(s[i] != '\0') i++;
    return i;
}

// Function to compare pattern with substring of main string starting at pos
int compareStrings(char str[], char pat[], int pos) {
    int i = 0;
    while(pat[i] != '\0') {
        if(str[pos + i] != pat[i])
            return 0; // Not matching
        i++;
    }
    return 1; // Match found
}
// Function to replace pattern with replacement string
void replacePattern(char str[], char pat[], char rep[]) {
    char result[MAX];
    int i = 0, k = 0;
    int lenStr = stringLength(str);
    int lenPat = stringLength(pat);
    int lenRep = stringLength(rep);
    int found = 0;
    while(i < lenStr) {
        if(compareStrings(str, pat, i)) {
            // Copy replacement string
            for(int j = 0; j < lenRep; j++)
                result[k++] = rep[j];
            i += lenPat; // skip pattern in main string
            found = 1;
        } else {
            result[k++] = str[i++];
        }
    }
    result[k] = '\0';

    if(found)
        printf("\nAfter replacement: %s\n", result);
    else
        printf("\nPattern not found in the main string.\n");
}
