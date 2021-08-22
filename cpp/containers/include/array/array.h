#ifndef TESTCONTAINER_ARRAY_H
#define TESTCONTAINER_ARRAY_H

#include <iostream>
#include "../namespace.h"

__YONGXIN_NAMESPACE_START

    template<typename T, size_t S>
class array {
public:
    constexpr size_t size() const { return S; }

    T& operator[](size_t index) { return m_data[index]; }
    const T& operator[](size_t index) const { return m_data[index]; }

private:
    T m_data[S];
};


__YONGXIN_NAMESPACE_END

#endif //TESTCONTAINER_ARRAY_H
