#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
  nametoiden[name] = id;
  idtopatron[id] = {license_limit, unordered_set<int>()};
}

void DocumentManager::addPatron(int patronID) {
  patrons.insert(patronID);
}

int DocumentManager::search(string name) {
  return nametoiden[name];
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
  if (patrons.find(patronID) == patrons.end() || idtopatron.find(docid) == idtopatron.end() || idtopatron[docid].second.size() ==idtopatron[docid].first) { 
    return false;
  }
  idtopatron[docid].second.insert(patronID);
  return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
  if (idtopatron.find(docid) != idtopatron.end()) {
    idtopatron[docid].second.erase(patronID);
  }
}
