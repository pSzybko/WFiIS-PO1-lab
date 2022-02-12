#include <iostream>
#include <utility>

#include "include/FancyText.h"

int main(){
    FancyText m("PO1");
    m += " is";
    m += " my";
    m += " _favourite_";
    m += " subject!";

    std::cout << "size " << m.size() << " " << m.fragments() <<  " " << m << std::endl;

    FancyText mm(std::move(m));
    
    std::cout << "m (after move) size " << m.size() <<  " " << m << std::endl;
    std::cout << "mm size " << mm.size() << " " << mm.fragments() <<  " " << mm << std::endl;

    FancyText n("Again. ");
    n += std::move(mm);
    std::cout << "n: " << n << std::endl;

    FancyText k;
    k = std::move(n);
    std::cout << "n (after move): " << n << std::endl;
    std::cout << "k: " << k << std::endl;
    const FancyText kk(std::move(k));
    std::cout << "kk: " << kk.fragments() << std::endl;
    std::cout << kk.fragment(4).str() << std::endl;
}

/* //Output:
size 30 5 PO1 is my _favourite_ subject!
m (after move) size 0 
mm size 30 5 PO1 is my _favourite_ subject!
n: Again. PO1 is my _favourite_ subject!
n (after move): 
k: Again. PO1 is my _favourite_ subject!
kk: 6
 _favourite_
*/
