#ifndef TESTCONTAINER_VECTOR_H
#define TESTCONTAINER_VECTOR_H

#include <iostream>
#include "../namespace.h"

__YONGXIN_NAMESPACE_START

template<typename vector>
class VectorIterator {
public:
    using ValueType = typename vector::ValueType;
    using PointerType = ValueType *;
    using ReferenceType = ValueType &;
public:
    VectorIterator(PointerType ptr): m_ptr(ptr){}
    ~VectorIterator() = default;

    VectorIterator& operator++() {
        m_ptr++;
        return *this;
    };

    VectorIterator operator++(int) {
        VectorIterator it = *this;
        ++(*this);
        return it;
    }

    VectorIterator& operator--() {
        m_ptr--;
        return *this;
    };

    VectorIterator operator--(int) {
        VectorIterator it = *this;
        --(*this);
        return it;
    }

    ReferenceType operator[] (int index) {
        return *(m_ptr[index]);
    }

    PointerType operator-> () {
        return m_ptr;
    }

    ReferenceType operator* () {
        return *m_ptr;
    }

    bool operator == (const VectorIterator& other) const {
        return m_ptr == other.m_ptr;
    }

    bool operator != (const VectorIterator& other) const {
        return !(*this == other);
    }

private:
    PointerType m_ptr;
};

template<typename T>
class vector {
public:
    using ValueType = T;
    using iterator = VectorIterator<vector<T>>;
public:
    vector(): m_data(nullptr), m_size(0), m_capacity(2) {
        ReAlloc(m_capacity);
    }

    ~vector() {
        clear();
        ::operator delete(m_data, m_capacity * sizeof(T));
    }

    void push_back(const T &value) {
        if (m_size >= m_capacity) {
            ReAlloc(m_capacity + (m_capacity >> 1));
        }
        m_data[m_size++] = value;
    }

    void push_back(T &&value) noexcept {
        if (m_size >= m_capacity) {
            ReAlloc(m_capacity + (m_capacity >> 1));
        }
        m_data[m_size++] = std::move(value);
    }

    template<typename... Args>

    T& emplace_back(Args &&... args){
        if (m_size >= m_capacity) {
            ReAlloc(m_capacity + (m_capacity >> 1));
        }
        new(&m_data[m_size])T(std::forward<Args>(args)...);
//        m_data[m_size] = T(std::forward<Args>(args)...);
        return m_data[m_size++];
    }

    void pop_back() {
        if (m_size > 0) {
            m_size--;
            m_data[m_size].~T();
        }
    }

    void clear() {
        for (size_t i = 0; i < m_size; i++)
            m_data[i].~T();
        m_size = 0;
    }

    size_t size() const { return m_size; }

    iterator begin() {
        return iterator(m_data);
    }

    iterator end() {
        return iterator(m_data + m_size);
    }

    const T &operator[](size_t index) const {
        return m_data[index];
    }

    T &operator[](size_t index) {
        return m_data[index];
    }

private:
    void ReAlloc(size_t newCapacity) {
        // 1. allocate a new block of memory
        // 2. copy/move the old elements into the new memory
        // 3. delete old memory
        T *newBlock = (T*)::operator new(sizeof(T) * newCapacity);
        m_size = (newCapacity < m_size) ? newCapacity : m_size;

        for (size_t i = 0; i < m_size; i++)
            new (&newBlock[i]) T(std::move(m_data[i]));

        for (size_t i = 0; i < m_size; i++)
            m_data[i].~T();

        ::operator delete(m_data, m_capacity * sizeof(T));
        m_data = newBlock;
        m_capacity = newCapacity;
    }
private:
    T *m_data;

    size_t m_size;
    size_t m_capacity;
};

__YONGXIN_NAMESPACE_END

#endif //TESTCONTAINER_VECTOR_H
