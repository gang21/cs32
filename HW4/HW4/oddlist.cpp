void removeOdd(list<int>& li) {
    if (li.empty())
        return;
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++) {
        if ((*it%2) == 1)
            li.erase(it);
    }
}
