#include <stdio.h>
#include <ospace/unix.h>
int child_function()
{
    while (true) // Loop forever.
    {
        Printf("Child loop\n");
        os_this_process::sleep(1);
    }
    return 0; // Will never execute.
}
int main()
{
    os_unix_toolkit initialize;
    os_process child(child function); // Spawn child. os_this_process::sleep( 4 ); printf("child.suspend()\n");
    child.suspend();
    printf("Parent sleeps for 4 seconds\n");
    os_this_process::sleep(4);
    printf("child.resume()");
    child.resume();
    os_this_process::sleep(4);
    printf("child.terminate()");
    child.terminate();
    printf("Parent finished");
    return 0;
}
