/*
 * =============================================================================
 *
 *       Filename:  oss_object_listing.c
 *
 *    Description:  oss_object_listing.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#define _OSS_OBJECT_LISTING_H
#include <ossc/modules/oss_object_listing.h>
#undef _OSS_OBJECT_LISTING_H

static const char * 
_object_listing_get_bucket_name(oss_object_listing_t *listing)
{
	return listing->bucket_name;
}

static inline void
__object_listing_set_bucket_name(
		oss_object_listing_t *listing,
		const char *bucket_name,
		size_t bucket_name_len)
{
	if (listing->bucket_name != NULL) {
		free(listing->bucket_name);
		listing->bucket_name = NULL;
	}
	listing->bucket_name = (char *)malloc(sizeof(char) * bucket_name_len + 1);
	strncpy(listing->bucket_name, bucket_name, bucket_name_len);
	(listing->bucket_name)[bucket_name_len] = '\0';
}

static void
_object_listing_set_bucket_name(
		oss_object_listing_t *listing,
		const char *bucket_name)
{
	assert(bucket_name != NULL);

	size_t bucket_name_len = strlen(bucket_name);
	__object_listing_set_bucket_name(listing, bucket_name, bucket_name_len);
}

static const char * 
_object_listing_get_marker(oss_object_listing_t *listing)
{
	return listing->marker;
}

static inline void
__object_listing_set_marker(
		oss_object_listing_t *listing,
		const char *marker,
		size_t marker_len)
{
	if (listing->marker != NULL) {
		free(listing->marker);
		listing->marker = NULL;
	}
	listing->marker = (char *)malloc(sizeof(char) * marker_len + 1);
	strncpy(listing->marker, marker, marker_len);
	(listing->marker)[marker_len] = '\0';
}

static void
_object_listing_set_marker(
		oss_object_listing_t *listing,
		const char *marker)
{
	assert(marker != NULL);

	size_t marker_len = strlen(marker);
	__object_listing_set_marker(listing, marker, marker_len);
}

static const char * 
_object_listing_get_next_marker(oss_object_listing_t *listing)
{
	return listing->next_marker;
}

static inline void
__object_listing_set_next_marker(
		oss_object_listing_t *listing,
		const char *next_marker,
		size_t next_marker_len)
{
	if (listing->next_marker != NULL) {
		free(listing->next_marker);
		listing->next_marker = NULL;
	}
	listing->next_marker = (char *)malloc(sizeof(char) * next_marker_len + 1);
	strncpy(listing->next_marker, next_marker, next_marker_len);
	(listing->next_marker)[next_marker_len] = '\0';
}

static void
_object_listing_set_next_marker(
		oss_object_listing_t *listing,
		const char *next_marker)
{
	assert(next_marker != NULL);

	size_t next_marker_len = strlen(next_marker);
	__object_listing_set_next_marker(listing, next_marker, next_marker_len);
}

static const char * 
_object_listing_get_max_keys(oss_object_listing_t *listing)
{
	return listing->max_keys;
}

static inline void
__object_listing_set_max_keys(
		oss_object_listing_t *listing,
		const char *max_keys,
		size_t max_keys_len)
{
	if (listing->max_keys != NULL) {
		free(listing->max_keys);
		listing->max_keys = NULL;
	}
	listing->max_keys = (char *)malloc(sizeof(char) * max_keys_len + 1);
	strncpy(listing->max_keys, max_keys, max_keys_len);
	(listing->max_keys)[max_keys_len] = '\0';
}

static void
_object_listing_set_max_keys(
		oss_object_listing_t *listing,
		const char *max_keys)
{
	assert(max_keys != NULL);

	size_t max_keys_len = strlen(max_keys);
	__object_listing_set_max_keys(listing, max_keys, max_keys_len);
}

static bool
_object_listing_get_is_truncated(oss_object_listing_t *listing)
{
	return listing->is_truncated;
}

static inline void
_object_listing_set_is_truncated(
		oss_object_listing_t *listing,
		bool is_truncated)
{
	listing->is_truncated = is_truncated;
}

static const char * 
_object_listing_get_delimiter(oss_object_listing_t *listing)
{
	return listing->delimiter;
}

static inline void
__object_listing_set_delimiter(
		oss_object_listing_t *listing,
		const char *delimiter,
		size_t delimiter_len)
{
	if (listing->delimiter != NULL) {
		free(listing->delimiter);
		listing->delimiter = NULL;
	}

	listing->delimiter = (char *)malloc(sizeof(char) * delimiter_len + 1);
	strncpy(listing->delimiter, delimiter, delimiter_len);
	(listing->delimiter)[delimiter_len] = '\0';
}

static void
_object_listing_set_delimiter(
		oss_object_listing_t *listing,
		const char *delimiter)
{
	assert(delimiter != NULL);

	size_t delimiter_len = strlen(delimiter);
	__object_listing_set_delimiter(listing, delimiter, delimiter_len);
}

static const char * 
_object_listing_get_prefix(oss_object_listing_t *listing)
{
	return listing->prefix;
}

static inline void
__object_listing_set_prefix(
		oss_object_listing_t *listing,
		const char *prefix,
		size_t prefix_len)
{
	if (listing->prefix != NULL) {
		free(listing->prefix);
		listing->prefix = NULL;
	}
	listing->prefix = (char *)malloc(sizeof(char) * prefix_len + 1);
	strncpy(listing->prefix, prefix, prefix_len);
	(listing->prefix)[prefix_len] = '\0';
}

static void
_object_listing_set_prefix(
		oss_object_listing_t *listing,
		const char *prefix)
{
	assert(prefix != NULL);

	size_t prefix_len = strlen(prefix);
	__object_listing_set_prefix(listing, prefix, prefix_len);
}

static inline const char **
_object_listing_get_common_prefixs(oss_object_listing_t *listing, unsigned int *counts)
{
	assert(listing != NULL);

	*counts = listing->_counts_common_prefixs;
	return (const char **)(listing->common_prefixs);

}

void _object_listing_set_common_prefixs(
		oss_object_listing_t *listing,
		const char **common_prefixs, unsigned int counts)
{

	assert(listing != NULL);
	assert(common_prefixs != NULL);

	/* *
	 * If listing->common_prefixs != NULL,
	 * free it one by one.
	 * */
	size_t j = 0;
	size_t total = listing->_counts_common_prefixs;
	if (listing->common_prefixs != NULL) {

		for (j = 0; j < total; j++) {
			if (*(listing->common_prefixs + j) != NULL) {
				free(*(listing->common_prefixs + j));
				*(listing->common_prefixs + j) = NULL;
			}
		}
	}

	size_t i = 0;
	const char **pnmec = common_prefixs;

	listing->common_prefixs = (char **)malloc(sizeof(char *) * counts);
	
	for (i = 0; i < counts; i++) {
		size_t len = strlen(*(pnmec + i));
		*(listing->common_prefixs + i) = (char *)malloc(sizeof(char) * len + 1);
		memset(*(listing->common_prefixs), 0, len + 1);
		strncpy(*(listing->common_prefixs + i), *(pnmec + i), len);
	}

	listing->_counts_common_prefixs = counts;
}

oss_object_listing_t *
object_listing_initialize(void)
{
	oss_object_listing_t *listing;
	listing = (oss_object_listing_t *)malloc(sizeof(oss_object_listing_t));

	listing->bucket_name = NULL;
	listing->marker = NULL;
	listing->next_marker = NULL;
	listing->max_keys = NULL;
	listing->delimiter = NULL;
	listing->prefix = NULL;
	listing->is_truncated = false;
	listing->common_prefixs = NULL;
	listing->_counts_common_prefixs = 0;

	listing->get_bucket_name = _object_listing_get_bucket_name;
	listing->set_bucket_name = _object_listing_set_bucket_name;
	listing->get_marker = _object_listing_get_marker;
	listing->set_marker = _object_listing_set_marker;
	listing->get_next_marker = _object_listing_get_next_marker;
	listing->set_next_marker = _object_listing_set_next_marker;
	listing->get_max_keys = _object_listing_get_max_keys;
	listing->set_max_keys = _object_listing_set_max_keys;
	listing->get_is_truncated = _object_listing_get_is_truncated;
	listing->set_is_truncated = _object_listing_set_is_truncated;
	listing->get_delimiter = _object_listing_get_delimiter;
	listing->set_delimiter = _object_listing_set_delimiter;
	listing->get_prefix = _object_listing_get_prefix;
	listing->set_prefix = _object_listing_set_prefix;
	listing->get_common_prefixs = _object_listing_get_common_prefixs;
	listing->set_common_prefixs = _object_listing_set_common_prefixs;

	return listing;
}

void
object_listing_finalize(oss_object_listing_t *listing)
{
	assert(listing != NULL);

	if (listing->bucket_name != NULL) {
		free(listing->bucket_name);
		listing->bucket_name = NULL;
	}
	if (listing->marker != NULL) {
		free(listing->marker);
		listing->marker = NULL;
	}
	if (listing->next_marker != NULL) {
		free(listing->next_marker);
		listing->next_marker = NULL;
	}
	if (listing->max_keys != NULL) {
		free(listing->max_keys);
		listing->max_keys = NULL;
	}
	if (listing->delimiter != NULL) {
		free(listing->delimiter);
		listing->delimiter = NULL;
	}
	if (listing->prefix != NULL) {
		free(listing->prefix);
		listing->prefix = NULL;
	}

	if (listing->common_prefixs != NULL) {
		size_t j = 0;
		size_t total = listing->_counts_common_prefixs;
		if (listing->common_prefixs != NULL) {
			for (; j < total; j++) {
				if (*(listing->common_prefixs + j) != NULL) {
					free(*(listing->common_prefixs + j));
					*(listing->common_prefixs + j) = NULL;
				}
			}
		}
	}

	free(listing);
}
