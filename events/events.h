#ifndef EVENTS_H
#define EVENTS_H

typedef enum {
    EVENT_NONE,
    EV_CREDENTIALS_REQUESTED,
    EV_USER_REQUESTED_ALL_LIGHTS,
    EV_CONNECTED_TO_TRADFRI,
    NUMBER_OF_EVENTS,
}Events_t;

typedef struct {
    char ipAddress[16];
    char identity[64];
	char key[64];
}EV_CREDENTIALS_REQUESTED_t;

#endif