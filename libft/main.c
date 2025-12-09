/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:14:59 by rogard-anto       #+#    #+#             */
/*   Updated: 2025/11/05 18:36:31 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	/*
	char c;
	char *dest;

	dest = malloc(sizeof(char) * 11);
	c = 'a';
	printf("------- Is Functions tests -------\n");
	printf("ft_isalpha : %d\n", ft_isalpha(c));
	printf("ft_isdigit : %d\n", ft_isdigit(c));
	printf("ft_isalnum : %d\n", ft_isalnum(c));
	printf("ft_isascii : %d\n", ft_isascii(c));
	printf("ft_isprint : %d\n", ft_isprint(c));

	printf("\n------- Strs Functions tests -------\n");
	printf("ft_strlcpy with not a large enough buffer : %d\n", (int)ft_strlcpy(dest, "Bonjour", 5));
	printf("ft_strlcpy with large enough buffer : %d\n", (int)ft_strlcpy(dest, "Bonjour", 10));
	printf("ft_strlcat return (: %d, str : %s\n", (int)ft_strlcat(dest, "C moi", 15), dest);
	printf("ft_strncmp : S1 bigger : %d\n", ft_strncmp("test", "Test", 4));
	printf("ft_strncmp : S2 bigger : %d\n", ft_strncmp("Test", "test", 4));
	printf("ft_strncmp : Equal : %d\n", ft_strncmp("test", "test", 4));
	printf("ft_strnstr : String found : %s\n", ft_strnstr("Mdr je suis pris a 42", "suis", 45));
	printf("ft_strnstr : String found : %s\n", ft_strnstr("Mdr je suis pris a 42", "", 45));
	printf("ft_strnstr : String found : %s\n", ft_strnstr("", "suis", 45));
	printf("ft_strnstr : String not found : %s\n", ft_strnstr("Mdr je suNis pris a 42", "suis", 3));
	printf("ft_tolower : %c\n", (char)ft_tolower('W'));
	printf("ft_toupper : %c\n", (char)ft_toupper('w'));
	printf("ft_strchr Retourne a partir du premier e: %s\n", ft_strchr("Je cherche une lettre", 101));
	printf("ft_strrchr Retourne a partir du dernier e: %s\n", ft_strrchr("Je cherche une lettre", 101));

	printf("\n------- Atoi Function tests -------\n");
	printf("ft_atoi : %d\n", ft_atoi("-784dsa78"));
	printf("ft_atoi : %d\n", ft_atoi("- -784dsa78"));

	printf("\n------- Mem Functions tests -------\n");
	char buffer[] = "String";
	printf("ft_memset : 300 retourner int(44) = ',' (lowest byte) : %s\n", (unsigned char *)ft_memset(buffer, 300, 6));
	char buffer2[] = "String";
	char dest2[20];
	printf("ft_memcpy : doit retourner String: %s\n", (unsigned char *)ft_memcpy(dest2, buffer2, 7));
	printf("ft_memchr : doit retourner ring: %s\n", (unsigned char *)ft_memchr(dest2, 114, 7));

	char *dup = ft_strdup(dest2);
	printf("ft_strdup : doit retourner String: %s\n", dup);

	char src3[] = "Pas tout compris";
	char dest3[20];
	printf("ft_memmove : %s\n", (unsigned char *)ft_memmove(dest3, src3, 17));

	printf("\n------- Calloc Function -------\n");
	char *dest4 = ft_calloc(8, 1);
	char *singlePointer = ft_calloc(45, 0);
	dest4 = "Bonjour";
	printf("ft_calloc : %s\n", dest4);
	printf("ft_calloc doit return un seul pointer freeable si Nmmemb ou size  = 0, si le main ne plante pas on est bon\n");
	free(singlePointer);

	printf("\n------- Split Function tests-------\n");
	char *split_str = ",,Je,,vais,split,cette,,,,str,,,";
	char **splited = ft_split(split_str, ',');
	while (*splited)
	{
		printf("%s\n", *splited);
		splited++;
	}

	printf("\n------- ft_itoa Function tests-------\n");
	printf("%s\n", ft_itoa(145));
	printf("%s\n", ft_itoa(-145));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));

	printf("\n------- FDs Functions tests-------\n");
	int fd = open("fds", O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		printf("Erreur douvrage Hassoul\n");
	ft_putchar_fd('O', fd);
	ft_putstr_fd(" Je mappelle ", fd);
	ft_putendl_fd(" Kheldin, j'ai ", fd);
	ft_putchar_fd(25, fd);
	close(fd);

	char string10[] = "Je bois du cafe";
	printf("\n------- Strs (part 2) Functions tests-------\n");
	printf("ft_substr : Devrait retourner \"bois\" : %s\n", ft_substr(string10, 3, 4));
	printf("ft_substr : Devrait retourner \"bois du cafe\" : %s\n", ft_substr(string10, 3, 40));
	printf("ft_substr : Devrait retourner \"NULL\" : %s\n", ft_substr(NULL, 3, 40));
	printf("ft_substr : Devrait retourner une str vide : %s\n", ft_substr(string10, 50, 1));
	printf("ft_strjoin : Devrait retourner \"bois du cafe\" : %s\n", ft_strjoin("bois du", " cafe"));
	printf("ft_strjoin : Devrait retourner une str vide : %s\n", ft_strjoin("", ""));
	printf("ft_strjoin : Devrait retourner NULL : %s\n", ft_strjoin(NULL, " du cafe"));

	printf("\nft_strtrim : Devrait retourner \" boisduca\" : %s\n", ft_strtrim(string10, "Jefe"));
	printf("ft_strtrim : Devrait retourner \"Je bois du cafe\" : %s\n", ft_strtrim(string10, "i"));
	printf("ft_strtrim : Devrait retourner \"Je bois du cafe\" : %s\n", ft_strtrim(string10, ""));
	printf("ft_strtrim : Devrait retourner une string vide : %s\n", ft_strtrim("", NULL));
	printf("ft_strtrim : Devrait retourner \"Je bois du cafe\" : %s\n", ft_strtrim(string10, NULL));
	printf("ft_strtrim : Devrait retourner NULL : %s\n", ft_strtrim(NULL, "set"));

	printf("ft_memcmp : Devrait retourner 32 : %d\n", ft_memcmp("t", "T", 1));
	printf("ft_memcmp : Devrait retourner -32 : %d\n", ft_memcmp("Test", "test", 1));
	printf("ft_memcmp : Devrait retourner 0 : %d\n", ft_memcmp("\xff\xaa\xde\x12", "\xff\xaa\xde\x12MACOSAAAAA", 4));
	*/
int r1, r2;

printf("\n=== STRING ===\n");
r1 = printf("printf : %s\n", "hello");
r2 = ft_printf("ft_printf : %s\n", "hello");
printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

printf("\n=== CHAR ===\n");
r1 = printf("printf : %c %c %c\n", 'a', 'Z', 0);
r2 = ft_printf("ft_printf : %c %c %c\n", 'a', 'Z', 0);
printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

printf("\n=== INT (d/i) ===\n");
r1 = printf("printf : %d | %i | %d | %i\n", 0, -1, INT_MAX, INT_MIN);
r2 = ft_printf("ft_printf : %d | %i | %d | %i\n", 0, -1, INT_MAX, INT_MIN);
printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

printf("\n=== UNSIGNED (u) ===\n");
r1 = printf("printf : %u | %u\n", 0, UINT_MAX);
r2 = ft_printf("ft_printf : %u | %u\n", 0, UINT_MAX);
printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

printf("\n=== HEXA (x/X) ===\n");
r1 = printf("printf : %x | %X | %x\n", 0, 255, UINT_MAX);
r2 = ft_printf("ft_printf : %x | %X | %x\n", 0, 255, UINT_MAX);
printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

printf("\n=== POINTER (p) ===\n");
int a = 42;
r1 = printf("printf : %p | %p\n", &a, NULL);
r2 = ft_printf("ft_printf : %p | %p\n", &a, NULL);
printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

printf("\n=== PERCENT (%%) ===\n");
r1 = printf("printf : %% %% %%\n");
r2 = ft_printf("ft_printf : %% %% %%\n");
printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);

printf("\n=== COMBO ===\n");
r1 = printf("printf : char=%c | str=%s | int=%d | hex=%x | ptr=%p | %%\n",
			'A', "test", -12345, 3735928559u, &a);
r2 = ft_printf("ft_printf : char=%c | str=%s | int=%d | hex=%x | ptr=%p | %%\n",
			'A', "test", -12345, 3735928559u, &a);
printf("retours -> printf: %d | ft_printf: %d\n\n", r1, r2);
	return (0);
}