
template <typename T>
LinkedListStack<T>::LinkedListStack() {
    this->top = nullptr;
    this->length = 0;
}


template <typename T>
LinkedListStack<T>::~LinkedListStack() { clear(); }


template <typename T>
void LinkedListStack<T>::clear() {
    while (this->top != nullptr) {
        Node<T>* n = this->top;
        this->top = this->top->next;
        delete n;
    }
    this->length = 0;
}


template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& other) {
    this->top = nullptr;
    this->length = 0;
    if (other.top == nullptr) return;

    Node<T>* src  = other.top;
    Node<T>* tail = nullptr;

    while (src != nullptr) {
        Node<T>* node = new Node<T>(src->data); // next defaults to nullptr
        if (tail == nullptr) this->top = node;
        else                 tail->next = node;
        tail = node;
        src = src->next;
        ++this->length;
    }
}


template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& rhs) {
    this->top = nullptr;
    this->length = 0;
    copy(rhs);
}


template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rhs) {
    if (this != &rhs) { clear(); copy(rhs); }
    return *this;
}


template <typename T>
int LinkedListStack<T>::getLength() const { return this->length; }

template <typename T>
bool LinkedListStack<T>::isEmpty() const { return this->length == 0; }


template <typename T>
T LinkedListStack<T>::peek() const {
    if (this->length == 0) throw string("peek: error, stack is empty, cannot access the top");
    return this->top->data;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    Node<T>* n = new Node<T>(elem);
    n->next = this->top;
    this->top = n;
    ++this->length;
}

template <typename T>
void LinkedListStack<T>::pop() {
    if (this->length == 0) throw string("pop: error, stack is empty, avoiding underflow");
    Node<T>* n = this->top;
    this->top = this->top->next;
    delete n;
    --this->length;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (this->top == nullptr || this->top->next == nullptr) return;

    if (dir == Stack<T>::RIGHT) {
        Node<T>* first = this->top;
        this->top = first->next;
        first->next = nullptr;

        Node<T>* tail = this->top;
        while (tail->next != nullptr) tail = tail->next;
        tail->next = first;
    } else {
        Node<T>* prev = nullptr;
        Node<T>* curr = this->top;
        while (curr->next != nullptr) { prev = curr; curr = curr->next; }
        prev->next = nullptr;
        curr->next = this->top;
        this->top = curr;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    } else {
        Node<T>* cur = this->top;
        while (cur != nullptr) { cout << cur->data << "\t"; cur = cur->next; }
        cout << "\n";
    }
}