


#include "computor.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
        cout << "Wrong number of arguments!" << endl;
    else {

        Computor computor((string(argv[1])));

        // computor.__debug();
        if (computor.init()) {
            computor.print_reduced_form();
            if (computor.print_polynomial_degree()) {
                computor.solve_equation();

            }
        }
    }
}
