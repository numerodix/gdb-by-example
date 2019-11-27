#!/usr/bin/env python3

import os
import re
import subprocess
import sys


IGNORE_DIRS = [
    re.compile('_.*'),
    re.compile('\..+'),
]

COMPILER = os.path.abspath(
    os.path.join(os.path.dirname(sys.argv[0]), 'compile.py'))

def run_compiler(infile):
    args = [COMPILER, infile]
    proc = subprocess.Popen(args)
    proc.communicate()

def compile_dir(dir):
    print("# Compiling in dir: %s" % dir)
    try:
        os.chdir(dir)
        items = os.listdir('.')
        items = [item for item in items if '_in' in item]
        
        for item in items:
            run_compiler(item)

    finally:
        os.chdir(path)

def is_ignored_dir(dir):
    return any((pat.match(dir) for pat in IGNORE_DIRS))

def compile_all(path):
    path = os.path.abspath(path)

    # assume one level of subdirs
    items = os.listdir(path) + ['.']
    dirs = [item for item in items if
            item and os.path.isdir(item) and not is_ignored_dir(item)]
    
    for dir in dirs:
        compile_dir(dir)


if __name__ == '__main__':
    path = os.getcwd()
    compile_all(path)
