#ifndef __RESTAURANTS__
#define __RESTAURANTS__

#include <map>
#include <list>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>

#define CATAGORY_NUM 8
#define TIME_SLOT 4
#define AVG_PRICE 60 // $0~60, $60~100, $100~200, $200↑

typedef bool Food_Catagory;
typedef bool Time_Interval;

// Either favorite or blacklist
enum class Favorite_Status
{
    NORMAL,
    FAVORITE,
    DISLIKE
};
// 5 levels comment
enum class Comment
{
    WORST,
    BAD,
    NOTBAD,
    GOOD,
    BEST
};

// Being used for filter. time[Time::Morning] may return whether it's true or not.
// TIME_SLOT = 4
enum Time{
    Moring,
    Afternoon,
    Evening,
    Night
};

// Being used for filter. kind[Food::BREAKFAST] may return whether it's true or not.
// CATAGARY_NUM = 8
enum Food
{
    BREAKFAST,
    RICE,
    NOODLES,
    HOTPOT,
    STEAK,
    BRAISE,
    DESSERT,
    FRY
};

class queryArg {
public:
    std::vector<Food_Catagory> filterArray;
    std::vector<Time_Interval> time;
    int price;
    Comment comment;
    Favorite_Status status;
    queryArg();
};

class Restaurant
{
private:
    std::string _name;
    std::string _address;
    std::string _phone;
    std::string _menu; //menu.jpg
    int _price;
    std::vector<Food_Catagory> _kind;
    std::vector<Time_Interval> _opening_time;
    Comment _comment;
    Favorite_Status _status;

public:
    Restaurant();
    Restaurant(const Restaurant &);
    Restaurant(std::string &name, std::string &address, std::string &phone, std::string &menu, int price, std::vector<Food_Catagory> &kind, std::vector<Time_Interval> &time, Comment &comment);
    std::string name() const;
    std::string address() const;
    std::string phone() const;
    std::string menu() const;
    int price() const;
    std::vector<Food_Catagory> kind() const;
    std::vector<Time_Interval> opening_time() const;
    Comment comment() const;
    Favorite_Status status() const;

    void view() const;
    void view_kind() const;

    Restaurant& operator=(const Restaurant &);

    void name(const std::string &);
    void address(const std::string &);
    void phone(const std::string &);
    void menu(const std::string &);
    void price(int);
    void kind(const std::vector<Food_Catagory> &filter);
    void kind(Food, bool);
    void comment(Comment &);
    void opening_time(const std::vector<Time_Interval> &);
    void opening_time(Time, bool);
    void status(Favorite_Status &);
    ~Restaurant();


};

class Restaurants
{
private:
    std::map<std::string, Restaurant> mapRestaurant;

public:
    Restaurants();
    Restaurants(std::vector<Restaurant> &datalist);
    Restaurants(const Restaurant &);
    int get_amount() const;
    int insert(const Restaurant &data);
    void remove(std::string &name);
    int update(std::string &name, const Restaurant &data);
    void show() const;                                                                                                                                                                      // show all element in dataset
    std::vector<Restaurant> find(const std::vector<Food_Catagory> &filterArray = std::vector<Food_Catagory>(CATAGORY_NUM, true), const std::vector<Time_Interval> &time = std::vector<Time_Interval>(TIME_SLOT, true), int price = AVG_PRICE, Comment comment = Comment::WORST, Favorite_Status status = Favorite_Status::NORMAL) const; // reply the queries
    std::vector<Restaurant> find(const queryArg &) const;
    std::vector<Restaurant> search_Addr(const std::string &addr) const;
    Restaurant search(const std::string &name) const; // search by name

    ~Restaurants();
};

#endif