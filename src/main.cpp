#include "Node.h"
#include <unistd.h>
#include <iostream>

int main (int argc, char* argv[])
{
    size_t num_nodes = 4;

    size_t n = 1;
    size_t r_quorum = 1;
    size_t w_quorum = 1;

    size_t default_port = 30000;

    for (int i = 0; i < num_nodes; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            std::cout << "Node created with id: " << i << std::endl;
            node node(i, default_port+i, n, r_quorum, w_quorum);
            exit(0);
        }
    }
    return 0;   
}