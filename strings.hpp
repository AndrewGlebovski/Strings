/**
 * \file
 * \brief Contains functions to work with stings
*/

#include <stdio.h>
#include <stdlib.h>


/**
 * \brief Prints string
 * \param [in] str String to print
*/
void _puts(const char str[]);


void _fgets(char str[], int n, FILE *stream);


void _getline(char str[], int n);


/**
 * \brief Counts length of the string
 * \param [in] str String to count
 * \return Length of the string
*/
int _strlen(const char str[]);


/**
 * \brief Compares two strings
 * \param [in] str1 The first string to compare
 * \param [in] str2 The second string to compare
 * \return if str1 > str2 returns 1, if str1 < str2 returns -1, otherwise returns 0
*/
int _strcmp(const char str1[], const char str2[]);


/**
 * \brief Finds specific symbol in string
 * \param [in] str String for search
 * \param [in] chr Symbol to find
 * \return Index of symbol if found or -1
*/
int _strchr(const char str[], char chr);


/**
 * \brief Copies content of one string to another
 * \param [out] copy The string in which we should copy
 * \param [in] origin The original string
*/ 
void _strcpy(char copy[], const char origin[]);


void _strncpy(char copy[], const char origin[], int n);


/**
 * \brief Сoncatenates two strings
 * \param [out] str1 The second string will be added to the end of this string
 * \param [in] str2 This string will be added to the end of str1
*/
void _strcat(char str1[], const char str2[]);


void _strncat(char str1[], const char str2[], int n);


char *_strdup(const char str[]);




void _puts(const char str[]) {
    for(int i = 0; str[i] != '\0'; i++)
        putchar(str[i]);
    putchar('\n');
}


void _fgets(char str[], int n, FILE* stream) {
    int c = 0, i = 0;
    for(; (c = fgetc(stream)) != '\n' && c != EOF && i < n; i++)
        str[i] = (char) c;
    
    if (c == '\n')
        ungetc(c, stream);
    
    str[i] = '\0';
}


void _getline(char str[], int n) {
    int c = 0, i = 0;
    for(; (c = getc(stdin)) != '\n' && c != EOF && i < n; i++)
        str[i] = (char) c;
    
    if (c == '\n')
        str[i++] = (char) c;
    
    str[i] = '\0';
}


int _strlen(const char str[]) {
    int len = 0;
    while (str[len] != '\0') 
        len++;
    
    return len;
}


int _strcmp(const char str1[], const char str2[]) {
    for(int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] > str2[i]) return 1;
        if (str1[i] < str2[i]) return -1;
    }

    return 0;
}


int _strchr(const char str[], char chr) {
    for(int i = 0; str[i] != '\0'; i++)
        if (str[i] == chr) return i;

    return -1;
}


void _strcpy(char copy[], const char origin[]) {
    int i = 0, size = _strlen(copy);
    for(; origin[i] != '\0' && i < size; i++)
        copy[i] = origin[i];
    
    copy[i] = '\0';
}


void _strncpy(char copy[], const char origin[], int n) {
    int i = 0, size = _strlen(copy);
    for(; origin[i] != '\0' && i < size && i < n; i++)
        copy[i] = origin[i];
    
    copy[i] = '\0';
}


void _strcat(char str1[], const char str2[]) {
    int len1 = _strlen(str1), i = 0;
    for(; str2[i] != '\0'; i++)
        str1[len1 + i] = str2[i];
    
    str1[len1 + i] = '\0';
}


void _strncat(char str1[], const char str2[], int n) {
    int len1 = _strlen(str1), i = 0;
    for(; str2[i] != '\0' && i < n; i++)
        str1[len1 + i] = str2[i];
    
    str1[len1 + i] = '\0';
}


char *_strdup(const char str[]) {
    int len = _strlen(str);
    char *dup = (char *) malloc(len + 1);

    for(int i = 0; str[i] != '\0'; i++)
        dup[i] = str[i];
    
    dup[len] = '\0';

    return dup;
}
