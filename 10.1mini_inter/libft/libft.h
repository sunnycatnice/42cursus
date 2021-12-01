/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:21:29 by sungslee          #+#    #+#             */
/*   Updated: 2021/11/30 20:39:53 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				*ft_strndup(const char *s, size_t n);
char				*ft_concat(char *s1, const char *s2);
char				*ft_ulltoa(unsigned long long n);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_uitoa(unsigned int n);
char				*ft_itoa_base(unsigned int n, const char *base);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(long long n, const char *base);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_strlen(const char *s);
int					ft_lstsize(t_list *lst);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
long long int		ft_atoll(const char *str);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_putnstr(char *s, int n);
int					ft_is_set(char c, char *set);
char				*ft_atouni(wchar_t w);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_realloc(char **ptr, char c);
int					ft_free(void *ptr);
int					ft_is_space(int c);
int					ft_is_number(char *str);
int					ft_is_alpha(int c);
int					ft_is_num(int c);
int					ft_is_print(int c);
char				**ft_dup_doublestr(char **str);
void				ft_sort_doublestr(char **strs, int left, int right);
int					ft_len_doublestr(char **str);
int					ft_startswith(const char *str, const char *sub);
char				**ft_realloc_doublestr(char ***strs_ref, char *item);
int					ft_free_doublestr(char ***doublestr_addr);
int					ft_free_str(char **str);
char				**ft_remove_doublestr(char **str, int idx);

#endif
