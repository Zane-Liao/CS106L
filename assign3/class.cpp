/** State classes*/

#include <stdexcept>
#include <iostream>

template <typename T>
State<T>::State() {
    _limit = 200;
    _point = 0;
}

template <typename T>
State<T>::~State() {
    std::cout << "Option" << std::endl;
}

template <typename T>
State<T>::State(T origin) {
    _point = origin;
}

template <typename T>
void State<T>::origin() {
    return _point;
}

template <typename T>
int State<T>::getData() const{
    return _point;
}

template <typename T>
void State<T>::setData(T number) {
    if (_point <= _limit) {
        _point = number;
    } else {
        throw std::out_of_range("Out of range!");
    }
}

template <typename T>
void State<T>::forword(T number) {
    if (_point <= _limit) {
        _point += number;
    } else {
        throw std::out_of_range("Out of range!");
    }
}

template <typename T>
void State<T>::back(T number) {
    _point -= number;
}