#include <training.hpp>

ACTION training::login(name username) {
  require_auth(username);

  // Find the record from _users table
  auto user_iterator = _users.find(username.value);
  if(user_iterator == _users.end()) {
  // Create a user record if it does not exist
    user_iterator = _users.emplace(username, [&](auto&new_user) {
        new_user.username = username;
    });
    
  }
  
}

ACTION training::insert(uint64_t activityid, name username, uint64_t training_time, double distance, double speed, uint64_t altitude, uint64_t heart_rate, uint64_t calories, uint64_t incline,         
      uint64_t cadence,  double temperature) {

  require_auth(username);

  // Find the record from _users table
  auto activity_iterator = _activities.find(activityid);
  if(activity_iterator == _activities.end()) {
  // Create a user record if it does not exist
    activity_iterator = _activities.emplace(username, [&](auto&new_activity) {
        new_activity.activityid = activityid;
        new_activity.username = username;
        new_activity.training_time = training_time;
        new_activity.distance = distance;
        new_activity.speed = speed;
        new_activity.altitude = altitude;
        new_activity.heart_rate = heart_rate;
        new_activity.calories = calories;
        new_activity.incline = incline;
        new_activity.cadence = cadence;
        new_activity.temperature = temperature;
    });
  }
}
























