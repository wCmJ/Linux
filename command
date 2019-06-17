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
    -e: 允许多个指令
    [p/d/i/a/s]
    
grep:
    处理行
    
    
awk:
    awk 'condition{command}'
    
    
    
    
