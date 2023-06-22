#pragma once
#include <stdio.h>

// (FILE *) output : Output file
// (void *|os_log_t) log_ent : Logger object given to `os_log_impl`
// (const char *) format : Format string given to `os_log_impl`
// (unsigned char *) buf : Buf object given to `os_log_impl`
// (unsigned int) size : Size variable given to `os_log_impl`
void format_os_log(FILE *output, void *log_ent, const char *format, unsigned char *buf, unsigned int size, int honor_private);