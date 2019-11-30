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

# print as deref array
(gdb) p *name._M_local_buf@name._M_string_length
$1 = "Ramin Djawadi"

# print as raw
$2 = {
  static npos = 18446744073709551615, 
  _M_dataplus = {
    <std::allocator<char>> = {
      <__gnu_cxx::new_allocator<char>> = {<No data fields>}, <No data fields>}, 
    members of std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider: 
    _M_p = 0x7fffffffe000 "Ramin Djawadi"
  }, 
  _M_string_length = 13, 
  {
    _M_local_buf = "Ramin Djawadi\000\000", 
    _M_allocated_capacity = 7657280925023953234
  }
}
```
