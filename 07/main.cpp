#include "include/Dir.h"
#include "include/File.h"


int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  *home += new Dir("rafal");
  *home += new File("proj.descr");
  *home += new File("proj.files.repo");
  *home += new Dir("adam");
  
  std::cout << (const Dir&)*top << std::endl;

  top->findDir("rafal")->add( new Dir("Desk") );

  Dir* rafal = home->findDir("rafal");  
  *rafal += new File("foto1.jpg");
  *rafal += new File("foto2.jpg");
  *rafal += new File("foto3.jpg");
  top->findDir("rafal")->add( new Dir("work") );


  std::cout << *top;
  std::cout << "--------------" << std::endl;
  std::cout << *(rafal->get("work"));
  std::cout << *(top->get("proj.descr"));

  delete top;
}

/* //OUTPUT 
. (DIR)
  home (DIR)
    rafal (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)

. (DIR)
  home (DIR)
    rafal (DIR)
      Desk (DIR)
      foto1.jpg (FILE)
      foto2.jpg (FILE)
      foto3.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)
--------------
work (DIR)
proj.descr (FILE)
Deleting Dir: .
About to delete home
Deleting Dir: home
About to delete rafal
Deleting Dir: rafal
About to delete Desk
Deleting Dir: Desk
About to delete foto1.jpg
About to delete foto2.jpg
About to delete foto3.jpg
About to delete work
Deleting Dir: work
About to delete proj.descr
About to delete proj.files.repo
About to delete adam
Deleting Dir: adam
 */
