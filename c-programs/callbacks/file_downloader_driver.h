//
// Created by edwin.mwiti on 9/14/2026.
//

#ifndef C_PROGRAMS_FILE_DOWNLOADDER_DRIVER_H
#define C_PROGRAMS_FILE_DOWNLOADDER_DRIVER_H

#include <stdio.h>

typedef void(*download_complete_callback_t)(void);
static download_complete_callback_t complete_cb;

// allow driver to register a callback
void register_download_callback(download_complete_callback_t cb);

// simulate a download finishing
void download_file();

#endif
