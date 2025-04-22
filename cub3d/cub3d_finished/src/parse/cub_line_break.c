/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_break.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:20:38 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/13 17:20:40 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	is_map(char *line, int *is_map, t_game *game)
{
	char		*temp;
	static int	line_break = 0;

	if (line_break == 1 && *is_map == 1 && line[0] != '\n')
		return (errors("Textures, colors or map not correctly written\n"));
	if (line[0] == '\n' && ft_strlen(line) == 1 && *is_map == 1)
		line_break = 1;
	if (line[0] == '\n')
		return (0);
	*is_map = 1;
	temp = game->is_map;
	game->is_map = ft_strjoin(temp, line);
	free(temp);
	if (!game->is_map)
		return (errors("Textures, colors or map not correctly written\n"));
	return (0);
}

int	is_texture(char *line, int is_map, t_game *game)
{
	char	*temp;
	char	**matrix;

	matrix = ft_split(line, ' ');
	if (!(((!ft_strncmp(matrix[0], "NO", 2) || !ft_strncmp(matrix[0], "SO", 2)
					|| !ft_strncmp(matrix[0], "EA", 2)
					|| !ft_strncmp(matrix[0], "WE", 2))
				&& ft_strlen(matrix[0]) == 2)
			|| ((!ft_strncmp(matrix[0], "F", 1)
					|| !ft_strncmp(matrix[0], "C", 1))
				&& ft_strlen(matrix[0]) == 1)))
	{
		free_matrix(matrix);
		return (2);
	}
	free_matrix(matrix);
	if (is_map == 1)
		return (errors("Textures, colors or map not correctly written\n"));
	temp = game->is_texture;
	game->is_texture = ft_strjoin(temp, line);
	free(temp);
	if (!game->is_texture)
		return (errors("Textures, colors or map not correctly written\n"));
	return (0);
}

int	open_save_all(char *argv, t_game *game, int temp)
{
	int		fd;
	int		map;
	char	*line;

	map = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (errors("Can't open .cub file\n"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (temp == 1)
		{
			free(line);
			continue ;
		}
		temp = is_texture(line, map, game);
		if (temp == 2)
			if (is_map(line, &map, game) == 1)
				temp = 1;
		free(line);
	}
	return (close(fd), temp);
}

int	check_cub(char *argv)
{
	char	*extension;
	int		len_extension;

	len_extension = ft_strlen(argv);
	extension = ft_substr(argv, len_extension - 4, 4);
	if (!extension)
		return (errors("Add only one argument ended in .cub\n"));
	if (ft_strncmp(".cub", extension, 4) == 0
		&& len_extension > 4 && argv[len_extension - 5] != '/')
	{
		free(extension);
		return (0);
	}
	free(extension);
	return (errors("Add only one argument ended in .cub\n"));
}
