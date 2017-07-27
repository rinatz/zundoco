#!/usr/bin/env python
# -*- coding: utf-8 -*-

import time
import random
import sys


def zundoco():
    choice = ['ズン', 'ドコ']
    expected = ['ズン', 'ズン', 'ズン', 'ズン', 'ドコ']
    finish = ['キ・', 'キ・ヨ・', 'キ・ヨ・シ！']

    words = [random.choice(choice)] * len(expected)

    while True:
        if words == expected:
            seconds = 1.2

            for word in words:
                sys.stdout.write(word + '\n')
                time.sleep(seconds)
                seconds = 0.7

            for word in finish:
                sys.stdout.write('\r' + word)
                time.sleep(0.3)

            sys.stdout.write('\n')

            return

        sys.stdout.write(words[0] + '\n')

        words = words[1:] + [random.choice(choice)]


def main():
    zundoco()


if __name__ == '__main__':
    main()
