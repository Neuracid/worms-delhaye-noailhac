

#include "CommandeService.hpp"

CommandeService::CommandeService (CommandeDB& commandeDB) : AbstractService("/Commande"),
    commandeDB(commandeDB) {

}

HttpStatus CommandeService::get (Json::Value& out, int id) const {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus CommandeService::post (const Json::Value& in, int id) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus CommandeService::put (Json::Value& out,const Json::Value& in) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus CommandeService::remove (int id) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}
