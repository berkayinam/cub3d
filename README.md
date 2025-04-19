# cub3d

42 okulunun grafik projesi olan cub3d, Wolfenstein 3D oyununun temel grafik motorunu C programlama dili kullanarak yeniden oluşturmayı amaçlayan bir projedir.

## 🎮 Proje Hakkında

cub3d, raycasting tekniğini kullanarak 2 boyutlu bir haritayı 3 boyutlu bir ortama dönüştüren bir grafik projesidir. Proje, temel 3D grafik programlama konseptlerini ve matematiksel hesaplamaları öğretmeyi amaçlamaktadır.

## 💻 Teknolojiler

- C Programlama Dili
- MinilibX Grafik Kütüphanesi
- Raycasting Algoritması
- Matematiksel Hesaplamalar
  - Vektör Matematiği
  - Trigonometri
  - Matris İşlemleri

## 🛠️ Kurulum

### Gereksinimler
- GCC Derleyici
- Make
- MinilibX Kütüphanesi
- X11 Geliştirme Kütüphaneleri (Linux için)

### Derleme ve Çalıştırma

1. Projeyi klonlayın:
```bash
git clone https://github.com/[kullanıcı-adı]/cub3d.git
cd cub3d
```

2. Projeyi derleyin:
```bash
make
```

3. Programı çalıştırın:
```bash
./cub3d maps/map.cub
```

## 📝 Özellikler

### Temel Özellikler
- [x] 3D Görüntüleme
- [x] WASD ile Hareket
- [x] Fare/Ok Tuşları ile Kamera Kontrolü
- [x] Duvar Çarpışma Tespiti
- [x] Doku Haritalama

### Harita Özellikleri
- [x] .cub Dosya Formatı Desteği
- [x] Özelleştirilebilir Harita Boyutu
- [x] Farklı Duvar Dokuları
- [x] Sprite Desteği

### Grafik Özellikleri
- [x] Duvar Dokuları
- [x] Tavan ve Zemin Renkleri
- [x] Sprite Renderlaması
- [x] Derinlik Tamponu

## 🗺️ Harita Formatı

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Harita Sembolleri
- `0`: Boş alan
- `1`: Duvar
- `N/S/E/W`: Oyuncu başlangıç pozisyonu ve yönü
- ` ` (boşluk): Harita dışı alan

## 🎯 42 Proje Gereksinimleri

### Zorunlu Kısım
- [x] MinilibX kullanımı
- [x] Pencere yönetimi
- [x] Raycasting implementasyonu
- [x] Duvar renderlaması
- [x] Hareket sistemi

### Bonus Özellikler
- [x] Duvar dokuları
- [x] Zemin ve tavan renkleri
- [x] Sprite desteği
- [x] Minimap
- [x] Duvar çarpışması

## 🔧 Kontroller

- `W`: İleri hareket
- `S`: Geri hareket
- `A`: Sola hareket
- `D`: Sağa hareket
- `←`: Sola dön
- `→`: Sağa dön
- `ESC`: Oyundan çık
- `Mouse`: Kamera kontrolü (opsiyonel)

## 🐛 Hata Ayıklama

### Yaygın Hatalar
1. Segmentation Fault
   - Harita sınırlarını kontrol edin
   - Bellek sızıntılarını kontrol edin
   - Doku dosyalarının varlığını doğrulayın

2. Görüntüleme Sorunları
   - MinilibX kurulumunu kontrol edin
   - Doku dosyalarının formatını doğrulayın
   - Pencere boyutlarını kontrol edin

## 📈 Optimizasyon İpuçları

1. Performans İyileştirmeleri
   - DDA algoritması optimizasyonu
   - Doku önbellekleme
   - Gereksiz hesaplamaları azaltma

2. Bellek Yönetimi
   - Dinamik bellek kontrolü
   - Bellek sızıntılarını önleme
   - Kaynakların düzgün serbest bırakılması

## 👥 Katkıda Bulunma

1. Bu repository'yi fork edin
2. Feature branch'i oluşturun (`git checkout -b feature/AmazingFeature`)
3. Değişikliklerinizi commit edin (`git commit -m 'Add some AmazingFeature'`)
4. Branch'inizi push edin (`git push origin feature/AmazingFeature`)
5. Pull Request oluşturun

## 📝 Lisans

Bu proje [MIT](LICENSE) lisansı altında lisanslanmıştır.

## 🎓 Kaynaklar

- [Wolfenstein 3D'nin Tarihi](https://en.wikipedia.org/wiki/Wolfenstein_3D)
- [Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [MinilibX Dokümantasyonu](https://qst0.github.io/ft_libgfx/man_mlx.html)

---

⭐️ Bu projeyi beğendiyseniz yıldız vermeyi unutmayın!
