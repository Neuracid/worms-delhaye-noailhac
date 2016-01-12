

#include "VersionService.hpp"

VersionService::VersionService () : AbstractService("/version") {

}

HttpStatus VersionService::get (Json::Value& jsonOut, int id) const {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}
