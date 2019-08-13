#include "Subject.h"
#include "Observer.h"
#include "Guest.h"
#include <iostream>
#include <memory>
using std::unique_ptr;
using std::cout;
using std::endl;

int main() {
    unique_ptr<Observer> b1(new Baby("lele"));
    unique_ptr<Observer> b2(new Baby("suosuo"));
    unique_ptr<Observer> n1(new Nurse("meimei"));
    unique_ptr<Observer> n2(new Nurse("lili"));

    Ring ring;
    ring.attach(b1.get());
    ring.attach(b2.get());
    ring.attach(n1.get());
    ring.attach(n2.get());

    Guest guest("mark");
    guest.knock(ring);

    ring.detach(n1.get());
    cout << endl;
    guest.knock(ring);

    return 0;
}

