#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(char str[], int start, int end)
{
    if (start == end)
        return true;
    else if (str[start] != str[end])
        return false;
    else if (start < end)
        return isPalindrome(str, start + 1, end - 1);

    return true;
}

int main()
{
    char ch[100];
    gets(ch);

    if(isPalindrome(ch, 0, strlen(ch) - 1))
    printf("Palindrome String.\n");
    else
    printf("Not Palindrome String.\n");

    return 0;
}