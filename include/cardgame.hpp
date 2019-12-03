#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT cardgame : public contract {
  public:
    using contract::contract;

    cardgame(name receiver, name code, datastream<const char*> ds):
    contract(receiver, code, ds), _users(receiver, receiver.value), _games(receiver, receiver.value) {}

    ACTION login(name username, uint64_t win_count, uint64_t lost_count);
    ACTION game(uint64_t gameid, bool isenabled, name username);
   
    
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

    TABLE game_struct {
      uint64_t gameid = 0;
       bool isenabled;
       name username;

        auto primary_key() const { return gameid; }
    };
    typedef multi_index<name("games"), game_struct> game_table;

    game_table _games;
};

