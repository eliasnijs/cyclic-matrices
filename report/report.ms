.RP
.TL
Over circulante matrices en hun implementatie in code
.AU
Elias Nijs
.AI
Universiteit Gent
.DA
.2C
.R1
accumulate
database bib.ref
move-punctuation
.R2
.EQ
delim $$
.EN
.NH
Introductie
.LP
Bij het numeriek modelleren van sommige praktische problmen verschijnen al eens speciale matrices. 
Een zo een type speciale matrix noemen we de cyclische of circulante matrix. 
In dit verslag worden enkele eigenschappen van deze bijzonder matrices, 
hun implementatie in code en 2 toepassing bekeken.
Voor we hier echter mee verdergaan is het toch nog even belangrijk om de definitie 
van een circulante matrix te bekijken.

Om een definitie voor een circulante matrix op te stellen, definieren we eerst een shift operator 
$T : A sup {n} -> A sup {n}$ door 
$T(v sub {0}, v sub {1}, ..., v sub{n-1}) = T(v sub {n-1}, v sub {0}, ..., v sub{n-2})$.
Een circulante matrix $A = circulant(v)$ voor de vector $v \[mo] A sup n$ is nu de $n * n$ matrix 
waarvoor de rijen bepaald zijn door de iteraties van de shift operator. We krijgen dan het volgende:
.EQ
A =
left [ 
matrix {
ccol {
  v sub {0} above v sub {n-1} above v sub {n-2} above ... above v sub {1}
}
ccol {
  v sub {1} above v sub {0} above  v sub {n-1} above ... above v sub {2}
}
ccol {
  v sub {2} above v sub {1} above  v sub {0} above ... above v sub {2}
}
ccol {
  ... above ... above ... above ... above ...
}
ccol {
  v sub {n-1} above v sub {n-2} above v sub {n-3} above ... above v sub {0}
}
}
right ]
.EN
.NH
Stellingen omtrent ciculante matrices
.LP
.I "(Opdracht 1)"
.NH 2
Stelling
.LP 
De som $A + B$ van twee cyclische matrices is een cyclische matrix.
.LP
.B "Bewijs:"
.LP
Stel $A$ en $B$ circulante $n*n$ matrices en $C = A + B$. We kunnen $A$ en $B$, gebruik makend van de voordien
gedefinieerde shift operator, definieren als 
$A sub k = T sup {k-1}v sub {A}$ en $B sub k = T sup {k-1}v sub {B}$ met $k$ de rij index gelijk aan $1, ..., n$.

C kunnen we nu herschrijven als 
$C sub k = (T sup {k-1}v sub {A}) + (T sup {k-1}v sub {B})$.
Dit is op zijn beurt gelijk aan 
$C = T sup {k-1}(v sub {A} + v sub {B})$.
Als we nu $v sub c$ gelijk stellen aan $v sub {A} + v sub {B}$, krijgen we
$C = T sup {k-1}v sub {c}$. Dit is gelijk aan onze defintie voor een circulante matrix.
$QED$

Een andere manier om dit te bewijzen is om $A$ en $B$ als 
polynomiaal in $P$ te beschouwen. (Dit wordt uitgelegd in het volgende
bewijs). Een polynomiaal in $P$ plus een polynomiaal in $P$ zal terug een polynomiaal
in $P$ zijn. $C$ is dus een polynomiaal in $P$ en dus circulant.

.NH 2
Stelling
.LP 
Het product $A * B$ van twee cyclische matrices is een cyclische matrix.
.LP
.B "Bewijs:"
.LP
Stel $A$ en $B$ circulante $n*n$ matrices en $C = A * B$.
Om dit te bewijzen moeten we eerst inzien dat we een circulante matrix kunnen schrijven als een polynomiaal.
We kunnen dit doen aan de hand van een matrix P die als volgt gedefinieerd is:
.EQ
P =
left [ 
matrix {
ccol {
 0  above 0  above ...  above 0 above 1
}
ccol {
 1  above 0  above ...  above 0 above 0
}
ccol {
 0  above 1  above ...  above 0 above 0
}
ccol {
 ...  above ...  above ...  above ... above ...
}
ccol {
 0  above 0  above ...  above 1 above 0
}
}
right ]
.EN
$P sup k$ zal fungeren als een soort van shift operator. Belangrijk om hierbij op te merken is dat 
$P sup n = I$, met $I$ gelijk aan de identiteits matrix.
Gebruik makend van deze kunnen we nu $A$ en $B$ schrijven als:
.LP
$A = a sub {0}I + a sub {1}P + a sub {2}P sup {2} + ... +a sub {n-1}P sup {n-1}$
.LP
$B = b sub {0}I + b sub {1}P + b sub {2}P sup {2} + ... +b sub {n-1}P sup {n-1}$
.LP
We hebben dus polynomialen in $P$. Indien we deze 2 nu vermenigvulgien krijgen we dus terug 
een polynomiaal in $P$. C is dus een polynomiaal in P, en dus is C ook een circulante matrix.$QED$
.NH 2
Stelling
.LP 
De inverse van een cyclische matrix $A sup {-1}$ is een cyclische matrix.
.LP
.B "Bewijs:"
.LP
Dit kunnen we bewijzen door de matrix A te beschouwen als een polynomiaal in P (deze werd in het vorige bewijs al gedefinieerd en verklaard). We hebben dan:
.LP
$A = a sub {0}I + a sub {1}P + a sub {2}P sup {2} + ... +a sub {n-1}P sup {n-1}$
.LP
Cayley-Hamilton zegt echter dat $A sup {-1}$ een polynomiaal is in $A$, en dus is $A sup {-1}$ 
ook een polynomiaal in P. Het inverse van A is dus ook cyclisch. $QED$
.NH
Circulante matrices in code
.NH 2
Keuze van taal
.LP
Voor de implementatie van deze matrices werd er beslist om ze te schrijven in c/c++. Het programma volgt zo goed als volledig c stijl en maakt dus geen gebruik van klasses of andere meer geavanceerde c++ functionaliteiten. Sommige functionaliteiten die c++ toevoegt zijn echter wel nuttig. In dit geval heeft dit vooral betrekking tot zaken zoals operator overloading.
.LP
Er werd voor c/c++ gekozen omdat deze taal efficient is en ons toegang geeft tot het memory. Dit geeft ons meer mogelijkheden voor optimalisatie, wat belangrijk is voor een wiskundig programma.
.NH 2
Correctheid
.LP
Om te illustreren dat de geschreven code de juiste resultaten weergeeft, werd er een test systeem geschreven. Dit systeem zal alle testen in de file
.CW "tests.cpp"
uitvoeren en de correctheid ervan checken. Op deze manier kan men dus gemakkelijk na gaan of de code wel degelijk juist is. 
.NH 2
Complexe getallen en vectoren
.LP
.I "(Opdracht 2)"
.LP
Voordat we cyclische matrices kunnen implementeren hebben we enkele andere wiskundige constructies nodig. Deze zijn complexe getallen en vectoren.

De implementatie van complexe getallen kan men terug vinden in de bestanden 
.CW "math/complex_number.h"
en
.CW "math/complex_number.cpp". 
Een complex getal is intern opgeslaan in een struct met 2 waarden, de reeele waarde en de complexe waarde. Beide zijn een floating point number bestaande uit 64 bits voor optimale accuraatheid. Verder werden alle volgende operatoren gedefinieerd: $+, -, *, /, ==, !=$.

Vectoren werden geimplementeerd als een struct met 2 velden, een veld die de lengte van de vector bijhoudt en een veld die een pointer bijhoudt naar een reeks copmlexe getallen in memory. Er werd beslist om de vectoren in lengte constant te houden. Vectoren ondersteunen alle basis operaties: optellen, aftrekken, schalen, lengte opvragen, element opvragen, ... De implementatie hiervan kan men terugvinden in de bestanden
.CW "math/vector.h"
en
.CW "math/vector.cpp". 

Nu dat we deze 2 constructies hebben, kunnen we aan het interessante werk, de matrices, beginnen.
.NH 2
Implementatie van cyclische matrices
.LP
.I "(Opdracht 3)"
.LP
De implementatie van cyclische matrices werd gedaan aan de hand van een struct die een vector bijhoudt. 
Om een cyclische matrix te definieren is er immers maar 1 vector nodig. Zo moeten we dus maar $n$ elementen bijhouden 
in plaats van $n*n$ elementen.

Volgende operatoren werden gedefinieerd voor deze matrices: get element, optellen, aftrekken, 2 cyclische matrices 
vermenigvuldigen en een cylische matrix met een vector vermenigvuldigen.
De code voor cyclische matrices kan worden teruggevonden in de files 
.CW "math/matrix_cyclic.h"
en
.CW "math/matrix_cyclic.cpp"

Elk van deze operatoren wordt nu kort besproken.
.NH 3 
Get element van een cyclische matrix
.LP
Deze operator neemt 2 indices, i en j, en geeft de waarde op deze plaats in de matrix terug. Dit gebeurt op volgende manier.
Stel een vector $v$ van lengte $n$ en een cyclische matrix $A = circ(a)$, dan geldt het volgende:
.EQ
A sub {i,j} = v sub {(n + j - i) % n}
.EN
In code vormt dit:
.DS L
.ft C
return a[(n+j-i)%n]
.DE
.NH 3 
Cylische matrices optellen en aftrekken
.LP
Het optellen of aftrekken van 2 cyclische matrices $A$ en $B$ verloopt heel eenvoudig.
We kunnen immers gewoon de 2 vectoren van de meegegeven matrices optellen/aftrekken en 
een cycliche matrix teruggeven met het resultaat hiervan als vector.
.NH 3 
Cyclische matrices vermenigvuldigen
.LP
Voor het vermenigvuldigen van matrices wordt gebruik gemaakt van wat soms indices-magie genoemd wordt.
Het algoritme neemt 2 cyclische matrices $A$ en $B$, gebasseerd op vectoren $a$ en $b$, van lengte n, en gaat als volgt:

.B1
.DS L
.ft C
r = nul-vector van lengte $n$
while i1 < n do
  while i2 < n do
    r[i1] = r[i1] + 
      a[(-i2+n)%n]*b[(i2+i1)%n]
    i1, i2 += 1
return cyclic_matrix(r)
.DE
.B2
.NH 3 
Cylische matrices met een vector vermenigvuldigen 
.LP
Het vermenigvuldigen van een cyclische matrix met een vector wordt ook gerealiseerd door met indices te spelen.
De functie neemt 2 argumenten, een cylische matrix A gebasseerd op vector a, en een vector v, beide van lengte n.

.B1
.DS L
.ft C
r = nul-vector van lengte $n$
while i1 < n do
  while i2 < n do
    r[i1] = r[i1] + 
      a[(n+i2-i1)%n]*b[i2]
    i1, i2 += 1
return r
.DE
.B2
.NH 1
Eigenwaarden en Eigenvectoren van circulante matrices
.LP
De $n$ eigenwaarden $lambda sub j$ en genormeerde eigenvectoren $v sub j$ van een 
cyclische $n * n$ matrix $A$ worden gegeven door:
.EQ
lambda sub j = sum from {k = 0} to {n-1} {a sub {k} omega sup {kj}}
.EN
.EQ
v sub j = {1 over {sqrt n}}(1, omega sup {j}, omega sup {2j}, ..., omega sup {(n-1)j} ) sup T
.EN
.LP
met j = 0, 1, ..., n-1. Hierbij is $(a sub {0}, a sub {1}, ..., a sub {n-1})$ de vector die $A$ bepaald en $omega = exp({2 pi i over n})$
.NH 2
Narekening van de formules voor eigenwaarden en eigenvectoren
.LP
.I "(Opdracht 4)"
.LP
Om dit aan te tonen bekijken we $A$ terug als een polynomiaal in $P$. We merken dan op dat we de eigenwaarden van P moeten zoeken. We doen dit als volgt:
.EQ
P - lambda I = 
left [ 
matrix {
ccol {
 - lambda  above 0  above ...  above 0 above 1
}
ccol {
 1  above - lambda  above ...  above 0 above 0
}
ccol {
 0  above 1  above  - lambda  above 0 above 0
}
ccol {
 ...  above ...  above ...  above ... above ...
}
ccol {
 0  above 0  above ...  above 1 above - lambda
}
}
right ]
.EN
.EQ
det(P - lambda I) = lambda sup {n} - 1 = 0
.EN
.EQ
lambda sup {n} = 1
.EN
.LP
We hebben dus n oplossingen.
Deze oplossingen worden gegeven door:
.EQ
omega sup {0}, omega sup {1}, ..., omega sup {n-1}
.EN
met
.EQ
omega = exp({2 pi i over n})
.EN
Op dit moment hebben we dus de eigenwaardes van P gevonden.
Maar wat zijn de eigenvectors?
.LP
We stellen een eigenvector matrix op:
.EQ
left [ 
matrix {
ccol {
 1  above 1  above 1  above ... above 1
}
ccol {
 1  above {omega sup 1}  above {omega sup 2}  above ... above {omega sup (n-1)}
}
ccol {
 1  above {omega sup 2}  above {omega sup 4}  above ... above {omega sup 2(n-1)}
}
ccol {
 ...  above ...  above ...  above ... above ...
}
ccol {
 1  above {omega sup {(n-1)}}  above {omega sup {2(n-1)}}  above ... above {omega sup (n-1)(n-1)}
}
}
right ] = F sub n
.EN
Dit is de Fourier matrix.
Indien we dit nu normeren komen we aan onze eerder gedefinieerde genormeerde eigenvectoren.
.EQ
v sub j = {1 over {sqrt n}}(1, omega sup {j}, omega sup {2j}, ..., omega sup {(n-1)j} ) sup T
.EN
Om nu onze eigen waardes te vinden moeten we gewoon onze vector die A definieert maal alle eigenvectors doen. We bekomen dan ook het andere voordien gedefinieerde.
.EQ
lambda sub j = sum from {k = 0} to {n-1} {a sub {k} omega sup {kj}}
.EN
.LP
Het kennen van deze eigenwaarden en eigenvectoren laat ons nu toe om leuke algoritmen te bedenken en implementeren.
.NH 2
Algoritme voor het bepalen van de m'de macht van een cylische n * n matrix. 
.LP
.I "(Opdracht 5)"
.LP
Stel circulant matrix $A$ van lengte $n$, en we willen deze tot de $m$'de macht verheffen. Hoe kunnen we dit 
efficient doen?
.NH 3
Wiskundige uitwerking
.LP
We vertrekken als volgt, gebruik makend van een eigenschap van diagonaliseerbare matrices, 
circulante matrices zijn immers diagonaliseerbare matrices:
.EQ
A sup n = (PDP sup {-1}) = (PDP sup {-1})(PDP sup {-1})...(PDP sup {-1}) 
.EN
We merken op dat we nu telkens $P sup {-1} * P$ kunnen schrappen. Dan bekomen we:
.EQ
A sup n = PD sup {n}P sup {-1}
.EN
De vraag die nu tevoorschijn komt is: wat zijn $P$ en $D$? Of in andere woorden hoe kunnen we 
circulante matrices diagonaliseren? Dit gebeurt als volgt:
.EQ
D = U sub {n} sup {*} A U sub {n}
.EN
waarbij $U$ gelijk is aan de matrix samengesteld uit de eigenvectoren van $A$. 
Als we nu terugkijken zien we ook dat:
.EQ
P = U sub {n}
.EN
(We kunnen dit gebruiken zonder efficientie te verliezen doordat de inverse van $U sub n$ makkelijk te berekenen is.)

Op dit moment hebben we dus een wiskundige weg naar de $m$'de macht van $A$.

Hoe zal dit zich nu vertalen in code?
.NH 3
Vertaling naar code
.LP
Het eerste dat we moeten maken, is het verheffen van een complex getal tot de m'de macht. Om dit 
efficient te doen zetten we de $(a + ib)$ vorm om naar het volgende $re sup {i theta}$. 
We bekomen deze vorm op volgende manier:
.EQ
r = sqrt{a sup {2} + b sup {2}}
.EN
.EQ
theta = tan sup -1 (b/a)
.EN
Deze vorm kunnen we dan makkelijk tot de m'de verheffen.
.EQ
r sup m e sup {i theta m}
.EN
Dit kunnen we dan daarna volgens Euler's formule terug makkelijk omzetten naar de
vorm van $a + bi$.
.EQ
a + bi = r sup m (cos( theta m ) + sin( theta m )i)
.EN

In code vertaalt zich dit als volgt:

.B1
.DS L
.ft C
complex_number
ComplexNumberIntPower
(complex_number A, int32 m)
{
real64 Rm = 
  pow((sqrt(pow(A.Real, 2) + 
  pow(A.Imaginary, 2))), m);
real64 Om = 
  (atan(A.Imaginary / A.Real
    ) * m);
complex_number Result = {
    Rm * cos(Om), Rm * sin(Om)};
return(Result);
}
.DE
.B2
Dit heeft comlexiteit $O(1)$.

Het volgende dat we nodig hebben is de matrix van eigenvectoren $U sub n$. We moeten deze niet in memory bijhouden maar kunnen gewoon een FourierMatrixGetElement functie maken die lengte n en index i, j als argumenten neemt.

.B1
.DS L
.ft C
complex_number
FourierMatrixElement
(uint32 n, uint32 i, uint32 j) 
{
real64 theta = 
  ((2 * Pi64 * i * j) / n);
complex_number Result = 
  {cos(theta), sin(theta)};
return(Result);
}
.DE
.B2

Nu we over deze matrix beschikken, kunnen we de diagonaal matrix van $A$ opstellen. Merk op dat we 
het element op plaats i,j van de inverse van F kunnen halen door het complex toegevoegde van 
FourierMatrixGetElement(j, i) te nemen.
Dit gebeurt simpel door de matrices zonder speciale methode te vermenigvuldigen.

Nu we deze functies hebben, kunnen we aan de hand van simpele for loops
de diagonaal matrix bepalen en deze daarna tot de m'de macht verheffen.
Nadien vormen we deze diagonaal matrix simpel terug naar een 
cyclische matrix met forloops.

De complexiteit van het geimplementeerde algoritme is $O(n sup {3})$. 
Een optimale implementatie kan echter $O(n sup 2 )$ bereiken door
de for loops minder omslachtig te maken.

De complexiteit hier is onafhankelijk van de macht.

De code hieroor is terug te vinden in de files 
.CW "math/matrix_cyclic.cpp" 
en
.CW "math/matrix_cyclic.h" 
.NH 3
Alternatieve vertaling naar code
.LP
Een alternatieve methode om dit algoritme in te vullen is door gewoon de normale matrix vermenigvuldiging op 
te roepen. In dat geval zouden we complexiteit $O(mn sup {2})$ hebben. 
Deze is echter afhankelijk van m, en
dus minder goed.
.NH 2
Algoritme voor het bepalen van x, gegeven cylische matrix A en n-dimensionale vector b, 
in de vergelijking Ax = b
.LP
.I "(Opdracht 6)"
.LP
.NH 3
Wiskundige uitwerking
.LP
Gegeven is volgende vergelijking:
.EQ
Ax = b
.EN
We kunnen dit herschrijven als een cyclische convolutie om het probleem te vereenvoudigen:

(We gebruiken $@$ om de cyclische convolutie aan te duiden)
.EQ
a @ x = b
.EN

Gebruik makend van de cyclische convolutie stelling, kunnen we nu de Discrete Fourier Transformatie (DFT) toepassen om dit te vervormen naar een componentgewijze vermenigvuldiging.
.EQ
F sub {n} (a) F sub {n} (x) = F sub {n} (b)
.EN
Als we nu omvormen naar x.
.EQ
x = F sub n sup -1 ( {{F sub n (b)} over {F sub n (a)}} ) sup T
.EN
We hebben nu dus een snel algoritme voor het vinden van x, zeker indien we de Fast Fourier Transform
zouden gebruiken.
.NH 3
Vertaling naar code
.LP
Het eerste dat we nodig hebben is de Discrete Fourier Transformatie of 
Fast Fourier Transformatie en de inverse hiervan. 
In deze code is gekozen voor de Discrete Fourier
Transformatie omdat deze makkelijker te implemteren is en de snelle niet 
noodzakelijk is voor dit verslag.

Stel dat we een vector $b$ hebben, de discrete fourier transformatie gaat dan 
als volgt:
.EQ
f sub k = sum from {j = 0} to {n - 1} {b sub {j} e sup {i 2 pi j k / n}}
.EN
De code hiervoor is zeer straig forward.
.B1
.DS L
.ft C
vector
FourierDiscreteTransform
(vector *Vector)
{
vector DFT = 
  VectorInit(Vector->Size);
for (uint32 k = 0;
     k < Vector->Size;
     ++k)
{
for (uint32 j = 0;
     j < Vector->Size;
     ++j)
{
DFT.Elements[k] = 
  DFT.Elements[k] 
  + (Vector->Elements[j] 
  * FourierMatrixElement(
      Vector->Size, k, j));
}
}
return(DFT);
}
.DE
.B2
De code voor de inverse is dezelfde behalve voor het feit dat we op het einde
elke element van de resulterende vector moeten delen door n.

Het implemneteren van de functie volgt nu gemakkelijk.

.B1
.DS L
.ft C
vector
SolveAxEqualsb
(matrix_cyclic *A, vector *B)
{
vector fc = 
  FourierDiscrete(&A->Vector);
vector fb = FourierDiscrete(&B);
for (uint32 i = 0;
     i < A->Vector.Size;
     ++i)
{
  fb.Elements[i] = fb.Elements[i] 
    / fc.Elements[i];
}
vector x =
  FourierDiscreteInv(&fb);
return(x);
}
.DE
.B2

De complexiteit van dit algoritme zal bepaalt worden
door de Fourier transformatie. In de code met de discrete fourier
transformatie bezorgt ons dit een complexiteit van $O(n sup 2 )$. 
Indien we de Fast Fourier transformatie gebruiken, kunnen we dit
beperken tot een complexiteit van $O(nlog(n))$.

.NH
Toepassing 1: De middens verbinden
.LP
Stel dat we starten met een willekeurige n-hoek zonder beperkingen op waar de punten mogen liggen, 
verbind dan de middens van deze punten om een nieuwe veelhoek te vormen. Opmerkelijk is dan dat de 
veelhoek steeds eenvoudiger zal worden.
.NH 2
Bewerking om de middens te verbinden aan de hand van een cyclische matrix.
.LP
.I "(Opdracht 7)"
.LP
Hiervoor beschouwen we onze n-hoek als een cycische vector $a$ van lengte $n$, 
waar de verbonden punten elkaar opvolgen. 

We zoeken nu naar een cyclische matrix die, wanneer met $a$ vermenigvuldigt, 
een nieuwe vector $a'$ geeft waarbij het volgende geldt: 
.EQ
a' sub i = (a sub i + a sub {(i + 1) % n})~/~2
.EN
De matrix die hiervoor kan zorgen is de cyclische matrix:
.EQ
M = circ([1/2, 1/2, 0, ..., 0] sup T )
.EN
We eindigen dan met de bewerking:
.EQ
a' = Ma
.EN
.NH 2
Complexiteit van deze bewerking
.LP
.I "(Opdracht 8)"
.LP
De complexiteit van deze bewerking is $O(mn sup 2 )$. Een bewerking heeft immers kost $n sup 2$ en we
hebben $m$ keer deze bewerking. 

Indien we het probleem anders bekijken, zonder matrix, kunnen 
we het probleem herleiden naar een complexiteit van $O(mn)$. Hiervoor moeten we volgende bewerking gebruiken:
.EQ
a' sub i = (a sub i + a sub {((i + 1) % n)}) / 2
.EN
.NH 2
De grootste 2 eigenwaarden in modulus en limietgedrag
.LP
.I "(Opdracht 9)"
.LP
Stel dus de cyclische vector:
.EQ
M = circ([1/2, 1/2, 0, ..., 0] sup T )
.EN
Het eerste inzicht dat we hebben is dat de eigenwaarden
van deze matrix de som gedeeld door 2 van de 2 eerste waarden in de 
eigenvectors zijn. Dit zijn dus telkens de 2 eerste $omega$'s$/2$ is. 
Met de 2 eeste $omega$'s wordt bedoeld $omega sup 0$ en $omega sup j$ 
waarbij j voor de kolom index in de Fourier matrix $F sub n$ staat.
Verder weten we ook dat alle $omega$'s dezelfde straal hebben, en dus 
de grootte van onze som zal afhangen van de hoek tussen $omega sup 0$ 
en $omega sup j$. Nu weten we ook dat de som van de 2 zal vergroten 
indien de hoek kleiner wordt (Dit bewijzen we hier niet). 
De 2 grootste eigenwaarden zullen dus gevormd worden door 
.EQ
{omega sup {(0 * 0)} + omega sup {(0 * 1)}} over 2 = 1
.EN
en
.EQ
{( omega sup {(0 * 0)} + omega sup {(1 * 1)} )} over 2 =
{(1 + omega )} over 2 
.EN
In modulus zal dit het volgende vormen:
.EQ
1
.EN
en
.EQ
sqrt {(1/2 + cos({2 pi} over n )) sup 2 + sin sup 2 ({2 pi} over n )}
.EN
Deze eigenvectoren kunnen ons vertellen dat de 2e eigenvector 
ook naar 1 zal naderen, en de 2 eigenvectoren dus gelijk zullen 
worden naarmate n oneindig groot wordt.
.NH 2
Implementatie in code
.LP
De code hiervoor is terug te vinden in de files:
.CW applications/connect_midpoints.h
,
.CW applications/connect_midpoints.cpp
en
.CW 
graph_data/graph.py
.LP
Omdat dit fenomeen van de middens verbinden wel interessant is, werd het
geimplemteerd in code. Vooral om eens te kunnen zien hoe zo een 
middens verbinden algoritme werkt.

Om zo een visualisatie te bereiken werd het algoritme bij de rest van 
de code in c/c++ geimplementeerd. Dit algoritme zal na een x aantal
stappen telkens de huidige staat van de vector wegschrijven in 
een csv bestand. Daarna zal dan een python script deze 
resultaten inlezen en de figuren plotten en opslaan met matplotlib.
Om het nog visueel interessanter te maken worden de verschillende 
figuren aan de hand van de imageio bibliotheek gecombineerd in een
gif afbeelding/video. Hierop valt dan zeer goed te zien hoe de vector
evolueert over m aantal stappen. Zo een gif kan gevonden worden op 
volgende link: 

.pdfhref W https://eliasnijs.xyz/scicomp/project.html

Terwijl het voor het bestuderen van wiskundige eigenschappen interessant
was om een algoritme te bestuderen op basis van een circulante matrix, 
werd er in de code toch voor gekozen om hiervan geen gebruik te maken
vermits dit meer memory zou innemen en een hogere complexiteit zou hebben.

.NH 1
Toepassing 2: De wildwaterbaan
.LP
Circulante matrices hebben ook betrekking op heel wat praktische toepassingen. 
Het simuleren van golven in een zwembad is daar een voorbeeld van.

Hiervoor beschouwen we een ringvormig zwembad met $n$ equidistante 
punten $x sub 0, ..., x sub n-1$.
De simulatie die we beschouwen rust op de volgende formule:
.EQ
h sup (k-1) - 2h sup (k) + h sup (k+1) = {{Delta t sup 2} over {Delta x sup 2}} Ah sup (k+1)
.EN
Hierbij is $h sup k$ een vector die de hoogte aanduid op de punten $x sub 0, ..., x sub n-1$
op het $k$'de moment. $Delta t$ is de hoeveelheid tijd tussen moment $k$ en $k + 1$. 
$Delta x$ is de afstand tussen alle 2 opeenvolgende punten. A is de volgende circulaire 
matrix:
.EQ
A = 1 over 12 circ([-30, 16, -1, 0, 0, ..., 0, -1, 16])
.EN
.NH 2
Omvormen naar een werkbare formule
.LP
Om dit nu te kunnen simuleren zullen we eerst de formule moeten 
hervormen naar een vorm die het toelaat om $h sup k$ te bereken.
De vorm die we zullen proberen uitkomen is de vorm Ax=b. We proberen dit
omdat we al eerder een functie implementeerden die in staat is om x te bereken
vanuit deze vorm.

Om de vergelijking er beter te doen uitzien, doen we eerst het volgende:
.EQ
g = {Delta t sup 2} over {Delta x sup 2}
.EN
We krijgen dan:
.EQ
h sup (k-1) - 2h sup (k) + h sup (k+1) = gAh sup (k+1)
.EN
Nu zullen we dus verder omvormen tot we deze vorm uitkomen:
.EQ
 gA h sup (k+1) - h sup (k+1) = {h sup (k-1) - 2h sup (k)}
.EN
.EQ
(gA - I) h sup (k+1) = h sup (k-1) - 2h sup (k)
.EN
Op dit moment hebben we de vorm $Ax=b$ bereikt en kunnen we dus starten
met het implementeren van deze simulatie in code.
.NH 2
Implementatie in code
.LP
De code hiervoor valt terug te vinden onder:
.CW "applications/waves.cpp"
en
.CW "applications/waves.h"

De code die we willen implementeren zal een paar parameters nemen: 
een start vector die de hoogte op het moment $k = 0$ geeft, de radius van het zwembdad,
de hoeveelheid tijd tussen momenten en tot slot het aantal simulatie stappen dat we willen
doen.

Het eerste dat we nu kunnen berekenen zijn de zaken die constant zullen blijven 
tijdens de simulatie stappen. De enige constante die wij hebben is de matrix $(gA-I)$.
Om dit te bereken hebben we eerst $Delta x$ nodig. We kunnen deze vinden door de afstand
tussen punten (1, 0) en $omega$ te berekenen. We weten immers dat de punten equidistant 
zijn en dus element op plaats (1,1) in de Fourier Matrix ons het eerste punt geeft.
Daarna moeten we enkel nog de afstand bereken. Dat kan gemakkelijk: 
.EQ
Delta x = sqrt {{(x sub 2 - x sub 1 )} sup 2  +  {(y sub 2 - y sub 1)} sup 2}
.EN

In code vertaalt zich dat als volgt:

.B1
.DS L
.ft C
complex_number w = r *
  FourierMatrixElement(
    Origin->Size, 1, 1);
real64 dx = 
  sqrt(pow((w.Real - r), 2) 
  + pow((w.Imaginary - 0), 2));
.DE
.B2

Nu kunnen we matrix A makkelijk opstellen.

.B1
.DS L
.ft C
real64 g = 
  (pow(dt, 2) / pow(dx, 2));
vector a = 
  VectorInit(Origin->Size);
a.Elements[0] = 
  ((g * (-30.0 / 12)) - 1);
a.Elements[1] = 
  (g * (16.0 / 12));
a.Elements[2] = 
  (g * (-1.0 / 12));
a.Elements[Origin->Size-2] = 
  (g * (-1.0 / 12));
a.Elements[Origin->Size-1] = 
  (g * (16.0 / 12));
matrix_cyclic A = {a};
.DE
.B2

Tot slot moeten gewoon m keer onze functie oproepen op onze vector:

.B1
.DS L
.ft C
vector
WaveSimulationStep
(vector hc, vectorhp, 
 matrix_cyclic A)
{
vector hn = 
  VectorInit(hc->Size);
vector b = 
  VectorInit(hc->Size);
for (uint32 i = 0;
     i < hc->Size;
     ++i)
{
  b.Elements[i] = 
    (hp->Elements[i] 
    - (2 * hc->Elements[i]));
}
vector x =
  SolveAxEqualsb(A, &b);
return(x);
}
.DE
.B2

En zo hebben we een werkende implementatie van de simulatie.

Om echter beter te kunnen experimenteren met verschillende inputs, 
wordt om de zoveel stappen de staat van de vector weggeschreven naar een csv 
bestand. Op het einde zal een python script dan al deze data combineren in een
gif die veel makkelijker te interpreteren is dan een reeks nummers.
Zo een reeks gifs zijn terug te vinden op volgende link:

.pdfhref W https://eliasnijs.xyz/scicomp/project.html

(Ik raad u zeker aan van hier zeker eens naar te kijken. Het is heel mooi om
het effect van de verschillende inputs naast elkaar te zien)
.NH 2
Bevindingen bij de simulaties
.LP
Na het bestuderen van de verschillende simulaties en de effecten van
verschillende inputs zijn er enkele conclusies die we kunnen trekken.
.NH 3
De parameters
.LP
We beginnen met het bespreken met de effecten van de verschillen inputs.

Het effect van start vector is dat waar er zich een piek bevindt, deze piek over tijd
mooi doorgegeven zal worden.

De radius van het zwembad bepaalt de snelheid waarmee 
de golf wordt doorgegeven. Dit is ook logisch, 
er moet immers meer water verplaats worden.

De $Delta t$ bepaalt hoeveel tijd 1 tranformatie voorstelt. We merken op dat
indien we deze groot maken de simulatie onrealistisch wordt.

De laatste input die we bespreken is het aantal punten dat we plaatsen. Het valt op
dat hoe meer punten we plaatsen, hoe meer stabiel de simulatie is. Zelf een 
chaotische input zal een mooie golf geven.
.NH 3
Belangrijkste bevindingen 
.LP
De eerste belangrijke bevinding is dat de mean van alle hoogtes 
steeds dezelfde blijft. Als we nadenken over de funtie werkt, is dit ook logisch.

De tweede belangrijke bevinding is dat terwijl de mean dezelfde blijft, de variantie
steeds zal verminderen. Uiteindelijk zal de golf dus altijd eindigen als stil water.

.NH 
References / Resources
.LP
Enkele bronnen die mij enorm geholpen
hebben tijdens dit project:

.nr step 1 1
.IP \n[step]. 3
MIT OpenCourseWare - MIT 18.065 Matrix Methods in Data Analysis, 
Signal Processing, and Machine Learning, Spring 2018 - Gilbert Strang
.IP \n+[step].
Steve Brunton's youtube channel
.IP \n+[step].
On Circulant Matrices - Irwin Kra and Santiago R. Simanca




.NH 1
Endnote
.LP
Tot slot wil ik u nog bedanken voor het uitdagende maar zeer 
interessante project.




