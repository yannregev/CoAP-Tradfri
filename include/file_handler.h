#ifndef FILE_HANDER_H_
#define FILE_HANDER_H_

typedef struct {
	char *identity;
	char *key;
}Credentials_t;

void FileHandlerInit(void);


int GetIpAddress(char *buffer, int size);


#endif //FILE_HANDER_H_