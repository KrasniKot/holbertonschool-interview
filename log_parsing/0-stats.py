#!/usr/bin/python3
""" This module parses stdin lines and prints stat

    contains:
        - An script that parses the input,
        - sts() that prints the stats.
"""

from sys import stdin


def sts(tz: int, src: dict) -> None:
    """ Prints the stats of the input:
        - tz: total size,
        - src: number of references for each status code.
    """
    if tz > 0:
        print("Total size:", tz)

    for k, v in sorted(src.items()):
        if v != 0:
            print("{}: {}".format(k, v))


# Initializing total size and status code references
tz = 0
scr = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

for i, line in enumerate(stdin):  # Loop over each input line

    try:
        line = line.split()  # Split the line
        tz += int(line[-1])  # add the file size
       
        sc = int(line[-2])

        if sc in scr.keys():
            scr[sc] += 1  # Count number of references

            if i % 10 == 0:
                sts(tz, scr)

    except KeyboardInterrupt as e:
        sts(tz, scr)

    except Exception:  # If wrong format
        continue
