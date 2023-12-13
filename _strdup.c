#include "main.h"

/*
 * str1- this is the string to be copied
 * return- the pointer to the string
 * 
 */

char *_strdup(const char *str1){
	if (str1 == NULL){
	return (NULL);
	}
//calculate length of string
size_t length = strlen(str1);
char *duplicate=(char*) malloc ((length+1) *sizeof (char));{
if (duplicate !=  NULL)
		strcpy(duplicate, str1);
	}
void free_string (char *str1){
free (duplicate);}//free allocated memory
return (duplicate);
}
