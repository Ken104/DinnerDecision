#include "Restaurants.h"
#include <iostream>

using namespace std;

int main(){
    Restaurants *mytest = nullptr;
    Restaurant res1;
    queryArg arg;

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

    /* Default arg:
     * filterArray = {false, false, false, false, false, false, false, false}
     * time = {false, false, false, false}
     * price = AVG_PRICE (=60)
     * comment = Comment::WORST;
     * status = Favorite_Status::NORMAL
     
     If you just feed default arg to find(), you will get nothing. You at least need ...
     to set 'filterArray' and 'time' when you wanna use class 'queryArg'.

     The following is the example we only set 'filterArray' & 'time' true on 'breakfast' ...
     and 'morning', respectly.
     Then the result will free from restrictions of 'price', of 'comment' and of 'status'...
     (still exclude blacklist).
    */
    arg.filterArray[Food::BREAKFAST] = true;
    arg.time[Time::Moring] = true;
    
    auto would_like = mytest->find(arg);

    cout << "\nQuerying start:" << endl;
    for (auto it=would_like.begin();it!=would_like.end();++it)
    {
        it->view();
        it->view_kind();
    }

    delete mytest;
}