/*
 * =============================================================================
 *
 *       Filename:  oss_upload_part_result.h
 *
 *    Description:  oss_upload_part_result.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technuprogy, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_UPLOAD_PART_RESULT_H
# error Never include <ossc/modules/oss_upload_part_result.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_UPLOAD_PART_RESULT_H
#define OSS_UPLOAD_PART_RESULT_H
#include "ossc-config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_PART_ETAG_H
#include <ossc/modules/oss_part_etag.h>
#undef _OSS_PART_ETAG_H



typedef struct oss_upload_part_result_s oss_upload_part_result_t;

struct oss_upload_part_result_s {
	char *etag;
	int part_number;

	const char * (*get_etag)(oss_upload_part_result_t *result);
	void (*set_etag)(oss_upload_part_result_t *result, const char *etag);
	int(*get_part_number)(oss_upload_part_result_t *result);
	void (*set_part_number)(oss_upload_part_result_t *result, int part_number);

	oss_part_etag_t * (*get_part_etag)(oss_upload_part_result_t * result);
};

extern oss_upload_part_result_t *
upload_part_result_initialize();

extern void 
upload_part_result_finalize(oss_upload_part_result_t *result);

#endif
