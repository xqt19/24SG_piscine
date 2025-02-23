int parse_input(char *str, int constraints[16])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
			constraints[j++] = str[i] - '0';
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (j != 16)
		return (0);
	return (1);
}