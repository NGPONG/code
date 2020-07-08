#pragma warning(disable:6031)
#pragma warning(disable:4996)	

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "config.h"

static struct ConfigInfo *config;

void init(char **encode_text) {

	if (*encode_text == NULL) {
	
		return;
	}

	config = malloc(sizeof(struct ConfigInfo) * 64);
	if (config == NULL) {
	
		return;
	}
	memset(config, 0, 64);

	char *str;
	int index_encode_text = 0;
	int index_config = 0;
	while ((str = encode_text[index_encode_text++]) != NULL) {

		if (!verificationStr(str)) {
		
			continue;
		}

		printf("%s\n", str);

		char *str_temp = strchr(str, ':');
		
		memset(config[index_config].key, 0, 64);
		memset(config[index_config].value, 0, 64);
		memcpy(config[index_config].key, str, str_temp - str);
		memcpy(config[index_config].value, str_temp + 1, strlen(str_temp));

		index_config++;
	}
}

int verificationStr(char *str) {

	if (str[0] == '\0' || str[0] == '\n' || !strchr(str,':')) {
	
		return FALSE;
	}

	return TRUE;
}

void freeConfig() {

	free(config);
}