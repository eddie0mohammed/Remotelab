#ifndef HEADER_H
# define HEADER_H

typedef struct		s_board
{
	char			board[104][104];
	int				size;
}					t_board;

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	int				content_size;
}					t_list;

typedef struct		s_tet
{
	int				row;
	int				col;
	char			letter;
	char			shape[4][4];
}					t_tet;

typedef struct		s_piece
{
	int				num;		// number if hashes in piece
	int				connection;	// number of neighbouring '#'
	int				left;		//distance from left to first '#' 
	int				top;		//distance from top	to first '#'
}					t_piece;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				initialize_board(char board[104][104]);
t_list				*create_list(int fd, char *buf);
t_tet				*create_tet(char *str, int count);
void				initialize_p(t_piece *p);
void				modify_p(t_piece *p, char *str, int i, int j);
int					calculate_connection(char *str, int position);
t_tet				*store_tet(char *str, int top, int left, int count);
t_list				*ft_lstback(t_list *current, t_list **lst, t_tet *tet);
t_list				*ft_lstnew(void	*content);
int					get_size(t_list *tetriminos);
int					get_nearest_square(int size);
int					solve(t_board *bord, t_list *tetriminos);
int					next_tet(t_board *bord, t_list *tetriminos);
int					fits(t_board *bord, t_tet *tet, int row, int col);
int					add_tet(t_board *bord, int row, int col, t_tet *tet);
int					delete_tet(t_board *bord, int row, int col, t_tet *tet);
void				print_board(char board[104][104], int size);

#endif
