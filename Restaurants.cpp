#include "Restaurants.h"
#include <iostream>
/*****************************
 * Initialize class Restaurant 
 *****************************/
Restaurant::Restaurant(Restaurant &node)
{
    _name = node.name();
    _address = node.address();
    _price = node.price();
    _kind = node.kind();
    _comment = node.comment();
    _opening_time = node.opening_time();
    _status = node.status();
}

Restaurant::Restaurant(std::string &name, std::string &address, int &price, std::vector<Food_Catagory> &kind, Comment &comment, std::list<Time_Interval> &time)
{
    _name = name;
    _address = address;
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

void Restaurant::name(std::string &name)
{
    _name = name;
}

std::string Restaurant::address() const
{
    return _address;
}

void Restaurant::address(std::string &address)
{
    _address = address;
}

int Restaurant::price() const
{
    return _price;
}

void Restaurant::price(int &price)
{
    _price = price;
}

std::vector<Food_Catagory> Restaurant::kind() const
{
    return _kind;
}

void Restaurant::kind(std::vector<Food_Catagory> &kind)
{
    _kind = kind;
}

Comment Restaurant::comment() const
{
    return _comment;
}

void Restaurant::comment(Comment &comment)
{
    _comment = comment;
}

std::list<Time_Interval> Restaurant::opening_time() const
{
    return _opening_time;
}

void Restaurant::opening_time(std::list<Time_Interval> &time)
{
    _opening_time = time;
}

Favorite_Status Restaurant::status() const
{
    return _status;
}

void Restaurant::status(Favorite_Status &status)
{
    _status = status;
}

Restaurant::~Restaurant() {}

/*****************************
 * Initialize class Restaurants
 *****************************/
Restaurants::Restaurants(std::vector<Restaurant> &list)
{
    for (std::vector<Restaurant>::iterator it = list.begin(); it != list.end(); ++it)
    {
        mapRestaurant[it->name()] = *it;
    }
}

Restaurants::Restaurants(Restaurant &item)
{
    mapRestaurant[item.name()] = item;
}

int Restaurants::get_amount() const
{
    return mapRestaurant.size();
}

void Restaurants::insert(Restaurant &item)
{
    mapRestaurant[item.name()] = item;
}

void Restaurants::remove(std::string &name)
{
    mapRestaurant.erase(name);
}

void Restaurants::update(std::string &name, Restaurant &item)
{
    mapRestaurant[name] = item;
}

void Restaurants::show() const
{
    std::map<std::string, Restaurant>::iterator it;
    for (it = mapRestaurant.begin(); it != mapRestaurant.cend(); ++it)
    {
        std::cout << it->first << std::endl;
    }
}

std::vector<Restaurant> Restaurants::find(std::vector<Food_Catagory> &query, int &price = AVG_PRICE, Favorite_Status &status = Favorite_Status::NORMAL) const
{
    std::vector<Restaurant> list;

    for (std::map<std::string, Restaurant>::iterator it = mapRestaurant.begin; it != mapRestaurant.end(); ++it)
    {
        if (price > it->second.price())
            continue;

        if (status == Favorite_Status::FAVORITE && it->second.status() != Favorite_Status::FAVORITE)
            continue;

        if (status == Favorite_Status::NORMAL && it->second.status() == Favorite_Status::DISLIKE)
            continue;

        if (status == Favorite_Status::DISLIKE && it->second.status() != Favorite_Status::DISLIKE)
            continue;

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

Restaurant Restaurants::search(std::string &name) const
{
    return mapRestaurant[name];
}

Restaurants::~Restaurants()
{
}