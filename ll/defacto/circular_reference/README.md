静态链接的环形引用问题，通常使用`--start-group`和`--end-group`来解决，如下：   
```
gcc main.o -Wl,--start-group -L. -lb -la -Wl,--end-group
```