/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:08:14 by acamelo           #+#    #+#             */
/*   Updated: 2026/07/31 13:27:52 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

char *ft_linebreak(char *leftovers)
{
	//"Hola Mundo\nQué tal el día"
	char *line; // 
	size_t i; //iterador
	// 1. Contar exactamente cuántos caracteres hay HASTA el '\n'
	// si por alguna razon leftovers no existe que devuelva NULL	
	if(!leftovers || !leftovers[0])
		return(NULL);
	i = 0;
	//mientras leftovers en i n o sea \n o \0, sigue recorriendo
	while(leftovers[i] != '\0' && leftovers[i] != '\n')
		i++;
	// Reservamos espacio para lo contado + 1 (para el '\n' si está)
	// + 1 (para el '\0')
	if (leftovers[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else 
		line = malloc(sizeof(char) * (i + 1));
	//si no hay line por alguna rezon,devuelve NULL	
		if(!line)
		return(NULL);
	// 2. Copiar letra por letra a 'line'
	i = 0;
	//mientras que en la posicion en la que esta i en leftovers no sea
	//\0 o \n copia lo de leffovers a line
	while(leftovers[i] != '\0' && leftovers[i] != '\n')
	{
		line[i] = leftovers[i];
		i++;
	}
	// 3. Si terminamos en '\n', también lo copiamos
    // si llegamos a leftovers[i] == \n copialo en el texto que ya teniamos
	if (leftovers[i] == '\n')
    {
        line[i] = leftovers[i];
        i++;
    }
	// 4. Cerramos la cadena con el nulo final
	line[i] = '\0';
	return(line);
}

char *ft_clean_leftovers(char *leftovers)
{
	char *new_lefovers;
	size_t i;
	size_t j;

	//Si leftovers esta vacio o no existe nada devuelve NULL
	if(!leftovers)
		return(NULL);
	i = 0;
	//MIENTRAS leftovers en i no sea \0 o \n continua
	while(leftovers[i] != '\0' && leftovers[i] != '\n')
		i++;
	//si leftovers llego al final sin encontrar \n libera
	//NO QUEDA SOBRANTE, y devuelve NULL	
	if (leftovers[i] == '\0')
		return(free(leftovers), NULL);
	// 2. Reservamos memoria para el sobrante
    // ft_strlen(leftovers) 
	//- i es el tamaño que queda desde la '\n' hasta el final
	//por lo tanto hacemos malloc del tamaño de leftovers menos lo que ya habia recorrdio
	new_lefovers = malloc(sizeof(char) * (ft_strlen(leftovers) -i + 1));
	//si fllo algo en new_leftovers, retorna nulo
	if(!new_lefovers)
		return(free(new_lefovers), free(leftovers), NULL);
	// 3. Copiamos desde (i + 1) hasta el final o sea despues del \n que ya tenimos de antes
	i++; //aca se avanza +1(como dije antes) para saltrse el \n
	j = 0; // inicializas j y mientras leftovers en i no sea el final
 	while(leftovers[i] != '\0')
	{
		//copia lo que hay en leftovers a newleftovers
		new_lefovers[j] = leftovers[i];
		i++;
		j++;
	}
	new_lefovers[j] = '\0'; //pones nulo al final
	// 4. ¡MUY IMPORTANTE! Liberamos la memoria vieja de leftovers
	return(free(leftovers), new_lefovers);
}
char *get_next_line(int fd)
{
    //buffer = cubo temporal    
    //leftovers = almacen estatico    
    //ft_strchr = la tijera
    static char *leftovers;  //almacen estatico 
    char *clean_line; // linea que guarda el texto de  leftovers hasta el \n 
	char *buffer; //cubo temporal
    ssize_t bytes_read;

	// Protección de fd y BUFFER_SIZE por si pasan valores raros
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
//////RESERVAMOS MEMORIA PARA EL CUBO TEMPORAL
    buffer = malloc(BUFFER_SIZE + 1); //cubo temporal es el tamaño del buffer_size + 1
    if(!buffer) // si no hay cubo temporal
        return(NULL); //devuelve null
    bytes_read = 1; //VALOR > 0 par que pueda entrar al while
    //mientras no haya \n en leftovers y bytesread sea mayor a 0
    while(!leftovers || !ft_strchr(leftovers, '\n') && bytes_read > 0)
    {
        //lee lo que hay en el fd, el n de casillas que ha sido asigando al buffer_size y pon as en el buffer
        bytes_read = read(fd, buffer, BUFFER_SIZE); //read devuelve un  numero tipo size_t
        //si por alguna razon bytes_read es igual  -1 (es seguramente por que algo no ha salido bien)
        if(bytes_read == -1)
            return(free(buffer), free(leftovers), NULL); //devulve NULL
        buffer[bytes_read] = '\0'; // el cubo temporal en la posicion final del bytes_read sera '\0'
        //junta lo que estaba en leftovers + LO NUEVO EN BUFFER 
        leftovers = ft_strjoin(leftovers, buffer);
    }
    free(buffer); // libera el cubo temporal
    //si llegamos aqui leftovers YA TIENE '\n' o se acabo el archivo
	// 1. Extraemos la línea que le daremos al usuario
    clean_line = ft_linebreak(leftovers);
    // 2. Limpiamos leftovers para dejar solo lo sobrante tras el '\n'
    leftovers = ft_clean_leftovers(leftovers);
    // 3. Devolvemos LA LÍNEA EXTRAÍDA (no leftovers)
    return (clean_line);
}

int main(void)
{
    char  *next_line;
    int fd;
    int   line_num = 1;

    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo.\n");
        return (1);
    }

    // Leemos línea a línea hasta llegar al final del archivo (NULL)
    while ((next_line = get_next_line(fd)) != NULL)
    {
        printf("Línea [%d]: %s", line_num++, next_line);
        free(next_line); // ¡Liberamos cada línea que nos devuelve GNL!
    }

    close(fd);
    return (0);
}