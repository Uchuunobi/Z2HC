#include <stdio.h>
#include <kv.h>

int main()
{
	kv_t *table = kv_init(1024);
	printf("Successfully put table at: %p\n", table);
	printf("Successfully initialized table with capacity: %ld\n", table->capacity);
	printf("\n=================================\n");

	char key_0[] = "haha";
	char value_0[] = "hehe";
	int idx = kv_put(table, key_0, value_0);
	printf("Found a place for '%s' at: %d\n", key_0, idx);


	char this_1[] = "haha";
	printf("%s: %s\n", this_1, kv_get(table, this_1));
	

	return 0;
}
