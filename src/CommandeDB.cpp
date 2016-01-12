
#include "CommandeDB.hpp"

CommandeDB::CommandeDB() : idseq(1) {

}

const Commande* CommandeDB::getCommande (int id) const {
    auto ite = commandes.find(id);
    if (ite == commandes.cend())
        return nullptr;
    return ite->second.get();
}

int CommandeDB::addCommande (unique_ptr<Commande> commande) {
    int id = idseq++;
    commandes.insert(std::make_pair(id,std::move(commande)));
    return id;
}

void CommandeDB::setCommande (int id, unique_ptr<Commande> commande) {
    commandes[id] = std::move(commande);
    if (id > idseq) {
        idseq = id;
    }
}

void CommandeDB::removeCommande (int id) {
    auto ite = commandes.find(id);
    if (ite == commandes.end())
        return;
    commandes.erase(ite);
}
