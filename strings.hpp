/**
 * \file
 * \brief Contains functions to work with stings
*/


/**
 * \brief Counts length of the string
 * \param [in] str String to count
 * \return Length of the string
*/
int strlen(const char str[]);


/**
 * \brief Compares two strings
 * \param [in] str1 The first string to compare
 * \param [in] str2 The second string to compare
 * \return if str1 > str2 returns 1, if str1 < str2 returns -1, otherwise returns 0
*/
int strcmp(const char str1[], const char str2[]);


/**
 * \brief Finds specific symbol in string
 * \param [in] str String for search
 * \param [in] chr Symbol to find
 * \return Index of symbol if found or -1
*/
int strchr(const char str[], char chr);


/**
 * \brief Copies content of one string to another
 * \param [out] copy The string in which we should copy
 * \param [in] origin The original string
*/ 
void strcpy(char copy[], const char origin[]);


/**
 * \brief Сoncatenates two strings
 * \param [out] str1 The second string will be added to the end of this string
 * \param [in] str2 This string will be added to the end of str1
*/
void strcat(char str1[], const char str2[]);


int strlen(const char str[]) {
    int len = 0;
    while (str[len] != '\0') 
        len++;
    
    return len;
}


int strcmp(const char str1[], const char str2[]) {
    for(int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] > str2[i]) return 1;
        if (str1[i] < str2[i]) return -1;
    }

    return 0;
}


int strchr(const char str[], char chr) {
    for(int i = 0; str[i] != '\0'; i++) {
        if (str[i] == chr)
            return i;
    }

    return -1;
}


void strcpy(char copy[], const char origin[]) {
    int i = 0;
    for(; origin[i] != '\0'; i++)
        copy[i] = origin[i];
    
    copy[i] = '\0';
}


void strcat(char str1[], const char str2[]) {
    int len1 = strlen(str1), i = 0;
    for(; str2[i] != '\0'; i++)
        str1[len1 + i] = str2[i];
    
    str1[len1 + i] = '\0';
}
