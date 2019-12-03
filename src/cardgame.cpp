#include <cardgame.hpp>
#include <gameplay.cpp>

ACTION cardgame::login(name username, uint64_t win_count, uint64_t lost_count) {
  require_auth(username);

  // Find the record from _users table
  auto user_iterator = _users.find(username.value);
  if(user_iterator == _users.end()) {
  // Create a user record if it does not exist
    user_iterator = _users.emplace(username, [&](auto&new_user) {
        new_user.username = username;
        new_user.win_count= win_count;
        new_user.lost_count = lost_count;
    });
    
  }
  
}

 
