## JNP - Zadanie3
Trzecie zadanie na kurs Języki i Narzędzia Programowania prowadzony na Wydziale Matematyki, Informatyki i Mechaniki Uniwersytetu Warszawskiego w semestrze zimowym roku 2017/18.

# Treść
Programiści pracujący nad Bardzo Tajnym Systemem potrzebują klasy, która będzie
służyła do przechowywania danych o ograniczonym dostępie. Dokładniej: przy
tworzeniu obiektu klasy Sejf podajemy napis, który będzie przechowywany
w sejfie i liczbę dostępów do tego obiektu, na które zezwolimy. Należy założyć,
że napis może być długi i zadbać o jego efektywną obsługę przy tworzeniu sejfu.
Sejf powinien udostępniać następujące metody (w przykładach s, s1, s2 itd. są
zmiennymi lokalnymi typu Sejf):

Sejf(napis, liczba) -- tworzy Sejf z podanym napisem i maksymalną liczbą
  dostępów. Powinno być też możliwe stworzenie sejfu z podaniem tylko
  napisu -- wtedy zezwalamy na 42 dostępy.

Dostęp do elementu -- odczyt elementu powinien być możliwy przez standardowy
  operator []. Nie powinno być możliwe zmienianie elementu. Na przykład po
  utworzeniu sejfu s4 z napisem "abc123" wynikiem wyrażenia s4[3] powinien być
  znak '1' zwrócony jako liczba 16-bitowa ze znakiem. Jeżeli próbujemy dostać
  się do elementu, który nie istnieje (niepoprawny indeks) w napisie, to
  powinna być zwrócona wartość -1 i taka operacja nie liczy się jako próba
  odczytu. Po przekroczeniu liczby dozwolonych odczytów także powinna być
  zwracana wartość -1. Podobnie jak niektóre funkcje z biblioteki standardowej,
  np. fgetc(), traktujemy znak w napisie jako typ unsigned char i rzutujemy go
  na zwracany typ, natomiast w przypadku błędu po prostu zwracamy wartość -1.
  Przykład:
  
  ```
  Sejf s("a\xff", 3);
  assert(s[0] == 'a');
  assert(s[1] == 255);
  assert(s[1] == (int)((unsigned char) -1));
  assert(s[1] == -1);
  assert(s[1] != (int)((unsigned char) -1));
  ```
  
Manipulacje sejfem -- za pomocą operatorów +=, -=, *= można zmienić pozostałą
  liczbę prób dostępu. Na przykład po wykonaniu kodu
  
  ```
  Sejf s1("aaa", 2);
  s1[0];
  s1 *=3;
  ```

  będzie możliwe wykonanie jeszcze 3 prób dostępu do sejfu. W przypadku
  wyczerpania liczby prób dostępu należy uznać, że liczba przed operacją
  wynosi 0. Nie należy dopuszczać do ustawienia w sejfie pozostałej liczby
  prób dostępu na wartość ujemną, a jeżeli operacja spowodowałaby ustawienie
  pozostałej liczby prób na ujemną to jej nie wykonujemy. Ponadto w wyniku
  działania operatora -= pozostała liczba prób dostępu nie może się zwiększyć,
  a w wyniku działania operatorów += i *= pozostała liczba prób dostępu nie
  może się zmniejszyć.

Ze względów bezpieczeństwa nie pozwalamy na kopiowanie sejfów, ale powinno dać
się na przykład zamienić sejfy za pomocą bibliotecznej operacji

  ```
  std::swap(s1, s2);
  ```

i wykonać inne standardowe operacje, które nie powodują utworzenia kopii sejfu.

Kompilacja każdej z poniższych linii powinna zakończyć się błędem:

  ```
  Sejf s4 = s1;
  Sejf s5(s1);
  s6 = s1;
  ```

kontroler() -- umożliwia dostęp do kontrolera danego sejfu.
  Powinno być możliwe przeprowadzenie następującej operacji:

  ```
  os << s1.kontroler();
  ```
  
  która wypisze na strumień os napis:
  * "ALARM: WLAMANIE\n", jeżeli po wyczerpaniu dozwolonej liczby odczytów była
    co najmniej jedna próba odczytu (z poprawnym indeksem);
  * "ALARM: ZMANIPULOWANY\n", jeżeli na sejfie dokonano z sukcesem jednej
    z operacji +=, -=, *=;
  * "OK\n" w pozostałych przypadkach
  Kontroler powinien pozostawać związany z sejfem przez cały czas, jeżeli oba
  te obiekty są widoczne. Na przykład wynikiem kodu:
  
  ```
  Sejf s1("aaa", 2);
  s1[2];
  auto k1 = s1.kontroler();
  cout << k1 << "test\n";
  s1[2];
  s1[3];
  s1[4];
  cout << k1;
  s1[3];
  cout << k1;
  s1[2];
  cout << k1;
  ```
  
  powinno być:
  
  ```
  OK
  test
  OK
  OK
  ALARM: WLAMANIE
  ```
  
  Kontroler powinno dać się zastosować jako wartość logiczna, przy czym wartość
  ta będzie prawdziwa, jeżeli liczba prób nie została jeszcze wyczerpana. Na
  przykład powinien działać następujący kod:
  
  ```
  Sejf s1("aaa", 2);
  if (s1.kontroler())
    /* Można jeszcze odczytać. */
  ```
  
  ale próba kompilacji kodu
  
  ```
  if (s1.kontroler() < s2.kontroler())
    ...;
  ```
  
  powinna zakończyć się błędem.

  Kontroler nie powinien udostępniać żadnych innych operacji.

  Obiekt klasy Kontroler można stworzyć tylko przez wywołanie metody kontroler()
  na obiekcie klasy Sejf.

Obiekty klas Sejf i Kontroler powinny być zabezpieczone (w zakresie, w którym
jest to możliwe w języku C++) przed modyfikacją ich stanu z zewnątrz.

Rozwiązanie powinno składać się z plików sejf.h oraz sejf.cc. Można dodać też
pliki kontroler.h i kontroler.cc, ale w programie powinno wystarczyć włączenie
pliku sejf.h. Pliki te należy umieścić w repozytorium w katalogu

grupaN/zadanie3/ab123456+cd123456

lub

grupaN/zadanie3/ab123456+cd123456+ef123456

gdzie N jest numerem grupy, a ab123456, cd123456, ef123456 są identyfikatorami
członków zespołu umieszczającego to rozwiązanie.
Katalog z rozwiązaniem nie powinien zawierać innych plików, ale może zawierać
podkatalog private, gdzie można umieszczać różne pliki, np. swoje testy. Pliki
umieszczone w tym podkatalogu nie będą oceniane.
