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

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::deque(const Allocator& a):
    _data {a} {
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::deque(araxes::shared::deque<T, Allocator>::size_type n) :
    _data {n} {
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::deque(araxes::shared::deque<T, Allocator>::size_type n,
        const T& v,
        const Allocator& a):
    _data {n,v,a} {
}

template<class T, class Allocator>
template <class InputIterator>
araxes::shared::deque<T, Allocator>::deque(InputIterator first, InputIterator last,const Allocator& allocator):
    _data {first,last,allocator} {
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::deque(const deque<T,Allocator>& x) :
    _data {x} {
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::deque(araxes::shared::deque<T, Allocator>&& other) {
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::deque(const araxes::shared::deque<T, Allocator>& other, const Allocator& allocator):
    _data {other._data, allocator} {
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::deque(araxes::shared::deque<T, Allocator>&& other, const Allocator& allocator):
    _data {other._data, allocator} {
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::deque(std::initializer_list<T> l, const Allocator& a):
    _data {l, a} {
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>::~deque() {
    // Nothing to do here
}

template<class T, class Allocator>
araxes::shared::deque<T,Allocator>& araxes::shared::deque<T, Allocator>::operator=(const araxes::shared::deque<T,Allocator>& other) {
    exclusive_lock_t lock(this->_lock);
    _data = other._data;
    return *this;
}

template<class T, class Allocator>
araxes::shared::deque<T,Allocator>& araxes::shared::deque<T, Allocator>::operator=(araxes::shared::deque<T,Allocator>&& other) {
    exclusive_lock_t lock(this->_lock);
    _data = other._data;
    return *this;
}

template<class T, class Allocator>
araxes::shared::deque<T, Allocator>& araxes::shared::deque<T, Allocator>::operator=(std::initializer_list<T> l) {
    exclusive_lock_t lock(this->_lock);
    _data.operator=(l);
}

template<class T, class Allocator>
template <class InputIterator>
void araxes::shared::deque<T, Allocator>::assign(InputIterator first, InputIterator last) {
    exclusive_lock_t lock(this->_lock);
    _data.assign(first,last);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::assign(size_type n, const T& t) {
    exclusive_lock_t lock(this->_lock);
    _data.assign(n,t);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::assign(std::initializer_list<T> l) {
    exclusive_lock_t lock(this->_lock);
    _data.assign(l);
}

template<class T, class Allocator>
Allocator araxes::shared::deque<T, Allocator>::get_allocator() const noexcept {
    // TODO: Determine if getting allocator requires shared or exclusive ownership
    return _data.get_allocator();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::iterator araxes::shared::deque<T, Allocator>::begin() noexcept {
    shared_lock_t lock(this->_lock);
    return _data.begin();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_iterator araxes::shared::deque<T, Allocator>::begin() const noexcept {
    shared_lock_t lock(this->_lock);
    return _data.begin();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::iterator araxes::shared::deque<T, Allocator>::end() noexcept {
    shared_lock_t lock(this->_lock);
    return _data.end();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_iterator araxes::shared::deque<T, Allocator>::end() const noexcept {
    shared_lock_t lock(this->_lock);
    return _data.end();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::reverse_iterator
araxes::shared::deque<T, Allocator>::rbegin() noexcept {
    shared_lock_t lock(this->_lock);
    return _data.rbegin();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_reverse_iterator
araxes::shared::deque<T, Allocator>::rbegin() const noexcept {
    shared_lock_t lock(this->_lock);
    return _data.rbegin();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::reverse_iterator
araxes::shared::deque<T, Allocator>::rend() noexcept {
    return _data.rend();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_reverse_iterator
araxes::shared::deque<T, Allocator>::rend() const noexcept {
    shared_lock_t lock(this->_lock);
    return _data.rend();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_iterator
araxes::shared::deque<T, Allocator>::cbegin() noexcept {
    shared_lock_t lock(this->_lock);
    return _data.cbegin();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_iterator
araxes::shared::deque<T, Allocator>::cend() noexcept {
    shared_lock_t lock(this->_lock);
    return _data.cend();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_reverse_iterator
araxes::shared::deque<T, Allocator>::crbegin() const noexcept {
    return _data.crbegin();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_reverse_iterator
araxes::shared::deque<T, Allocator>::crend() const noexcept {
    shared_lock_t lock(this->_lock);
    return _data.crend();
}

// capacity:
template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::size_type
araxes::shared::deque<T, Allocator>::size() const noexcept {
    return _data.size();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::size_type
araxes::shared::deque<T, Allocator>::size() noexcept {
    shared_lock_t lock(this->_lock);
    return _data.size();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::size_type
araxes::shared::deque<T, Allocator>::max_size() const noexcept {
    return _data.max_size();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::size_type
araxes::shared::deque<T, Allocator>::max_size() noexcept {
    shared_lock_t lock(this->_lock);
    return _data.max_size();
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::resize(araxes::shared::deque<T, Allocator>::size_type sz) {
    exclusive_lock_t lock(this->_lock);
    _data.resize(sz);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::resize(araxes::shared::deque<T, Allocator>::size_type sz, const T& c) {
    exclusive_lock_t lock(this->_lock);
    _data.resize(sz,c);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::shrink_to_fit() {
    exclusive_lock_t lock(this->_lock);
    _data.shrink_to_fit();
}

template<class T, class Allocator>
bool araxes::shared::deque<T, Allocator>::empty() const noexcept {
    return _data.empty();
}

template<class T, class Allocator>
bool araxes::shared::deque<T, Allocator>::empty() noexcept {
    shared_lock_t lock(this->_lock);
    return _data.empty();
}

// element access:
template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::reference
araxes::shared::deque<T, Allocator>::operator[](araxes::shared::deque<T, Allocator>::size_type n) {
    // WARNING: This operation is not thread-safe
    exclusive_lock_t lock(this->_lock);
    return _data[n];
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_reference
araxes::shared::deque<T, Allocator>::operator[](araxes::shared::deque<T, Allocator>::size_type n) const {
    // WARNING: This operation is not thread-safe
    shared_lock_t lock(this->_lock);
    return _data[n];
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::reference
araxes::shared::deque<T, Allocator>::at(araxes::shared::deque<T, Allocator>::size_type n) {
    // WARNING: This operation is not thread-safe
    shared_lock_t lock(this->_lock);
    return _data.at(n);
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_reference
araxes::shared::deque<T, Allocator>::at(araxes::shared::deque<T, Allocator>::size_type n) const {
    shared_lock_t lock(this->_lock);
    return _data.at(n);
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::reference
araxes::shared::deque<T, Allocator>::front() {
    shared_lock_t lock(this->_lock);
    return _data.front();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_reference
araxes::shared::deque<T, Allocator>::front() const {
    shared_lock_t lock(this->_lock);
    return _data.front();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::reference
araxes::shared::deque<T, Allocator>::back() {
    shared_lock_t lock(this->_lock);
    return _data.back();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::const_reference
araxes::shared::deque<T, Allocator>::back() const {
    shared_lock_t lock(this->_lock);
    return _data.back();
}

// modifiers:
template<class T, class Allocator>
template <class... Args> void araxes::shared::deque<T, Allocator>::emplace_front(Args&& ... args) {
    exclusive_lock_t lock(this->_lock);
    _data.emplace_front(std::forward<Args>(args)...);
}

template<class T, class Allocator>
template <class... Args> void araxes::shared::deque<T, Allocator>::emplace_back(Args&& ... args) {
    exclusive_lock_t lock(this->_lock);
    _data.emplace_back(std::forward<Args>(args)...);
}

template<class T, class Allocator>
template <class... Args>
typename araxes::shared::deque<T, Allocator>::iterator
araxes::shared::deque<T, Allocator>::emplace(araxes::shared::deque<T, Allocator>::const_iterator position, Args&& ... args) {
    exclusive_lock_t lock(this->_lock);
    _data.emplace(position,std::forward<Args>(args)...);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::push_front(const T& x) {
    exclusive_lock_t lock(this->_lock);
    _data.push_front(x);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::push_front(T&& x) {
    exclusive_lock_t lock(this->_lock);
    _data.push_front(x);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::push_back(const T& x) {
    exclusive_lock_t lock(this->_lock);
    _data.push_back(x);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::push_back(T&& x) {
    exclusive_lock_t lock(this->_lock);
    _data.push_back(x);
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::iterator
araxes::shared::deque<T, Allocator>::insert(araxes::shared::deque<T, Allocator>::const_iterator position, const T& x) {
    exclusive_lock_t lock(this->_lock);
    _data.insert(position,x);
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::iterator
araxes::shared::deque<T, Allocator>::insert(araxes::shared::deque<T, Allocator>::const_iterator position, T&& x) {
    exclusive_lock_t lock(this->_lock);
    _data.insert(position,x);
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::iterator
araxes::shared::deque<T, Allocator>::insert(araxes::shared::deque<T, Allocator>::const_iterator position,
        araxes::shared::deque<T, Allocator>::size_type n, const T& x) {
    exclusive_lock_t lock(this->_lock);
    _data.insert(position,n,x);
}

template<class T, class Allocator>
template <class InputIterator>
typename araxes::shared::deque<T, Allocator>::iterator
araxes::shared::deque<T, Allocator>::insert (araxes::shared::deque<T, Allocator>::const_iterator position,
        InputIterator first,
        InputIterator last) {
    exclusive_lock_t lock(this->_lock);
    _data.insert(position,first,last);
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::iterator
araxes::shared::deque<T, Allocator>::insert(araxes::shared::deque<T, Allocator>::const_iterator position,
        std::initializer_list<T> list) {
    exclusive_lock_t lock(this->_lock);
    _data.insert(position,list);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::pop_front() {
    exclusive_lock_t lock(this->_lock);
    _data.pop_front();
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::pop_back() {
    _data.pop_back();
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::iterator araxes::shared::deque<T, Allocator>::erase(araxes::shared::deque<T, Allocator>::const_iterator position) {
    exclusive_lock_t lock(this->_lock);
    _data.erase(position);
}

template<class T, class Allocator>
typename araxes::shared::deque<T, Allocator>::iterator
araxes::shared::deque<T, Allocator>::erase(araxes::shared::deque<T, Allocator>::const_iterator first,
        araxes::shared::deque<T, Allocator>::const_iterator last) {
    exclusive_lock_t lock(this->_lock);
    _data.erase(first,last);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::swap(araxes::shared::deque<T,Allocator>& other) {
    exclusive_lock_t lock(this->_lock);
    _data.swap(other._data);
}

template<class T, class Allocator>
void araxes::shared::deque<T, Allocator>::clear() noexcept {
    exclusive_lock_t lock(this->_lock);
    _data.clear();
}



