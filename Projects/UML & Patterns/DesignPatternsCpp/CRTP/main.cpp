#include <iostream>
using namespace std;

/*
  Мханизм CRTP (Curiously recurring template pattern). Идея проста: применить не виртуальное наследование
  и обеспечить полиморфное поведение с помощью явного приведения типа наследника к типу родителя.
 */

template<typename Filtrator> class FiltratorImpl {
inline void find_message(...) {
   FiltratorImpl()
   {
         /*
          В конструктор родителя можно добавить подобный асерт, чтобы избежать ошибок:
          */
        static_assert(std::is_member_function_pointer<decltype(&Filtrator::find_and_read_message)>::value)
   }

   Filtrator* filtrator = static_cast<Filtrator* >(this);
   …
   filtrator->find_and_read_message(info, collection);
}
};
...
class CIFSFiltrator : public FiltratorImpl<CIFSFiltrator> {
...
inline void find_and_read_message(PacketInfo& info) {...}
...
};
class RPCFiltrator : public FiltratorImpl<RPCFiltrator> {
...
inline void find_and_read_message(PacketInfo& info) {...}
...
};




int main () {

   return 0;
};
