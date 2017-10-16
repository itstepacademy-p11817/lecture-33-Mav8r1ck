#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char* convert_to_salt(const char* str, const char* vowels)
{
	int size = 100;
	int size_p = 0;
	char* result_string = (char*)calloc(size, sizeof(char));
	for (int i = 0; i < strlen(str); i++)
	{
		bool flag = false;
		for (int j = 0; j < 12; j++)
		{
			if (str[i] == vowels[j])
			{
				flag = true;
				result_string[size_p] = str[i];
				result_string[size_p+2] = str[i];
				result_string[size_p + 1] = 's';
				size_p = size_p + 3;
			}
		}
		if (!flag)
		{
			result_string[size_p] = str[i];
			size_p = size_p + 1;
		}
	}
	result_string[size_p] = '\0';
	return result_string;
	free(result_string);
}

void* level_saltlang(char* b, const char* vowels)
{
	int salt = 0;
	int plain = 0;
	for (int i = 0; i < strlen(b); i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (b[i] == vowels[j] && b[i + 1] == 's' && b[i + 2] == vowels[j])
			{
				salt++;
			}
			else if (b[i] == vowels[j] && b[i + 1] != 's' && b[i + 2] != vowels[j])
			{
				plain++;
			}
		}
	}
	int temp = ((salt / plain) * 100);
	printf("Salt of language is: %d percents \n", temp);
}

char* convert_to_nonsalt(char* b, const char* vowels)
{
	for (int i = 0; i < strlen(b); i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (b[i] == vowels[j] && b[i + 1] == 's' && b[i + 2] == vowels[j])
			{
				for (int k = i; k < strlen(b); k++)
				{
					b[k + 1] = b[k + 3];
				}
			}
		}
	}
	return b;
}

char* change_letter(char* c, const char* vowels)
{
	for (int i = 0; i < strlen(c); i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (c[i] == vowels[j])
			{
				c[i] = vowels[12 - j];

			}
		}
	}
	return c;
}


int main()
{
	const char str[100] = "To be or not to be";
	const char vowels[] = { 'A', 'a', 'E', 'e', 'I', 'i', 'U', 'u', 'O', 'o', 'Y', 'y' };
	const char vowels1[] = { 'y', 'o', 'u', 'i', 'e', 'a' };
	char* b;
	b = convert_to_salt(str, vowels);
	printf("%s\n", b);
	level_saltlang(b, vowels);
	char* c;
	c = convert_to_nonsalt(b, vowels);
	printf("%s\n", c);
	char* d;
	d = change_letter(c, vowels);
	printf("%s\n", d);
    system("Pause");
	return 0;
}