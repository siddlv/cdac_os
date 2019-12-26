#include <stdio.h>
#include <pthread.h>
#include <string.h>

static char alpha_l = 'a';
static char alpha_c = 'A';
static int alpha_count[26];

void* fun_1(void *x)
{
	char *c = x;
	for (int i = 0; i < 26; ++i)
	{
		if (*c == (alpha_l + i) || *c == (alpha_c + i))
		{
			++alpha_count[i];
		}
	}
}

int main()
{
	FILE* fp;
	char *ch;

	pthread_t id_1;

	printf("Counting Alphabets ...\n");

	fp = fopen("/usr/share/dict/words", "r");

	*ch = fgetc(fp);
	while (*ch != EOF)
	{
		pthread_create(&id_1, NULL, fun_1, ch);
		pthread_join(id_1, NULL);

		*ch = fgetc(fp);
	}

	for (int i = 0; i < 26; ++i)
	{
		printf("\n%c : %d\n", (alpha_c + i), alpha_count[i]);
	}

	return 0;
}

