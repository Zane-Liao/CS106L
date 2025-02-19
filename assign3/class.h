/* This is State classes
    forword
    back
    up
    down
    origin
    For Example, in games, Player
*/

#pragma once

#include <cstddef>

template <typename T>
class State {
public:
    State();
    ~State();
    
    State(T origin);

    int getData() const;

    void setData(T number);
    void forword(T number);
    void back(T number);
private:
    size_t _limit;
    T _point;
    T _data;
    void origin();
};

#include "class.cpp"