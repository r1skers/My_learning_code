#include"bm.h"


bool is_opening_bracket(char c)
{
    return strchr(open_brackets, c) != NULL;
}
char* filter(char* input)
{
    char* filtered_string = (char*)malloc(strlen(input)+1);
    if(!filtered_string)
    {
        return NULL; // Memory allocation failed
    }
    int j = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(is_opening_bracket(input[i]))
        {
            filtered_string[j++] = input[i];
        }
    }
    filtered_string[j] = '\0'; // Null-terminate the filtered string
    return filtered_string;
}