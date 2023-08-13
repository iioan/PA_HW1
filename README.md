
# Tema 1 Proiectarea Algoritmilor

### Teodorescu Ioan, 323CB

Arhiva consta in rezolvarea celor 4 probleme integral, avand un punctaj total de 110 puncte (fara README si coding style)

## Feribot

Pentru a calcula costul (greutatea) minim necesar al lui C (C fiind maximul dintre costurile celor K feriboturi), m-am 
gandit sa parcurg intervalul dintre cea mai grea masina (cazul in care avem un feribot pentru fiecare masina ⇒ C = 
maximul din vector) si suma greutatilor masinilor (daca avem un singur feribot ⇒ C = suma greutatilor masinilor). 
Pentru a parcurge eficient acest interval, am folosit algoritmul de cautare binara pentru a gasi costul minim. 
Pornind cu limita de jos (maximul din vector) si cu limita de sus (suma greutatilor masinilor), se calculeaza mijlocul 
intervalului, care reprezinta capacitatea limita a unui feribot.

Apoi se apeleaza FindMinCost, care calculeaza numarul de feriboturi, care au o capacitate limita (middle). Setam un 
contor (ferryboats) care il setam cu 1, intrucat urmeaza sa umplem primul feribot. Se ia cate o masina din vector si 
greutatea ei se aduna intr-o variabila weigth. Daca aceasta depaseste capacitatea maxima a feribotului, asta inseamna 
ca **deja** am umplut un feribot cu masini si vom folosi inca unul, punand masina curenta in ea. Functia returneaza 
numarul de feriboturi folosite, care urmeaza a fi comparate cu numarul dorit.

Daca numarul rezultat este mai mare decat K (numarul de feriboturi cerut de problema), inseamna ca fiecare feribot 
are o capacitate prea mica pentru a pune masinile in ordinea in care sunt in convoi. Astfel, limita inferioara se va marii.

Daca numarul rezultat este mai mic decat K, rezulta faptul ca fiecare feribot are o capacitate prea un C prea mare si 
trebuie minimizat. Asadar, limita superioara se va muta la mijlocul intervalului ([left, middle]). Algoritmul de cautare 
binara se executa pana cand cele doua limite ajung sa fiu egale, rezultant Costul minim cerut.

In opinia mea, complexitatea temporala este O(n * log SUM) (n - numar de masini; SUM = suma greutatilor masinilor).

- FindMax - O(n) - parcurg vectorul o data
- GetSum - O(n) - parcurg vectorul o data
- FindMinCost - O(n) - parcurg vectorul o data
- Cautarea binara - O(log SUM)

Functia FindMinCost este imbricata in cautare binara → O(n * log SUM)

Complexitatea spatiala a problemei este O(n) - folosesc vectorul de masini de dimensiune n si 6 variabile locale (left, 
right, middle, max, sum, etc.)

Resurse utile:

[https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-01](https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-01)

## Nostory

! Consider ca sortarea nu este o suita de mutari, intrucat ele nu implica interschimbarea a doua numere intre doua liste.

### Task 1

Sortez crescator lista A si descrescator lista B, astfel incat valorile mai miic din A sa pot fi schimbate cu valorile 
maxime din B (astfel, maximizam suma). Apoi, in structura repetitiva while (a[i] <= b[i]), interschimb numerele din listele
A si B. Intreschimbarile au loc pana cand un numarul curent din B ajunge sa fie mai mic decat cel din A. La final, A-ul 
va avea in lista elementele, care adunate, aduc suma maxima dorita. Se parcurge vectorul si se returneaza suma.

Consider ca, complexitatea temporala este, in medie (in functie de elementele din vectori), O(n * log n)

- sortarea - O(n * log n) - depinde
- Interschimbarea numerelor - O(n)
- Calcularea sumei - O(n)

Complexitatea spatiala este O(n^2) deoarece folosesc 2 vectori de lungime n.

### Task 2

Pentru acest task, voi folosi doi vectori aditionali: max si min. Ei sunt folositi in felul urmator:

Parcurg A si B, iar pentru fiecare pereche (a[i], b[i]) aflu maximul dintre ele. Daca maximul e egal cu a[i], atunci voi
adauga a[i] in max si b[i] in min. In caz negativ, voi proceda invers. Apoi restul implementarii este asemanator ca cel 
de la Task-ul 1, doar ca atunci cand interschimb numerele, o voi face doar in moves pasi. La final, A e vectorul cu suma
maxima dorita.

Complexitatea temporala = O(n * log n) (la fel ca task 1)

Completixatea spatiala = O(n^4) - mai am 2 vectori suplimentari!

## Sushi

Principala sursa de inspiratie a fost problema (recurenta) RUCSAC din cadrul **laboratorului 3 de programare dinamica**.
Aici, inloc de obiecte care trebuiesc puse in ghiozdan, avem platouri de sushi, fiecare avand un pret si nota totala 
(totalGrades / tg) (suma tutoror notelor date de cele N persoane pe platoul respectiv). Capacitatea este inlocuita cu 
bugetul total, astfel: dp[i][price] profitul maxim obținut folosind (doar o parte) din **primele i meniuri** și având 
un buget maxim **price**.

Avem cazul de baza: dp[0][budget] = 0 - nu alegem niciun meniu, avem profitul 0!

### Task 1

Aici intalnim cazul in care cumparat maxim un platou de fiecare tip de sushi.

Se parcurg toate meniurile (i) si toate valorile posibile ale bugetului (j), iar pentru fiecare meniu se verifica daca 
poate fi cumparat cu bugetul disponibil. Daca bugetul este mai mare sau egal cu pretul meniului, voi folosi meniul i. 
Asta inseamna ca trebuie sa folosesc p[i - 1] bani din bugetul total si ca inainte trebuia sa ocup maxim j (budget) - 
p[i - 1] bani. Se calculeaza profitul daca meniul maximineaza valoarea solutiei (maximul dintre *dp[i - 1][j]* sau 
*dp[i - 1][j - price] + tg[i - 1]*). Profitul este urmat de un castig de tg[i - 1] (deoarece luam DOAR un meniu din fiecare).

Daca nu avem bugetul de a cumpara meniul i, alegem cea mai buna solutie cu i - 1 meniuri si bugetul j. Rezultatul este 
aflat in ultimul element al matricei (dp[m][budget]).

### Task 2

Mai adaugam un platou la fiecare tip de sushi.

Intrucat acum comandam maxim 2 platouri pentru fiecare meniu, va trebuii sa dublam atat pretul, cat si nota totala. 
La fel ca la task-ul 1, parcurg toate meniurile si toate valorile posibile ale bugetului, si verific daca acesta (bugetul 
actual) este mai mare decat dublul pretului meniului i. Se face maximul intre cele trei optiuni întrucat se cauta solutia 
optima, adica cea care maximizeaza profitul. Daca se cumpara doua platouri din meniul i, se obtine un profit mai mare decat 
daca s-ar cumpara un singur platou, insa la dp[i - 1][j - price[i - 1]] e posibil sa existe un profit mai mare.

Daca bugetul actual e mai mic, se verifica daca acesta este mai mare decat pretul unui singur meniu. Aici, implementarea 
este asemanatoare cu cea de la task-ul 1.

### Task 3

Acum, trebuie sa punem si restrictie legata de numarul de meniuri cumparate. Am decis sa folosesc o matrice tridimensionala 
astfel incat: dp[i][price] profitul maxim obținut folosind (doar o parte) din **primele i meniuri,** având un buget maxim 
**price si cumparand n meniuri** (putem cumpara maxim doua meniuri din fiecare tip de sushi insa trebuie sa tinem cont ca 
trebuie sa cumparam maxim n meniuri in total). Se parcurg toate meniurile (i), toate valorile posibile ale bugetului (j) 
si toate valorile posibile ale numarului de meniuri cumparate (k). Implementarea este asemanatoare ca task-urile anterioare, 
insa a 3-a dimensiune a matricii asigura ca am cumparat N meniuri. Atunci cand gasim un meniu, am selectat primele i - 1 
meniuri, ne-am asigurat ca nu am cumparat mai mult decat j - priceX1/X2 si ca nu trebuie sa ocup mai mult de K - 1 (sau 2) 
meniuri cumparate.

Complexitatea temporala:

Task 1 = O(n * x * m)

Task 2 = O(n * x * m)

Task 3 = O(n^2 * x * m) - mai avem un for imbricat

Complexitatea spatiala:

Task 1 = O((m + 1) * (n * k + 1))

Task 2 = O((m + 1) * (n * k + 1))

Task 3 = O((m + 1) * (n * k + 1) * (n + 1))

## Semnale

### Task 1

Am pornit de la rezolvarea recursiva a problemei:

```cpp
int recursively(int x, int y, int prev) {
    if (x == 0 && y == 0) {
        return 1;
    }
    if (x < 0 || y < 0) {
        return 0;
    }
    int count = 0;
    if (prev == 0) {
        count += recursively(x - 1, y, 0);
        count += recursively(x, y - 1, 1);
    }
    if (prev == 1)
        count += recursively(x - 1, y, 0);
    return count;
}
```

Apelez prima data functia cu prev = 0. Daca atat x cat si y sunt egale cu 0, am gasit solutie. Daca unul dintre numere 
e negativ, nu este o solutie. Daca prev e egal cu 0, sunt 2 apeluri cand urmatoarea cifra e 0 sau 1. Iar pentru 1, 
apelam direct pentru 0, intrucat nu avem voie sa avem secvente de 2 de 1 consecutiv. Solutia rezolva cerinta temei, 
insa nu este eficient dpdv temporal.

Solutia din tema, foloseste programare dinamica, avand o matrice de dimensiune (x+1) * (y + 1),  astfel incat: dp[i][j] 
= numarul de semnale care indeplinesc conditia folosind ‘i’ de 0-uri si ‘j’ de 1.

Rezultatul curent se bazeaza pe rezultatele anterioare. Pentru inceput, setez coloana dp[i][0] cu 1, deoarece avem o 
singura solutie atunci cand avem ‘i’ de 0-uri si niciun 1. Apoi, parcurg matricea de la stanga la dreapta, se aduna numarul 
de semnale care contin `i-1` biti de 0 si `j` biti de 1 cu numarul de semnale care contin i-1 biti de 0 si j-1 biti de 1 
(dp[i - 1][j], dp[i - 1][j - 1]).

- dp[i - 1][j] trateaza cazul in care adaugam un bit de 0, care va ramane valida indiferent de ce bit a fost inainte.
- dp[i - 1][j - 1] trateaza cazul in care adaugam un bit de 1 la, asta fiind permisa doar atunci cand ultima cifra din
secventa nemodificata este 0 (nu avem permisiunea de a avea secvente de doi de 1).

La final, rezultatul dorit este suma dintre dp[x][y] si dp[x][y - 1]. Ideea sumei a pornit de la modul in care am calculat
numarele din matrice

### Task 2

Este aproximativ aceeasi implementare, insa de data asta nu este permis sa avem secvente de 3 de 1 consecutivi (deci sunt 
permise cele cu doi de 1).

Initializarea si parcurgerea matricei sunt la fel ca la task-ul 1. Pentru fiecare dp[i][j], fac suma dintre dp[i - 1][j - 1] 
si dp[i -1][j]. In plus, se verifica daca j≥2 (daca exista cel putin doi biti de 1), caz in care se va adauga valoarea 
dp[i - 1][j - 2], pentru a adauga inca un 1 la semnalele care folosesc i - 1 0-uri si j - 2 de 1 (este permis sa avem
secvente cu doi de 1 pozitionati unul langa altul).

La final, rezultatul dorit este suma dintre dp[x][y] si dp[x][y - 1] si dp[x][y - 2].

Complexitatea temporala:

Task 1 = O(x * y)

Task 2 = O(x * y)

Complexitatea spatiala

Task 1 = O((x + 1) * (y + 1))

Task 2 = O((x + 1) * (y + 1))