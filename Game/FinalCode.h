#ifndef __FINALCODE__
#define __FINALCODE__
#include <iostream>
#include <vector>
#include <string>
#include "FinalCodewidget.h"
#include "controller.h"


class FinalCode
{
private:
    std::vector<std::string> Stores;
    int sup;
    int n_store;
    int inf;

public:
    FinalCode(const char *);
    std::vector<int> randIdx();
    std::string play();
    int refresh();
};

#endif
