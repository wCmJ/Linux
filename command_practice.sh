string="abcd"
echo $string        #  abcd
echo ${string}      #  abcd
echo ${#string}     #  4
echo ${string:1:4}  #  bcd
echo `expr index "$string" c`   #  3
#support []
array=(abcd abc ac c)
echo $array         #  abcd
echo ${array[0]}    #  abcd
echo ${#array[0]}   #  4
echo ${array[@]}    #  abcd abc ac c
echo ${array[*]}    #  abcd abc ac c
echo ${#array[@]}   #  4

echo "hh \n"        #  hh \n
echo -e "hh \n"     #  hh
echo -e "hh \c"
echo "hhh"          #  hh hhh

#number
a="1"
b="2"
echo $a             #  1
echo $b             #  2
echo $[a+b]         #  3
#  -eq  -ne  -gt  -ge  -lt  -le

#string
#  =  !=  -z(true if length is 0)  -n(true if length is not zero)

#file
#  -e(exist)  -r(exist and read)  -w(exist and write)  -x(exist and executable)  -s(exist and has one char or more)
#  -d(exist and is dir)  -f(exist and is common file)  -c(exist and is char file)  -b(exist and is block file)


#logic
#  !(not)  >  -a(and)  >  -o(or)  


if condition
then
    command
fi

if condition
then
    command1
else
    command2
fi


if condition
then
    command1
elif
then
    command2
else
    command3
fi

for var in item1 item2 ...
do
    command1
    command2
    ...
done

while condition
do
    command
done
int=1
while test $int -le 6
do
    echo $int
    let int++
done
while (( $int <= 5 ))
do
    echo $int
    let int++
done



























