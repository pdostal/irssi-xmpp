/* $Id: xmpp-channels.h,v 1.5 2007/10/08 19:44:31 cdidier Exp $ */

#ifndef __XMPP_CHANNELS_H
#define __XMPP_CHANNELS_H

#include "channels.h"
#include "xmpp-servers.h"

/* Returns XMPP_CHANNEL_REC if it's XMPP channel, NULL if it isn't. */
#define XMPP_CHANNEL(channel) 					\
	PROTO_CHECK_CAST(CHANNEL(channel), XMPP_CHANNEL_REC, chat_type, "XMPP")

#define IS_XMPP_CHANNEL(channel) 				\
	(XMPP_CHANNEL(channel) ? TRUE : FALSE)

#define xmpp_channel_find(server, name) 			\
	XMPP_CHANNEL(channel_find(SERVER(server), name))

#define STRUCT_SERVER_REC XMPP_SERVER_REC
struct _XMPP_CHANNEL_REC {
	#include "channel-rec.h"

	char	*nick;

	gboolean non_anonymous; /* status code 100 */
	gboolean logging; /* status code 170 */

	time_t	 composing_time;
};

__BEGIN_DECLS
CHANNEL_REC	*xmpp_channel_create(XMPP_SERVER_REC *, const char *,
		     const char *, int, const char *);
void		 xmpp_channel_send_message(XMPP_SERVER_REC *, const char *,
		     const char *);

void xmpp_channels_init(void);
void xmpp_channels_deinit(void);
__END_DECLS

#endif