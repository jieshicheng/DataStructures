基于数组的线性表

arrayList<type>

construct function:
    arrayList<type>(size);
    arrayList<type>(size, value);
    arrayList<type>();
    arrayList<type>(const arrayList<type> &arr)
    arrayList<type>(arrayList<type> &&arr)


member function:
    bool empty();
    size_t size();
    type &at(size_t index);
    iterator begin()
    const iterator cbegin();
    iterator end();
    const iterator cend();

erase function:
    iterator erase(iterator pos);
    iterator erase(iterator begin, iterator end);
    void pop_back()

insert function:
    iterator insert(iterator pos, value);
    iterator insert(iterator pos, size_t count, value);
    void push_back(value);

assigned operator:
    = (const arrayList<int> &);
    = (arrayList<int> &&);

access operator:
    [](size_t index);

compare operator:
    ==
    !=
    <
    >
    <=
    >=
