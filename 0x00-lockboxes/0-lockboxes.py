#!/usr/bin/python3
"""Module for unlocking boxes"""


def canUnlockAll(boxes):
    """Determines if the keys inside the given boxes are sufficient to
    open all the boxes"""
    cnt_boxes = len(boxes)
    opened = [False] * cnt_boxes
    opened[0] = True
    unlock(boxes[0], boxes, cnt_boxes, opened)
    return all(opened)

def unlock(box, boxes, cnt_boxes, opened):
    """Opens a box and uses its key as long as it hasnt been opened before"""
    for key in box:
        if key < cnt_boxes and not opened[key]:
            opened[key] = True
            unlock(boxes[key], boxes, cnt_boxes, opened)


