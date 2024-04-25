#C - Simple Shell
![alt text](https://uploads-ssl.webflow.com/6105315644a26f77912a1ada/63eea844ae4e3022154e2878_Holberton.png)

##Overview
Basic Shell is a simple, interactive command line interpreter that provides a user interface to access the operating system's services. It is designed to execute commands and manage your files and processes.

## General
Unified Shell merges the essential features from various shell implementations to provide a robust and user-friendly command-line interface.

![Shell GIF](https://i.makeagif.com/media/4-11-2016/n0XzXz.gif)

## Key Functionalities
- **User-Friendly Prompt:** Offers a clear and welcoming prompt for user interaction.
- **Command Execution:** Executes commands with graceful error handling.
- **File Navigation:** Allows easy navigation through directories and file management.
- **Process Management:** Manages processes efficiently, including script execution.
- **Custom Commands:** Supports built-in commands like `exit` and `env` for enhanced functionality.

## Installation
To install Unified Shell, follow these steps:

1. Clone the repository:
    ```bash
    git clone <repository_url>
    ```
2. Compile the code:
    ```bash
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o UnifiedShell
    ```
3. Run the compiled shell:
    ```bash
    ./UnifiedShell
    ```


## Custom Commands
Unified Shell supports the following custom commands:
- `exit`: Terminates the shell or program.
- `env`: Displays the current environment or runs a specified command in a modified environment.

## Contributing
Contributions from developers like you make Unified Shell better. Here's how you can contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeature`).
3. Commit your changes (`git commit -m 'Add YourFeature'`).
4. Push to the branch (`git push origin feature/YourFeature`).
5. Open a pull request.

## Content of Files
| File                | Description                                  |
| ------------------- | -------------------------------------------- |
| [AUTHORS](link)     | List of contributors to the repository       |
| [man_1_simple_shell](link)  | Information about the repository             |
| [main.h](link)      | Prototypes, functions, and headers           |
| [Flowchart](link)   | Visual representation of shell's workflow    |

##Authors
-Narmin Mammadova
-Rufat Jabbarov
