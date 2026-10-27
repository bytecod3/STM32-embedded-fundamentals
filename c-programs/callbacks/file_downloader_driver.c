#include <stdio.h>

#include "file_downloader_driver.h"

// allow driver to register a callback
void register_download_callback(download_complete_callback_t cb) {
    complete_cb = cb;
}

// simulate a download finishing
void download_file() {
    /// download logic here
    ///
    ///
    ///


    if (complete_cb) {
        complete_cb();
    }
}