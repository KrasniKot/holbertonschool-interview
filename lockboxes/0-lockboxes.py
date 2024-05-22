#!/usr/bin/python3
""" This module contains canUnlockAll() """


def canUnlockAll(boxes: list) -> bool:
    """ Determines whether it is possible to open all boxes """
    sto = [0]
    o = []

    while sto:
        k = sto.pop()

        if k not in o:
            o.append(k)
            sto.extend(boxes[k])

    return len(boxes) == len(o)
