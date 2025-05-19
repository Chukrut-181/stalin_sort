/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stalin_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:55:01 by igchurru          #+#    #+#             */
/*   Updated: 2025/05/19 15:09:42 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*			STALIN SORT - The fastest sorting algorythm there is.			*/
/*			"One death is a tragedy; one million is a statistic."			*/

#include <stdio.h>
#include <stdbool.h>

/**
 * evaluate_level_of_marxism - This function takes a string of digits,
 * pretending it's a soldier's ideological purity score (because why not?),
 * and meticulously converts it into an integer. One might wonder if
 * higher scores get you extra rations of borscht.
 *
 * Return: An integer representing the "level" of Marxism.
 * May or may not reflect their actual understanding of Das Kapital.
 */
static int	evaluate_level_of_marxism(const char *str)
{
	int	level;

	level = 0;
	while (*str)
	{
		level = level * 10 + (*str - '0');
		str++;
	}
	return (level);
}

/**
 * is_a_good_soviet - Determines if a soldier is a "good Soviet" based on
 * their self-proclaimed level of Marxism. It's a highly scientific process
 * involving comparing their score to the current Kommisar's (who, naturally,
 * always has the highest score... until someone else claims they do).
 *
 * Return: true if the soldier's Marxist level is higher than the current
 * Kommisar's, thus making them a "better" Soviet (for now).
 * False otherwise, suggesting they need more mandatory readings.
 */
static bool	is_a_good_soviet(char *soldier)
{
	static int	kommisar;
	int			political_index;

	political_index = evaluate_level_of_marxism(soldier);
	if (political_index > kommisar)
	{
		kommisar = political_index;
		return (true);
	}
	else
		return (false);
}

/**
 * uniform_is_clean - Checks if a soldier's uniform is "clean".
 * A "clean" uniform is represented by a string containing only digits.
 * Any non-digit character implies a non-communist thought... or just dirt.
 *
 * Return: true if the uniform is "clean", false otherwise.
 */
static bool	uniform_is_clean(char *soldier)
{
	int	i;

	i = 0;
	while (soldier[i])
	{
		if (soldier[i] < '0' || '9' < soldier[i])
			return (false);
		else
			i++;
	}
	return (true);
}

/**
 * purge_soldiers - This function ruthlessly iterates through a list of
 * soldiers (provided as command-line arguments). Only those with a
 * "clean" uniform (all digits, no pesky letters or symbols of
 * dissent) AND a sufficiently high (and ever-increasing) level of
 * self-proclaimed Marxism are deemed worthy and printed to the console.
 * The rest? Well, let's just say they're sent for "re-education".
 */
static void	purge_soldiers(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (uniform_is_clean(argv[i]) && is_a_good_soviet(argv[i]))
		{
			printf("%s\n", argv[i]);
			i++;
		}
		else
			i++;
	}
}

/**
 * main - The glorious entry point of this highly critical soldier
 * evaluation program. It checks if there are enough comrades. If not,
 * it politely does nothing. Otherwise, it proudly displays some very
 * important ASCII art before unleashing the purge function to separate
 * the ideologically pure from the others.
 *
 * @comrades: The number of command-line arguments. We expect at least
 * three to have some soldiers to evaluate.
 * @argv: An array of strings containing the command-line arguments. The
 * elements starting from index 1 are treated as soldiers' data.
 *
 * Return: 0 upon execution... LOL
 */
int	main(int comrades, char **argv)
{
	if (comrades < 3)
		return (0);
	else
	{
		printf("\n⡿⠄⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠞⠛⠁⠄⡼⣿⣿⣿\n");
		printf("⣿⡇⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠙⣦⠐⠠⡥⣿⣿\n");
		printf("⣿⡇⠄⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⡔⠛⣿⣿\n");
		printf("⣿⡇⢰⢏⣤⣦⣤⣍⣉⣿⣿⣿⡟⢋⣁⣤⣤⣤⣈⢻⣿⣿⣿⣿⠚⣯⡄⣿⣿\n");
		printf("⣿⡇⣾⣿⣉⣀⣠⠅⠄⣽⣿⣿⣇⠈⢈⣉⣩⣐⡙⢿⣿⣿⣿⣿⠤⢿⢱⣿⣿\n");
		printf("⣿⠁⣿⣿⣿⣿⣿⣦⣾⣿⣿⣿⣿⣷⣤⣽⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⠾⣿⣿\n");
		printf("⡏⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡇⣿⣿\n");
		printf("⣧⢾⣿⣿⣿⣿⣿⣾⣯⣽⣋⠽⢭⣽⣤⡘⢿⣿⣿⣿⣿⣿⣿⣿⣿⠄⣿⣿⣿\n");
		printf("⣿⣿⣿⣿⣿⣿⠿⠩⣭⣽⠁⢣⢿⣯⡉⣿⡶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
		printf("⣿⣿⣿⣿⠿⠁⠄⠈⠋⠈⠄⡈⠁⠒⠌⠊⣃⠹⣿⣿⣿⣿⣿⣏⣻⣿⣿⣿⣿\n");
		printf("⣿⣿⣿⣷⣶⣤⣤⣶⣿⣿⣿⡿⣿⣷⣤⣄⣤⣠⣼⣿⣿⣿⣿⡟⣿⣿⣿⣿⣿\n");
		printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁⠸⣿⣿⣿⣿\n");
		printf("⣿⣿⡿⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣷⣿⣿⣿⣿⣿\n");
		printf("⡿⠛⠄⠄⠄⠙⢿⣷⣿⣭⣤⣬⡁⢉⣻⣿⣿⣿⣿⣿⣿⡟⠄⠹⣿⣿⣿⣿⣿\n\n");
		purge_soldiers(argv);
	}
	return (0);
}

/*		cc -Wall -Wextra -Werror stalin_sort.c -o purge		*/
/*		USAGE: ./purge arg1 arg2 arg3 ...					*/