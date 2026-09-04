#include <stdio.h>
#include <kv.h>

int main()
{
	kv_t *db = kv_init(16);

	kv_put(db, "name", "alice");
	kv_put(db, "city", "berlin");
	kv_put(db, "lang", "c");

	kv_delete(db, "city");

	kv_free(db);
	db = NULL;
	// valgrind should report 0 bytes in use at exit

	return 0;
}
