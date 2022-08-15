#pragma once

#include <stddef.h>

#define      _PASSWORD_LEN           128
#define BCRYPT_USE_SYSTEM_PREFERRED_RNG 0x00000002

int             bcrypt_newhash(const char*, int, char*, size_t);
int             bcrypt_checkpass(const char*, const char*);
