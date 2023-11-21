#include <vector>
#include <iostream>
#include <memory>

template <typename T>
    class List {
        private:
            struct Node {
                T data;
                Node *next;
                friend std::ostream &operator << (std::ostream &os, const Node &node) {
                    os << node.data << ", " << node.next;
                    return os;
                }
                Node();
                Node(const T &value);
                Node(const Node &other);
                ~Node() = default;
                
                T& get(size_t idx);
                bool operator==(const Node &other) const;
            };
            Node *head;
            Node *tail;
            size_t size;
        public:
        
            friend std::ostream &operator << (std::ostream &os, const List<T> &list) {
                os << '[';
                Node *cur = list.head;
                while (cur->next) {
                    os << cur->data << ", ";
                    cur = cur->next;
                }
                os << cur->data << ']' << std::endl;
                return os;
            }

            List();
            List(const std::initializer_list<T> &l);
            List(const List &other);
            List(const List &&other) noexcept;
            ~List() noexcept;

            int getSize() const;
            void push_back(const T &value);
            void emplace(const T &value);
            void remove();
            void pop();
            bool is_empty() const;
            T & front() const;
            T & back() const;

            T &operator [] (size_t idx);
            bool operator==(const List<T> &other) const;
            List<T> &operator=(List<T> &other);
            List<T> &operator=(List<T> &&other) noexcept;
            
            class Iterator {
                friend class List;
                private:
                    Node *item;
                public:

                    Iterator(Iterator &other);
                    Iterator(Iterator &&other) noexcept;
                    Iterator(Node *node);
                    ~Iterator() = default;
                    
                    List::Iterator &operator ++();
                    List::Iterator operator ++(int);
                    List::Iterator &operator + (size_t rhs);
                    T& operator* () const;
                    T* operator-> () const;
                    bool operator ==(const Iterator &other) const;
                    bool operator !=(const Iterator &other) const;
                    List::Iterator &operator =(const Iterator &other);
                    List::Iterator &operator =(Iterator &&other) noexcept;
            };

            class ConstIterator {
                friend class List;
                private:
                    const Node *item;
                public:

                    ConstIterator(ConstIterator &other);
                    ConstIterator(ConstIterator &&other) noexcept;
                    ConstIterator(Node *node);
                    ~ConstIterator() = default;
                    
                    const List::ConstIterator &operator ++();
                    List::ConstIterator operator ++(int);
                    const List::ConstIterator &operator + (size_t rhs);
                    const T& operator *() const;
                    const T* operator ->() const;
                    bool operator ==(const ConstIterator &other) const;
                    bool operator !=(const ConstIterator &other) const;
                    List::ConstIterator &operator =(const ConstIterator &other);
                    List::ConstIterator &operator =(ConstIterator &&other) noexcept;
            };
            List::ConstIterator cbegin();
            List::ConstIterator cend();
            List::Iterator begin();
            List::Iterator end();
            void insert(List::Iterator iter, const T& value);
            void erase(List::Iterator iter);
    };

template <typename T>
List<T>::List() : head(nullptr), size(0), tail(nullptr) {}

template <typename T>
List<T>::Node::Node() : next(nullptr), data() {}

template <typename T>
List<T>::Node::Node(const T &value) : next(nullptr), data(value) {}

template <typename T>
List<T>::Node::Node(const Node &other) {
    data = other.data;
    next = other.next;
}

template<typename T>
T& List<T>::Node::get(size_t idx) {
    if (idx == 0) return data;
    if (next) return next->get(--idx);
    throw std::range_error("Out of range");
}

template<typename T>
bool List<T>::Node::operator==(const Node &other) const {
    return data == other.data;
}

template <typename T>
List<T>::List(const std::initializer_list<T> &l) {
    head = new Node(*l.begin());
    size = l.size();
    Node *cur = head;
    for (auto el = l.begin() + 1; el != l.end(); ++el) {
        cur->next = new Node(*el);
        cur = cur->next;
    }
    tail = cur;
    cur->next = nullptr;
}

template <typename T>
List<T>::List(const List &other) {
    size = other.size;
    head = new Node(*other.head);
    Node *cur = head;
    for (Node *t = other.head->next; t != nullptr; t = t->next) {
        cur->next = new Node(*t);
        cur = cur->next;
    }
    tail = cur;
    cur->next = nullptr;
}

template <typename T>
List<T>::~List() noexcept{
    while (head != NULL) {
        remove();
    }
}

template <typename T>
List<T>::List(const List &&other) noexcept{
    size = other.size;
    head = other.head;
    tail = other.tail;
}

template<typename T>
T& List<T>::operator[] (size_t idx) {
    if (size < idx) {
        throw std::range_error("Out of range");
    } else {
        return head->get(idx);
    }
}

template<typename T>
int List<T>::getSize () const{
    return size;
}

template<typename T>
bool List<T>::is_empty() const {
    return size == 0;
}


template<typename T>
void List<T>::push_back (const T &value){
    Node *tmp = new Node(value);
    if (this->is_empty()) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
    size++;
}

template<typename T>
void List<T>::emplace (const T &value){
    Node *tmp = new Node(head->data);
    tmp->next = head->next;
    head->data = value;
    head->next = tmp;
    size++;
}

template<typename T>
void List<T>::remove(){
    if (this->is_empty()) {
        throw std::logic_error("Can't remove from empty list");
    }
    if (head == tail) {
        delete tail;
        head = tail = NULL;
        size = 0;
        return;
    }
    Node *tmp = head;
    head = tmp->next;
    size--;
    delete tmp;
}

template<typename T>
void List<T>::pop(){
    if (this->is_empty()) {
        throw std::logic_error("Can't remove from empty list");
    }
    if (head == tail) {
        remove();
    }
    size--;
    Node *tmp = head;
    while (tmp->next != tail) tmp = tmp->next;
    tmp->next = nullptr;
    delete tail;
    tail = tmp;
}

template<typename T>
T &List<T>::front() const {
    return head->data;
}

template<typename T>
T &List<T>::back() const {
    return tail->data;
}

template<typename T>
bool List<T>::operator==(const List<T> &other) const{
    if (size != other.getSize()) {
        return false;
    }
    Node *tmp1 = head;
    Node *tmp2 = other.head;
    while (tmp1) {
        if (!(*tmp1 == *tmp2)) return false;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return true;
}

template<typename T>
List<T> &List<T>::operator=(List<T> &other) {
    size = other.size;
    head = new Node(*other.head);
    Node *cur = head;
    for (Node *t = other.head->next; t != nullptr; t = t->next) {
        cur->next = new Node(*t);
        cur = cur->next;
    }
    tail = cur;
    cur->next = nullptr;
    return *this;
}

template<typename T>
List<T> &List<T>::operator=(List<T> &&other) noexcept {
    size = other.size; other.size = 0;
    head = other.head; other.head = nullptr;
    tail = other.tail; other.tail = nullptr;
    return *this;
}

template <typename T>
List<T>::Iterator::Iterator(Iterator &other) : item(other.item) {}

template <typename T>
List<T>::Iterator::Iterator(Iterator &&other) noexcept {
    item = std::move(other.item);
}

template <typename T>
List<T>::Iterator::Iterator(Node *node) : item(node) {}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator++() {
    if (item == nullptr) {
        throw std::range_error("Out of range");
    }
    item = item->next;
    return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    List::Iterator tmp = *this;
    if (tmp == nullptr) {
        throw std::range_error("Out of range");
    }
    ++(tmp); 
    return tmp;
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator+(size_t rhs) {
    for (size_t i = 0; i < rhs; i++) {
        if (item == nullptr) {
            throw std::range_error("Out of range");
        }
        item = item->next;
    }
    if (item == nullptr) {
        throw std::range_error("Out of range");
    }
    return *this;
}

template <typename T>
T& List<T>::Iterator::operator *() const {
    return item->data;
}

template <typename T>
bool List<T>::Iterator::operator == (const Iterator &other) const {
    return item == other.item;
}

template <typename T>
bool List<T>::Iterator::operator != (const Iterator &other) const{
    return !(other == *this);
}

template <typename T>
T* List<T>::Iterator::operator ->() const {
    return &(item->data);
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator =(const typename List<T>::Iterator &other) {
    item = other.item;
    return *this;
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator =(typename List<T>::Iterator &&other) noexcept{
    item = std::move(other.item);
}

template <typename T>
typename List<T>::Iterator List<T>::begin() {
    return Iterator(head);
}

template <typename T>
typename List<T>::Iterator List<T>::end() {
    return Iterator(nullptr);
}

template <typename T>
void List<T>::insert(List::Iterator iter, const T& value) {
    auto jter = this->begin();
    Node *cur = head;
    while (iter != jter) {
        cur = cur->next;
        ++jter;
    }
    Node *tmp = cur->next;
    cur->next = new Node(value);
    cur->next->next = tmp;
    size++;
}

template <typename T>
void List<T>::erase(List::Iterator iter) {
    auto jter = this->begin();
    Node *cur = head;
    Node *prev;
    while (iter != jter) {
        prev = cur;
        if (cur == nullptr) {
            throw std::range_error("Out of range");
        }
        cur = cur->next;
        ++jter;
    }
    Node *tmp = prev->next->next;
    delete prev->next;
    prev->next = tmp;
    size--;
}

template <typename T>
List<T>::ConstIterator::ConstIterator(ConstIterator &other) : item(other.item) {}

template <typename T>
List<T>::ConstIterator::ConstIterator(ConstIterator &&other) noexcept {
    item = std::move(other.item);
}

template <typename T>
List<T>::ConstIterator::ConstIterator(Node *node) : item(node) {}


template <typename T>
const typename List<T>::ConstIterator &List<T>::ConstIterator::operator++() {
    if (item == nullptr) {
        throw std::range_error("Out of range");
    }
    item = item->next;
    return *this;
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int) {
    List::ConstIterator tmp = *this;
    if (tmp == nullptr) {
        throw std::range_error("Out of range");
    }
    ++(tmp); 
    return tmp;
}

template <typename T>
const typename List<T>::ConstIterator &List<T>::ConstIterator::operator+(size_t rhs) {
    for (size_t i = 0; i < rhs; i++) {
        if (item == nullptr) {
            throw std::range_error("Out of range");
        }
        item = item->next;
    }
    if (item == nullptr) {
        throw std::range_error("Out of range");
    }
    return *this;
}

template <typename T>
const T& List<T>::ConstIterator::operator *() const {
    return item->data;
}

template <typename T>
bool List<T>::ConstIterator::operator == (const ConstIterator &other) const {
    return item == other.item;
}

template <typename T>
bool List<T>::ConstIterator::operator != (const ConstIterator &other) const{
    return !(other == *this);
}

template <typename T>
const T* List<T>::ConstIterator::operator-> () const {
    return &(item->data);
}

template <typename T>
typename List<T>::ConstIterator &List<T>::ConstIterator::operator =(const typename List<T>::ConstIterator &other) {
    item = other.item;
    return *this;
}

template <typename T>
typename List<T>::ConstIterator &List<T>::ConstIterator::operator =(typename List<T>::ConstIterator &&other) noexcept{
    item = std::move(other.item);
}

template <typename T>
typename List<T>::ConstIterator List<T>::cbegin() {
    return ConstIterator(head);
}

template <typename T>
typename List<T>::ConstIterator List<T>::cend() {
    return ConstIterator(nullptr);
}