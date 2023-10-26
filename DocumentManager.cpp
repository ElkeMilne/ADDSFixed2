#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {

nametoid[name] = id;

idtopatrons[id] = {license_limit, unordered_set<int>()};
}

void DocumentManager::addPatron(int patronID) {
  patrons.insert(patronID);
}

int DocumentManager::search(string name) {
  return nametoid[name];
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
  if (patrons.find(patronID) == patrons.end() || 
      idtopatrons.find(docid) ==
          idtopatrons.end() || 
      idtopatrons[docid].second.size() ==
          idtopatrons[docid].first) { 
    return false;
  }
  idtopatrons[docid].second.insert(patronID);
  return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
  if (idtopatrons.find(docid) != idtopatrons.end()) {
    idtopatrons[docid].second.erase(patronID);
  }
}
