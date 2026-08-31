#include "Bank.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

Bank::Bank(string file)
{
    filename = file;

    srand(static_cast<unsigned int>(time(nullptr)));

    loadAccounts();
}
