#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT training : public contract {
  public:
    using contract::contract;

    //Contract name
    training(name receiver, name code, datastream<const char*> ds):
    contract(receiver, code, ds), _users(receiver, receiver.value), _activities(receiver, receiver.value){}

    //Actions login, insert, delete
    ACTION login(name username);
    ACTION insert(uint64_t activityid, name username, string duration, double distance, uint64_t speed1, uint64_t speed2, uint64_t speed3, uint64_t speed4, uint64_t speed5,
    uint64_t speed6, uint64_t speed7, uint64_t avg_speed, uint64_t altitude, uint64_t hrate1, uint64_t hrate2, uint64_t hrate3, uint64_t hrate4, uint64_t hrate5, uint64_t hrate6,
    uint64_t hrate7, uint64_t avg_hrate, uint64_t calories, string weather, double temperature, bool shared);        
    ACTION remove(uint64_t activityid, name username);
    
  private:
    //Tables users, activities
    TABLE user_info {
      name        username;
      auto primary_key() const { return username.value; }
    };
    typedef multi_index<name("users"), user_info> users_table;
    users_table _users;

    TABLE activity_struct {
       uint64_t    activityid;
       name        username;
       string      duration;            //min
       double      distance;            //km
       uint64_t    speed1;              //1-10
       uint64_t    speed2;              //1-10
       uint64_t    speed3;              //1-10
       uint64_t    speed4;              //1-10
       uint64_t    speed5;              //1-10
       uint64_t    speed6;              //1-10
       uint64_t    speed7;              //1-10
       uint64_t    avg_speed;           //1-10
       uint64_t    altitude;            //m
       uint64_t    hrate1;              //bpm
       uint64_t    hrate2;              //bpm
       uint64_t    hrate3;              //bpm
       uint64_t    hrate4;              //bpm
       uint64_t    hrate5;              //bpm
       uint64_t    hrate6;              //bpm
       uint64_t    hrate7;              //bpm
       uint64_t    avg_hrate;           //bpm
       uint64_t    calories;            //kcal
       string      weather;             //Cloudy, Sunny, Rainy
       double      temperature;         //ºC
       bool        shared = false;      //false by default
        
       auto primary_key() const { return activityid;}
      
    };
    typedef multi_index<name("activities"),activity_struct> activities_table;
    activities_table _activities;

};

