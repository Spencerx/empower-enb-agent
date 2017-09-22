/* Copyright (c) 2017 Kewin Rausch
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

/*    HELLO MESSAGE
 *
 * Such message is a presentation done by the agent to the controller.
 * Usually its used to check the connection between agent and controller.
 */

#ifndef __EMAGE_PROTOCOLS_HELLO_H
#define __EMAGE_PROTOCOLS_HELLO_H

#include <stdint.h>

/*
 * Hello message
 */

typedef struct __ep_hello_reply {
	uint32_t id;
}__attribute__((packed)) ep_hello_rep;

typedef struct __ep_hello_request {
	uint32_t id;
}__attribute__((packed)) ep_hello_req;

/* Format an Hello request message with the desired fields.
 * Returns the size of the message, or a negative error number.
 */
int epf_single_hello_req(
	char * buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t id);

#endif /* __EMAGE_PROTOCOLS_HELLO_H */
