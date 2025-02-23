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
  friend std::ostream& operator<<(std::ostream& os, const User& u);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  ~User();
  User(const User& user);
  User& User::operator=(const User& user);
  User::User(User&& user) noexcept;
  User& User::operator=(User&& user) noexcept;
  User& User::operator+=(const User& user);
  bool User::operator<(const User& user) const;

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};