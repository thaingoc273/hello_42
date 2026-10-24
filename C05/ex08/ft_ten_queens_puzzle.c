#include <unistd.h>

void	print_board(int *board)
{
	char	c;
	int	i;

	i = 0;
	while (i < 7)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_save(int col, int row, int *board)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (i - board[i] == col - row)
			return (0);
		if (i - board[i] == row - col)
			return (0);
		i++;
	}
	return (1);
}

void	ten_queens_recursive(int col, int *board, int *found)
{
	int	row;

	row = 0;
	if (col == 6)
	{
		if (is_save(col, row, board))
		{
			print_board(board);
			*found++;
		}
	}
	else
	{
		while (row < 7)
		{
			if (is_save(col, row, board))
			{
				board[col] = row;
				ten_queens_recursive(col + 1, board, found);
			}
			row++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int board[7];
	int	*found;

	*found = 0;
	ten_queens_recursive(0, board, found);
	return (*found);

}

#include <stdio.h>

int	main(void)
{
	printf("The number of valid solutions %d", ft_ten_queens_puzzle());
}
