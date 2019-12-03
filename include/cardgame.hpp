#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT cardgame : public contract {
  public:
    using contract::contract;

    cardgame(name receiver, name code, datastream<const char*> ds):
    contract(receiver, code, ds), _users(receiver, receiver.value) {}

    ACTION login(name username, uint64_t win_count, uint64_t lost_count);
   
    
  private:
    TABLE user_info {
      name        username;
      uint64_t    win_count;
      uint64_t    lost_count;

      auto primary_key() const { return username.value; }
    };
    typedef multi_index<name("users"), user_info> users_table;
    
    //Table name
    users_table _users;
   
};

