# C++ standard library


* [string](#string)


## string

```
std::string name{"Ramin Djawadi"};
```

```
# show type
(gdb) ptype name
type = std::string

# print as default
(gdb) p name
$1 = "Ramin Djawadi"

# print as deref array
(gdb) p *name._M_local_buf@name._M_string_length
$2 = "Ramin Djawadi"

# print as raw
(gdb) p/r name
<not shown>
```
