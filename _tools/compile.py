#!/usr/bin/env python3

import re
import sys


pat_indent = ',indent[:](?P<indent>[0-9-]+)'
pat_options = '(' + pat_indent + ')*'

# {{<chars.snippet>}}
# // {{<chars.snippet,indent:-4>}}
rx_include = re.compile(
    '([/]{2}[ \t]*)*'
    '[{][{][<]'
    '(?P<filepath>.*?)' + pat_options +
    '[>][}][}]'
)

rx_table_delim = re.compile('[-][+][-]')

def indent_block(num, block):
    lines = block.split('\n')
    if num > 0:
        lines = [' ' * num + line for line in lines]
    else:
        num = num * -1
        rx = re.compile('^[ ]{' + str(num) + '}')
        lines = [rx.sub('', line) for line in lines]
    return '\n'.join(lines)

def process(infile):
    outfile = infile.replace('_in', '')
    outfile = outfile.replace('.org', '.md')

    print(" < Reading from: %s" % infile)
    with open(infile) as f:
        content = f.read()

    match = rx_include.search(content)
    while match:
        filepath = match.group('filepath')

        indent_s = match.group('indent')
        indent_chars = int(indent_s) if indent_s else 0

        print("  - Including file: %s" % filepath)
        with open(filepath) as f:
            included_content = f.read()

        included_content = indent_block(indent_chars, included_content)

        content = content[:match.start()] + included_content + content[match.end():]

        match = rx_include.search(content)

    content = rx_table_delim.sub('-|-', content)

    print(" > Writing to: %s" % outfile)
    with open(outfile, 'w') as f:
        f.write(content)


if __name__ == '__main__':
    try:
        infile = sys.argv[1]
    except IndexError:
        print("Usage: %s file_in" % sys.argv[0])
    process(infile)
