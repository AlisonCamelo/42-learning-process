/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excercises.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:36:15 by acamelo           #+#    #+#             */
/*   Updated: 2026/07/31 12:58:31 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Exercise 1.1: The Counter
//Write a function void count_calls(void) that prints 
//how many times it has been called.

//#include <stdio.h>
/*
void count_calls(void)
{
    static int i; // starts automtically at zero, and remembers values
    
    i++;
    printf("call the number %d\n", i);
}

int main(void)
{
    count_calls(); 
    count_calls();
    count_calls();
    return(0);
}*/
//                        THE BIG DIFFERENCE
//   Feature                  Regular int i                   static int i
// Where it lives          The Stack (Temporary)        Data Segment (Permanent)
//   Life cycle          Born when function enters      Born when program starts
//                        dies when function exits       dies when program quits
// Default value            Garbage / Undefined       Automatically initialized to 0
//Remembers past?                 ❌ No               ✅ Yes! Keeps state between calls


//----------------------------------------------------------------------------------
//Exercise 1.2: The Savings Account
//Write a function int deposit(int amount) 
//that uses a static int balance.
//Every time you call deposit(50), 
// it adds 50 to the total and returns the updated balance.
//In main(), call it 3 times with different amounts and print the result.

//     FIRST PASS
//     deposit(50); 
/*int deposit(int amount)
{
//      mount = 0;
    static int mount;
    
    //0 += 50 o lo mismo que 
    // 0 = 0 + 50;
    mount = mount + amount;
    // return(50)
    return(mount);
}

int main (void)
{
    printf("Total %d\n", deposit(50)); 
    return(0);
}
//     SECOND PASS
//     deposit(100); 
int deposit(int amount)
{
//      mount = 50;
    static int mount;
    
    // 50 = 50 + 100;
    mount = mount + amount;
    // return(150)
    return(mount);
}

int main (void)
{
    printf("Total %d\n", deposit(100)); 
    return(0);
}
//     THIRD  PASS
//     deposit(150); 
int deposit(int amount)
{
//      mount = 150;
    static int mount;
    
    // 150 = 150 + 150;
    mount = mount + amount;
    // return(300)
    return(mount);
}

int main (void)
{
    printf("Total %d\n", deposit(150)); 
    return(0);
}*/


//----------------------------------------------------------------------
//Exercise 1.3: The Stash
//Write a function char *stash_char(char c) that uses a static char buffer[100] and a static int index.
//Every time stash_char(c) is called, it adds c into buffer[index] and increments index.
//Null-terminate the buffer (buffer[index] = '\0').
//Return buffer.
/*
#include <unistd.h>
#include <stdio.h>

// stash_char(A)
char *stash_char(char c)
{
//           buffer[100]    
    static char buffer[100];
//         index = 0     
    static int index;
    //buffer[0] = A;
    //buffer[0, 1] = AB
    buffer[index] = c; 
//    0    
    index++;
//    1 
    //buffer[0] = A\0;
    buffer[index] = '\0';
    
    return(buffer);
}
int main(void)
{
    stash_char('A');
    stash_char('B');
    printf("%s\n", stash_char('C')); "abc";
    return(0);
}
*/
//Exercise to remember things about pointers, 
//memory and arrays 
/*
#include <stdio.h> 

int main()
{
    int array[] = {1, 2, 3, 5, 6};
    
    array[2] = 7;
    printf("%i\n", array[2]);
    
    return 0;
    
}*/

