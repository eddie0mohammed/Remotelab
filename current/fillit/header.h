#ifndef	HEADER_H
# define HEADER_H

typedef	struct s_board
{
	char			board[104][104];
	int				size;
}				t_board;

typedef	struct s_list
{
	struct s_list	*next;
	void			*content;
	int				content_size;
}				t_list;

typedef	struct s_tetri
{
	int				row;		//store location of top-most '#' of piece in block
	int 			column;		//store location of left-most '#' of piece in block
	char			alpha;
	char			shape[4][4];
}				t_tetri;

typedef struct s_piece
{
	int 			num_hash;		//number of hashes in block
	int 			connection;		//number of connection pieces (6 || 8)
	int 			left;		//left-most '#' of piece
	int 			top;		//top-most '#' if piece
}				t_piece;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	initialize_board(char board[104][104]);
void	initialize_p(t_piece *p);
void	modify_p(t_piece *p, char *str, int i, int j);
int 	calculate_connection(char *str, int position);

t_list	*ft_create_list(int fd, char *buf);
t_tetri	*ft_create_tetri(char *str, int num_pieces);
t_list	*ft_lst_new(void *content);

t_tetri	*store_tetri(char *str, int top, int left, int num_pieces);
t_list	*ft_lst_add_back(t_list *current, t_list **lst, t_tetri *tetri);

int		ft_get_size(t_list *begin_list);
int		ft_get_nearest_square(int size);
//int 	next_tetri(t_board *board, t_list *tetriminos);
//int		solve(t_board *board, t_list *tetriminos);
//int 	fits(t_board *bord, t_tetri *tetri, int row, int column);
//int 	add_tetri(t_board *bord, int row, int column, t_tetri *tetri);
//int 	delete_tetri(t_board *bord, int row, int column, t_tetri *tetri);
void	print_board(char board[104][104], int size);


int		delete_tet(t_board *brd, int row, int col, t_tetri *tet);
int		add_tet(t_board *brd, int row, int col, t_tetri *tet);
int		fits(t_board *brd, t_tetri *tet, int row, int col);
int		next_tet(t_board *brd, t_list *tetriminos);
int		solve(t_board *brd, t_list *tetriminos);






#endif