//Template beider Klassen
template <class A, class B>
//versuche, IsSame<A,B> aufzurufen
//je nachdem, welcher struct aufgerufen wird, gibt es ein anderes Ergebnis
//wenn nämlich die Klasse DIESELBE ist, dann wird IsSame(){} aufgerufen, 
//andernfalls IsSame<A,B>
bool IsSameClass(){
    return IsSame<A,B>::value;
}

//benutze template mit 2 verschiedenen Datentypen:
template <typename T, typename U>
//dann weiß ich, dass sie NICHT gleich sind
//ich brauche hier keine PArameter spezifizieren, weil es in dem Beispiel nur
//2 Fälle gibt
struct IsSame(){
    static const bool value = false;
}

template <typename T>
struct IsSame<T,T>{
    static const bool value = true;
}