#!/usr/bin/python3
""" This module contains minOperations(),
    that calculates the minimum operations to get n H's in a text file
"""


def minOperations(n):
    """ Your text editor can execute only two operations: Copy All and Paste.
        Given a number n, calculates the fewest number of operations needed
        to result in exactly n H characters in the file.
            - n: number of required H characters.
    """
    if n < 2:
        return 0

    if n in range(2, 6):
        return n

    lop = ["c", "p"]
    c = "H"
    hs = "HH"

    while len(hs) <= n:
        if n % len(hs) == 0 and n % len(hs) + len(c) != 0 and lop[-1] != "c":
            c = hs[:]
            lop.append("c")
        else:
            hs += c
            lop.append("p")

    return len(lop) - 2
