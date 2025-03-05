cat /etc/passwd | grep -v '^#' | awk 'NR%2==0' | cut -d: -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ', ' | sed 's/, $/./' | tr -d '\n'
# remove comments, skips every other line , gets only login names (first field), reverses, sorts, prints only lines between FT1&2, 
# replace newline w comma and space, replace last comma w fullstop, removes last newline