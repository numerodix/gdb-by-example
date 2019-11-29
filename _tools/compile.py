#!/usr/bin/env python3

import re
import sys


pat_open = '[{][{][<]'
pat_close = '[>][}][}]'

pat_include = 'include[:](?P<filepath>.*?)'
pat_indent = ',indent[:](?P<indent>[0-9-]+)'
pat_include_options = '(' + pat_indent + ')*'

pat_toc = 'toc'
pat_levels = ',levels[:](?P<level_from>[0-9]+)[-](?P<level_to>[0-9]+)'
pat_source = ',source:(?P<source>([.]|.*?))'
pat_toc_options = '(' + pat_levels + '|' + pat_source + ')*'

# {{<chars.snippet>}}
# // {{<chars.snippet,indent:-4>}}
rx_include = re.compile(
    '([/]{2}[ \t]*)*' +
    pat_open +
    pat_include + pat_include_options +
    pat_close
)

rx_toc = re.compile(
    pat_open +
    pat_toc + pat_toc_options +
    pat_close
)

rx_md_headline = re.compile('^(?P<level>[#]+)[ \t]*(?P<heading>.*)')

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

def build_md_toc(level_zero, spec):
    lines = []

    indent = '  '
    for level, title, url in spec:
        level = level - level_zero
        line = '%s* [%s](%s)' % (indent * level, title, url)
        lines.append(line)

    return '\n'.join(lines)

def create_toc(level_from, level_to, source, cur_content):
    content = cur_content
    if source != '.':
        with open(source) as f:
            content = f.read()

    lines = content.split('\n')

    spec = []

    for line in lines:
        match = rx_md_headline.search(line)
        if match:
            level = len(match.group('level'))
            heading = match.group('heading').strip()

            if level_from <= level <= level_to:
                url = '#' + heading.replace(' ', '-').lower()
                if source != '.':
                    url = '%s%s' % (source, url)
                spec.append((level, heading, url))

    return build_md_toc(level_from, spec)

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

    match = rx_toc.search(content)
    while match:
        level_from = int(match.group('level_from'))
        level_to = int(match.group('level_to'))
        source = match.group('source')

        print("  - Creating toc from file: %s" % source)
        toc = create_toc(level_from, level_to, source, content)
        content = content[:match.start()] + toc + content[match.end():]

        match = rx_toc.search(content)

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
