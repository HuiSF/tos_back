
#include <kernel.h>
#include <test.h>


/*
 * Make sure that scrolling works
 */
void test_window_3()
{
        int i, j;

        test_reset();
        for (i = 0; i < 30; i++) {
                for (j = 0; j < i; j++) {
                        output_char(kernel_window, '*');
                }
                output_char(kernel_window, '\n');
        }
        wprintf(kernel_window, "Hello World!\n");

        char* expected_output[] = {
                "******",
                "*******",
                "********",
                "*********",
                "**********",
                "***********",
                "************",
                "*************",
                "**************",
                "***************",
                "****************",
                "*****************",
                "******************",
                "*******************",
                "********************",
                "*********************",
                "**********************",
                "***********************",
                "************************",
                "*************************",
                "**************************",
                "***************************",
                NULL
        };

        check_screen_output(expected_output);
        if (test_result != 0)
                test_failed(test_result);
}
