#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <bits/stdc++.h>

using namespace std;

class DocumentManager {
 private:
  unordered_map<string, int> nametoid;  
  unordered_set<int> patrons; 
  unordered_map<int, pair<int, unordered_set<int>>>
      idtopatrons; 

 public:
  void addDocument(string name, int id, int license_limit);
  void addPatron(int patronID);
  int search(string name); 
  bool borrowDocument(int docid,int patronID); 
  void returnDocument(int docid, int patronID);
};

#endif
