#include "Restaurants.h"
#include <iostream>
/*****************************
 * Initialize Argument struct 
******************************/
queryArg::queryArg()
{
    filterArray = std::vector<Food_Catagory>(CATAGORY_NUM, false);
    time = std::vector<Time_Interval>(TIME_SLOT, false);
    price = AVG_PRICE;
    comment = Comment::WORST;
    status = Favorite_Status::NORMAL;
}

/*****************************
 * Initialize class Restaurant 
 *****************************/
Restaurant::Restaurant()
{
    _name = std::string("empty");
    _address = std::string();
    _phone = std::string();
    _menu = std::string();
    _price = 0;
    _kind = std::vector<Food_Catagory>(CATAGORY_NUM, false);
    _opening_time = std::vector<Time_Interval>(TIME_SLOT, false);
    _comment = Comment::WORST;
    _status = Favorite_Status::NORMAL;
}

Restaurant::Restaurant(const Restaurant &node)
{
    if (node.name() == "empty")
    {
        std::cout << "Argument is an empty object!" << std::endl;
    }

    _name = node.name();
    _address = node.address();
    _phone = node.phone();
    _menu = node.menu();
    _price = node.price();
    _kind = node.kind();
    _opening_time = node.opening_time();
    _comment = node.comment();
    _status = node.status();
}

Restaurant::Restaurant(std::string &name, std::string &address, std::string &phone, std::string &menu, int price, std::vector<Food_Catagory> &kind, std::vector<Time_Interval> &time, Comment &comment)
{
    _name = name;
    _address = address;
    _phone = phone;
    _menu = menu;
    _price = price;
    _kind = kind;
    _comment = comment;
    _opening_time = time;
    _status = Favorite_Status::NORMAL;
}

std::string Restaurant::name() const
{
    return _name;
}

void Restaurant::name(const std::string &name)
{
    _name = name;
}

std::string Restaurant::address() const
{
    return _address;
}

void Restaurant::address(const std::string &address)
{
    _address = address;
}

std::string Restaurant::phone() const
{
    return _phone;
}

void Restaurant::phone(const std::string &phone)
{
    _phone = phone;
}

std::string Restaurant::menu() const
{
    return _menu;
}

void Restaurant::menu(const std::string &menu)
{
    _menu = menu;
}

int Restaurant::price() const
{
    return _price;
}

void Restaurant::price(int price)
{
    _price = price;
}

std::vector<Food_Catagory> Restaurant::kind() const
{
    return _kind;
}

void Restaurant::kind(const std::vector<Food_Catagory> &kind)
{
    if (kind.size() != CATAGORY_NUM)
    {
        std::cout << "Wrong variety number!" << std::endl;
        return;
    }
    _kind = kind;
}

void Restaurant::kind(Food tag, bool b)
{
    _kind[tag] = b;
}

Comment Restaurant::comment() const
{
    return _comment;
}

void Restaurant::comment(Comment &comment)
{
    _comment = comment;
}

std::vector<Time_Interval> Restaurant::opening_time() const
{
    return _opening_time;
}

void Restaurant::opening_time(const std::vector<Time_Interval> &time)
{
    _opening_time = time;
}

void Restaurant::opening_time(Time tag, bool b)
{
    _opening_time[tag] = b;
}

Favorite_Status Restaurant::status() const
{
    return _status;
}

void Restaurant::status(Favorite_Status &status)
{
    _status = status;
}

Restaurant& Restaurant::operator=(const Restaurant &node)
{
    if(this != &node)
    {
        _name = node.name();
        _address = node.address();
        _phone = node.phone();
        _menu = node.menu();
        _price = node.price();
        _kind = node.kind();
        _opening_time = node.opening_time();
        _comment = node.comment();
        _status = node.status();
    }

    return *this;
}

void Restaurant::view() const
{
    std::string this_status;
    std::string this_comment;

    switch(this->status())
    {
    case Favorite_Status::DISLIKE:
        this_status = "dislike";
        break;
    case Favorite_Status::FAVORITE:
        this_status = "favorite";
        break;
    case Favorite_Status::NORMAL:
        this_status = "normal";
        break;
    }

    switch (this->comment())
    {
    case Comment::WORST:
        this_comment = "worst";
        break;
    case Comment::BAD:
        this_comment = "bad";
        break;
    case Comment::NOTBAD:
        this_comment = "not bad";
        break;
    case Comment::GOOD:
        this_comment = "good";
        break;
    case Comment::BEST:
        this_comment = "best";
        break;
    }

    std::cout << "["
    << "Name: " <<  this->name() << ", "
    << "Address: " << this->address() << ", "
    << "Phone number: " << this->phone() << ", "
    << "Comment: " << this_comment << ", "
    << "Status: " << this_status << "]"
    << std::endl;
}

void Restaurant::view_kind() const
{
    std::cout << '[';
    for (int catagory=Food::BREAKFAST; catagory < CATAGORY_NUM; ++catagory)
    {
        if (_kind[catagory])
        {    
            switch(catagory)
            {
            case Food::BREAKFAST:
                std::cout << "Breakfast ";
                break;
            case Food::RICE:
                std::cout << "Rice ";
                break;
            case Food::NOODLES:
                std::cout << "Noodles ";
                break;
            case Food::HOTPOT:
                std::cout << "Hotpot ";
                break;
            case Food::STEAK:
                std::cout << "Steak ";
                break;
            case Food::BRAISE:
                std::cout << "Braise ";
                break;
            case Food::DESSERT:
                std::cout << "Dessert ";
                break;
            case Food::FRY:
                std::cout << "Fry";
                break;
            }
        }
    }
    std::cout << ']' << std::endl;
}

Restaurant::~Restaurant() {}

/*****************************
 * Initialize class Restaurants
 *****************************/

Restaurants::Restaurants()
{}

Restaurants::Restaurants(std::vector<Restaurant> &list)
{
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        mapRestaurant[it->name()] = *it;
    }
}

Restaurants::Restaurants(const Restaurant &item)
{
    mapRestaurant[item.name()] = item;
}

int Restaurants::get_amount() const
{
    return mapRestaurant.size();
}

void Restaurants::insert(const Restaurant &item)
{
    mapRestaurant[item.name()] = item;
}

void Restaurants::remove(std::string &name)
{
    mapRestaurant.erase(name);
}

void Restaurants::update(std::string &name, const Restaurant &item)
{
    mapRestaurant[name] = item;
}

void Restaurants::show() const
{
    for (auto it=mapRestaurant.begin(); it != mapRestaurant.end(); ++it)
    {
        it->second.view();
    }
}

std::vector<Restaurant> Restaurants::find(const std::vector<Food_Catagory> &query, const std::vector<Time_Interval> &qtime, int price, Comment comment, Favorite_Status status) const
{
    std::vector<Restaurant> list;
    bool is_opening = false;
    int i=0;

    for (auto it = mapRestaurant.begin(); it != mapRestaurant.end(); ++it)
    {
        is_opening = false;
      
        if (price > it->second.price())
            continue;

        if (static_cast<int>(comment) > static_cast<int>(it->second.comment()))
            continue;

        if (status == Favorite_Status::FAVORITE && it->second.status() != Favorite_Status::FAVORITE)
            continue;

        if (status == Favorite_Status::NORMAL && it->second.status() == Favorite_Status::DISLIKE)
            continue;

        if (status == Favorite_Status::DISLIKE && it->second.status() != Favorite_Status::DISLIKE)
            continue;

        for (i = 0; i != TIME_SLOT; ++i)
        {
            if (qtime[i] && (it->second.opening_time())[i])
                is_opening = true;
        }

        if (!is_opening)
            continue;

        // Final Selection
        if (query[Food::BREAKFAST] && (it->second.kind())[Food::BREAKFAST])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::RICE] && (it->second.kind())[Food::RICE])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::NOODLES] && (it->second.kind())[Food::NOODLES])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::HOTPOT] && (it->second.kind())[Food::HOTPOT])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::STEAK] && (it->second.kind())[Food::STEAK])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::BRAISE] && (it->second.kind())[Food::BRAISE])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::DESSERT] && (it->second.kind())[Food::DESSERT])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::FRY] && (it->second.kind())[Food::FRY])
        {
            list.push_back(it->second);
            continue;
        }
    }

    return list;
}

std::vector<Restaurant> Restaurants::find(const queryArg &arg) const
{
    std::vector<Food_Catagory> query = arg.filterArray;
    std::vector<Time_Interval> qtime = arg.time;
    int price = arg.price;
    Comment comment = arg.comment;
    Favorite_Status status = arg.status;

    std::vector<Restaurant> list;
    bool is_opening = false;
    int i=0;

    for (auto it = mapRestaurant.begin(); it != mapRestaurant.end(); ++it)
    {
        is_opening = false;
      
        if (price > it->second.price())
            continue;

        if (static_cast<int>(comment) > static_cast<int>(it->second.comment()))
            continue;

        if (status == Favorite_Status::FAVORITE && it->second.status() != Favorite_Status::FAVORITE)
            continue;

        if (status == Favorite_Status::NORMAL && it->second.status() == Favorite_Status::DISLIKE)
            continue;

        if (status == Favorite_Status::DISLIKE && it->second.status() != Favorite_Status::DISLIKE)
            continue;

        for (i = 0; i != TIME_SLOT; ++i)
        {
            if (qtime[i] && (it->second.opening_time())[i])
                is_opening = true;
        }

        if (!is_opening)
            continue;

        // Final Selection
        if (query[Food::BREAKFAST] && (it->second.kind())[Food::BREAKFAST])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::RICE] && (it->second.kind())[Food::RICE])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::NOODLES] && (it->second.kind())[Food::NOODLES])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::HOTPOT] && (it->second.kind())[Food::HOTPOT])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::STEAK] && (it->second.kind())[Food::STEAK])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::BRAISE] && (it->second.kind())[Food::BRAISE])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::DESSERT] && (it->second.kind())[Food::DESSERT])
        {
            list.push_back(it->second);
            continue;
        }
        if (query[Food::FRY] && (it->second.kind())[Food::FRY])
        {
            list.push_back(it->second);
            continue;
        }
    }

    return list;
}

std::vector<Restaurant> Restaurants::search_Addr(const std::string &addr) const
{
    std::vector<Restaurant> list;
    std::string tmp;
    for (auto it = mapRestaurant.begin(); it != mapRestaurant.cend(); ++it)
    {
        tmp = it->second.address();
        if (tmp.find(addr) != std::string::npos)
            list.push_back(it->second);
    }

    return list;
}

Restaurant Restaurants::search(const std::string &name) const
{
    std::map<std::string, Restaurant>::const_iterator it = mapRestaurant.find(name);
    if (it != mapRestaurant.end())
        return it->second;
    else
    {
        std::cout << name << " is not in your database." << std::endl;
        return mapRestaurant.begin()->second;
    }
}

Restaurants::~Restaurants()
{
    std::cout << "Clear!" << std::endl;
}