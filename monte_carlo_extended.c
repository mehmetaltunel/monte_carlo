/**
 * Genişletilmiş Monte Carlo Simülasyonu
 * 
 * Bu program:
 * 1. 1000 rastgele tam sayı üretir ve bunları 0.0-1.0 arasında uniform dağılımlı sayılara dönüştürür
 * 2. Bu rastgele sayıları kullanarak banka müşterilerinin hizmet sürelerini simüle eder
 * 3. Sonuçları beklenen değerlerle karşılaştırır
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Hizmet süreleri (dakika)
#define TS_1 4  // %35 olasılık
#define TS_2 8  // %50 olasılık
#define TS_3 12 // %15 olasılık

// Müşteri sayısı
#define NUM_CUSTOMERS 1000

// Beklenen olasılıklar
#define PROB_TS1 0.35
#define PROB_TS2 0.50
#define PROB_TS3 0.15

// 0.0 ile 1.0 arasında uniform dağılımlı rastgele sayı üretir
double generate_random_uniform() {
    return (double)rand() / RAND_MAX;
}

// Rastgele sayıya göre hizmet süresini belirler
int determine_service_time(double random_num) {
    if (random_num < PROB_TS1) {
        return TS_1;
    } else if (random_num < PROB_TS1 + PROB_TS2) {
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
    
    // Rastgele sayıları ve hizmet sürelerini saklamak için diziler
    double random_numbers[NUM_CUSTOMERS];
    int service_times[NUM_CUSTOMERS];
    
    printf("İlk 100 Müşteri için Rastgele Sayı -> Atanan Hizmet Süresi\n");
    printf("--------------------------------------------------------\n");
    
    // 1000 müşteri için simülasyon
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        // Rastgele sayı üret
        random_numbers[i] = generate_random_uniform();
        
        // Hizmet süresini belirle
        service_times[i] = determine_service_time(random_numbers[i]);
        
        // Hizmet süresine göre sayaçları güncelle
        if (service_times[i] == TS_1) {
            count_ts1++;
        } else if (service_times[i] == TS_2) {
            count_ts2++;
        } else {
            count_ts3++;
        }
        
        // İlk 100 müşteri için detaylı çıktı
        if (i < 100) {
            if (service_times[i] == TS_1) {
                printf("%.4f -> Ts-1 (%d dakika)\n", random_numbers[i], TS_1);
            } else if (service_times[i] == TS_2) {
                printf("%.4f -> Ts-2 (%d dakika)\n", random_numbers[i], TS_2);
            } else {
                printf("%.4f -> Ts-3 (%d dakika)\n", random_numbers[i], TS_3);
            }
        }
    }
    
    // Gerçek olasılıkları hesapla
    double actual_prob_ts1 = (double)count_ts1 / NUM_CUSTOMERS;
    double actual_prob_ts2 = (double)count_ts2 / NUM_CUSTOMERS;
    double actual_prob_ts3 = (double)count_ts3 / NUM_CUSTOMERS;
    
    // Beklenen değerler
    int expected_ts1 = NUM_CUSTOMERS * PROB_TS1;
    int expected_ts2 = NUM_CUSTOMERS * PROB_TS2;
    int expected_ts3 = NUM_CUSTOMERS * PROB_TS3;
    
    // Sonuç özeti
    printf("\nSonuç Özeti (%d Müşteri):\n", NUM_CUSTOMERS);
    printf("-------------------------\n");
    printf("Ts-1 (%d dakika): %d müşteri (%.2f%%) - Beklenen: %d (%.2f%%)\n", 
           TS_1, count_ts1, actual_prob_ts1 * 100, expected_ts1, PROB_TS1 * 100);
    printf("Ts-2 (%d dakika): %d müşteri (%.2f%%) - Beklenen: %d (%.2f%%)\n", 
           TS_2, count_ts2, actual_prob_ts2 * 100, expected_ts2, PROB_TS2 * 100);
    printf("Ts-3 (%d dakika): %d müşteri (%.2f%%) - Beklenen: %d (%.2f%%)\n", 
           TS_3, count_ts3, actual_prob_ts3 * 100, expected_ts3, PROB_TS3 * 100);
    
    // Sapma analizi
    printf("\nSapma Analizi:\n");
    printf("--------------\n");
    printf("Ts-1: Fark = %d (%.2f%%)\n", 
           count_ts1 - expected_ts1, fabs(actual_prob_ts1 - PROB_TS1) * 100);
    printf("Ts-2: Fark = %d (%.2f%%)\n", 
           count_ts2 - expected_ts2, fabs(actual_prob_ts2 - PROB_TS2) * 100);
    printf("Ts-3: Fark = %d (%.2f%%)\n", 
           count_ts3 - expected_ts3, fabs(actual_prob_ts3 - PROB_TS3) * 100);
    
    // Toplam hizmet süresi
    int total_service_time = count_ts1 * TS_1 + count_ts2 * TS_2 + count_ts3 * TS_3;
    double avg_service_time = (double)total_service_time / NUM_CUSTOMERS;
    
    printf("\nToplam hizmet süresi: %d dakika\n", total_service_time);
    printf("Ortalama hizmet süresi: %.2f dakika\n", avg_service_time);
    
    return 0;
} 