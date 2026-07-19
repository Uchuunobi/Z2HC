#include <stdio.h>
#include <kv.h>

int main()
{
	kv_t *table = kv_init(1024);
	printf("Successfully put table at: %p\n", table);
	printf("Successfully initialized table with capacity: %ld\n", table->capacity);
	printf("\n=================================\n");

	char key_0[] = "today";
	char value_0[] = "12 PM";
	int idx = kv_put(table, key_0, value_0);
	printf("Found a place for '%s' at: %d\n", key_0, idx);

	char key_1[] = "tomorrow";
	char value_1[] = "1 PM";
	idx = kv_put(table, key_1, value_1);
	printf("Found a place for '%s' at: %d\n", key_1, idx);

	char key_2[] = "Wednesday";
	char value_2[] = "11 AM";
	idx = kv_put(table, key_2, value_2);
	printf("Found a place for '%s' at: %d\n", key_2, idx);

	printf("%s: %s\n", key_0, kv_get(table, key_0));
	printf("%s: %s\n", key_1, kv_get(table, key_1));
	printf("%s: %s\n", key_2, kv_get(table, key_2));


	printf("\nAttempting to delete entry with key: %s\n", key_0);
	if(kv_delete(table, key_0) == -1)
	{
		printf("\nFailed to delete key.\n");
	}
	
	
	printf("%s: %s\n", key_0, kv_get(table, key_0));
	printf("%s: %s\n", key_1, kv_get(table, key_1));
	printf("%s: %s\n", key_2, kv_get(table, key_2));

	return 0;
}
