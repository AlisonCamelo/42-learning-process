/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:19:05 by acamelo           #+#    #+#             */
/*   Updated: 2026/07/29 15:37:32 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🧱 Level 2: String Joining & Re-allocation (The "Fridge" Assembly)
//Goal: Practice taking what’s currently in a buffer and gluing it onto what you already saved.


//Exercise 2.1: Manual Glue
//Write a function that takes two strings (e.g., "Hello " and "Alison") and uses malloc to return a 
//brand new string containing "Hello Alison". Don't forget to free any temporary memory!
/*
#include <stdlib.h>
#include <stdio.h>      

size_t ft_strlen(char *str)
{
    size_t i;
    
    i = 0;
    while(str[i] != '\0')
        i++;
    return(i);
}
                           //Alison Camelo
char *twostrings(char *string1, char *string2)
{
    char *mixofstrings;
    size_t lenght1;
    size_t lenght2;
    size_t i;
    size_t j;
    
    lenght1 = ft_strlen(string1);
    lenght2 = ft_strlen(string2);
    mixofstrings = malloc(sizeof(char)*((lenght1 + lenght2 + 1)));
    if(!mixofstrings)
        return(NULL);
    i = 0;
    while(i < lenght1)
    {
        mixofstrings[i] = string1[i];
        i++;
    }
    j = 0;
    while (j < lenght2)
    {
        mixofstrings[i + j] = string2[j];
        j++;
    }
    mixofstrings[i + j] = '\0';
    return(mixofstrings);
    
    
}
int main()
{
    printf("%s", twostrings("Alison", "Camelo"));
}
*/
//----------------------------------------------------------------------------------------

//Exercise 2.2: Accumulating Strings with Static
//
//Write a function char *append_word(char *new_word) with a 
//static char *leftovers. 
//
//Call append_word("Hello") -> leftovers becomes "Hello"
//Call append_word(" World") -> leftovers becomes "Hello World"
//Return the full string each time.  
/*
#include <stdlib.h>
#include <stdio.h>      

size_t ft_strlen(char *firstcall)
{
    size_t i;

    i = 0;
    while(firstcall[i] != '\0')
        i++;
    return(i);
}

//       append_word( World)
//       append_word(Hello)
char *append_word(char *new_word)
{
    //static char *leftovers = "Hello world";
    //static char *leftovers = "Hello";
    //static char *leftovers = 0;
    static char *leftovers; //permanent bucket
    char *temp_str; // new table, here ill keep the mix of both words
    size_t firstcall; // size of old word
    size_t lastcall;  // size of new word
    size_t i; //to iterate
    size_t j; //to iterate

    if(leftovers != NULL)
        firstcall = ft_strlen(leftovers); // size of leftovers
    else
        firstcall = 0;
    lastcall = ft_strlen(new_word); // size of new word 
    // for temp_str calculate the size of the two words 
    temp_str = malloc(sizeof(char) * (firstcall + lastcall + 1));
    i = 0;
    //here is to copy the old/firs string
    while(i < firstcall)
    {
        //this copies letter by letter
        temp_str[i] = leftovers[i];
        i++;
    }
    j = 0;
    while(j < lastcall)
    {   
        //this copies letter by letter from the last position
        //so after the first string was copied, we start to copy 
        temp_str[i + j] = new_word[j];
        j++;
    }
    //at the end we put '\0' to understand is the end
    temp_str[i + j] = '\0';
    // this free is to clean garbage in the leftovers
    if(leftovers)
        free(leftovers);
    leftovers = temp_str;
    return(leftovers);
}
int main(void)
{
    //printf("%s", append_word("Hello"));
    //printf("%s", append_word(" World"));
    //printf("%s", append_word(" Alison"));
    append_word("Hello");
    printf("%s\n", append_word(" World")); // Print ONLY the second result

    return(0);
}*/