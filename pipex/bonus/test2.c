#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int open_file(char *filename, int flags);
void print_error(char *str);
void free_double_pointer(char **str);
char **get_paths(char **envp);
char *get_cmd_path(char *cmd, char **envp);
void command_error(char **cmd);
void exec_child(int *fd, char *argv, char **envp);
void execute_command(char *argv, char **envp);
void exec_commands(int start, int argc, char **argv, char **envp, int fileout);
void handle_commands(int argc, char **argv, char **envp);
void here_doc_child(int *fd, char *limiter);
void handle_here_doc(int argc, char **argv, char **envp);

// Define BUFFER_SIZE for get_next_line
#define BUFFER_SIZE 1024

typedef struct s_gnlist {
	char *content;
	struct s_gnlist *next;
} t_gnlist;

// Function prototypes for get_next_line and its helpers
void refine_list(t_gnlist **lst);
char *retrieve_line(t_gnlist *lst);
void append_node(t_gnlist **lst, char *buffer);
void create_list(t_gnlist **lst, int fd);
char *get_next_line(int fd);
t_gnlist *ft_lstlast(t_gnlist *lst);
int find_newline(t_gnlist *lst);
int find_length_line(t_gnlist *lst);
void copy_str(t_gnlist *lst, char *str);
void dealloc(t_gnlist **lst, t_gnlist *new_node, char *buffer);

size_t ft_strlen(const char *s) {
	size_t i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t ft_strlcpy(char *dest, const char *src, size_t n) {
	size_t i, len;
	len = ft_strlen(src);
	i = 0;
	if (n != 0) {
		while (src[i] != '\0' && i < (n - 1)) {
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

char *ft_strjoin(char const *s1, char const *s2) {
	char *dest;
	size_t i, j;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0') {
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0') {
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int ft_strncmp(const char *s1, const char *s2, size_t n) {
	size_t i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && (s1[i] || s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static size_t ft_countword(char const *s, char c) {
	size_t i, word_count;
	int new_word;

	if (s == 0)
		return (0);
	i = 0;
	word_count = 0;
	while (s[i] != '\0') {
		new_word = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0') {
			if (new_word == 0) {
				word_count++;
				new_word = 1;
			}
			i++;
		}
	}
	return (word_count);
}

static size_t try_malloc(char **dest, size_t pos, size_t size) {
	size_t i;

	i = 0;
	dest[pos] = malloc(size);
	if (dest[pos] == 0) {
		while (i < pos) {
			free(dest[i++]);
		}
		free(dest);
		return (1);
	}
	return (0);
}

static size_t ft_fill_words(char **dest, char const *s, char c) {
	size_t i, len;

	i = 0;
	while (*s) {
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s) {
			len++;
			s++;
		}
		if (len) {
			if (try_malloc(dest, i, len + 1))
				return (1);
			ft_strlcpy(dest[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

char **ft_split(char const *s, char c) {
	size_t words;
	char **dest;

	words = ft_countword(s, c);
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (s == 0 || dest == 0)
		return (0);
	if (ft_fill_words(dest, s, c))
		return (0);
	dest[words] = 0;
	return (dest);
}

int main(int argc, char **argv, char **envp) {
	if (argc < 5) {
		print_error("Error: Invalid number of arguments\n");
	} else if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc >= 6) {
		handle_here_doc(argc, argv, envp);
	} else {
		handle_commands(argc, argv, envp);
	}
	return 0;
}

void handle_here_doc(int argc, char **argv, char **envp) {
	int fileout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0777);
	int fd[2];

	if (pipe(fd) < 0)
		print_error("Error: Problem occurred with pipe\n");

	if (fork() == 0)
		here_doc_child(fd, argv[2]);
	else {
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		exec_commands(3, argc, argv, envp, fileout);
	}
}

void here_doc_child(int *fd, char *limiter) {
	char *line;
	close(fd[0]);
	while ((line = get_next_line(STDIN_FILENO)) != NULL) {
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && ft_strlen(line) == ft_strlen(limiter) + 1) { // Adjusted to check the length
			free(line);
			break;
		}
		write(fd[1], line, ft_strlen(line));
		free(line); // Freed here to avoid double free
	}
	close(fd[1]);
	exit(0);
}

void handle_commands(int argc, char **argv, char **envp) {
	int fileout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	int filein = open(argv[1], O_RDONLY, 0777);

	if (filein < 0 || fileout < 0)
		print_error("Error: Unable to open file\n");

	dup2(filein, STDIN_FILENO);
	close(filein);
	exec_commands(2, argc, argv, envp, fileout);
}

void exec_commands(int start, int argc, char **argv, char **envp, int fileout) {
	int fd[2];
	pid_t pid;
	int i = start;

	while (i < argc - 2) {
		if (pipe(fd) < 0)
			print_error("Error: Problem occurred with pipe\n");

		if ((pid = fork()) == 0)
			exec_child(fd, argv[i], envp);
		else
			waitpid(pid, NULL, 0);

		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		i++;
	}

	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	execute_command(argv[argc - 2], envp);
}

void exec_child(int *fd, char *argv, char **envp) {
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execute_command(argv, envp);
}

void execute_command(char *argv, char **envp) {
	char **cmd = ft_split(argv, ' ');
	char *cmd_path = get_cmd_path(cmd[0], envp);
	if (!cmd_path)
		command_error(cmd);

	if (execve(cmd_path, cmd, envp) < 0)
		print_error("Error: Not possible to execute command\n");

	// Free memory if execve fails
	free(cmd_path);
	free_double_pointer(cmd);
}

void command_error(char **cmd) {
	free_double_pointer(cmd);
	perror("Command");
	exit(127);
}

char *get_cmd_path(char *cmd, char **envp) {
	char **paths = get_paths(envp);
	char *temp, *result;
	int i = 0;

	while (paths[i]) {
		temp = ft_strjoin(paths[i], "/");
		result = ft_strjoin(temp, cmd);
		free(temp);
		if (access(result, F_OK | X_OK) == 0) {
			free_double_pointer(paths);
			return result;
		}
		free(result);
		i++;
	}
	free_double_pointer(paths);
	return NULL;
}

char **get_paths(char **envp) {
	int i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	return ft_split(envp[i] + 5, ':');
}

void free_double_pointer(char **str) {
	int i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void print_error(char *str) {
	write(1, str, ft_strlen(str));
	exit(127);
}

int open_file(char *filename, int flags) {
	int fd = open(filename, flags, 0777);
	if (fd < 0)
		print_error("Error: Unable to open file\n");
	return fd;
}

// New get_next_line and helper functions

void refine_list(t_gnlist **lst) {
	t_gnlist *new_node;
	t_gnlist *last_node;
	int i, j;
	char *buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_gnlist));
	if (!buffer || !new_node)
		return;
	last_node = ft_lstlast(*lst);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	if (last_node->content[i] == '\n')
		i += 1;
	while (last_node->content[i]) {
		buffer[j++] = last_node->content[i++];
	}
	buffer[j] = '\0';
	new_node->content = buffer;
	new_node->next = 0;
	dealloc(lst, new_node, buffer);
}

char *retrieve_line(t_gnlist *lst) {
	int line_len;
	char *final_line;

	if (!lst)
		return (0);
	line_len = find_length_line(lst);
	final_line = malloc(line_len + 1);
	if (!final_line)
		return (0);
	copy_str(lst, final_line);
	return (final_line);
}

void append_node(t_gnlist **lst, char *buffer) {
	t_gnlist *new_node;
	t_gnlist *last_node;

	new_node = (t_gnlist *)malloc(sizeof(t_gnlist));
	if (!new_node)
		return;
	last_node = ft_lstlast(*lst);
	if (!last_node)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = 0;
}

void create_list(t_gnlist **lst, int fd) {
	int bytes_read;
	char *buffer;

	while (!find_newline(*lst)) {
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read) {
			free(buffer);
			return;
		}
		buffer[bytes_read] = '\0';
		append_node(lst, buffer);
	}
}

char *get_next_line(int fd) {
	static t_gnlist *lst;
	t_gnlist *temp;
	char *finished_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &finished_line, 0) < 0) {
		while (lst) {
			temp = lst->next;
			free(lst->content);
			free(lst);
			lst = temp;
		}
		return (0);
	}
	create_list(&lst, fd);
	if (!lst)
		return (0);
	finished_line = retrieve_line(lst);
	refine_list(&lst);
	return (finished_line);
}

t_gnlist *ft_lstlast(t_gnlist *lst) {
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int find_newline(t_gnlist *lst) {
	int i;

	if (!lst)
		return (0);
	while (lst) {
		i = 0;
		while (lst->content[i] && i < BUFFER_SIZE) {
			if (lst->content[i] == '\n')
				return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}

int find_length_line(t_gnlist *lst) {
	int i;
	int len;

	if (!lst)
		return (0);
	len = 0;
	while (lst) {
		i = 0;
		while (lst->content[i]) {
			if (lst->content[i] == '\n') {
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

void copy_str(t_gnlist *lst, char *str) {
	int i, j;

	if (!lst)
		return;
	i = 0;
	while (lst) {
		j = 0;
		while (lst->content[j]) {
			if (lst->content[j] == '\n') {
				str[i] = '\n';
				i++;
				str[i] = '\0';
				return;
			}
			str[i++] = lst->content[j++];
		}
		lst = lst->next;
	}
	str[i] = '\0';
}

void dealloc(t_gnlist **lst, t_gnlist *new_node, char *buffer) {
	t_gnlist *temp;

	if (!(*lst))
		return;
	while (*lst) {
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = 0;
	if (new_node->content[0])
		*lst = new_node;
	else {
		free(buffer);
		free(new_node);
	}
}
