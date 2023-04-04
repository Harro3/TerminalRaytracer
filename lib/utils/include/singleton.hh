#pragma once

#include <string>

/**
 * @brief Simple implementation of the singleton design pattern
 * 
 * @tparam T 
 */
template <typename T>
class Singleton
{
public:
    static T* instance()
    {
        if (!m_instance)
            m_instance = new T();
        return m_instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton) = delete;

protected:
    Singleton() = default;
    ~Singleton() {}

private:
    inline static T* m_instance = nullptr;
};