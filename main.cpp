#include "DocumentManager.h"

int main() {
  DocumentManager libraryManager;
  libraryManager.addDocument("Book1", 1, 2);  
  libraryManager.addDocument("Book2", 2,1);  
  libraryManager.addPatron(1);
  libraryManager.addPatron(2);   

  assert(libraryManager.search("Book1") == 1);    
  assert(libraryManager.search("Book2") == 2);  

  assert(libraryManager.borrowDocument(1, 1) ==  true); 
  assert(libraryManager.borrowDocument(1, 2) ==  true); 
  assert(libraryManager.borrowDocument(2, 1) ==  true); 
  assert(libraryManager.borrowDocument(2, 2) ==  false);  
              
  assert(libraryManager.borrowDocument(1, 3) == false); 

  libraryManager.returnDocument(2, 1);
  assert(libraryManager.borrowDocument(2, 2) == true); 
}