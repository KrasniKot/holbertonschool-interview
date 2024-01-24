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

    ops = 0
    div = 2

    while n > 1:
        while n % div == 0:
            ops += div
            n //= div
        div += 1

    return ops
