#ifndef M_SET_H
#define M_SET_H

#include <m_trie.h>
#include <stddef.h>

#define M_SET_TRUE M_TRIE_OK
#define M_SET_FALSE M_TRIE_E_NOT_FOUND

struct m_set {
	struct m_trie trie;
};

int m_set_init(struct m_set* set);
int m_set_add(struct m_set* set, void* data, size_t size);
int m_set_remove(struct m_set* set, void* data, size_t size);
int m_set_remove_prefix(struct m_set* set, void* data, size_t size);
int m_set_test(struct m_set* set, void* data, size_t size);
int m_set_error_string(int code, char** out_error_string);

#endif

