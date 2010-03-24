//============================================================================
// Name        : command-line-agrs.cpp
// Author      : Matt Todd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;

void print_out_args(int argc, char *argv[])
{
    cout << "Args: ";
    for(int i = 0;i < argc;i++){
        cout << argv[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
	cout << "argc: " << argc << "\n";

	cout << "sizeof argv: " << sizeof(argv) << "\n";

    print_out_args(argc, argv);

	return EXIT_SUCCESS;
}
