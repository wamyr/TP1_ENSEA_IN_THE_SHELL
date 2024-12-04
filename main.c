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

    welcome();
    print_prompt();
    print_percentage();

    while(True) {
        prompt_reading(command);
        start_timer();
        //execute_command(command, &status);
        separate_arguments(command, argv);
        switch (identify_pipe_and_brackets(argv, &position_pipe_or_bracket)) {
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
        }
        end_timer();
        if (command_exit(command) == True) {
            exit(0);
        }
        print_prompt();
        print_status(status);
        print_time(get_time());
        print_percentage();
    }
    return 0;
}
