# C++ standard library


* [string](#string)


## string

```
std::string name{"Ramin Djawadi"};
```

| Format                   | Command                                      | Output            |
|--------------------------|----------------------------------------------|-------------------|
| show type                | `ptype name`                                 | `std::string`     |
| **print as deref array** | `p *name._M_local_buf@name._M_string_length` | `"Ramin Djawadi"` |