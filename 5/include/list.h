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
            };
            Node *head;
            size_t size;
        public:

            friend std::ostream &operator << (std::ostream &os, List<T> list) {
                os << '[';
                while (list.head) {
                    os << '(' << *list.head << ") ";
                    list.head = list.head->next;
                }
                os << "]\n";
                return os;
            }

            List();
            List(const std::initializer_list<T> &l);
            List(const List &other);
            List(const List &&other) noexcept;
    };

template <typename T>
List<T>::List() : head(), size(0) {}

template <typename T>
List<T>::Node::Node() : next(nullptr), data() {}

template <typename T>
List<T>::Node::Node(const T &value) : next(nullptr), data(value) {}

template <typename T>
List<T>::Node::Node(const Node &other) {
    data = other.data;
    next = other.next;
}

template <typename T>
List<T>::List(const std::initializer_list<T> &l) {
    head = new Node();
    size = l.size();
    Node *first = head;
    for (const auto &el: l) {
        Node *tmp = new Node(el);
        head->next = tmp;
        head = head->next;
    }
    head = first;
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
    cur->next = nullptr;
}

template <typename T>
List<T>::List(const List &&other) noexcept{
    size = other.size;
    head = other.head;
}