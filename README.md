## The "hsh" Shell

The "hsh" shell works by following these steps:

1. The user launches the shell by running the compiled executable.

2. The shell displays a prompt (e.g., `$ `) indicating that it is ready to receive a command.

3. The user enters a command, which is read by the shell.

4. The shell tokenizes the command into individual words, separating them based on whitespace characters.

5. The shell checks if the command is a built-in command. If it is, the corresponding built-in function is executed.

6. If the command is not a built-in, the shell searches for the command in the directories specified by the `PATH` environment variable. If the command is found, it is executed.

7. If the command is not found in the directories specified by `PATH`, an error message is displayed.

8. The shell waits for the execution of the command to complete.

9. The shell prints the prompt again, indicating that it is ready to receive the next command.

10. The above steps are repeated until the user exits the shell.


Additionally, the shell handles signals such as `Ctrl+C` (SIGINT) to ignore the keyboard interrupt and `Ctrl+D` (EOF) to exit the shell.


## Features

The "hsh" shell provides the following features:

- Execution of system commands.
- Handling command line arguments.
- Environment variable replacement.
- Variable assignment and substitution.
- Control operator (`;`) for command sequencing.
- Built-in commands, including `exit` and `env`.
- Ignoring keyboard interrupts (SIGINT) with `Ctrl+C`.
- Exiting the shell using `Ctrl+D` (EOF).

## Built-in Commands

The "hsh" shell supports the following built-in commands:

- `exit [STATUS]`: Exit the shell with an optional status.
- `env`: Display the current environment variables.

For more details on the usage and behavior of each built-in command, refer to the [Usage](#usage) section or consult the shell's help using the `help` command.

## Usage

To use the "hsh" shell, follow these steps:

1. Launch the shell by running the compiled executable.

2. The shell will display a prompt (e.g., `$ `).

3. Enter a command and press Enter to execute it.

4. The shell will execute the command and display the output, if any.

5. Enter another command or use any of the supported features.

6. To exit the shell, type `exit` and press Enter, or press `Ctrl+D`.

## Example Usage of "hsh" Shell

Here's an example of how to use the **"hsh" shell** for executing commands and utilizing its features:

1. Start the shell by running the executable:
   ```
   $ ./hsh
   ```

2. The shell will display a prompt indicating it's ready to accept commands:
   ```
   $
   ```

3. Execute a system command, such as listing the files in the current directory:
   ```
   $ ls
   file1.txt  file2.txt  directory
   ```

4. Verify the current directory has changed:
   ```
   $ pwd
   /path/to/directory
   ```

5. Display environment variables using the `env` command:
   ```
   $ env
   PATH=/usr/bin:/usr/local/bin:/usr/sbin
   HOME=/home/user
   ...
   ```

6. Exit the shell:
    ```
    $ exit
    ```


The **"hsh" shell** can also be used in non-interactive mode, where commands are read from a file or provided directly as input. Here's an example of using the shell in non-interactive mode:

### 1. Using files
1. Create a file named `commands.txt` containing the commands you want to execute:
   ```shell
   $ echo "ls" > commands.txt
   $ echo "pwd" >> commands.txt
   $ echo "echo Hello, world!" >> commands.txt
   ```

2. Run the **"hsh" shell** with the input file:
   ```shell
   $ ./hsh commands.txt
   ```
   The shell will read the commands from the file and execute them sequentially.

3. The output will be displayed for each command:
   ```shell
   file1.txt  file2.txt  directory
   /path/to/current/directory
   Hello, world!
   ```
### 2. using directly input

You can directly pass commands as input using command substitution or by piping the commands from another command's output. Here's an example:

1. Using command substitution:
   ```shell
   $ ./hsh <<< "ls -l"
   ```
   This command passes the `ls -l` command as input using command substitution (`<<<`). The shell will execute the command and display the output.

2. Piping commands from another command's output:
   ```shell
   $ echo "pwd" | ./hsh
   ```
   This command pipes the `echo "pwd"` command's output as input to the **"hsh" shell**. The shell will execute the command and display the output.

Both methods allow you to provide commands directly as input without the need for an intermediate file. You can customize the commands as per your requirements, and the shell will execute them accordingly.

#### Note
This is just a brief example of the **"hsh" shell** usage. Feel free to explore more commands, functionalities, and features provided by the shell. Refer to the documentation or source code for detailed instructions and additional information.

## Contributing

Contributions to the "hsh" shell project are welcome and encouraged. If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your contribution.
3. Make the necessary changes and commit them.
4. Push your

## Contact

For any questions, issues, or feedback, please contact us at [Mahmoud Hamdy](https://github.com/TutTrue) or [Mohamed Elshafae](https://github.com/MohamedElshafae)

Enjoy using our **"hsh" shell** ^_^!
 simple_shell
