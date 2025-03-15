/**
 * Monte Carlo Simülasyonu
 * 
 * Bu program:
 * 1. 100 rastgele tam sayı üretir ve bunları 0.0-1.0 arasında uniform dağılımlı sayılara dönüştürür
 * 2. Bu rastgele sayıları kullanarak banka müşterilerinin hizmet sürelerini simüle eder
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hizmet süreleri (dakika)
#define TS_1 4  // %35 olasılık
#define TS_2 8  // %50 olasılık
#define TS_3 12 // %15 olasılık

// Müşteri sayısı
#define NUM_CUSTOMERS 100

// 0.0 ile 1.0 arasında uniform dağılımlı rastgele sayı üretir
double generate_random_uniform() {
    return (double)rand() / RAND_MAX;
}

// Rastgele sayıya göre hizmet süresini belirler
int determine_service_time(double random_num) {
    if (random_num < 0.35) {
        return TS_1;
    } else if (random_num < 0.85) { // 0.35 + 0.50 = 0.85
        return TS_2;
    } else {
        return TS_3;
    }
}

int main() {
    // Rastgele sayı üretecini başlat
    srand(time(NULL));
    
    // Hizmet süresi sayaçları
    int count_ts1 = 0;
    int count_ts2 = 0;
    int count_ts3 = 0;
    
    printf("Rastgele Sayı -> Atanan Hizmet Süresi\n");
    printf("--------------------------------------\n");
    
    // 100 müşteri için simülasyon
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        // Rastgele sayı üret
        double random_num = generate_random_uniform();
        
        // Hizmet süresini belirle
        int service_time = determine_service_time(random_num);
        
        // Hizmet süresine göre sayaçları güncelle
        if (service_time == TS_1) {
            count_ts1++;
            printf("%.4f -> Ts-1 (%d dakika)\n", random_num, TS_1);
        } else if (service_time == TS_2) {
            count_ts2++;
            printf("%.4f -> Ts-2 (%d dakika)\n", random_num, TS_2);
        } else {
            count_ts3++;
            printf("%.4f -> Ts-3 (%d dakika)\n", random_num, TS_3);
        }
    }
    
    // Sonuç özeti
    printf("\nSonuç Özeti:\n");
    printf("------------\n");
    printf("Ts-1 (%d dakika): %d müşteri (%.2f%%)\n", TS_1, count_ts1, (float)count_ts1 / NUM_CUSTOMERS * 100);
    printf("Ts-2 (%d dakika): %d müşteri (%.2f%%)\n", TS_2, count_ts2, (float)count_ts2 / NUM_CUSTOMERS * 100);
    printf("Ts-3 (%d dakika): %d müşteri (%.2f%%)\n", TS_3, count_ts3, (float)count_ts3 / NUM_CUSTOMERS * 100);
    
    return 0;
} 