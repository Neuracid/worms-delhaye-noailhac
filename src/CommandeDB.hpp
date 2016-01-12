

#ifndef __CommandeDB_hpp__
#define __CommandeDB_hpp__

#include <memory>
#include <map>

using std::unique_ptr;
using std::map;

#include "Commande.hpp"
#include "CommandeDB.h"

template<class T,typename ... Args>
std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}

#endif
