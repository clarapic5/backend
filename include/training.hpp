#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT training : public contract {
  public:
    using contract::contract;

    training(name receiver, name code, datastream<const char*> ds):
    contract(receiver, code, ds), _users(receiver, receiver.value), _activities(receiver, receiver.value){}

    ACTION login(name username);
    ACTION insert(uint64_t activityid, name username, uint64_t training_time, double distance, double speed, uint64_t altitude, uint64_t heart_rate, uint64_t calories, uint64_t incline,         
    uint64_t cadence, double temperature);        
   
    
  private:
    TABLE user_info {
      name        username;
      //uint64_t    num_activities = 0;

      auto primary_key() const { return username.value; }
    };
    typedef multi_index<name("users"), user_info> users_table;
    
    //Table name
    users_table _users;


    TABLE activity_struct {
       uint64_t activityid;
       name     username;
       uint64_t training_time;       //Seconds
       double   distance;            //km
       double   speed;               //kmxh
       uint64_t altitude;            //m
       uint64_t heart_rate;          //bpm
       uint64_t calories;            //kcal
       uint64_t incline;             //%
       uint64_t cadence;             //rpm
       double   temperature;         //ºC
        
       auto primary_key() const { return activityid; }
    };
    typedef multi_index<name("activities"),activity_struct> activities_table;

    //Table name
    activities_table _activities;





};

