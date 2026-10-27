#include <stdio.h>
#include "file_downloader_driver.h"

void show_message(void) {
    printf("Download complete\n");
}

int main() {
    // register callbacks
    register_download_callback(show_message);

    // run the driver
    download_file();

    return 0;
}