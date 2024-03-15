# C++ Keylogger

This repository contains a keylogger implemented in C++ that utilizes the libinput library for capturing keyboard input. Please note that this keylogger is designed for educational purposes only, and it should only be used responsibly and with the appropiate permissions.

## Requirements
- Linux operating system
- libinput library
- C++ compiler

## Installation
1. Clone this repository to your local machine:
```Bash
git clone git@github.com:ignabelitzky/keylogger.git
```
2. Navigate to the cloned directory:
```Bash
cd keylogger
```
3. Compile the program using the provided Makefile:
```Bash
make
```

## Usage
To run the keylogger, execute the compiled program with superuser privileges:
```Bash
sudo ./main
```
After 20 keystrokes a file with the name keystrokes.txt is updated with the corresponding pressed keys.
Please note that running the keylogger without superuser privileges may result in errors or incomplete functionality.

## Disclaimer
This keylogger was implemented for educational purposes only. Misuse of this software for illegal activities is strictly prohibited. The author and contributors of this repository are not responsible for any misuse or damage caused by the use of this keylogger.

## Contributing
Contributions to improve the keylogger or add new features are welcome. Please fork the repository, make your changes, and submit a pull request for review.

## License
This project is licensed under the [GNU General Public License v3.0](LICENSE)
