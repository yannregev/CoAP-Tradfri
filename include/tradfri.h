#ifndef TRADFRI_H
#define TRADFRI_H



//int tradfri_init();
int tradfri_get_all_lamps(char* response);
int tradfri_turn_on_lamp(char* lamp_endpoint, char* response);
int tradfri_turn_off_lamp(char* lamp_endpoint, char* response);

#endif