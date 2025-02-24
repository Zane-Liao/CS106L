/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);
/** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  // friend function -> use public and private 
  friend std::ostream& operator<<(std::ostream& os, const User& u);
  // Special Member Function
  // Destructor
  ~User(); 
  // Copy Constructor
  User(const User& user);
  // Copy Assignment Operator
  User& operator=(const User& user);
  // Move Constructor
  User(User&& user) = delete;
  // Move Assignment Operator
  User& operator=(User&& user) = delete;
  // Object += Another object, Another Object += Object
  User& operator+=(User& user);
  // Object.size() (<,>,=) Another Object.size()
  bool operator<(const User& user) const;

  // Member element 

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};
