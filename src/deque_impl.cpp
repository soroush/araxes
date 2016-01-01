                                // construct/copy/destroy:
template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::deque(const Allocator& a):
        _data{a} {
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::deque(araxes::lockfree::deque<T, Allocator>::size_type n) :
        _data{n} {
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::deque(araxes::lockfree::deque<T, Allocator>::size_type n,
                                             const T& v,
                                             const Allocator& a):
        _data{n,v,a} {
}

template<class T, class Allocator>
template <class InputIterator>
araxes::lockfree::deque<T, Allocator>::deque(InputIterator first, InputIterator last,const Allocator& allocator):
        _data{first,last,allocator} {
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::deque(const deque<T,Allocator>& x) :
        _data{x} {
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::deque(araxes::lockfree::deque<T, Allocator>&& other) {
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::deque(const araxes::lockfree::deque<T, Allocator>& other, const Allocator& allocator):
        _data{other._data, allocator} {
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::deque(araxes::lockfree::deque<T, Allocator>&& other, const Allocator& allocator):
        _data{other._data, allocator} {
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::deque(std::initializer_list<T> l, const Allocator& a):
        _data{l, a}{
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>::~deque(){
        // Nothing to do here
}

template<class T, class Allocator>
araxes::lockfree::deque<T,Allocator>& araxes::lockfree::deque<T, Allocator>::operator=(const araxes::lockfree::deque<T,Allocator>& other) {
        _data = other._data;
        return *this;
}

template<class T, class Allocator>
araxes::lockfree::deque<T,Allocator>& araxes::lockfree::deque<T, Allocator>::operator=(araxes::lockfree::deque<T,Allocator>&& other) {
        _data = other._data;
        return *this;
}

template<class T, class Allocator>
araxes::lockfree::deque<T, Allocator>& araxes::lockfree::deque<T, Allocator>::operator=(std::initializer_list<T> l) {
        _data.operator=(l);
}

template<class T, class Allocator>
template <class InputIterator>
void araxes::lockfree::deque<T, Allocator>::assign(InputIterator first, InputIterator last) {
        _data.assign(first,last);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::assign(size_type n, const T& t) {
        _data.assign(n,t);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::assign(std::initializer_list<T> l) {
        _data.assign(l);
}

template<class T, class Allocator>
Allocator araxes::lockfree::deque<T, Allocator>::get_allocator() const noexcept {
        return _data.get_allocator();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::iterator araxes::lockfree::deque<T, Allocator>::begin() noexcept {
        return _data.begin();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_iterator araxes::lockfree::deque<T, Allocator>::begin() const noexcept {
        return _data.begin();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::iterator araxes::lockfree::deque<T, Allocator>::end() noexcept {
        return _data.end();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_iterator araxes::lockfree::deque<T, Allocator>::end() const noexcept {
        return _data.end();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::reverse_iterator
araxes::lockfree::deque<T, Allocator>::rbegin() noexcept {
        return _data.rbegin();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_reverse_iterator
araxes::lockfree::deque<T, Allocator>::rbegin() const noexcept {
        return _data.rbegin();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::reverse_iterator
araxes::lockfree::deque<T, Allocator>::rend() noexcept {
        return _data.rend();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_reverse_iterator
araxes::lockfree::deque<T, Allocator>::rend() const noexcept {
        return _data.rend();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_iterator
araxes::lockfree::deque<T, Allocator>::cbegin() noexcept {
        return _data.cbegin();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_iterator
araxes::lockfree::deque<T, Allocator>::cend() noexcept {
        return _data.cend();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_reverse_iterator
araxes::lockfree::deque<T, Allocator>::crbegin() const noexcept {
        return _data.crbegin();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_reverse_iterator
araxes::lockfree::deque<T, Allocator>::crend() const noexcept {
        return _data.crend();
}

// capacity:
template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::size_type
araxes::lockfree::deque<T, Allocator>::size() const noexcept {
        return _data.size();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::size_type
araxes::lockfree::deque<T, Allocator>::max_size() const noexcept {
        return _data.max_size();
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::resize(araxes::lockfree::deque<T, Allocator>::size_type sz) {
        _data.resize(sz);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::resize(araxes::lockfree::deque<T, Allocator>::size_type sz, const T& c) {
        _data.resize(sz,c);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::shrink_to_fit() {
        _data.shrink_to_fit();
}

template<class T, class Allocator>
bool araxes::lockfree::deque<T, Allocator>::empty() const noexcept {
        return _data.empty();
}

// element access:
template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::reference
araxes::lockfree::deque<T, Allocator>::operator[](araxes::lockfree::deque<T, Allocator>::size_type n) {
        return _data[n];
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_reference
araxes::lockfree::deque<T, Allocator>::operator[](araxes::lockfree::deque<T, Allocator>::size_type n) const {
        return _data[n];
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::reference
araxes::lockfree::deque<T, Allocator>::at(araxes::lockfree::deque<T, Allocator>::size_type n) {
        return _data.at(n);
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_reference
araxes::lockfree::deque<T, Allocator>::at(araxes::lockfree::deque<T, Allocator>::size_type n) const {
        return _data.at(n);
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::reference
araxes::lockfree::deque<T, Allocator>::front() {
        return _data.front();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_reference
araxes::lockfree::deque<T, Allocator>::front() const {
        return _data.front();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::reference
araxes::lockfree::deque<T, Allocator>::back() {
        return _data.back();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::const_reference
araxes::lockfree::deque<T, Allocator>::back() const {
        return _data.back();
}

// modifiers:
template<class T, class Allocator>
template <class... Args> void araxes::lockfree::deque<T, Allocator>::emplace_front(Args&&... args) {
        _data.emplace_front(std::forward<Args>(args)...);
}

template<class T, class Allocator>
template <class... Args> void araxes::lockfree::deque<T, Allocator>::emplace_back(Args&&... args) {
        _data.emplace_back(std::forward<Args>(args)...);
}

template<class T, class Allocator>
template <class... Args>
typename araxes::lockfree::deque<T, Allocator>::iterator
araxes::lockfree::deque<T, Allocator>::emplace(araxes::lockfree::deque<T, Allocator>::const_iterator position, Args&&... args) {
        _data.emplace(position,std::forward<Args>(args)...);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::push_front(const T& x) {
        _data.push_front(x);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::push_front(T&& x) {
        _data.push_front(x);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::push_back(const T& x) {
        _data.push_back(x);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::push_back(T&& x) {
        _data.push_back(x);
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::iterator
araxes::lockfree::deque<T, Allocator>::insert(araxes::lockfree::deque<T, Allocator>::const_iterator position, const T& x) {
        _data.insert(position,x);
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::iterator
araxes::lockfree::deque<T, Allocator>::insert(araxes::lockfree::deque<T, Allocator>::const_iterator position, T&& x) {
        _data.insert(position,x);
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::iterator
araxes::lockfree::deque<T, Allocator>::insert(araxes::lockfree::deque<T, Allocator>::const_iterator position,
                                                                araxes::lockfree::deque<T, Allocator>::size_type n, const T& x) {
        _data.insert(position,n,x);
}

template<class T, class Allocator>
template <class InputIterator>
typename araxes::lockfree::deque<T, Allocator>::iterator
araxes::lockfree::deque<T, Allocator>::insert (araxes::lockfree::deque<T, Allocator>::const_iterator position,
                                                                 InputIterator first,
                                                                 InputIterator last) {
        _data.insert(position,first,last);
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::iterator
araxes::lockfree::deque<T, Allocator>::insert(araxes::lockfree::deque<T, Allocator>::const_iterator position,
                                              std::initializer_list<T> list) {
        _data.insert(position,list);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::pop_front() {
        _data.pop_front();
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::pop_back(){
        _data.pop_back();
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::iterator araxes::lockfree::deque<T, Allocator>::erase(araxes::lockfree::deque<T, Allocator>::const_iterator position) {
        _data.erase(position);
}

template<class T, class Allocator>
typename araxes::lockfree::deque<T, Allocator>::iterator
araxes::lockfree::deque<T, Allocator>::erase(araxes::lockfree::deque<T, Allocator>::const_iterator first,
                                             araxes::lockfree::deque<T, Allocator>::const_iterator last) {
        _data.erase(first,last);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::swap(araxes::lockfree::deque<T,Allocator>& other) {
        _data.swap(other._data);
}

template<class T, class Allocator>
void araxes::lockfree::deque<T, Allocator>::clear() noexcept {
        _data.clear();
}
