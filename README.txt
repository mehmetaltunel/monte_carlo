MONTE CARLO SİMÜLASYONU ÖDEVİ
============================

Bu ödev, rastgele sayı üretimi ve Monte Carlo simülasyonu kullanarak banka müşterilerinin hizmet sürelerini modellemektedir.

DOSYALAR
--------
1. monte_carlo.c - 100 müşteri için Monte Carlo simülasyonu
2. monte_carlo_extended.c - 1000 müşteri için genişletilmiş Monte Carlo simülasyonu
3. README.txt - Bu dosya

DERLEYİCİ BİLGİSİ
----------------
Bu programlar GCC derleyicisi kullanılarak geliştirilmiştir.
Kullanılan GCC sürümü: gcc (GCC) 11.3.0

DERLEME TALİMATLARI
------------------
Programları derlemek için aşağıdaki komutları kullanabilirsiniz:

100 müşteri için simülasyon:
```
gcc -o monte_carlo monte_carlo.c -lm
```

1000 müşteri için genişletilmiş simülasyon:
```
gcc -o monte_carlo_extended monte_carlo_extended.c -lm
```

ÇALIŞTIRMA TALİMATLARI
---------------------
Derlenmiş programları çalıştırmak için:

100 müşteri için simülasyon:
```
./monte_carlo
```

1000 müşteri için genişletilmiş simülasyon:
```
./monte_carlo_extended
```

PROGRAM AÇIKLAMASI
-----------------
Bu programlar aşağıdaki işlemleri gerçekleştirir:

1. Uniform dağılımlı (0.0-1.0 arasında) rastgele sayılar üretir.
2. Bu rastgele sayıları belirli olasılıklarla hizmet sürelerine dönüştürür:
   - Ts-1 (4 dakika): %35 olasılık
   - Ts-2 (8 dakika): %50 olasılık
   - Ts-3 (12 dakika): %15 olasılık
3. Her müşteri için üretilen rastgele sayıyı ve atanan hizmet süresini gösterir.
4. Simülasyon sonunda her hizmet süresi tipinin kaç kez üretildiğini ve yüzdesini hesaplar.
5. Genişletilmiş versiyonda, gerçek sonuçları beklenen değerlerle karşılaştırır ve sapma analizini gösterir.

NOTLAR
------
- Programlar her çalıştırıldığında farklı sonuçlar üretecektir çünkü rastgele sayı üreteci srand(time(NULL)) ile başlatılmaktadır.
- Genişletilmiş versiyonda, yalnızca ilk 100 müşteri için detaylı çıktı gösterilir, ancak istatistikler tüm 1000 müşteri için hesaplanır.
- Programlar, math.h kütüphanesini kullandığı için -lm bayrağı ile derlenmelidir. 