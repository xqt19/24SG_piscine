#!/bin/sh
# bases: ’\"?! 01234
# bases: mrdoc 01234
#FT_NBR1=\'?"\"'\
#FT_NBR2=rcrdmddd
echo $FT_NBR1 + $FT_NBR2 | sed "s/'/0/g" | tr '\\"?!' 1234 | tr mrdoc 01234 | xargs echo 'obase=13; ibase=5;' | bc | tr 0123456789ABC 'gtaio luSnemf'
