#ifndef __CONFIG_H__
#define __CONFIG_H__

struct ConfigInfo {
	char key[64];
	char value[64];
};

void init(char **encode_text);

void freeConfig();

#endif
