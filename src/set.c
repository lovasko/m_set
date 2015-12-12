#include "m_set.h"

int
m_set_init(struct m_set* set)
{
	return m_trie_init(&set->trie,
	                   m_trie_generic_byte_hash,
	                   M_TRIE_AUX_STORE_NONE);
}

int
m_set_add(struct m_set* set, void* data, size_t size)
{
	return m_trie_set(&set->trie,
	                  data,
	                  size,
	                  M_TRIE_COPY_DEEP,
	                  M_TRIE_OVERWRITE_ALLOW,
	                  NULL,
	                  0);
}

int
m_set_remove(struct m_set* set, void* data, size_t size)
{
	return m_trie_remove(&set->trie, data, size, M_TRIE_REMOVE_NONE);
}

int
m_set_remove_prefix(struct m_set* set, void* data, size_t size)
{
	return m_trie_remove(&set->trie, data, size, M_TRIE_REMOVE_PREFIX);
}

int
m_set_test(struct m_set* set, void* data, size_t size)
{
	return m_trie_get(&set->trie, data, size, NULL);
}

int
m_set_error_string(int code, char** out_error_string)
{
	return m_trie_error_string(code, out_error_string);
}

