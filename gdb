gcc/g++ -g
gdb exe-file
set args xxx1 xxx2
show listsize
set listsize 20
l test.cpp:10
l test.cpp:main
b 12
i b
d 1(breakpoints number)
d 2 3 
d 2-6
dis 1
ena 1
b 17 if i==10
b test.cpp:12
b test.cpp:main
p i
ptype i
n(one step)
s(step into function)
finish(step out function)
c(continue to next breakpoint)
display 
x /16xb addr
set var i=5
until(无断点时跳出循环)
r
start(stop at first line)


x/nfu addr
n:正整数，需要显示的内存单元的个数
f:  x按十六进制格式显示变量
    d按十进制格式显示变量
    u按十六进制格式显示无符号整型
    o按八字节格式显示变量
    t按二进制格式显示
    
u:  b表示单字节
    h表示双字节
    w表示四字节
    g表示八字节












