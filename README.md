# SERBEST ÖDEV: KOD TESPİTİ

## Uygulamanın Detayları

- Bir mesaj, iletim kanalı üzerinden gizli kodla iletildiğinde genellikle bir bit dizisi olarak iletilir, yani 0 ve 1'lerden oluşur.
- İletim kanalındaki gürültü nedeniyle, iletilen mesaj bozulabilir.
- Alıcıda alınan mesaj, iletilen mesajla aynı değildir; bazı bitler değiştirilmiş olabilir.
- İletilen mesajın geçerliliğini kontrol etmek için çeşitli teknikler vardır.
- Bu tekniklerden biri, aynı mesajı iki kez iletmektir. Alıcıda, her iki mesaj kopyası bit
bit karşılaştırılır.
- Eşleşen bitler varsa, alınan mesaj hatasızdır.
Ödevde hatasız bir mesajı kontrol etmek için dizi ve sınıf yapılarının birlikte kullanıldığı bir program yazılması beklenmektedir.
Gizli kodun mesajı 0 ile 9 arasındaki rakamlarla temsil edildiği varsayılmalı  ve mesajın
maksimum uzunluğu 250 rakam olmalıdır. Ek olarak mesajın ilk sayısının mesajın uzunluğu
olduğu varsayılmalıdır.

**Örneğin gizli kod aşağıdaki gibiyse:**

```text
7 9 2 7 8 3 5 6
```

o zaman mesaj 7 rakam uzunluğundadır. Ayrıca, mesaj iki kez iletilmektedir.
Yukarıdaki mesaj şu şekilde iletilir:

```text
7 9 2 7 8 3 5 6 7 9 2 7 8 3 5 6
```

**Ödev için örnek girdi ve çıktı dosyaları:**

**Girdi:** Gizli kod ve kopyası bunları içeren bir dosyadan alınmalıdır.

**Çıktı:** Gizli kod, kopyası ve alınan kodun hatasız olduğu bilgisini aşağıdaki biçimde dosyaya yazdırılmalıdır.

| Kod Rakam | Kod Rakam Kopyası |
| --------- | ----------------- |
| 9         | 9                 |
| 2         | 2                 |
| 7         | 7                 |
| 8         | 8                 |
| 3         | 3                 |
| 5         | 5                 |
| 6         | 6                 |

Mesaj hatasız iletildi.

## Problem Analizi ve Algoritma Tasarımı

Bu uygulama sınıf yapısı kullanılarak geliştirilmelidir. Gizli
kodun ve kopyasının karşılık geldiği rakamların karşılaştırılması gerektiği
için, önce gizli kodu okuyup bir diziye kaydetmek için bir sınıf
oluşturulmalıdır. Ardından, kopyanın rakamlarını okuyup gizli kodun rakamları
ile karşılaştırma yapılmalıdır. Eşleşmeyen rakamlar için (varsa) bir hata
mesajı yazılmalıdır.

### Sınıf yapısı genel itibariyle aşağıdaki gibi olmalıdır

`CodeChecker` adında bir sınıf oluşturulmalı. Bu sınıfın içinde gizli kodu
okumak için readCode adlı bir metod ve kodları karşılaştırmak için `compareCode`
adlı başka bir metod yazılmalıdır. Diğer üye fonksiyon ve üye değişkenlerin
tanımları istenilen şekilde yapılabilir.

## Özetle Sırasıyla Yapılması Beklenenler

- Girdi ve çıktı dosyalarını açılmalıdır.
- Eğer girdi dosyası yoksa, programdan çıkılmalıdır.
- Gizli kodun uzunluğunu okunmalıdır.
- Eğer gizli kodun uzunluğu 250'den büyükse, programı sonlandırılmalıdır çünkü
  bu programda kodun maksimum uzunluğu 250'dir.
- Gizli kod okunmalı ve bir diziye kaydedilmelidir.
- Kopyanın uzunluğu okunmalıdır.
- Eğer gizli kodun ve kopyasının uzunlukları aynı ise, kodlar
  karşılaştırılmalıdır; aksi takdirde bir hata mesajı yazdırılmalıdır.
- Tüm bu işlemler, CodeChecker sınıfı aracılığıyla gerçekleştirilmelidir.
