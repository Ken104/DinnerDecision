#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "FinalCode.h"

FinalCode::FinalCode(const char *filename)
{
    std::ifstream ifs(filename);
    std::string store;
    if (!ifs.is_open())
    {
        std::cout << "Failed open file!" << std::endl;
        return;
    }

    while (std::getline(ifs, store))
    {
        Stores.push_back(store);
    }
    ifs.close();
    n_store = Stores.size();
    sup = (ceil(n_store / 100) + 1) * 100;
    inf = 0;
}

int FinalCode::refresh()
{
    if (Stores.empty())
    {
        std::cout << "Please contruct first." << std::endl;
        return -1;
    }
    n_store = Stores.size();
    sup = (ceil(n_store / 100) + 1) * 100;
    inf = 0;
    return 0;
}

std::string FinalCode::play()
{
    std::vector<int> storeNo;
    std::vector<std::string> remainStores(Stores);
    std::vector<int> buffer;
    int a=0, b=0;
    bool is_existed = false;

    srand(time(NULL));

    storeNo = randIdx();

    /* implement play process */
    while(remainStores.size() > 1)
    {
        // show remain restaurants

        // show the hint of input

        // Read two number a, b

        // check the order of a, b
        if(a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }

        if((a==b) || (a < inf) || (b > sup))
        {
            // address WrongTypying()
            continue;
        }

        is_existed = false;
        buffer = storeNo;
        for(int i=0; i < remainStores.size(); ++i)
        {
            if((storeNo[i] >= a) && (storeNo[i] < b))
                is_existed = true;
            else
                buffer[i] = 0;
        }

        if(!is_existed)
        {
            // address WrongTypying()
            continue;
        }

        for(int i = buffer.size()-1; i >= 0; --i)
        {
            if(buffer[i] == 0)
            {
                remainStores.erase(remainStores.begin() + i);
                storeNo.erase(storeNo.begin() + i);
            }
        }

        inf = a;
        sup = b;
    }

    return remainStores.front();
}

std::vector<int> FinalCode::randIdx()
{
    std::vector<int> myIdx(n_store, 0);
    bool is_used;

    for (int i = 0; i < n_store; i++)
    {
        do
        {
            is_used = false;
            myIdx[i] = rand() % sup;
            for (int j = 0; j < i; j++)
            {
                is_used = true;
                break;
            }
        } while (is_used);
    }

    return myIdx;
}
