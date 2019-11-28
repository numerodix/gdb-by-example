# C primitive types



## Integers

### Code

```
    unsigned char village = 240;
    unsigned short town = 63 * 1000;
    unsigned int city = 12 * 1000 * 1000;
    unsigned long long universe = 5LL << 60;
```

### unsigned char

| Format           | Command         | Output          |
|------------------|-----------------|-----------------|
| show type        | `ptype village` | `unsigned char` |
| display default  | `p village`     | `240 '\360'`    |
| display unsigned | `p/u village`   | `240`           |
| display signed   | `p/d village`   | `-16`           |



## Characters and strings

### Code

```
    char initial = 'H';
    char first[] = "Hans";
    char last[] = {'Z', 'i', 'm', 'm', 'e', 'r', 0};

    char *pinitial = &initial;
    char *pfirst = &first[0];
    char *plast = &last[0];
```

### Type and size

gdb knows the size and type of the character variables:

```
(gdb) ptype initial
type = char
(gdb) ptype first
type = char [5]
(gdb) ptype last
type = char [7]
```

But all it knows about the pointer variables is that they're pointers to a char:

```
(gdb) ptype pinitial 
type = char *
(gdb) ptype pfirst 
type = char *
```

### Displaying character variables

As chars/strings - this is gdb's default formatting:

```
(gdb) p initial
$13 = 72 'H'
(gdb) p first
$14 = "Hans"
(gdb) p last
$15 = "Zimmer"
```

As numbers:

```
(gdb) p/d initial
$16 = 72
(gdb) p/d first
$17 = {72, 97, 110, 115, 0}
```

Using the `x` command:

```
(gdb) x/c &initial
0x7fffffffe07f: 72 'H'
(gdb) x &first
0x7fffffffe09c: "Hans"
(gdb) x/s &first
0x7fffffffe09c: "Hans"
```

### Displaying pointers to chars

```
(gdb) p pinitial        # not very useful
$58 = 0x7fffffffe07f "H\177\340\377\377\377\177"
(gdb) p *pinitial       # deference
$56 = 72 'H'
(gdb) p/c *pinitial     # and display as char
$57 = 72 'H'
(gdb) x/c pinitial
0x7fffffffe07f: 72 'H'
```

### Display pointers to strings

With the default formatter gdb displays the pointer value and (optimistically?) dereferences it and displays the bytes as a null terminated string.

```
(gdb) p pfirst   
$63 = 0x7fffffffe09c "Hans"
```

With the `x` command:

```
(gdb) x/s pfirst                # same end result
0x7fffffffe09c: "Hans"
(gdb) x/5c pfirst               # show me 5 chars
0x7fffffffe09c: 72 'H'  97 'a'  110 'n' 115 's' 0 '\000'
```

Trying to deference the pointer confuses gdb:

```
(gdb) p *pfirst 
$78 = 72 'H'
(gdb) p/s *pfirst               # doesn't help
$79 = 72 'H'
```
