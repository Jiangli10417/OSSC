/*
 * =============================================================================
 *
 *       Filename:  oss_grant.h
 *
 *    Description:  oss_grant.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_GRANT_H
# error Never include <ossc/modules/oss_grant.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_GRANT_H
#define OSS_GRANT_H
#include "ossc-config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct oss_grant_s oss_grant_t;

struct oss_grant_s {
	char *identifier;
	char *permission;
	struct oss_grant_s *next;

	const char * (*get_identifier)(oss_grant_t *grant);
	void (*set_identifier)(oss_grant_t *grant, const char * identifier);

	const char * (*get_permission)(oss_grant_t *grant);
	void (*set_permission)(oss_grant_t *grant, const char *permission);

};

extern oss_grant_t *
grant_initialize(const char *identifier, const char *permission);

extern void 
grant_finalize(oss_grant_t *grant);

#endif
