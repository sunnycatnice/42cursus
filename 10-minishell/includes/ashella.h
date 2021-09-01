#ifndef ASHELLA_H
# define ASHELLA_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_data
{
	int				n_philo;
	uint64_t		todie;
	uint64_t		toeat;
	uint64_t		tosleep;
	int				n_musteat;
	int				n_forchette;
	uint64_t		start;

	pthread_mutex_t	*forks_m;
	pthread_mutex_t	can_print;
	pthread_mutex_t	someone_died;
}				t_data;

/* Lib */
int					ft_isdigit(char c);
int					is_space(char c);
int					is_neg(char c);
int					check_bychar(char const *c);
void				ft_putnbr_fd(uint64_t n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);

/* Core */

#endif
