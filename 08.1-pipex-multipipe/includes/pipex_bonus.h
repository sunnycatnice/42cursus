/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:11:15 by ecarciof          #+#    #+#             */
/*   Updated: 2021/11/24 19:21:04 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_var {
	int		f_limiter;
	char	*limiter;
	int		pipes;
	int		id;
}	t_var;

/* ft_strjoin */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin3(char const *s1, char const *s2);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strjoin1(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	**ft_split(char const *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_max(int a, int b);
void	ft_error(void);
char	*ft_pathfinder(char **cmd);
char	*ft_gnl(void);
void	ft_free(char **cmd, char *path);
void	ft_close(t_var bonus, int *fd);
void	ft_error_arg(void);
void	ft_error_fork(void);
void	ft_error_pipe(int *fd);
void	ft_error_permission(void);
void	ft_error_command(char **cmd, char *path);
void	ft_limiter(int in, char *temp, char *path, t_var bonus);
void	ft_pipeline(char **argv, int *fd, char **envp, t_var bonus);
void	ft_middleman(char **argv, int *fd, char **envp, t_var bonus);
void	ft_son(char **argv, int *fd, char **envp, t_var bonus);
void	ft_father(char **argv, int *fd, char **envp, t_var bonus);
void	ft_pathchecker(char **argv, t_var bonus);
void	ft_free_mat(char **mat);
void	ft_arg_checker(int argc, char **argv);
#endif