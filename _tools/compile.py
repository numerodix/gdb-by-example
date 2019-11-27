#!/usr/bin/env python3

import re
import sys


# {{<chars.snippet>}}
# // {{<chars.snippet>}}
rx_include = re.compile('([/]{2}[ \t]*)*[{][{][<](?P<filepath>.*?)[>][}][}]')

def process(infile):
    outfile = infile.replace('_in', '')

    print("Reading from: %s" % infile)
    with open(infile) as f:
        content = f.read()

    match = rx_include.search(content)
    while match:
        filepath = match.group('filepath')

        print("Including file: %s" % filepath)
        with open(filepath) as f:
            included_content = f.read()

        content = content[:match.start()] + included_content + content[match.end():]

        match = rx_include.search(content)

    print("Writing to: %s" % outfile)
    with open(outfile, 'w') as f:
        f.write(content)


if __name__ == '__main__':
    try:
        infile = sys.argv[1]
    except IndexError:
        print("Usage: %s file_in" % sys.argv[0])
    process(infile)
