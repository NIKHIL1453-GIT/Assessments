/*Create an application that can perform all string related operations*/ 

/*START*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Auxilary function declaration*/
void reverseString(char str[]);
void concatenateStrings(char str1[], char str2[]);
void checkPalindrome(char str[]);
void copyString(char source[], char destination[]);
void stringLength(char str[]);
void charFrequency(char str[], char ch);
void countVowelsConsonants(char str[]);
void countSpacesDigits(char str[]);


/*Main function declaration*/
int main() {
    char str1[100], str2[100], choice;
    int option;

    do {
    	/*Menu declaration*/
        printf("\nMenu Driven String Operations\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenation\n");
        printf("3. Palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Length of the string\n");
        printf("6. Frequency of character in a string\n");
        printf("7. Find number of vowels and consonants\n");
        printf("8. Find number of blank spaces and digits\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar();
        
        
		/*choice declaration*/
        switch (option) {
            case 1:
                printf("Enter a string: ");
                gets(str1);
                reverseString(str1);
                break;
            case 2:
                printf("Enter first string: ");
                gets(str1);
                printf("Enter second string: ");
                gets(str2);
                concatenateStrings(str1, str2);
                break;
            case 3:
                printf("Enter a string: ");
                gets(str1);
                checkPalindrome(str1);
                break;
            case 4:
                printf("Enter a string to copy: ");
                gets(str1);
                copyString(str1, str2);
                printf("Copied string: %s\n", str2);
                break;
            case 5:
                printf("Enter a string: ");
                gets(str1);
                stringLength(str1);
                break;
            case 6:
                printf("Enter a string: ");
                gets(str1);
                char ch;
                printf("Enter character to count frequency: ");
                scanf("%c", &ch);
                charFrequency(str1, ch);
                break;
            case 7:
                printf("Enter a string: ");
                gets(str1);
                countVowelsConsonants(str1);
                break;
            case 8:
                printf("Enter a string: ");
                gets(str1);
                countSpacesDigits(str1);
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
        getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the application!\n"); /*proper message after using application*/
    return 0;
}


/*Auxilary functions program*/
void reverseString(char str[]) {
    int len = strlen(str),i;
    printf("Reversed string: ");
    for ( i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void concatenateStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
}

void checkPalindrome(char str[]) {
    int len = strlen(str),i;
    int flag = 1;
    for ( i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

void copyString(char source[], char destination[]) {
    strcpy(destination, source);
}

void stringLength(char str[]) {
    printf("Length of string: %lu\n", strlen(str));
}

void charFrequency(char str[], char ch) {
    int count = 0,i;
    for ( i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            count++;
    }
    printf("Frequency of '%c': %d\n", ch, count);
}

void countVowelsConsonants(char str[]) {
    int vowels = 0, consonants = 0,i;
    for ( i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}

void countSpacesDigits(char str[]) {
    int spaces = 0, digits = 0,i;
    for ( i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            spaces++;
        else if (isdigit(str[i]))
            digits++;
    }
    printf("Spaces: %d, Digits: %d\n", spaces, digits);
}
/*END*/
