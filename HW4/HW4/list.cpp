//void listAll(string path, const Class* c)  // two-parameter overload
//{
//    if (c == nullptr)
//        return;
//    if (path == "") {
//        cout << c->name() << endl;
//    }
//    else if (c->subclasses().size() == 0) {
//        cout << path << endl;
//        return;
//    }
//
//    for (int i = 0; i < c->subclasses().size(); i++) {
//        if (path == "") { //root
//            listAll(c->name() + "=>" + c->subclasses()[i]->name(), c->subclasses()[i]);
//        }
//        else { // not root
//            listAll(path + "=>" + c->subclasses()[i]->name(), c->subclasses()[i]);
//        }
//    }
//}
