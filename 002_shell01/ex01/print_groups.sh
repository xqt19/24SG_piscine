id -nG $FT_USER | tr -s ' ' ',' | tr -d '\n'
# prints user groups then replace all spaces with commas then removes newline