


#include "parcer.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
        cout << "Wrong number of arguments!" << endl;
    else {

        Parcer parcer((string(argv[1])));
        parcer.parce();

    }
}
