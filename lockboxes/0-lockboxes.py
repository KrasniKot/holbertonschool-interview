def canUnlockAll(boxes: list) -> bool:
    """ Determines whether all boxes can be opened
        - boxes .... contains n lists, each representing a box, containing keys to other boxes.

        >>> True if all boxes can be opened else False
    """
    # Call open_boxes()
    return open_boxes(boxes, {0}, set())


def open_boxes(boxes: list, keys: set, opened: set) -> bool:
    """ Opens the boxes recursivelly to determine if all boxes can be opened
        - boxes ... contains n lists, each representing a box, containing keys to other boxes.
        - keys ... contains a set of indices of boxes that can currently be opened.
        - opened ... contains a set of indices of boxes that have been unlocked.

        >>> True if all boxes can be opened else False
    """
    if len(boxes) == len(opened): return True
    if len(keys) == 0: return False

    next_keys = set()
    for k in keys:
        if k not in opened:
            next_keys.update(boxes[k])  # Get the next boxes to be opened
            opened.add(k)               # Register box was opened

    return open_boxes(boxes, next_keys, opened)


if __name__ == '__main__':
    # Declare examples
    boxes1  = [[1], [2], [3], [4], []]
    boxes2  = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    boxes3  = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    boxes4  = [[1], [2], []]
    boxes5  = [[1], [3], [], []]
    boxes6  = [[1], [2], [5], [], [], []]
    boxes7  = [[1, 2], [3], [4], [], []]
    boxes8  = [[1], [2], [0], []]
    boxes9  = [[]]
    boxes10 = [[0]]

    # Print the results
    print('example: boxes1, is correct?', canUnlockAll(boxes1) == True)
    print('example: boxes2, is correct?', canUnlockAll(boxes2) == True)
    print('example: boxes3, is correct?', canUnlockAll(boxes3) == False)
    print('example: boxes4, is correct?', canUnlockAll(boxes4) == True)
    print('example: boxes5, is correct?', canUnlockAll(boxes5) == False)
    print('example: boxes6, is correct?', canUnlockAll(boxes6) == False)
    print('example: boxes7, is correct?', canUnlockAll(boxes7) == True)
    print('example: boxes8, is correct?', canUnlockAll(boxes8) == False)
    print('example: boxes9, is correct?', canUnlockAll(boxes7) == True)
    print('example: boxes10, is correct?', canUnlockAll(boxes10) == True)
