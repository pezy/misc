/*
=================================================================================
C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/CppPrimer

own version of Blob class

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>
=================================================================================
*/

#ifndef CP5_BLOB_H_
#define CP5_BLOB_H_

#include <vector>
#include <initializer_list>
#include <memory>
#include <exception>

template <typename> class BlobPtr;
template <typename> class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);

    BlobPtr<T> begin();
    BlobPtr<T> end();
    
    size_type size() const { return data_->size(); }
    bool empty() const { return data_->empty(); }

    void push_back(const T& t) { data_->push_back(t); }
    void push_back(T&& t) { data_->push_back(std::move(t)); }
    void pop_back();

    T& back();
    T& operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data_;
    void check(size_type i, const std::string& msg) const;

};

template<typename T>
Blob<T>::Blob() : data_(std::make_shared<std::vector<T>>())
{
}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data_(std::make_shared<std::vector<T>>(il))
{
}

template<typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data_->pop_back();
}

template<typename T>
T & Blob<T>::back()
{
    check(0, "back on the empty Blob");
    return data_->back();
}

template<typename T>
T & Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data_)[i];
}

template<typename T>
void Blob<T>::check(size_type i, const std::string & msg) const
{
    if (i >= data_->size())
        throw std::out_of_range(msg);
}

template<typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return *lhs.data_ == *rhs.data_;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
class BlobPtr
{
    friend bool operator!=<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

public:
    BlobPtr() : curr_(0) {}
    BlobPtr(Blob<T>& a, size_t sz = 0) : wptr_(a.data_), curr_(sz) {}

    T& operator*() const
    {
        auto p = check(curr_, "dereference past end");
        return (*p)[curr_];
    }

    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);

private:
    std::shared_ptr<std::vector<T>> check(std::size_t i, const std::string& msg) const;

    std::weak_ptr<std::vector<T>> wptr_;
    std::size_t curr_;
};

template<typename T>
inline BlobPtr<T> & BlobPtr<T>::operator++()
{
    check(curr_, "increment past end of BlobPtr");
    ++curr_;
    return *this;
}

template<typename T>
inline BlobPtr<T> & BlobPtr<T>::operator--()
{
    --cur_;
    check(curr_, "decrement past end of BlobPtr");
    return *this;
}

template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr<T> ret = *this;
    ++*this;
    return ret;
}

template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr<T> ret = *this;
    --*this;
    return ret;
}

template<typename T>
inline std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string & msg) const
{
    auto ret = wptr_.lock();

    if (!ret)
    {
        throw std::runtime_error("unbound BlobPtr");
    }

    if (i >= ret->size())
    {
        throw std::runtime_error(msg);
    }

    return ret;
}

template<typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return !(lhs.curr_ == rhs.curr_);
}

template<typename T>
inline BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template<typename T>
inline BlobPtr<T> Blob<T>::end()
{
    return BlobPtr<T>(*this, data_->size());
}

#endif

