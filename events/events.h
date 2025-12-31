#ifndef EVENTS_H
#define EVENTS_H

typedef enum {
  EVENT_NONE,
  EV_CREDENTIALS_REQUESTED,
  EV_CONNECTED_TO_TRADFRI,
  EV_USER_REQUESTED_ALL_LAMPS,
  EV_USER_REQUESTED_LAMP,
  EV_USER_REQUESTED_TURN_ON_LAMP,
  EV_USER_REQUESTED_TURN_OFF_LAMP,
  EV_USER_REQUESTED_DIM_LAMP,
  EV_USER_REQUESTED_COLOR_LAMP,
  EV_USER_REQUEST_HANDLED,
  NUMBER_OF_EVENTS,
} Events_t;

typedef struct {
  char ipAddress[20];
  char identity[64];
  char key[64];
} EV_CREDENTIALS_REQUESTED_t;

typedef struct {
  uint32_t lampId;
} EV_USER_REQUESTED_LAMP_t, EV_USER_REQUESTED_TURN_ON_LAMP_t,
    EV_USER_REQUESTED_TURN_OFF_LAMP_t;

typedef struct {
  uint32_t lampId;
  uint8_t dimValue;
} EV_USER_REQUESTED_DIM_LAMP_t;

typedef struct {
  uint32_t lampId;
  char colorHex[7];
} EV_USER_REQUESTED_COLOR_LAMP_t;
#endif