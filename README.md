Stalin Sort 🚩

"One death is a tragedy; one million is a statistic."

## Overview
Stalin Sort is the fastest sorting algorithm known to man — because it doesn't sort at all.
Instead, it purges any element that isn't greater than the previous one, keeping only those that fall in strictly ascending order.
The rest are sent for re-education.

The program accepts a list of non-negative integers as command-line arguments and prints only those that are ideologically pure: clean (digits only) and ever-increasing.
Any element that fails to surpass its predecessor is silently eliminated.

## Instructions

Compile:
cc -Wall -Wextra -Werror stalin_sort.c -o purge

Run:
./purge arg1 arg2 arg3 ... argN

At least two arguments are required for the purge to begin.

Example:
bash./purge 3 1 4 5 2 9
Output:
3
4
5
9
Elements 1, 2, and any non-numeric arguments are eliminated.

Long live the algorithm!
