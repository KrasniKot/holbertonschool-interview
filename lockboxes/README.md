# Lockboxes

In this context a **lockbox** is just a conceptual container which can only be opened with a specific key.

## Tasks

### 0. Lockboxes
You have ``n`` number of locked boxes in front of you. Each box is numbered sequentially from ``0`` to ``n - 1`` and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

- Prototype: ``def canUnlockAll(boxes)``
  - ``boxes`` is a list of lists
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- There can be keys that do not have boxes
- The first box ``boxes[0]`` is unlocked
- Return ``True`` if all boxes can be opened, else return ``False``

#### Execution
To execute the code, run it by typping ``python3 ./0-lockboxes.py``

```
root@ffbdd98be718:~/holbertonschool-interview/lockboxes# python3 0-lockboxes.py 
example: boxes1, is correct? True
example: boxes2, is correct? True
example: boxes3, is correct? True
example: boxes4, is correct? True
example: boxes5, is correct? True
example: boxes6, is correct? True
example: boxes7, is correct? True
example: boxes8, is correct? True
example: boxes9, is correct? True
example: boxes10, is correct? True
root@ffbdd98be718:~/holbertonschool-interview/lockboxes# 
```
