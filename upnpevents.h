/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2008 Thomas Bernard
 * This software is subject to the conditions detailed
 * in the LICENCE file provided within the distribution */

#ifndef __UPNPEVENTS_H__
#define __UPNPEVENTS_H__
enum subscriber_service_enum {
 EContentDirectory = 1,
 EConnectionManager,
 EMSMediaReceiverRegistrar
};

void
upnp_event_var_change_notify(enum subscriber_service_enum service);

const char *
upnpevents_addSubscriber(const char * eventurl,
                         const char * callback, int callbacklen,
                         int timeout);

int
upnpevents_removeSubscriber(const char * sid, int sidlen);

int
renewSubscription(const char * sid, int sidlen, int timeout);

void upnpevents_selectfds(fd_set *readset, fd_set *writeset, int * max_fd);
void upnpevents_processfds(fd_set *readset, fd_set *writeset);

#ifdef USE_MINIUPNPDCTL
void write_events_details(int s);
#endif

#endif
