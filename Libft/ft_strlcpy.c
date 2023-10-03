/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheres <sonheres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:00:28 by sonheres          #+#    #+#             */
/*   Updated: 2023/10/03 13:07:16 by sonheres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize) // Devuelve el tamaño de la cadena de origen. Da igual el tamaño de las cadenas.
{
	size_t	len_src;//contador cadena origen.
	size_t	cont;//valor para copiar.
	
	len_src = 0;
	while	(src[len_src] != '\0')//mientras el valor de la cadena de origen no sea el valor nulo...
	{
		len_src++;//cuenta.
	}	
	if (dstsize == 0)//Y si el tamaño de la cadena de destino es 0...
	{
		return (len_src);//No hay que copiar nada. Simplemente devolver la longitud)
	}
	cont = 0;
	while (src[cont] != '\0' && cont < dstsize -1)//mientras el valor de origen no sea '\0' y no coincida con el nulo de la cadena de destino...
	{
		dst[cont] = src[cont];//copia el valor de la cadena de origen en la de destino.
		cont++;
	}
	dst[cont] = '\0';//acaba con el valor nulo.
	return (len_src);//devuelve el contador de la cadena de origen.
}

int	main(void)
{
	char cad_src[] = "Cuentame un cuento por favor";
	char cad_dst[50];//tamaño suficiente para contener la cadena de origen
	char mycad_dst[20];//creo un array para propio para probar con 20 caracteres de tamaño.
	size_t	copy;//creo una variable que guarda el número de caracteres del string.
	size_t	mycopy;//esta variable guarda los caracteres de mi función,
	
	copy = strlcpy(cad_dst, cad_src, 50);//asigno valor a la variable original. 50 es el tamaño de caracteres que voy a pasar.
	printf("original copy = %d\n", copy);// imprime el número de caracteres de la cadena de origen. %d números.
	printf("original cad_dest = %s\n", cad_dst);// imprime los caracteres que se han copiado. %s porque es string.
	mycopy = ft_strlcpy(mycad_dst, cad_src, 60);// No da error a pesar de que quiero copiar más de 20 caracteres.
	printf("propia mycopy = %d\n", mycopy);
	printf("propia mycad_dest = %s\n", mycad_dst);
	return (0);
}