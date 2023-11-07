#include <shell.h>

void parse_command(char* input, char** args) {
    int i = 0;
    args[i] = strtok(input, " \t\n");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \t\n");
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char* args[MAX_INPUT_LENGTH];

    while (1) {
        printf(":) ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline

        // Parse the command into arguments
        parse_command(input, args);

        if (args[0] == NULL) {
            continue; // Empty command, prompt again
        }

        if (strcmp(args[0], "exit") == 0) {
            // Handle the "exit" command
            printf("Exiting the shell...\n");
            exit(0);
        }

        // Check if the command exists in the PATH
        char* path = getenv("PATH");
        char* path_copy = strdup(path);
        char* path_token = strtok(path_copy, ":");
        int command_found = 0;

        while (path_token != NULL) {
            char full_path[MAX_PATH_LENGTH];
            snprintf(full_path, sizeof(full_path), "%s/%s", path_token, args[0]);
            if (access(full_path, X_OK) == 0) {
                command_found = 1;
                // Execute the command with arguments
                pid_t child_pid = fork();
                if (child_pid == 0) {
                    // This is the child process
                    execv(full_path, args);
                    // If execv returns, it means the command execution failed
                    perror("execv");
                    exit(1);
                } else if (child_pid > 0) {
                    // This is the parent process
                    int status;
                    waitpid(child_pid, &status, 0);
                } else {
                    perror("fork");
                }
                break;
            }
            path_token = strtok(NULL, ":");
        }

        if (!command_found) {
            printf("Command not found: %s\n", args[0]);
        }

        free(path_copy);
    }

    return 0;
}
