#include "Node.h"
#include <unistd.h>
#include <iostream>

int main (int argc, char* argv[])
{
    size_t num_nodes = 4;

    size_t n = 1;
    size_t rQuorum = 1;
    size_t wQuorum = 1;

    for (int i = 0; i < num_nodes; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            std::cout << "My id is: " << i << std::endl;
            Node node(i, n, rQuorum, wQuorum);
            exit(0);
        }
    }
    return 0;   
}