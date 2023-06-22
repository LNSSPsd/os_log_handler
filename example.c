#include <substrate.h>
#include "os_log_handler.h"

static FILE *log_file;

void *orig_os_log_impl;
void my_os_log_impl(void *dso, void *log_ent, uint64_t type, const char *format, uint8_t *buf, uint32_t size) {
	format_os_log(log_file, log_ent, format, buf, size, 0);
	fflush(log_file);
}

__attribute__((constructor)) static void log_redirector_init() {
	log_file=fopen("/var/log/my_os_log_output.txt", "wb");
	MSHookFunction(_dyld_get_image_vmaddr_slide(0)+0x100538D64/*address of _os_log_impl or whatsoever*/, (void*)my_os_log_impl, &orig_os_log_impl);
}

__attribute__((destructor)) static void log_redirector_teardown() {
	fclose(log_file);
}