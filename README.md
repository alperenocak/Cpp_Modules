# 42 — C++ Modules

C++ programlama dilini sıfırdan öğrenmek amacıyla yazılmış 42 School müfredatı projeleri. Her modül belirli bir C++ konseptini derinlemesine ele alır.

---

## Modules

| Modül | Konu | Egzersizler |
|:---:|---|:---:|
| [cpp00](./cpp00) | Namespace, sınıflar, member fonksiyonlar, stdio streams, initialization lists | ex00–ex01 |
| [cpp01](./cpp01) | Bellek yönetimi, pointer to member, referanslar, switch | ex00–ex05 |
| [cpp02](./cpp02) | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | ex00–ex02 |
| [cpp03](./cpp03) | Kalıtım (Inheritance) | ex00–ex02 |
| [cpp04](./cpp04) | Subtype polymorphism, abstract sınıflar, interface'ler | ex00–ex02 |
| [cpp05](./cpp05) | Tekrarlama (repetition) ve exception handling | ex00–ex03 |
| [cpp06](./cpp06) | C++ tür dönüşümleri (static, dynamic, reinterpret, const cast) | ex00–ex02 |
| [cpp07](./cpp07) | C++ template'ler | ex00–ex02 |
| [cpp08](./cpp08) | STL container'lar, iterator'lar ve algorithm'lar | ex00–ex02 |
| [cpp09](./cpp09) | STL container'ların ileri kullanımı | ex00–ex02 |

---

## Highlights

### cpp09 — STL Advanced Usage

| Egzersiz | Proje | Açıklama |
|---|---|---|
| ex00 | **BitcoinExchange** | CSV dosyasından BTC fiyatlarını okur ve tarihe göre değer hesaplar (`std::map`) |
| ex01 | **RPN** | Reverse Polish Notation hesap makinesi (`std::stack`) |
| ex02 | **PmergeMe** | Ford-Johnson (Merge-Insertion Sort) algoritması ile sıralama (`std::vector`, `std::deque`) |

### cpp08 — STL Containers & Algorithms

| Egzersiz | Proje | Açıklama |
|---|---|---|
| ex00 | **easyfind** | Generic template fonksiyon ile container içinde eleman arama |
| ex01 | **Span** | Min/Max span hesaplayan özel container sınıfı |
| ex02 | **MutantStack** | Iterator desteği eklenmiş `std::stack` türevi |

---

## Kullanılan Teknolojiler

- **Dil:** C++98
- **Derleme:** `g++` `-Wall -Wextra -Werror -std=c++98`
- **Build sistemi:** `make` (her egzersizde Makefile mevcut)
- **STL:** `std::vector`, `std::deque`, `std::map`, `std::stack`, `std::list`
- **OOP:** Kalıtım, polymorphism, abstract sınıflar, operator overloading, template'ler
- **Diğer:** Exception handling, type casting, Orthodox Canonical Form

---

## Repo Yapısı

```
Cpp_Modules/
├── cpp00/ ... cpp09/   # Modül egzersizleri
├── notes/              # Öğrenme notları ve algoritma analizleri
├── playground/         # Deneme / scratch kodları
├── scripts/            # Yardımcı shell scriptleri
└── subjects/           # 42 subject PDF'leri
```

---

## Derleme

Her egzersizin kendi dizininde:

```bash
make        # derleme
make clean  # obje dosyaları sil
make fclean # binary dahil temizle
make re     # yeniden derle
```

---

## Author

**Yusuf Alperen Ocak** — [yuocak](https://github.com/yuocak)
