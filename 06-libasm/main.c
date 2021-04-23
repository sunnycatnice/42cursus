/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:41:06 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/15 16:41:34 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
	char *str1;
	char *str2;
	char *emp;
	char *lunga;

	str1 = "Barbara Nessi\n";
	str2 = "bde-luca\n";
	emp = "";
	lunga = "barbaranessifaigraffiti373^&$@*@(/**/.//e\n";
	ft_print_start();
	ft_green_color();
	printf("\n\n-------------------TEST FT_STRLEN-------------------\n\n");
	ft_reset_color();
    printf(" input: %s", str1);
    printf("  real: %lu\nlibasm: %lu\n", strlen(str1), ft_strlen(str1));
    printf("\n input: [empty string]\n");
    printf("  real: %lu\nlibasm: %lu\n", strlen(emp), ft_strlen(emp));
    printf("\n input: %s", lunga);
    printf("  real: %lu\nlibasm: %lu\n", strlen(lunga), ft_strlen(lunga));
	ft_green_color();
    printf("\n\n-------------------TEST FT_STRCPY-------------------\n\n");
	ft_reset_color();
    char    empty1[50];
    char    empty2[50];
    printf("  real: %slibasm: %s\n", strcpy(empty1, str1), ft_strcpy(empty2, str1));
	ft_green_color();
    printf("\n\n-------------------TEST FT_STRCMP-------------------\n\n");
	ft_reset_color();
    printf("  real: %i\nlibasm: %i\n\n", strcmp(str1, str2), ft_strcmp(str1, str2));
    printf("  real: %i\nlibasm: %i\n\n", strcmp(str1, str1), ft_strcmp(str1, str1));
    printf("  real: %i\nlibasm: %i\n\n", strcmp(lunga, str2), ft_strcmp(lunga, str2));
	ft_green_color();
    printf("\n\n-------------------TEST FT_WRITE-------------------\n\n");
	ft_reset_color();
    FILE *test_file = fopen("test.txt", "w");
    fclose(test_file);
    int w_fd = open("test.txt", O_RDWR);
    printf("  real return: %zi\n", write(w_fd, str2, 9));
    printf("libasm return: %zi\n", ft_write(w_fd, str2, 9));
    printf("\n");
    printf("  Real Error: %zi, %s\n", write(-7, str2, 7), strerror(errno));
    printf("Libasm Error: %zi, %s\n", ft_write(-7, str2, 7), strerror(errno));
	ft_green_color();
    printf("\n\n-------------------TEST FT_READ-------------------\n\n");
	ft_reset_color();
    close(w_fd);
    char *buffer1 = calloc(500, sizeof(char));
    char *buffer2 = calloc (500, sizeof(char));
    int fd = open("test.txt", O_RDONLY);
    printf("  real return: %zi, %s\n", read(fd, buffer1, 5), buffer1);
    fd = open("test.txt", O_RDONLY);
    printf("libasm return: %zi, %s\n", ft_read(fd, buffer2, 5), buffer2);
    printf("\n");
    printf("  Real Error: %zi, %s\n", read(-7, buffer1, 7), strerror(errno));
    printf("Libasm Error: %zi, %s\n", ft_read(-7, buffer2, 7), strerror(errno));
	ft_green_color();
    printf("\n\n-------------------TEST FT_STRDUP-------------------\n\n");
	ft_reset_color();
    printf("  real: %slibasm: %s\n", strdup(str1), ft_strdup(str1));
    printf("  real: %s\nlibasm: %s\n\n", strdup(emp), ft_strdup(emp));
    printf("  real: %slibasm: %s", strdup(lunga), ft_strdup(lunga));
}
