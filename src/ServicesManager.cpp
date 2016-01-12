
#include "ServicesManager.hpp"

using namespace std;

void ServicesManager::registerService (unique_ptr<AbstractService> service) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

AbstractService* ServicesManager::findService (const string& url) const {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus ServicesManager::queryService (string& out, const string& in, const string& url, const string& method) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}
