#ifndef RESTAURANTS
#define RESTAURANTS

#include <map>
#include <list>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>

#define CATAGORY_NUM 8
#define AVG_PRICE 99 // $99, $199, $299

typedef std::pair<int, int> Time_Interval;
typedef bool Food_Catagory;

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

// Being used for filter. kind[Food::BREAKFAST] may return whether it's true or not.
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

class Restaurant
{
private:
    std::string _name;
    std::string _address;
    int _price;
    std::vector<Food_Catagory> _kind;
    Comment _comment;
    std::list<Time_Interval> _opening_time;
    Favorite_Status _status;

public:
    Restaurant(Restaurant &);
    Restaurant(std::string &name, std::string &address, int &price, std::vector<Food_Catagory> &kind, Comment &comment, std::list<Time_Interval> &time);
    std::string name() const;
    std::string address() const;
    int price() const;
    std::vector<Food_Catagory> kind() const;
    Comment comment() const;
    std::list<Time_Interval> opening_time() const;
    Favorite_Status status() const;
    void name(std::string &);
    void address(std::string &);
    void price(int &);
    void kind(std::vector<Food_Catagory> &filter);
    void comment(Comment &);
    void opening_time(std::list<Time_Interval> &);
    void status(Favorite_Status &);
    ~Restaurant();
};

class Restaurants
{
private:
    std::map<std::string, Restaurant> mapRestaurant;

public:
    Restaurants(std::vector<Restaurant> &datalist);
    Restaurants(Restaurant &);
    int get_amount() const;
    void insert(Restaurant &data);
    void remove(std::string &name);
    void update(std::string &name, Restaurant &data);
    void show() const;                                                                                                                                      // show all element in dataset
    std::vector<Restaurant> find(std::vector<Food_Catagory> &filterArray, int &price = AVG_PRICE, Favorite_Status &status = Favorite_Status::NORMAL) const; // reply the queries
    Restaurant search(std::string &name) const;                                                                                                             // search by name
    ~Restaurants();
};

#endif