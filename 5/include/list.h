#include <vector>
#include <iostream>
#include <memory>

template <typename T>
    class List {
        private:
            struct Node {
                T data;
                std::shared_ptr<Node> next;
                friend std::ostream &operator << (std::ostream &os, const Node &node) {
                    os << node.data << ", " << node.next;
                    return os;
                }
                Node();
                Node(const T &value);
            };
            std::shared_ptr<Node> head;
            size_t size;
        public:

            friend std::ostream &operator << (std::ostream &os, List<T> list) {
                os << '[';
                while (list.head) {
                    os << '(' << *list.head.get() << ") ";
                    list.head = list.head->next;
                }
                os << "]\n";
                return os;
            }

            List();
            List(const std::vector<T> &v);
            List(const std::initializer_list<T> &l);
            List(const List &other);
            List(const List &&other);
    };

template <typename T>
List<T>::List() : head(), size(0) {}

template <typename T>
List<T>::Node::Node() : next(nullptr), data() {}

template <typename T>
List<T>::Node::Node(const T &value) : next(nullptr), data(value) {}

template <typename T>
List<T>::List(const std::vector<T> &v) {
    head = std::make_shared<Node>();
    size = v.size();
    std::shared_ptr<Node> first = head;
    for (int i = 0; i < v.size(); i++) {
        std::shared_ptr<Node> tmp = std::make_shared<Node>(v[i]);
        head->next = tmp;
        head = head->next;
    }
    head = std::move(first);
}

template <typename T>
List<T>::List(const std::initializer_list<T> &l) {
    head = std::make_shared<Node>();
    size = l.size();
    std::shared_ptr<Node> first = head;
    for (const auto &el: l) {
        std::shared_ptr<Node> tmp = std::make_shared<Node>(el);
        head->next = tmp;
        head = head->next;
    }
    head = first;
}

template <typename T>
List<T>::List(const List &other) {
    head = other.head;
    size = other.size;
}

template <typename T>
List<T>::List(const List &&other) {
    size = other.size;
    
}