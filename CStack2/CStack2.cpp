#include <iostream>

template <typename T>
struct Node
{
    T info;
    Node* next;

    Node() : info(T()), next(nullptr) {} // Добавляем конструктор по умолчанию
};

template <typename T>
class CStack
{
private:
    Node<T>* top;

public:
    CStack() : top(nullptr) {}

    ~CStack()
    {
        clear();
    }

    void push(T value)
    {
        Node<T>* newNode = new Node<T>(); // Используем конструктор по умолчанию
        newNode->info = value;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top)
        {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void clear()
    {
        while (top)
        {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void operator*=(T factor)
    {
        Node<T>* current = top;
        while (current)
        {
            current->info *= factor;
            current = current->next;
        }
    }

    CStack& operator=(const CStack& other)
    {
        if (this == &other)
        {
            return *this;
        }
        clear();
        Node<T>* current = other.top;
        while (current)
        {
            push(current->info);
            current = current->next;
        }
        return *this;
    }

    T operator[](T index) const
    {
        Node<T>* current = top;
        int i = 0;
        while (current && i < index)
        {
            current = current->next;
            i++;
        }
        if (current)
        {
            return current->info;
        }
        return T(); // Возвращаем значение по умолчанию для типа T
    }
};

template <typename T>
bool operator<(const Node<T>& left, const Node<T>& right)
{
    return left.info < right.info;
}

template <typename T>
int main()
{
    CStack<T> c, c1;
    c.push(1);
    c.push(2);
    c.push(3);
    c1 = c;

    std::cout << "Elements in c1: ";
    for (int i = 0; i < 3; i++)
    {
        std::cout << c1[i] << " ";
    }
    std::cout << std::endl;

    c *= 3;
    std::cout << "Elements in c after *3: ";
    for (int i = 0; i < 3; i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    Node<T> n, n1;
    n.info = 1;
    n1.info = 2;
    if (n1 < n)
        std::cout << "Congratulations!" << std::endl;
    else
        std::cout << "Commiserations!" << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
