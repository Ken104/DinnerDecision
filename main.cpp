#include "Restaurants.h"
#include <iostream>

using namespace std;

int main(){
    Restaurants *mytest = nullptr;
    Restaurant res1;
    vector<Food_Catagory> query(CATAGORY_NUM, false);
    res1.name(string("Abao"));
    res1.address(string("CY"));
    res1.phone(string("0228836654"));
    res1.kind(Food::BRAISE, true);
    res1.opening_time(Time::Evening, true);
    res1.price(60);

    mytest = new Restaurants();
    
    mytest->insert(res1);

    res1.name(string("123"));
    res1.phone(string("0288641124"));
    res1.kind(Food::BREAKFAST, true);
    res1.opening_time(Time::Moring, true);


    mytest->insert(res1);

    mytest->show();

    query[Food::BREAKFAST] = true;
    
    auto would_like = mytest->find(query);

    cout << "\nQuerying start:" << endl;
    for (auto it=would_like.begin();it!=would_like.end();++it)
    {
        it->view();
        it->view_kind();
    }

    delete mytest;
}