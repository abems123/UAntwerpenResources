#include <iostream>
#include <memory>

class Foo {};

int main(int argc, char *argv[]) {
  std::shared_ptr<Foo> sp1(
      new Foo); // make a new shared_ptr, reference count is now at 1
  std::cout << sp1.use_count() << std::endl; // check the reference count
  std::shared_ptr<Foo> sp2 =
      sp1; // copy constructor, reference count increases again by 1
  std::cout << sp1.use_count() << std::endl; // check the reference count
  // sp2->printFoo();                              // you can call a member
  // function like a built-in pointer

  // std::cout << *sp1 << std::endl;               // you can dereference it a
  // like a built-in pointer

  std::cout << &(*sp1) << std::endl; // ask for its address
  std::cout << &(*sp2) << std::endl; // ask for its address
  // the addresses should match up

  std::shared_ptr<Foo> sp3 = sp2;
  sp2 = nullptr;                             // decreases the reference count
  std::cout << sp3.use_count() << std::endl; // check the reference count
  sp1.reset();                               // decreases the reference count
  std::cout << sp3.use_count() << std::endl; // check the reference count
                                             //
  // Custom deleter
  auto loggingDeleter =
      [](Foo *f) {
        std::cout << "Deleting a Foo object.." << std::endl;

        delete f;
      }

  std::shared_ptr<Foo>
      fooInstance(new Foo, loggingDeleter);

  return 0;
}
