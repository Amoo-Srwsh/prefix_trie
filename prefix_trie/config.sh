#!/bin/sh

set -xe

cc -Wall -Werror -std=c11 -pedantic -ggdb -o trie trie.c
