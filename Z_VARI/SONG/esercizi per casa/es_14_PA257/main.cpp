#include <iostream>
#include <string>

int Occorrenze(std::string stringa, char carattere){
    int cont  = 0;
    if(stringa.empty()) return 0;
    if(stringa[0] == carattere) cont++;
    return cont + Occorrenze(stringa.substr(1),carattere);
}
int main(){
    std::string s;
    char c;
    std::cin >> s;
    std::cin >> c;
    int x = 0;
    x = Occorrenze(s, c);
    std::cout << "Nella stringa " << s <<  " ci sono " << x << " occorrenze di " << c << std::endl;
}