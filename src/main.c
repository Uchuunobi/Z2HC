#include <stdio.h>
#include <kv.h>

int main()
{
	kv_t *table = kv_init(1024);
	printf("Successfully put table at: %p\n", table);
	printf("Successfully initialized table with capacity: %ld\n", table->capacity);
	printf("\n=================================\n");

	int idx = kv_put(table, "haha", "hehe");
	printf("Found a place at: %d\n", idx);

	return 0;
}
