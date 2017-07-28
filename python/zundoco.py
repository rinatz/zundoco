#!/usr/bin/env python
# -*- coding: utf-8 -*-

import time
import random
import sys


def zundoco():
    choice = ['ズン', 'ドコ']
    expected = ['ズン', 'ズン', 'ズン', 'ズン', 'ドコ']
    finish = ['キ・', 'ヨ・', 'シ！']

    words = [random.choice(choice)] * len(expected)

    while True:
        if words == expected:
            seconds = 1.0

            for word in words:
                print(word)
                time.sleep(seconds)
                seconds = 0.5

            for word in finish:
                print(word, end='', flush=True)
                time.sleep(0.3)

            print()

            return

        print(words[0])

        words = words[1:] + [random.choice(choice)]


def main():
    zundoco()


if __name__ == '__main__':
    main()
