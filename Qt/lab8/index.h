#ifndef ARRAY_INDEX_H
#define ARRAY_INDEX_H

#include "array.h"

template <typename T>
Array<T>::Array(const std::vector<T>& data) : data_(data) {}

template <typename T>
Array<T>::~Array() {}

template <typename T>
void Array<T>::view() const {
    for (const auto& item : data_) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template <>
void Array<int>::solve() const {
    auto min_it = std::min_element(data_.begin(), data_.end());
    if (min_it != data_.end()) {
        for (auto it = min_it + 1; it != data_.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}

template <>
void Array<double>::solve() const {
    double sum = std::accumulate(data_.begin(), data_.end(), 0.0);
    double average = sum / data_.size();
    std::cout << "Average: " << average << std::endl;
}

template <>
void Array<char>::solve() const {
    auto min_it = std::min_element(data_.begin(), data_.end());
    auto max_it = std::max_element(data_.begin(), data_.end());
    if (min_it != data_.end() && max_it != data_.end()) {
        for (auto it = min_it + 1; it != max_it; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}

#endif // ARRAY_INDEX_H
