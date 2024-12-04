#include "question1.h"
#include "question2.h"
#include "question3.h"
#include "question4.h"
#include "question5.h"
#include "question6.h"
#include "question7.h"
#include "question8.h"


int main(void) {

    char command[MAXSIZE] = {0};
    int status = 0;
    char* argv[MAXSIZE];
    int position_pipe_or_bracket = 0;

    welcome_message();
    print_prompt();
    print_percentage(); //the welcome message and first prompt (without exit or sign) is printed

    while(True) {
        prompt_reading(command); //shell instruction stored in the char table : command
        start_timer(); //timer launched for the command execution time
        separate_arguments(command, argv); //separate each argument of command and store it in argv
        switch (identify_pipe_and_brackets(argv, &position_pipe_or_bracket)) { //determine if there is < > or | in the received command and execute the associated operation.
            case HAVE_PIPE:
                execute_command_pipe(argv, &status, position_pipe_or_bracket);
                break;
            case HAVE_LESSER_THAN:
                execute_command_lesser_than(argv, &status, position_pipe_or_bracket);
                break;
            case HAVE_GREATER_THAN:
                execute_command_greater_than(argv, &status, position_pipe_or_bracket);
                break;
            case NO_PIPE_NO_LESSER_THAN_NO_GREATER_THAN:
                execute_command_complex(argv, &status);
                break;
            default:
                break;
        }
        end_timer();
        if (command_exit(command) == True) { //if the instruction is exit, we stop
            exit(0);
        }
        print_prompt(); //the command has been executed, no exit, we print the next prompt
        print_status(status); //Displaying the return code (or signal) of the previous command in the prompt
        print_time(get_time());// get_time return the command execution time, we just print it
        print_percentage();
    }
    return 0;
}
