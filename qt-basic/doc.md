# QT basic types


* [QString](#qstring)


## QString

```
QString name("Harry Gregson Williams");
```

```
# print as raw
(gdb) p/r name
$0 = {
  static null = {<No data fields>}, 
  d = 0x55555576ecf0
}

# print the data object as raw
(gdb) p/r name.d
$1 = (QString::Data *) 0x55555576ecf0

# pretty print the data object
(gdb) p/r *name.d
$2 = {
  <QArrayData> = {
...

# print the length of the string
(gdb) p/r (*name.d).size
$3 = 22

# print the allocated size of the string
(gdb) p/r (*name.d).alloc
$4 = 23
```
