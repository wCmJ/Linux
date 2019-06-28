string="abcd"
echo $string        #  abcd
echo ${string}      #  abcd
echo ${#string}     #  4
echo ${string:1:4}  #  bcd
echo `expr index "$string" c`   #  3
#support []
