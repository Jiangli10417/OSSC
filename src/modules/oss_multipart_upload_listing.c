/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_upload_listing.c
 *
 *    Description:  oss_multipart_upload_listing.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#define _OSS_MULTIPART_UPLOAD_LISTING_H
#include "oss_multipart_upload_listing.h"
#undef _OSS_MULTIPART_UPLOAD_LISTING_H



void 
multipart_upload_listing_finalize(oss_multipart_upload_listing_t *mul)
{
	if (mul->bucket_name) {
		free(mul->bucket_name);
		mul->bucket_name = NULL;
	}
	if (mul->key_marker) {
		free(mul->key_marker);
		mul->key_marker = NULL;
	}
	if (mul->upload_id_marker) {
		free(mul->upload_id_marker);
		mul->upload_id_marker = NULL;
	}
	if (mul->next_key_marker) {
		free(mul->next_key_marker);
		mul->next_key_marker = NULL;
	}
	if (mul->next_upload_id_marker) {
		free(mul->next_upload_id_marker);
		mul->next_upload_id_marker = NULL;
	}
	if (mul->max_uploads) {
		free(mul->max_uploads);
		mul->max_uploads = NULL;
	}
	if (mul->delimiter) {
		free(mul->delimiter);
		mul->delimiter = NULL;
	}
	if (mul->prefix) {
		free(mul->prefix);
		mul->prefix = NULL;
	}
	if (mul) {
		free(mul);
		mul = NULL;
	}
}

static const char * 
_multipart_upload_listing_get_bucket_name(oss_multipart_upload_listing_t *mul)
{
	return mul->bucket_name;
}

static inline void
__multipart_upload_listing_set_bucket_name(
		oss_multipart_upload_listing_t *mul, 
		const char *bucket_name,
		size_t bucket_name_len)
{
	if (mul->bucket_name) {
		free(mul->bucket_name);
		mul->bucket_name = NULL;
	}
	mul->bucket_name = (char *)malloc(sizeof(char) * bucket_name_len + 1);
	strncpy(mul->bucket_name, bucket_name, bucket_name_len);
	(mul->bucket_name)[bucket_name_len] = '\0';
}

static void
_multipart_upload_listing_set_bucket_name(
		oss_multipart_upload_listing_t *mul, 
		const char *bucket_name)
{
	assert(bucket_name != NULL);
	size_t bucket_name_len = strlen(bucket_name);
	__multipart_upload_listing_set_bucket_name(mul, bucket_name, bucket_name_len);
}

static const char * 
_multipart_upload_listing_get_key_marker(oss_multipart_upload_listing_t *mul)
{
	return mul->key_marker;
}

static inline void
__multipart_upload_listing_set_key_marker(
		oss_multipart_upload_listing_t *mul, 
		const char *key_marker,
		size_t key_marker_len)
{
	if (mul->key_marker) {
		free(mul->key_marker);
		mul->key_marker = NULL;
	}
	mul->key_marker = (char *)malloc(sizeof(char) * key_marker_len + 1);
	strncpy(mul->key_marker, key_marker, key_marker_len);
	(mul->key_marker)[key_marker_len] = '\0';
}

static void
_multipart_upload_listing_set_key_marker(
		oss_multipart_upload_listing_t *mul, 
		const char *key_marker)
{
	assert(key_marker != NULL);
	size_t key_marker_len = strlen(key_marker);
	__multipart_upload_listing_set_key_marker(mul, key_marker, key_marker_len);
}

static const char * 
_multipart_upload_listing_get_upload_id_marker(oss_multipart_upload_listing_t *mul)
{
	return mul->upload_id_marker;
}

static inline void
__multipart_upload_listing_set_upload_id_marker(
		oss_multipart_upload_listing_t *mul, 
		const char *upload_id_marker,
		size_t upload_id_marker_len)
{
	if (mul->upload_id_marker) {
		free(mul->upload_id_marker);
		mul->upload_id_marker = NULL;
	}
	mul->upload_id_marker = (char *)malloc(sizeof(char) * upload_id_marker_len + 1);
	strncpy(mul->upload_id_marker, upload_id_marker, upload_id_marker_len);
	(mul->upload_id_marker)[upload_id_marker_len] = '\0';
}

static void
_multipart_upload_listing_set_upload_id_marker(
		oss_multipart_upload_listing_t *mul, 
		const char *upload_id_marker)
{
	assert(upload_id_marker != NULL);
	size_t upload_id_marker_len = strlen(upload_id_marker);
	__multipart_upload_listing_set_upload_id_marker(mul, upload_id_marker, upload_id_marker_len);
}

static const char * 
_multipart_upload_listing_get_next_key_marker(oss_multipart_upload_listing_t *mul)
{
	return mul->next_key_marker;
}

static inline void
__multipart_upload_listing_set_next_key_marker(
		oss_multipart_upload_listing_t *mul, 
		const char *next_key_marker,
		size_t next_key_marker_len)
{
	if (mul->next_key_marker) {
		free(mul->next_key_marker);
		mul->next_key_marker = NULL;
	}
	mul->next_key_marker = (char *)malloc(sizeof(char) * next_key_marker_len + 1);
	strncpy(mul->next_key_marker, next_key_marker, next_key_marker_len);
	(mul->next_key_marker)[next_key_marker_len] = '\0';
}

static void
_multipart_upload_listing_set_next_key_marker(
		oss_multipart_upload_listing_t *mul, 
		const char *next_key_marker)
{
	assert(next_key_marker != NULL);
	size_t next_key_marker_len = strlen(next_key_marker);
	__multipart_upload_listing_set_next_key_marker(mul, next_key_marker, next_key_marker_len);
}

static const char * 
_multipart_upload_listing_get_next_upload_id_marker(oss_multipart_upload_listing_t *mul)
{
	return mul->next_upload_id_marker;
}

static inline void
__multipart_upload_listing_set_next_upload_id_marker(
		oss_multipart_upload_listing_t *mul, 
		const char *next_upload_id_marker,
		size_t next_upload_id_marker_len)
{
	if (mul->next_upload_id_marker) {
		free(mul->next_upload_id_marker);
		mul->next_upload_id_marker = NULL;
	}
	mul->next_upload_id_marker = (char *)malloc(sizeof(char) * next_upload_id_marker_len + 1);
	strncpy(mul->next_upload_id_marker, next_upload_id_marker, next_upload_id_marker_len);
	(mul->next_upload_id_marker)[next_upload_id_marker_len] = '\0';
}

static void
_multipart_upload_listing_set_next_upload_id_marker(
		oss_multipart_upload_listing_t *mul, 
		const char *next_upload_id_marker)
{
	assert(next_upload_id_marker != NULL);
	size_t next_upload_id_marker_len = strlen(next_upload_id_marker);
	__multipart_upload_listing_set_next_upload_id_marker(mul, next_upload_id_marker, next_upload_id_marker_len);
}

static const char * 
_multipart_upload_listing_get_max_uploads(oss_multipart_upload_listing_t *mul)
{
	return mul->max_uploads;
}

static inline void
__multipart_upload_listing_set_max_uploads(
		oss_multipart_upload_listing_t *mul, 
		const char *max_uploads,
		size_t max_uploads_len)
{
	if (mul->max_uploads) {
		free(mul->max_uploads);
		mul->max_uploads = NULL;
	}
	mul->max_uploads = (char *)malloc(sizeof(char) * max_uploads_len + 1);
	strncpy(mul->max_uploads, max_uploads, max_uploads_len);
	(mul->max_uploads)[max_uploads_len] = '\0';
}

static void
_multipart_upload_listing_set_max_uploads(
		oss_multipart_upload_listing_t *mul, 
		const char *max_uploads)
{
	assert(max_uploads != NULL);
	size_t max_uploads_len = strlen(max_uploads);
	__multipart_upload_listing_set_max_uploads(mul, max_uploads, max_uploads_len);
}

static bool
_multipart_upload_listing_get_is_truncated(oss_multipart_upload_listing_t *mul)
{
	return mul->is_truncated;
}

static inline void
_multipart_upload_listing_set_is_truncated(
		oss_multipart_upload_listing_t *mul, 
		bool is_truncated)
{
	mul->is_truncated = is_truncated;
}

static const char * 
_multipart_upload_listing_get_delimiter(oss_multipart_upload_listing_t *mul)
{
	return mul->delimiter;
}

static inline void
__multipart_upload_listing_set_delimiter(
		oss_multipart_upload_listing_t *mul, 
		const char *delimiter,
		size_t delimiter_len)
{
	if (mul->delimiter) {
		free(mul->delimiter);
		mul->delimiter = NULL;
	}
	mul->delimiter = (char *)malloc(sizeof(char) * delimiter_len + 1);
	strncpy(mul->delimiter, delimiter, delimiter_len);
	(mul->delimiter)[delimiter_len] = '\0';
}

static void
_multipart_upload_listing_set_delimiter(
		oss_multipart_upload_listing_t *mul, 
		const char *delimiter)
{
	assert(delimiter != NULL);
	size_t delimiter_len = strlen(delimiter);
	__multipart_upload_listing_set_delimiter(mul, delimiter, delimiter_len);
}

static const char * 
_multipart_upload_listing_get_prefix(oss_multipart_upload_listing_t *mul)
{
	return mul->prefix;
}

static inline void
__multipart_upload_listing_set_prefix(
		oss_multipart_upload_listing_t *mul, 
		const char *prefix,
		size_t prefix_len)
{
	if (mul->prefix) {
		free(mul->prefix);
		mul->prefix = NULL;
	}
	mul->prefix = (char *)malloc(sizeof(char) * prefix_len + 1);
	strncpy(mul->prefix, prefix, prefix_len);
	(mul->prefix)[prefix_len] = '\0';
}

static void
_multipart_upload_listing_set_prefix(
		oss_multipart_upload_listing_t *mul, 
		const char *prefix)
{
	assert(prefix != NULL);
	size_t prefix_len = strlen(prefix);
	__multipart_upload_listing_set_prefix(mul, prefix, prefix_len);
}

oss_multipart_upload_listing_t *
multipart_upload_listing_initialize(void)
{
	oss_multipart_upload_listing_t *mul;
	mul = (oss_multipart_upload_listing_t *)malloc(sizeof(oss_multipart_upload_listing_t));
	mul->bucket_name = NULL;
	mul->key_marker = NULL;
	mul->upload_id_marker = NULL;
	mul->next_key_marker = NULL;
	mul->next_upload_id_marker = NULL;
	mul->max_uploads = NULL;
	mul->delimiter = NULL;
	mul->prefix = NULL;
	mul->is_truncated = false;

	mul->get_bucket_name = _multipart_upload_listing_get_bucket_name;
	mul->set_bucket_name = _multipart_upload_listing_set_bucket_name;
	mul->get_key_marker = _multipart_upload_listing_get_key_marker;
	mul->set_key_marker = _multipart_upload_listing_set_key_marker;
	mul->get_upload_id_marker = _multipart_upload_listing_get_upload_id_marker;
	mul->set_upload_id_marker = _multipart_upload_listing_set_upload_id_marker;
	mul->get_next_key_marker = _multipart_upload_listing_get_next_key_marker;
	mul->set_next_key_marker = _multipart_upload_listing_set_next_key_marker;
	mul->get_next_upload_id_marker = _multipart_upload_listing_get_next_upload_id_marker;
	mul->set_next_upload_id_marker = _multipart_upload_listing_set_next_upload_id_marker;
	mul->get_max_uploads = _multipart_upload_listing_get_max_uploads;
	mul->set_max_uploads = _multipart_upload_listing_set_max_uploads;
	mul->get_is_truncated = _multipart_upload_listing_get_is_truncated;
	mul->set_is_truncated = _multipart_upload_listing_set_is_truncated;
	mul->get_delimiter = _multipart_upload_listing_get_delimiter;
	mul->set_delimiter = _multipart_upload_listing_set_delimiter;
	mul->get_prefix = _multipart_upload_listing_get_prefix;
	mul->set_prefix = _multipart_upload_listing_set_prefix;

	return mul;
}