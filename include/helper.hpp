#ifndef HELPER_HPP
#define HELPER_HPP

#include <libinput.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <fstream>
#include <vector>
#include <iostream>
#include "params.hpp"

int keyboard_event_callback(struct libinput_event *event, void *user_data);

#endif