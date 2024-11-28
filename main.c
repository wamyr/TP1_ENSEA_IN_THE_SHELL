#include "question1.h"
#include "question2.h"
#include "question3.h"
#include "question4.h"
#include "question5.h"
#include "question6.h"
#define True 1

int main(void) {
    welcome();
    char command[MAXSIZE] = {0};
    int status = 0;
    print_prompt();
    print_pourcentage();
    while(True) {
        prompt_reading(command);
        start_timer();
        //execute_command(command, &status);
        execute_command_complex(command, &status);
        end_timer();
        if (command_exit(command) == True) {
            exit(0);
        }
        print_prompt();
        print_status(status);
        print_time(get_time());
        print_pourcentage();
    }
    return 0;
}
