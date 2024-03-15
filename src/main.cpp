#include "../include/helper.hpp"

static struct libinput_interface interface = {
    .open_restricted = [](const char *path, int flags, void *user_data) -> int {
        int fd = open(path, flags);
        return fd >= 0 ? fd : -1;
    },
    .close_restricted = [](int fd, void *user_data) {
        close(fd);
    },
};

int main() {
    struct libinput *li;
    struct libinput_event *event;

    // Create a libinput context
    li = libinput_path_create_context(&interface, NULL);
    if (!li) {
        fprintf(stderr, "Failed to initialize libinput context\n");
        return 1;
    }

    // Configure the context to listen for keyboard events
    libinput_path_add_device(li, "/dev/input/event9");  // Replace eventX with the event number of your keyboard

    // Main event loop
    while (true) {
        libinput_dispatch(li);
        event = libinput_get_event(li);
        if (event) {
            // Handle the event
            if(libinput_event_get_type(event) == LIBINPUT_EVENT_KEYBOARD_KEY) {
                keyboard_event_callback(event, NULL);
            }
            libinput_event_destroy(event);
        }
    }

    // Destroy the libinput context
    libinput_unref(li);
    return 0;
}
