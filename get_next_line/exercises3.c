/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:37:55 by acamelo           #+#    #+#             */
/*   Updated: 2026/07/30 12:28:35 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Exercise 3.1: Find the Index
//Write a function int find_newline(char *str) that returns the array index where \n 
//is located, or -1 if there is no \n.
/*
int find_newline(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\n')
        return(str[i]);
    else
        return(-1);
}

int main ()
{
        
}


Exercise 3.2: Slice the CakeGiven the string "Hello\nWorld", write two small functions:

get_before_newline(str) -> returns a malloc  string "Hello\n"
get_after_newline(str) -> returns a malloc string "World"

*/