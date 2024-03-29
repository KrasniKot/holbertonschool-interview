#!/usr/bin/python3
""" This module contains canUnlockAll() """


def canUnlockAll(boxes: list) -> bool:
    """ Determines whether it is possible to open all boxes """
    o = set()
    sto = [0]

    while sto:
        cb = sto.pop()

        if cb not in o and 0 <= cb < len(boxes):
            o.add(cb)
            sto.extend(boxes[cb])

    return len(boxes) == len(o)
