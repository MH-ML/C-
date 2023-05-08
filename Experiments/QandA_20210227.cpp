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

//----------------------------------


//Test if derived class:
template <class A, class B>
bool IsDerived{
    return Helper<A,B>::Is;
}

template <typename T, typename T>
class Helper{
    class No{};
    class Yes{No no[3];};
    
    static Yes Test{B*};
    static No Test{...};
    
    public:
        enum { Is = sizeof(Test(static_cast<T*>(0))) == sizeof(Yes)};
    
}