#include "user.h"
#include <vector>
/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr) // _friends -> pointer  
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

// 1. The function use ostream output.
std::ostream& 
operator<<(std::ostream& os, const User& u) {
  os << "User(name=" << u._name << ", friends=[";

  for (int i = 0; i < u.size(); ++i) {
    os << u._friends[i]; // Iter -> os << output!!! ostream=output
    if (i < u.size() - 1) {
      os << ", ";
    }
  }

  os << "])";
  return os;
}

// 2. 

// Drop Function 
User::~User() {
  delete[] _friends;
}

// Copy -> Object
User::User(const User& user) : _capacity(user._capacity) {
  _size = user._size;
  _capacity = user._capacity;
  _name = user._name;
  _friends = new std::string[_capacity];
  for (size_t i = 0; i < _size; i++) {
    _friends[i] = user._friends[i];
  }
}

// Object Copy Another Object
User& User::operator=(const User& user) {
  if (this != &user) {
    delete[] _friends;
    _name = user._name;
    _friends = new std::string[_capacity];
    _size = user._size;
    _capacity = user._capacity;
    
    for (size_t i = 0; i < _size; ++i) {
      _friends[i] = user._friends[i];
    }

  }

  return *this;
}

/**
 * If you not prevent, Please check out ---> user.h
 *  pop("= delete"), push("noexcept") 
 */

// Prevent 
// User::User(User&& user) noexcept 
// {
//   _name = user._name;
//   _friends = user._friends;
//   _size = user._size;
//   _capacity = user._capacity;

//   user._name = "";
//   user._friends = nullptr; 
//   user._size = 0;
//   user._capacity = 0;
// }

// Prevent
// User& User::operator=(User&& user) noexcept
// {
//   if (this != &user) {
//     delete[] _friends;
//     _name = user._name;
//     _friends = user._friends;
//     _size = user._size;
//     _capacity = user._capacity;

//     user._name = "";
//     user._friends = nullptr;
//     user._size = 0;
//     user._capacity = 0;
//   }

//   return *this;
// }


// 3.
User& User::operator+=(User& user) {
  if (user._name != _name) {
    add_friend(user._name);
    user.add_friend(_name);
  }
  return *this;
}

// "<" and ">" std::string
bool User::operator<(const User& user) const {
  if (_name < user._name) {
    return true;
  } else {
    return false;
  }





}