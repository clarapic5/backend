#include <training.hpp>

ACTION training::login(name username) {
  require_auth(username);

  auto user_iterator = _users.find(username.value);
  if(user_iterator == _users.end()) {
  // Create a user record if it does not exist
    user_iterator = _users.emplace(username, [&](auto&new_user) {
        new_user.username = username;
    });
    
  }
  
}


ACTION training::remove(uint64_t activityid, name username) {
    require_auth(username);
    auto act_iterator = _activities.find(activityid);
    act_iterator = _activities.erase(act_iterator);
    
}
 

ACTION training::insert(uint64_t activityid, name username, string duration, double distance, uint64_t speed1, uint64_t speed2, uint64_t speed3, uint64_t speed4, uint64_t speed5,
    uint64_t speed6, uint64_t speed7, uint64_t avg_speed, uint64_t altitude, uint64_t hrate1, uint64_t hrate2, uint64_t hrate3, uint64_t hrate4, uint64_t hrate5, uint64_t hrate6,
    uint64_t hrate7, uint64_t avg_hrate, uint64_t calories, string weather, double temperature) {

  require_auth(username);

  
  auto activity_iterator = _activities.find(activityid);
  if(activity_iterator == _activities.end()) {
  // Create an activityrecord if it does not exist
    activity_iterator = _activities.emplace(username, [&](auto&new_activity) {
         new_activity.activityid = activityid;
         new_activity.username = username;
         new_activity.duration = duration;
         new_activity.distance = distance;
         new_activity.speed1 = speed1;
         new_activity.speed2 = speed2;
         new_activity.speed3 = speed3;
         new_activity.speed4 = speed4;
         new_activity.speed5 = speed5;
         new_activity.speed6 = speed6;
         new_activity.speed7 = speed7;
         new_activity.avg_speed = avg_speed;
         new_activity.altitude = altitude;
         new_activity.hrate1 = hrate1;
         new_activity.hrate2 = hrate2;
         new_activity.hrate3 = hrate3;
         new_activity.hrate4 = hrate4;
         new_activity.hrate5 = hrate5;
         new_activity.hrate6 = hrate6;
         new_activity.hrate7 = hrate7;
         new_activity.avg_hrate = avg_hrate;
         new_activity.calories = calories;
         new_activity.weather = weather;
         new_activity.temperature = temperature;
    });
  }
}
























