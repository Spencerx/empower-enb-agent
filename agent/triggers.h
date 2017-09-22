/* Copyright (c) 2016 Kewin Rausch
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Empower Agent internal triggers logic.
 */

#ifndef __EMAGE_TRIGGERS_H
#define __EMAGE_TRIGGERS_H

#include "emlist.h"

/* Definition for a single trigger. */
struct trigger {
	/* Member of a list. */
	struct list_head next;

	/* Id of this trigger. */
	int id;
	/* Type of this trigger. */
	int type;

	/* Original request message. */
	char * req;
	/* Size of the original request */
	unsigned int size;
};

/* Triggering context for an agent. */
struct tr_context {
	/* List of triggers. */
	struct list_head ts;

	/* Id for the next trigger*/
	int next;

	/* Lock for this context. */
	pthread_spinlock_t lock;
};

/* Add a new trigger in the agent triggering context.
 * By adding a trigger you make it valid, since disabled triggers are just
 * removed from the list.
 */
struct trigger * tr_add(
	struct tr_context * tc,
	int id,
	int type,
	char * req,
	unsigned char size);

/* Find, remove and free a trigger */
int tr_del(struct tr_context * tc, int id, int type);

/* Find an existing trigger */
struct trigger * tr_find(struct tr_context * tc, int id, int type);

/* Flush everything and clean the context. */
int tr_flush(struct tr_context * tc);

/* Free the resources of a trigger */
void tr_free(struct trigger * tc);

/* Peek the context to see if it has a specific trigger. */
struct trigger * tr_has_trigger(struct tr_context * tc, int id, int type);

/* Acquires the next usable trigger id */
int tr_next_id(struct tr_context * tc);

/* Removes a trigger from the agent triggering context. */
int tr_rem(struct tr_context * tc, int id, int type);

#endif
