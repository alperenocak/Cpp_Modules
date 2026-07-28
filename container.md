  C++ standart kütüphanesindeki (STL) konteynerlerin bellekteki yerleşim biçimleri 3 ana kategoriye ayrılır:
  1. Bitişik/Sıralı (Contiguous): Elemanlar bellekte peş peşe dizilir.
  2. Parçalı Bitişik (Chunked/Paged): Sabit boyutlu küçük bloklar halinde peş peşe dizilir.
  3. Düğümsel/Dağınık (Node-based / Non-contiguous): Elemanlar belleğin rastgele yerlerine dağılır, birbirine
  pointer'lar ile bağlanır.
  ──────
  ### 1. Bitişik (Sıralı) Bellek Düzeni

  #### std::vector ve std::array
  Elemanların hepsi bellekte tek bir blok halinde ve kesintisiz sırayla yan yana tutulur.

    [ Eleman 0 ] [ Eleman 1 ] [ Eleman 2 ] [ Eleman 3 ]
    0x1000       0x1004       0x1008       0x100C       <-- Adresler tam sıralı artar
    
  • Adres Mantığı: &v[1] adresi, &v[0] + 1 adresine eşittir.
  • Performans: İşlemci (CPU) önbelleği (Cache) dostudur. İşlemci ilk elemanı okurken devamındaki elemanları da
  önbelleğe (L1/L2 Cache) yükler, bu yüzden erişimi aşırı hızlıdır.
  ──────
  ### 2. Parçalı Bitişik Bellek Düzeni
  #### std::deque (Double-Ended Queue)

  Tek bir devasa blok yerine, sabit boyutlu küçük bellek blokları (chunks) oluşturur. Her blok kendi içinde
  sıralıdır, ancak bloklar belleğin farklı yerlerinde olabilir.

    Harita (Pointer Dizisi)
    ┌──────────┐
    │ Block 1  ├───────> [ Eleman 0 ] [ Eleman 1 ] [ Eleman 2 ]  (0x1000 - 0x1008)
    │ Block 2  ├───────> [ Eleman 3 ] [ Eleman 4 ] [ Eleman 5 ]  (0x5000 - 0x5008)
    └──────────┘
    
  • Adres Mantığı: Kendi bloğu içinde elemanlar sıralıdır, ama blok geçişlerinde adresler zıplayabilir.
  • Neden var?: Reallocation (bellek yeniden boyutlandırma) maliyeti vector kadar yüksek değildir. Baştan ve
  sondan ekleme/çıkarma O(1) sürede yapılır. (std::stack varsayılan olarak bunu kullanır).
  ──────
  ### 3. Düğümsel (Rastgele / Dağınık) Bellek Düzeni

  #### std::list (Çift Yönlü Bağlı Liste) ve std::forward_list

  Her eleman bellekte tamamen bağımsız ve rastgele (Heap neresi boşsa oraya) yerleştirilir. Elemanlar birbirini
  işaretçi (pointer) ile tanır.

         Düğüm 0                    Düğüm 1                    Düğüm 2
    ┌────────────────┐         ┌────────────────┐         ┌────────────────┐
    │ Prev: NULL     │         │ Prev: 0x1000   │         │ Prev: 0x4000   │
    │ Data: 10       │         │ Data: 20       │         │ Data: 30       │
    │ Next: 0x4000 ──┼────────>│ Next: 0x2500 ──┼────────>│ Next: NULL     │
    └────────────────┘         └────────────────┘         └────────────────┘
    Adres: 0x1000              Adres: 0x4000              Adres: 0x2500
    
  • Adres Mantığı: Adresler tamamen dağınıktır (0x1000, 0x4000, 0x2500...).
  • Performans: CPU Cache dostu değildir (Cache miss yaşanır). Ancak araya eleman ekleme/çıkarma O(1) sürer.
  ──────
  ### 4. Ağaç Yapısındaki Dağınık Bellek

  #### std::map, std::set, std::multimap, std::multiset

  Bu konteynerlar arka planda Kırmızı-Siyah Ağaç (Red-Black Tree) adı verilen dengeli bir arama ağacı tutar.

                      [ Düğüm (Kök) ] (Adres: 0x7000)
                     /               \
                    /                 \
      [ Düğüm (Sol) ] (0x1200)      [ Düğüm (Sağ) ] (0x9500)
    
  • Adres Mantığı: std::list gibi her düğüm Heap'ten rastgele yerlerde tahsis edilir (Dağınıktır).
  • Düğümler içinde Parent, Left, Right pointer'ları ve Color (kırmızı/siyah) bilgisi tutulur.
  ──────
  ### 5. Hash Table (Karma Tablo) Bellek Düzeni

  #### std::unordered_map ve std::unordered_set

  Bir Bucket (Kova) Dizisi + Bağlı Liste (Linked List) birleşimidir.

    Bucket Dizisi (Bitişik Dizi)
    ┌───┬────────────────────────────────┐
    │ 0 │ ───> [Düğüm A] ───> [Düğüm B]  │ (Dağınık Heap Adresleri)
    ├───┼────────────────────────────────┤
    │ 1 │ ───> NULL                      │
    ├───┼────────────────────────────────┤
    │ 2 │ ───> [Düğüm C]                 │
    └───┴────────────────────────────────┘

  • Adres Mantığı: Bucket indekslerinin tutulduğu ana dizi bitişiktir, ama kovalara takılan çakışma (collision)
  düğümleri Heap'te dağınık durur.
  ──────
  ### 6. Konteyner Adaptörleri (std::stack, std::queue, std::priority_queue)

  Bu yapılar kendi bellek düzenlerine sahip değildir.

  • std::stack: Varsayılan olarak std::deque kullandığı için parçalı bitişiktir.
  • std::queue: Varsayılan olarak std::deque kullanır.
  • std::priority_queue: Varsayılan olarak std::vector kullandığı için bitişiktir.
  ──────
  ### Özet Karşılaştırma Tablosu

   Konteyner                | Bellek Düzeni              | CPU Önbellek Verimi (Cache… | Rastgele Erişim ([i])
  --------------------------|----------------------------|-----------------------------|-----------------------
   std::vector / std::array | Tamamen Bitişik (Sıralı)   | 🟢 Mükemmel (O(1))          | var (O(1))
   std::deque               | Parçalı Bitişik            | 🟡 Orta                     | var (O(1))
   std::list                | Tamamen Dağınık (Düğümsel) | 🔴 Zayıf                    | yok (O(N))
   std::map / std::set      | Tamamen Dağınık (Ağaç)     | 🔴 Zayıf                    | yok (O(log N))
   std::unordered_map       | Karma (Dizi + Dağınık)     | 🟡 Orta                     | yok (O(1) ortalama)
