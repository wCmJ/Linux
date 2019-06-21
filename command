sort | wc | uniq |
sort:
    -r: reverse
    -n: number
    -u: unique
    -f: 忽略大小写
    -t: 分隔符，默认是[tab]
    -k: 以某个区间排序
    cat /etc/passwd | sort 
    cat /etc/passwd | sort -t ":" -k 3
    cat /etc/passwd | sort -t ":" -k 3n
    cat /etc/passwd | sort -t ":" -k 3nr
    cat /etc/passwd | sort -t ":" -k 6.2,6.4 -k 1r
    cat /etc/passwd | sort -t ":" -k 7 -u
    
uniq:
    为了使uniq生效，所有的重复行必须是相邻的。
    -i: 忽略大小写
    -c: 进行计数
    -u: 只显示唯一的行
    -d: 仅显示重复的行
    
cut:
    提取列
    -d: 分隔字符
    -f: 依据-d的分隔符将一段信息分割成为数段，用-f取出第几段
    -c: 以字符的单位取出固定字符区间
    cat $PATH | cut -d ":" -f 3     第三段
    cat $PATH | cut -d ":" -f 3,5   第三段和第五段
    cat $PATH | cut -d ":" -f 3-    第三段至最后一段
    cat $PATH | cut -d ":" -f 1-3   第一段至第三段
    
wc:
    统计文件里面单词数，行数，字符数
    -l: 仅列出行
    -w: 仅列出多少字
    -m: 字符数

sed:
    处理列
    -i: 写入文件
    -n: 仅显示选定的行
    -e: 允许多个指令,直接在命令列模式上进行sed的动作编辑
    [a/c/d/i/p/s]
    a: 新增，字符出现在下一行
    c: 取代，可以取代n1,n2之间的行
    d: 删除，
    i: 插入，字符出现在上一行
    p: 打印
    s: 替换
    
    nl /etc/passwd | sed '2,5d'
    nl /etc/passwd | sed '2d'
    nl /etc/passwd | sed '3,$d'
    nl /etc/passwd | sed '2a drink tea'
    nl /etc/passwd | sed '2i drink tea'
    nl /etc/passwd | sed '2,5c No 2-5 number'
    nl /etc/passwd | sed '5,7p'
    nl /etc/passwd | sed '/root/p' 搜索有root关键字的行
    nl /etc/passwd | sed -n '/root/p' 只输出包含root的行
    nl /etc/passwd | sed '/root/d' 删除包含root的行，其他行输出
    nl /etc/passwd | sed -n '/root/{s/bash/blueshell/;p}'
    nl /etc/passwd | sed -n '/bash/{s/bash/blueshell/;p;q}'
    nl /etc/passwd | sed -e '3,$d' -e 's/bash/blueshell/'
       
grep:
    global search regular expression and print out the line
    -a: 将binary文件以text文件的方式搜寻数据
    -c: 计数
    -i: 忽略大小写搜索
    -n: 输出行号
    -v: 反向选择
    --color=auto: 
    dmesg | grep 'eth' -n -A2 -B3 --color=auto
    grep 'string' * 在当前目录搜索带string行的文件
    grep -r 'string' 在当前目录及其子目录下搜索带string行的文件
    grep -l -r 'string' 在当前目录及其子目录下搜索string行的文件，但是不显示匹配的行，只显示匹配的文件
    grep -n 't[ae]st' filename
    grep -n '[^g]oo' filename
    grep -n '[^a-z]oo' filename
    grep -n '[0-9]' filename
    grep -n '^the' filename
    grep -n '^[^0-9a-zA-Z]' filename
    grep -n '\.$' filename
    grep -n '^$' filename
    grep -n '^  *$' filename
    
    
    
    
    
awk:
    awk 'condition{command}'
    awk工作流程： 读入有'\n'换行符分割的一条记录，然后将记录按制定的域分隔符划分域，填充域，$0表示所有域，$1表示第一个域，默认分隔符是空白键或tab键。
    内置变量：
        ARGC: 命令行参数个数
        ARGV: 命令行参数排列
        ENVIRON: 系统环境变量
        FILENAME: awk浏览的文件名
        FNR: 浏览文件的记录数
        FS: 输入域分隔符，等价于-F
        NF: 域的个数
        NR: 已读的记录数
        OFS: 输出域分隔符
        RS: 控制记录分隔符
        print: 参数可以是变量、数值和字符串。字符串必须用""，参数用逗号分隔。
        
    cat /etc/passwd | awk -F ":" '{print $1}'
    awk -F: '/root/' /etc/passwd
    awk -F: '/root/{print $7}' /etc/passwd
    ls -l | awk 'BEGIN{size = 0;}{size = size+$5;}END{print "size is:" size}'
    awk -F ":" 'BEGIN{count=0;} {name[count]=$5;count++;} END{for(i=0;i<NR;i++)print i, name[i]}' /etc/passwd
    
netstat:
    netstat -a
    netstat -at
    netstat -au
    netstat -atn
    netstat -aun
    netstat -tln//不要加-a,否则会列出所有连接，而不仅仅是监听端口
    netstat -uln//不要加-a,否则会列出所有连接，而不仅仅是监听端口
    sudo netstat -nlpt//-p，查看对应的进程名和进程号
    netstat -ltep//-ep可以同时查看进程名和用户名
    netstat -s//统计网络数据，包括某个协议下的收发包数量
    netstat -st
    netstat -su
    netstat -r
    netstat -rn
    netstat -i//打印网络接口
    netstat -ie
    netstat -tc//持续输出
    netstat -g//输出IPV4和IPV6的多播组信息
    
    
    
    
    
    
    
