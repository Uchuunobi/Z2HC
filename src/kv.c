#include <kv.h>
#include <string.h>
#include <stdlib.h>


#define TOMBSTONE ((char*)0x1)

kv_t *kv_init(size_t capacity)
{
	if (capacity == 0)
	{
		return NULL;
	}

	kv_t *table = malloc(sizeof(kv_t));
	if (table == NULL)
	{
		return NULL;
	}

	table->capacity = capacity;
	table->count = 0;

	table->entries = calloc(sizeof(kv_entry_t), capacity);

	if (table->entries == NULL)
	{
		free(table);
		return NULL;
	}

	return table;
}

static size_t hash(char*, size_t);
int kv_put(kv_t *db, char *key, char *value)
{
	if (!db || !key || !value) return -1;

	size_t idx = hash(key, db->capacity);

	for(int i = 0; i < db->capacity - 1; i++)
	{
		size_t real_idx = (idx + i) % db->capacity;

		kv_entry_t *entry = &db->entries[real_idx];

		// Key is set. Update.
		if 
		(
			entry->key && 
			entry->key != TOMBSTONE && 
			!strcmp(entry->key, key)
		)
		{
			char *newval = strdup(value);
			if (!newval) return -1;
			entry->value = newval;
			return real_idx;
		}

		// Key not found. Update.
		if (!entry->key || entry->key == TOMBSTONE)
		{
			char *newval = strdup(value);
			char *newkey = strdup(key);
			if (!newval || !newkey)
			{
				free(newval);
				free(newkey);
				return -1;
			}
			entry->key = newkey;
			entry->value = newval;
			db->count++;
			return real_idx;
		}
			
	}
		// DB is occupied.
		return -2;
}

size_t hash(char *val, size_t capacity)
{
	size_t hash = 0x13371337deadbeef;
	while(*val)
	{
		hash ^= *val;
		hash = hash << 8;
		hash += *val;

		val++;
	}

	return hash % capacity;
}

