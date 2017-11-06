/* src/ocspd/cache.c */

#include "general.h"

// Allocates a new caching entry
OCSPD_CACHE_ENTRY * OCSPD_CACHE_ENTRY_new(void) {

	OCSPD_CACHE_ENTRY * e = NULL;

	// Allocates the required memory
	if ((e = PKI_Malloc(sizeof(OCSPD_CACHE_ENTRY))) == NULL) {
		PKI_ERROR(PKI_ERR_MEMORY_ALLOC, NULL);
		return NULL;
	}

	// Makes sure we null pointers

	// Initializes the MUTEX

	return e;
}

// Frees all memory associated with a cache entry
void OCSPD_CACHE_ENTRY_free(OCSPD_CACHE_ENTRY *e) {

	if (!e) return;

	// Free all internal pointers

	// Remove itself from the queue and move
	// the next element up the chain

	// Free the associated memory
	PKI_Free(e);

	// All Done
	return;
}

void OCSPD_CACHE_free(OCSPD_CACHE * oc) {

	// Input check
	if (!oc) return;

	// Free the memory
	if (oc->idx) PKI_Free(oc->idx);

	// Free the data structure
	PKI_Free(oc);
}

OCSPD_CACHE * OCSPD_CACHE_new(size_t size) {

	OCSPD_CACHE * oc = NULL;

	// Input checks
	if (size <= 0) size = 1000;

	// Allocates the memory
	if ((oc = PKI_Malloc(sizeof(OCSPD_CACHE))) == NULL) {
		PKI_log_err("Can not allocate cache memory");
		return NULL;
	}

	// Allocates the memory for the cache
	if ((oc->idx = PKI_Malloc(sizeof(OCSPD_CACHE_ENTRY) * size)) == NULL) {
		OCSPD_CACHE_free(oc);
		PKI_log_err("Can not allocate cache memory");
		return NULL;
	}

	// Sets the size of the index
	oc->size = size;
	
	// Initializes the lock
	PKI_RWLOCK_init(&oc->lock);

	// Return the initialized data structure
	return oc;

}

int OCSPD_CACHE_entry_idx(OCSPD_CACHE_ENTRY *entry) {
}

int OCSPD_CACHE_set_entry(OCSPD_CACHE * cache, OCSPD_CACHE_ENTRY *entry) {
}

OCSPD_CACHE_ENTRY * OCSPD_CACHE_get0_entry(OCSPD_CACHE * cache, ASN1_INTEGER *serialNumber) {
}
