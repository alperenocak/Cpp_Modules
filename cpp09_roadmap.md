  ### 📋 1. Genel Kurallar & Yasaklar

  • Derleme Bayrakları: Tüm kodlar c++ -Wall -Wextra -Werror -std=c++98 ile derlenmelidir.
  • Makefile: Her egzersiz için $(NAME), all, clean, fclean, re kurallarını içeren ve relink
  yapmayan bir Makefile teslim edilmelidir.
  • Ortodoks Kanonik Form (Orthodox Canonical Form): Yazılan sınıflar (Default Constructor, Copy
  Constructor, Copy Assignment Operator, Destructor) yapısına uygun olmalıdır.
  • Header Kuralları: Header dosyalarında şablonlar (templates) dışında fonksiyon gövdesi yazmak
  YASAKtır (0 puan). Header Guard kullanılmalıdır.
  • Yasaklar:
      • printf(), malloc(), free() kullanmak kesinlikle YASAKtır (0 puan).
      • using namespace <ns_name> ve friend kullanımı YASAKtır (-42 puan).
      • C++11/C++14/C++17 özellikleri ve Boost kütüphanesi YASAKtır.

  ──────
  ### 🚨 2. Module 09'a Özel EN KRİTİK Kural (Konteyner Kuralı)

  • Her egzersizde en az 1 STL konteyneri kullanılmalıdır (ex02 için 2 konteyner).
  • TEKRAR KULLANIM YASAĞI: Bir egzersizde kullandığınız konteyneri sonraki egzersizlerde
  KESİNLİKLE TEKRAR KULLANAMAZSINIZ!
  • Stratejik Konteyner Dağılımımız:
      1. ex00 (Bitcoin Exchange): std::map (Tarih-fiyat eşleşmesi ve lower_bound araması için
      ideal)
      2. ex01 (RPN): std::stack (Ters Leh Notasyonu yığın mantığı için ideal)
      3. ex02 (PmergeMe): std::vector ve std::deque (Ford-Johnson sıralama algoritmasında
      karşılaştırma yapmak için ideal)

  ──────
  ### 📚 3. Egzersiz İsterleri

  #### 🟢 Exercise 00: Bitcoin Exchange (ex00/)

  • Program Adı: btc
  • Girdi: Parametre olarak bir dosya yolu alır (Örn: ./btc input.txt).
  • Veritabanı: subjects/data.csv içindeki tarih-fiyat verilerini okur.
  • Girdi Formatı: date | value (Tarih formatı: YYYY-MM-DD, Değer: 0 ile 1000 arasında float/int).
  • Arama Mantığı: Aranan tarih veritabanında tam yoksa, veritabanındaki en yakın önceki (küçük)
  tarih kullanılır.
  • Hatalar: Dosya açılamazsa, sayı negatifse (Error: not a positive number.), sayı > 1000 ise
  (Error: too large a number.), tarih veya format hatalıysa (Error: bad input => ...) mesajları
  basılır.

  #### 🟡 Exercise 01: Reverse Polish Notation (ex01/)

  • Program Adı: RPN
  • Girdi: Komut satırından RPN ifadesi alan tek bir string alır (Örn: ./RPN "8 9 * 9 - 9 - 4 - 1 +
  ").
  • Operatörler: +, -, /, *
  • Kural: Girdideki sayılar 10'dan küçük (0-9 tek basamaklı) olmalıdır. Ancak işlem sonuçları
  10'dan büyük/küçük olabilir.
  • Hatalar: Hatalı ifade veya 0'a bölme gibi durumlarda std::cerr üzerinden Error basılır.

  #### 🔴 Exercise 02: PmergeMe (ex02/)

  • Program Adı: PmergeMe
  • Girdi: Pozitif tamsayı dizisi alır (Örn: ./PmergeMe 3 5 9 7 4). En az 3000 sayıyı
  işleyebilmelidir.
  • Algoritma: Ford-Johnson (Merge-Insert Sort) algoritması kullanılmalıdır.
  • Gereksinim: Algoritma 2 farklı konteyner ile uygulanmalı ve geçen süreler mikrosaniye (us)
  cinsinden ekrana yazdırılmalıdır.
  • Çıktı Formatı:
      • Before:  3 5 9 7 4
      • After:   3 4 5 7 9
      • Time to process a range of 5 elements with std::vector : 0.00031 us
      • Time to process a range of 5 elements with std::deque : 0.00014 us

  ──────
  ### 🚀 Yol Haritamız

  1. Adım 1: ex00 (Bitcoin Exchange) uygulamasını std::map kullanarak yazmak ve test etmek.
  2. Adım 2: ex01 (RPN) uygulamasını std::stack kullanarak yazmak ve test etmek.
  3. Adım 3: ex02 (PmergeMe) uygulamasını Ford-Johnson algoritmasıyla std::vector ve std::deque
  kullanarak yazmak ve test etmek.



İhtiyaç duyulan attributeler ===> string ve float alan bir map.