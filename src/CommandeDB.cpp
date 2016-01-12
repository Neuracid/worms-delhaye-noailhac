
#include "CommandeDB.hpp"

CommandeDB::CommandeDB() : idseq(1) {

}

const Commande* CommandeDB::getCommande (int id) const {
    auto ite = Commande.find(id);
    if (ite == Commande.cend())
        return nullptr;
    return ite->second.get();
}

int CommandeDB::addCommande (unique_ptr<Commande> Commande) {
    int id = idseq++;
    Commande.insert(std::make_pair(id,std::move(Commande)));
    return id;
}

void CommandeDB::setCommande (int id, unique_ptr<Commande> Commande) {
    Commande[id] = std::move(Commande);
    if (id > idseq) {
        idseq = id;
    }
}

void CommandeDB::removeCommande (int id) {
    auto ite = Commande.find(id);
    if (ite == Commande.end())
        return;
    Commande.erase(ite);
}
