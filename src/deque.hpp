/*
 * Araxes Library, A C++ library of Lockfree data structures tools.
 *
 * Copyright (c) 2015 Soroush Rabiei <rabiei@tidm.ir>,
 *
 * libaraxes is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more
 * information.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef ARAXES_DEQUE_HPP
#define ARAXES_DEQUE_HPP

#include <memory>
#include <deque>
#include <initializer_list>
#include "locks.hpp"

namespace araxes {
    namespace shared {
        template<class T, class Allocator = std::allocator<T>>
        class deque {
            public:
                // types:
                typedef T value_type;
                typedef value_type& reference;
                // typedef typename std::deque<T,Allocator>::value_type value_type;
                typedef const value_type& const_reference;
                typedef typename std::deque<T,Allocator>::iterator iterator;
                typedef typename std::deque<T,Allocator>::const_iterator const_iterator;
                typedef typename std::deque<T,Allocator>::size_type size_type;
                // typedef typename std::deque<T,Allocator>::difference_type difference_type;
                // typedef typename std::deque<T,Allocator>::Allocator Allocator;
                // typedef typename
                //     std::deque<T,Allocator>::allocator_traits<Allocator>::pointer
                //                              allocator_traits<Allocator>::pointer;
                // typedef typename
                //     std::deque<T,Allocator>::allocator_traits<Allocator>::const_pointer
                //                              allocator_traits<Allocator>::const_pointer;
                typedef typename std::reverse_iterator<iterator> reverse_iterator;
                typedef typename std::reverse_iterator<const_iterator>
                const_reverse_iterator;

                // construct/copy/destroy:
                explicit deque(const Allocator& = Allocator());
                explicit deque(size_type n);
                deque(size_type n, const T& value,const Allocator& = Allocator());
                template <class InputIterator>
                deque(InputIterator first, InputIterator last,const Allocator& = Allocator());
                deque(const deque<T,Allocator>& x);
                deque(deque&&);
                deque(const deque&, const Allocator&);
                deque(deque&&, const Allocator&);
                deque(std::initializer_list<T>, const Allocator& = Allocator());

                ~deque();
                deque<T,Allocator>& operator=(const deque<T,Allocator>& x);
                deque<T,Allocator>& operator=(deque<T,Allocator>&& x);
                deque& operator=(std::initializer_list<T>);
                template <class InputIterator>
                void assign(InputIterator first, InputIterator last);
                void assign(size_type n, const T& t);
                void assign(std::initializer_list<T>);
                Allocator get_allocator() const noexcept;

                // iterators:
                iterator                begin() noexcept;
                const_iterator          begin() const noexcept;
                iterator                end() noexcept;
                const_iterator          end() const noexcept;

                reverse_iterator        rbegin() noexcept;
                const_reverse_iterator  rbegin() const noexcept;
                reverse_iterator        rend() noexcept;
                const_reverse_iterator  rend() const noexcept;

                const_iterator          cbegin() noexcept;
                const_iterator          cend() noexcept;
                const_reverse_iterator  crbegin() const noexcept;
                const_reverse_iterator  crend() const noexcept;

                // capacity:
                size_type size() const noexcept;
                size_type size() noexcept;
                size_type max_size() const noexcept;
                size_type max_size() noexcept;
                void      resize(size_type sz);
                void      resize(size_type sz, const T& c);
                void      shrink_to_fit();
                bool      empty() const noexcept;
                bool      empty() noexcept;

                // element access:
                reference       operator[](size_type n);
                const_reference operator[](size_type n) const;
                reference       at(size_type n);
                const_reference at(size_type n) const;
                reference       front();
                const_reference front() const;
                reference       back();
                const_reference back() const;

                // modifiers:
                template <class... Args> void emplace_front(Args&& ... args);
                template <class... Args> void emplace_back(Args&& ... args);
                template <class... Args> iterator emplace(const_iterator position, Args&& ... args);

                void push_front(const T& x);
                void push_front(T&& x);
                void push_back(const T& x);
                void push_back(T&& x);

                iterator insert(const_iterator position, const T& x);
                iterator insert(const_iterator position, T&& x);
                iterator insert(const_iterator position, size_type n, const T& x);
                template <class InputIterator>
                iterator insert (const_iterator position, InputIterator first,
                                 InputIterator last);
                iterator insert(const_iterator position, std::initializer_list<T>);

                void pop_front();
                void pop_back();

                iterator erase(const_iterator position);
                iterator erase(const_iterator first, const_iterator last);
                void     swap(deque<T,Allocator>&);
                void     clear() noexcept;
            private:
                std::deque<T> _data;
                shared_mutex_t _lock;
        };
    }
}

#include "deque.tpp"
#endif




