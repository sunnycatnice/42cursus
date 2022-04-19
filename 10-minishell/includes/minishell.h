/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:03:01 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/22 21:13:53 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <locale.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <sys/param.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/incs/libft.h"

# define BUFFERSIZE 200

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

typedef struct s_node
{
	char				*name;
	void				*string;
	struct s_node		*next;
}	t_node;

typedef struct s_checks
{
	int		header_vic;
	int		bool_pipes;
	int		input_file;
	int		output_file;
	int		append_file;
	int		delimiter_file;
}	t_checks;

typedef struct s_cmds
{
	int		idx;
	char	*cmd;
	char	**all_cmds;
	char	*path_cmd;
	int		x;
	int		i;
	char	**cmd_and_flags;
}	t_cmds;

typedef struct s_pipe
{
	int				pipe_nbr;
	int				fd[2];
	int				g_res;
	char			**matrix;
	char			*cmd;
	struct s_pipe	*next;
	struct s_pipe	*prev;
}	t_pipe;

typedef struct s_files
{
	char	*filein;
	int		fd_file1;
	char	*fileout;
	int		fd_file2;
	int		saved_stdout;
	int		saved_stdin;
}	t_files;

typedef struct s_red
{
	int				fd;
	int				ret;
	char			*filename;
	char			*cmd;
	char			*token;
	int				start;
	struct s_red	*next;
	struct s_red	*prev;
}	t_red;

typedef struct s_gstruct
{
	char				pwd[1024];
	char				**av;
	int					argc;
	int					firstoldpwd;
	char				oldpwd[1024];
	char				**envp;
	char				*line;
	char				**line_divided;
	t_checks			checkif;
	t_files				files;
	t_cmds				cmds;
	t_pipe				pipe;
	t_pipe				**pipes;
	t_red				**red;
	struct sigaction	t_sa;
	struct sigaction	t_sa2;	
	struct s_node		**var;
	struct s_node		**node;
	struct s_node		**exp;
	int					standard_in;
	int					standard_out;
	int					last_output;
	int					in_pipe;
	int					here_file_helper;
	int					close_helper;
}	t_gstruct;

t_gstruct	g_sh;

char	*ft_append(char *s1, char *s2, char glue);
char	**get_env(void);
char	**get_cmd(char *line);
char	*get_pipepath(char *cmd);
void	has_pipesandred(char *line);
int		sort_pipes(void);
void	padre(int pid, t_pipe *p, int open);
int		do_cmd(char *cmd);
void	pipe_addback(t_pipe **lst, t_pipe *new);
int		exp_exists(char *name);
char	*remove_quotes(char *path);
char	*get_pwdpath(char *name);
void	is_a_red(char *input);
char	**splits(char *line, char split);
void	start_red(void);
void	red_addback(t_red **lst, t_red *new);
void	right_token(t_red *red);
void	save_standardfd(void);
int		check_token_error(char *input);
void	get_token(t_red *red, char *line);
t_red	*init_red(char *input);
void	free_matrix(char **matrix);
void	finish_her(t_red *red);
void	left_token(t_red *red);
void	here_doc(t_red *red);
char	*get_echo(char *name);
int		get_i(char *line);
t_pipe	*new_pipe(char *line);
int		get_fd_one(t_red *red, int fd);
void	ft_check_for_d(char *line);
void	parse_line(void);
int		ft_checkif_cmd(void);
void	ft_checkif_files(char **envp);
void	ft_check_specialchars(void);
int		ft_search_cmd(char *word, char **envp);
int		ft_index_position(char **src, char *to_find);
int		ft_access_file(char *path);
int		ft_check_inputfile(char *str, char **envp);
int		ft_check_outputfile(char *str, char **envp);
void	ft_redirect_output(void);
void	ft_redirect_input(void);
void	ft_reset_output(void);
void	ft_save_standard_fd(void);
void	restore_standard_fd(void);
void	ft_countpipes(void);
void	execcmd(char *path, char **cmd);
void	ft_ifpipes(void);
void	ft_check_in_out(void);
void	ft_redirect_output_append(void);
void	close_fd_and_pipes(void);
int		*make_pipes(void);
void	ft_call_parent(pid_t pid);
int		exec_recoded_cmds(int i);
int		ft_exec_cmd(void);
void	execve_cmd(int i);
int		check_for_var(char *line);
void	minishell_loop(void);
int		ft_pwd(void);
void	init_shell(void);
void	is_c(int sign);
void	is_sig(void);
int		ft_env(int sent);
int		ft_export(char *line);
void	ft_export2(int o, char *line);
int		is_useless(char c);
int		ft_echo(char *line);
int		ft_cd(char *line);
int		ft_exit(void);
void	put_in_env(char *old, char *new);
int		check_unclosed_quotes(char *line);
char	*parseline(char *line);
char	*exec_command(char *line);
char	*read_line(void);
char	*ft_space_remove(char *line);
char	*findrightpath(char **path, char **cmd);
char	**pathfinder(char *line);
void	continue_env(t_node *new, int sent);
void	continue_print_export(t_node *p, int sent);
void	continue_put_data_var(char *name, char *content);
void	create_node(t_node **node, char *name);
void	put_data_in_node(t_node **node, char *ref, char *data);
void	delete_node(t_node **node, char *ref);
void	ft_signals(void);
int		ft_dollaro(char *name);
void	ft_lstadd_back(t_node **lst, char *name);
void	*ft_lstlast(t_node *lst);
void	delete_var(char *name);
void	ft_lstaddnode_back(t_node **lst, t_node *new);
int		get_node(char *id);
void	add_exp_info(char *name, char *string);
int		check_existance(char *id);
char	*takeout_spaces(char *id);
void	print_export(int sent);
int		ft_unset(char *id);
void	put_data_var(char *line);
int		check_existance_var(char *id);
char	*get_err_name(char *string);
int		matrix_check_unset(char **matrix);
void	put_data_exp(char *line);
int		check_existance_exp(char *id);
char	*get_name(char *longstring, char *name);
int		matrix_check(char **matrix);
void	parse_exp_matrix(char **matrix);
void	exp_has_content(char *longstring);
void	new_exp(char *name);
void	ft_init(void);
void	ft_print_start_msg(void);
char	**ft_split_and_count(char const *s, char c);
char	**from_list_to_mtx(t_node *env_list);
void	print_matrix(char **matrix);
char	*double_quotes(char *line);
char	*get_path(char *path);
char	*single_quote(char *line);
char	*extract_quotes(char *path);
void	put_in_env(char *old, char *new);
char	*get_cdline(char *line);
void	ft_print_cderror(char *string);
int		mini_squig(char *path, int i);
void	ft_fork_pipe(t_pipe *p, int is_open);
t_red	*pipe_the_red(char *cmd);
void	parse_line(void);
int		check_token(char first, char second);
void	figlio(t_pipe *pipe, char *line);
void	padre(int pid, t_pipe *p, int open);
int		ft_lstsize(t_node *p);
char	*ft_checkif_path(char *word);
void	set_signal(void);
void	ft_print_prompt(void);
int		ft_echo_helper(char *line, int i);
void	ft_d_helper(char *to_save, char *name);
void	finish_adding(char *name, char *content);
void	finish_read_line(char *input);
void	free_pipes(void);
void	launch_pipes(void);
void	unsetter(t_node *unset, t_node *bef, t_node *aft);

#endif
