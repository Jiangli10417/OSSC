/*
 * =============================================================================
 *
 *       Filename:  oss_object_summary.c
 *
 *    Description:  oss_object_summary.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#define _OSS_OBJECT_SUMMARY_H
#include <ossc/modules/oss_object_summary.h>
#undef _OSS_OBJECT_SUMMARY_H

static const char * 
_object_summary_get_bucket_name(oss_object_summary_t *summary)
{
	return summary->bucket_name;
}

static inline void
__object_summary_set_bucket_name(
		oss_object_summary_t *summary,
		const char *bucket_name,
		size_t bucket_name_len)
{
	if (summary->bucket_name != NULL) {
		free(summary->bucket_name);
		summary->bucket_name = NULL;
	}

	summary->bucket_name = (char *)malloc(sizeof(char) * bucket_name_len + 1);
	strncpy(summary->bucket_name, bucket_name, bucket_name_len);
	(summary->bucket_name)[bucket_name_len] = '\0';
}

static void
_object_summary_set_bucket_name(
		oss_object_summary_t *summary,
		const char *bucket_name)
{
	assert(bucket_name != NULL);

	size_t bucket_name_len = strlen(bucket_name);
	__object_summary_set_bucket_name(summary, bucket_name, bucket_name_len);
}

static const char * 
_object_summary_get_etag(oss_object_summary_t *summary)
{
	return summary->etag;
}

static inline void
__object_summary_set_etag(
		oss_object_summary_t *summary,
		const char *etag,
		size_t etag_len)
{
	if (summary->etag != NULL) {
		free(summary->etag);
		summary->etag = NULL;
	}

	summary->etag = (char *)malloc(sizeof(char) * etag_len + 1);
	strncpy(summary->etag, etag, etag_len);
	(summary->etag)[etag_len] = '\0';
}

static void
_object_summary_set_etag(
		oss_object_summary_t *summary,
		const char *etag)
{
	assert(etag != NULL);

	size_t etag_len = strlen(etag);
	__object_summary_set_etag(summary, etag, etag_len);
}


static const char * 
_object_summary_get_key(oss_object_summary_t *summary)
{
	return summary->key;
}

static inline void
__object_summary_set_key(
		oss_object_summary_t *summary,
		const char *key,
		size_t key_len)
{
	if (summary->key != NULL) {
		free(summary->key);
		summary->key = NULL;
	}

	summary->key = (char *)malloc(sizeof(char) * key_len + 1);
	strncpy(summary->key, key, key_len);
	(summary->key)[key_len] = '\0';
}

static void
_object_summary_set_key(
		oss_object_summary_t *summary,
		const char *key)
{
	assert(key != NULL);

	size_t key_len = strlen(key);
	__object_summary_set_key(summary, key, key_len);
}

static const char * 
_object_summary_get_last_modified(oss_object_summary_t *summary)
{
	return summary->last_modified;
}

static inline void
__object_summary_set_last_modified(
		oss_object_summary_t *summary,
		const char *last_modified,
		size_t last_modified_len)
{
	if (summary->last_modified != NULL) {
		free(summary->last_modified);
		summary->last_modified = NULL;
	}
	summary->last_modified = (char *)malloc(sizeof(char) * last_modified_len + 1);
	strncpy(summary->last_modified, last_modified, last_modified_len);
	(summary->last_modified)[last_modified_len] = '\0';
}

static void
_object_summary_set_last_modified(
		oss_object_summary_t *summary,
		const char *last_modified)
{
	assert(last_modified != NULL);

	size_t last_modified_len = strlen(last_modified);
	__object_summary_set_last_modified(summary, last_modified, last_modified_len);
}

static const char * 
_object_summary_get_storage_class(oss_object_summary_t *summary)
{
	return summary->storage_class;
}

static inline void
__object_summary_set_storage_class(
		oss_object_summary_t *summary,
		const char *storage_class,
		size_t storage_class_len)
{
	if (summary->storage_class != NULL) {
		free(summary->storage_class);
		summary->storage_class = NULL;
	}
	summary->storage_class = (char *)malloc(sizeof(char) * storage_class_len + 1);
	strncpy(summary->storage_class, storage_class, storage_class_len);
	(summary->storage_class)[storage_class_len] = '\0';
}

static void
_object_summary_set_storage_class(
		oss_object_summary_t *summary,
		const char *storage_class)
{
	assert(storage_class != NULL);

	size_t storage_class_len = strlen(storage_class);
	__object_summary_set_storage_class(summary, storage_class, storage_class_len);
}

static long
_object_summary_get_size(oss_object_summary_t *summary)
{
	return summary->size;
}

static void
_object_summary_set_size(
		oss_object_summary_t *summary,
		long size)
{
	summary->size = size;
}


static oss_owner_t * 
_object_summary_get_owner(oss_object_summary_t *summary)
{
	return summary->owner;
}

static void
_object_summary_set_owner(
		oss_object_summary_t *summary,
		oss_owner_t *owner)
{
	assert(owner != NULL);
	//if(summary->owner)
	//	owner_finalize(summary->owner);
	summary->owner = owner;
	//summary->owner = (oss_owner_t *)malloc(sizeof(oss_owner_t));
	//size_t display_name_len = strlen(owner->display_name);
	//summary->owner->display_name = (char *)malloc(sizeof(char) * display_name_len + 1);
	//strncpy(summary->owner->display_name, owner->display_name, display_name_len);
	//(summary->owner->display_name)[display_name_len] = '\0';

	//size_t id_len = strlen(owner->id);
	//summary->owner->id = (char *)malloc(sizeof(char) * id_len + 1);
	//strncpy(summary->owner->id, owner->id, id_len);
	//(summary->owner->id)[id_len] = '\0';

}

oss_object_summary_t *
object_summary_initialize(void)
{
	oss_object_summary_t *summary;
	summary = (oss_object_summary_t *)malloc(sizeof(oss_object_summary_t));

	summary->bucket_name = NULL;
	summary->etag = NULL;
	summary->key = NULL;
	summary->last_modified = NULL;
	summary->storage_class = NULL;
	summary->size = 0;
	summary->owner = NULL;

	summary->get_bucket_name = _object_summary_get_bucket_name;
	summary->set_bucket_name = _object_summary_set_bucket_name;
	summary->get_key = _object_summary_get_key;
	summary->set_key = _object_summary_set_key;
	summary->get_last_modified = _object_summary_get_last_modified;
	summary->set_last_modified = _object_summary_set_last_modified;
	summary->get_storage_class = _object_summary_get_storage_class;
	summary->set_storage_class = _object_summary_set_storage_class;
	summary->get_size = _object_summary_get_size;
	summary->set_size = _object_summary_set_size;
	summary->get_etag = _object_summary_get_etag;
	summary->set_etag = _object_summary_set_etag;
	summary->get_owner = _object_summary_get_owner;
	summary->set_owner = _object_summary_set_owner;

	return summary;
}

void object_summary_finalize(oss_object_summary_t *summary)
{
	assert(summary != NULL);
	if (summary->bucket_name != NULL) {
		free(summary->bucket_name);
		summary->bucket_name = NULL;
	}

	if (summary->etag != NULL) {
		free(summary->etag);
		summary->etag = NULL;
	}

	if (summary->key != NULL) {
		free(summary->key);
		summary->key = NULL;
	}

	if (summary->last_modified != NULL) {
		free(summary->last_modified);
		summary->last_modified = NULL;
	}

	if (summary->storage_class != NULL) {
		free(summary->storage_class);
		summary->storage_class = NULL;
	}

	if (summary->owner != NULL) {
		summary->owner = NULL;
	}

	free(summary);
}
