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


// construct/copy/destroy:
template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::vector(const Allocator& allocator_object):
    _data(allocator_object) {
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::vector(size_type n):
    _data(n) {
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::vector(size_type n, const T& value, const Allocator& allocator_object):
    _data (n,value,allocator_object) {
}

template<class T, class Allocator>
template <class InputIterator>
araxes::shared::vector<T,Allocator>::vector(InputIterator first, InputIterator last,const Allocator& allocator_object):
    _data (first, last, allocator_object) {
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::vector(const vector<T,Allocator>& x):
    _data (x) {
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::vector(vector&& other):
    _data (std::move(other._data)) {
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::vector(const vector& other, const Allocator& allocator_object):
    _data (other, allocator_object) {
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::vector(vector&& other, const Allocator& allocator_object):
    _data (std::move(other._data),allocator_object) {
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::vector(std::initializer_list<T> list, const Allocator& allocator_object):
    _data (list, allocator_object) {
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>::~vector() {
    // Intentionally left blank
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>& araxes::shared::vector<T,Allocator>::operator=(const araxes::shared::vector<T,Allocator>& other) {
    exclusive_lock_t lock {this->_lock};
    shared_lock_t other_lock {other._lock};
    _data = other._data;
    return *this;
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>& araxes::shared::vector<T,Allocator>::operator=(vector<T,Allocator>&& other) {
    exclusive_lock_t lock {this->_lock};
    exclusive_lock_t other_lock {other._lock};
    this->_data = std::move(other._data);
    return *this;
}

template<class T, class Allocator>
araxes::shared::vector<T,Allocator>& araxes::shared::vector<T,Allocator>::operator=(std::initializer_list<T> list) {
    exclusive_lock_t lock {this->_lock};
    this->_data.operator=(list);
    return *this;
}

template<class T, class Allocator>
template <class InputIterator>
void araxes::shared::vector<T,Allocator>::assign(InputIterator first, InputIterator last) {
    exclusive_lock_t lock {this->_lock};
    this->_data.assign(first, last);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::assign(size_type n, const T& t) {
    exclusive_lock_t lock {this->_lock};
    this->_data.assign(n,t);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::assign(std::initializer_list<T> list) {
    exclusive_lock_t lock {this->_lock};
    this->_data.assign(list);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::allocator_type araxes::shared::vector<T,Allocator>::get_allocator() const noexcept {
    return this->_data.get_allocator();
}

// iterators:

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::iterator araxes::shared::vector<T,Allocator>::begin() noexcept {
    return this->_data.begin();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_iterator araxes::shared::vector<T,Allocator>::begin() const noexcept {
    return this->_data.begin();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::iterator araxes::shared::vector<T,Allocator>::end() noexcept {
    return this->_data.end();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_iterator araxes::shared::vector<T,Allocator>::end() const noexcept {
    return this->_data.end();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::reverse_iterator araxes::shared::vector<T,Allocator>::rbegin() noexcept {
    return this->_data.rbegin();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_reverse_iterator araxes::shared::vector<T,Allocator>::rbegin() const noexcept {
    return this->_data.rbegin();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::reverse_iterator araxes::shared::vector<T,Allocator>::rend() noexcept {
    return this->_data.rend();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_reverse_iterator araxes::shared::vector<T,Allocator>::rend() const noexcept {
    return this->_data.rend();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_iterator araxes::shared::vector<T,Allocator>::cbegin() noexcept {
    return this->_data.cbegin();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_iterator araxes::shared::vector<T,Allocator>::cend() noexcept {
    return this->_data.cend();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_reverse_iterator araxes::shared::vector<T,Allocator>::crbegin() const noexcept {
    return this->_data.crbegin();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_reverse_iterator araxes::shared::vector<T,Allocator>::crend() const noexcept {
    return this->_data.crend();
}

// capacity:
template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::size_type araxes::shared::vector<T,Allocator>::size() const noexcept {
    shared_lock_t lock {this->_lock};
    return this->_data.size();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::size_type araxes::shared::vector<T,Allocator>::max_size() const noexcept {
    shared_lock_t lock {this->_lock};
    return this->_data.max_size();
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::resize(size_type sz) {
    exclusive_lock_t lock {this->_lock};
    this->_data.resize(sz);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::resize(size_type sz, const T& c) {
    exclusive_lock_t lock {this->_lock};
    this->_data.resize(sz,c);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::size_type araxes::shared::vector<T,Allocator>::capacity() const noexcept {
    shared_lock_t lock {this->_lock};
    return this->_data.capacity();
}

template<class T, class Allocator>
bool araxes::shared::vector<T,Allocator>::empty() const noexcept {
    shared_lock_t lock {this->_lock};
    return this->_data.empty();
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::reserve(size_type n) {
    exclusive_lock_t lock {this->_lock};
    this->_data.reserve(n);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::shrink_to_fit() {
    exclusive_lock_t lock {this->_lock};
    this->_data.shrink_to_fit();
}

// element access:
template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::reference araxes::shared::vector<T,Allocator>::operator[](size_type n) {
    // TODO: Check this semantic:
    exclusive_lock_t lock {this->_lock};
    return this->_data[n];
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_reference araxes::shared::vector<T,Allocator>::operator[](size_type n) const {
    // TODO: Check this semantic:
    shared_lock_t lock {this->_lock};
    return this->_data[n];
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::reference araxes::shared::vector<T,Allocator>::at(size_type n) {
    // TODO: Check this semantic:
    exclusive_lock_t lock {this->_lock};
    return this->_data.at(n);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_reference araxes::shared::vector<T,Allocator>::at(size_type n) const {
    // TODO: Check this semantic:
    shared_lock_t lock {this->_lock};
    return this->_data.at(n);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::reference araxes::shared::vector<T,Allocator>::front() {
    // TODO: Check this semantic:
    exclusive_lock_t lock {this->_lock};
    return this->_data.front();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_reference araxes::shared::vector<T,Allocator>::front() const {
    // TODO: Check this semantic:
    shared_lock_t lock {this->_lock};
    return this->_data.front();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::reference araxes::shared::vector<T,Allocator>::back() {
    // TODO: Check this semantic:
    exclusive_lock_t lock {this->_lock};
    return this->_data.back();
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::const_reference araxes::shared::vector<T,Allocator>::back() const {
    // TODO: Check this semantic:
    shared_lock_t lock {this->_lock};
    return this->_data.back();
}

//data access
template<class T, class Allocator>
T* araxes::shared::vector<T,Allocator>::data() noexcept {
    // Unsafe
    return this->_data.data();
}

template<class T, class Allocator>
const T* araxes::shared::vector<T,Allocator>::data() const noexcept {
    // Unsafe
    return this->_data.data();
}

// modifiers:
template<class T, class Allocator>
template <class... Args>
void araxes::shared::vector<T,Allocator>::emplace_back(Args&& ... args) {
    exclusive_lock_t lock {this->_lock};
    this->_data.emplace_back(std::forward<Args>(args)...);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::push_back(const T& x) {
    exclusive_lock_t lock {this->_lock};
    this->_data.push_back(x);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::push_back(T&& x) {
    exclusive_lock_t lock {this->_lock};
    this->_data.push_back(x);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::pop_back() {
    exclusive_lock_t lock {this->_lock};
    this->_data.pop_back();
}

template<class T, class Allocator>
template <class... Args>
typename araxes::shared::vector<T,Allocator>::iterator
araxes::shared::vector<T,Allocator>::emplace(const_iterator position, Args&& ... args) {
    exclusive_lock_t lock {this->_lock};
    return this->_data.emplace(position,std::forward<Args>(args)...);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::iterator
araxes::shared::vector<T,Allocator>::insert(const_iterator position, const T& x) {
    exclusive_lock_t lock {this->_lock};
    return this->_data.insert(position,x);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::iterator
araxes::shared::vector<T,Allocator>::insert(const_iterator position, T&& x) {
    exclusive_lock_t lock {this->_lock};
    return this->_data.insert(position,x);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::iterator
araxes::shared::vector<T,Allocator>::insert(const_iterator position, size_type n,const T& x) {
    exclusive_lock_t lock {this->_lock};
    return this->_data.insert(position,n,x);
}

template<class T, class Allocator>
template <class InputIterator>
typename araxes::shared::vector<T,Allocator>::iterator
araxes::shared::vector<T,Allocator>::insert(const_iterator position, InputIterator first, InputIterator last) {
    exclusive_lock_t lock {this->_lock};
    return this->_data.insert(position,first,last);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::iterator
araxes::shared::vector<T,Allocator>::insert(const_iterator position, std::initializer_list<T> list) {
    exclusive_lock_t lock {this->_lock};
    return this->_data.insert(position,list);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::iterator
araxes::shared::vector<T,Allocator>::erase(const_iterator position) {
    exclusive_lock_t lock {this->_lock};
    return this->_data.erase(position);
}

template<class T, class Allocator>
typename araxes::shared::vector<T,Allocator>::iterator
araxes::shared::vector<T,Allocator>::erase(const_iterator first, const_iterator last) {
    exclusive_lock_t lock {this->_lock};
    return this->_data.erase(first,last);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::swap(vector<T,Allocator>& other) {
    exclusive_lock_t lock {this->_lock};
    exclusive_lock_t lock_other {other._lock};
    this->_data.swap(other._data);
}

template<class T, class Allocator>
void araxes::shared::vector<T,Allocator>::clear() noexcept {
    exclusive_lock_t lock {this->_lock};
    this->_data.clear();
}


