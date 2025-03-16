# hastane.islevleri
# Acil Servis Hasta Takip Sistemi (C Programlama)

Bu proje, bir hastanenin acil servisinde hasta kayıtlarını takip eden basit bir **C dili** uygulamasıdır. Program, hastaları kaydeder, listeleyebilir ve **HL7 formatında** veri oluşturur.

## ✨ **Özellikler**
- ➕ **Hasta ekleme** (İsim, yaş, cinsiyet, öncelik, reçete numarası)
- 📝 **Hasta listeleme** (Öncelik sırasına göre düzenlenmemiş)
- 🔢 **HL7 formatında veri çıkışı**
- ⭐ **Kullanıcı dostu menü sistemi**
- ❌ **Hasta kaydı sınırı (Maksimum 100 hasta)**

## 📚 **Kullanım Kılavuzu**
### **1. Derleme ve Çalıştırma**
Aşağıdaki komutları kullanarak programı derleyip çalıştırabilirsiniz:
```sh
gcc emergency_system.c -o emergency_system
./emergency_system
```
### **2. Menü Seçenekleri**
Program çalıştırıldığında aşağıdaki menü görüntülenir:
```
Acil Servis Sistemi
1. Hasta Ekle
2. Hasta Listele
3. Cikis
Seciminiz:
```
- **1:** Yeni bir hasta eklemek için kullanılır.
- **2:** Kayıtlı hastaları listelemek için kullanılır.
- **3:** Programdan çıkış yapar.

## 📝 **HL7 Formatı Örneği**
Hasta eklendiğinde aşağıdaki formatta kayıt oluşturulur:
```
MSH|^~\&|ACIL|HOSPITAL|||
PID|1|Ahmet|45|Erkek|1|1000
```
Bu veri HL7 sağlık bilgi sistemleri ile uyumludur.

## 🚀 **Geliştirme Önerileri**
- Hastaları **öncelik sırasına göre** listeleme
- **Hasta silme** işlemi ekleme
- **Dosyaya kayıt** ekleyerek verileri kalıcı hale getirme
- **Hasta bilgilerini güncelleme** seçeneği ekleme

## ✨ **Lisans**
Bu proje açık kaynaklıdır ve MIT lisansı ile sunulmaktadır.




# Acil Servis Hasta Takip Sistemi - Proje Analiz Dökümanı

## 1️⃣ **Proje Tanımı**
Bu proje, bir hastanenin **acil servisinde hasta kayıtlarını** yöneten basit bir **C programıdır**. Kullanıcılar hasta ekleyebilir, hastaları listeleyebilir ve hastaların bilgilerini **HL7 formatında** alabilir.

## 2️⃣ **Sistem Akışı & Çalışma Mantığı**

### **2.1. Genel Akış Şeması**
1. **Başlangıç:** Program çalıştırılır.
2. **Ana Menü Gösterilir:** Kullanıcıdan seçim yapması istenir.
3. **Hasta Ekleme Seçildiğinde:** 
   - Kullanıcıdan **hasta bilgileri** alınır.
   - Sistem, hastaya **benzersiz bir ID ve reçete numarası** atar.
   - Hasta bilgileri **HL7 formatında** oluşturulur ve kayıt edilir.
4. **Hasta Listeleme Seçildiğinde:**
   - Kayıtlı hastalar listelenir.
5. **Çıkış Seçildiğinde:** Program sonlandırılır.

### **2.2. Akış Şemaları**
#### **Hasta Ekleme Akış Şeması**
1️⃣ Kullanıcı "Hasta Ekle" seçeneğini seçer.  
2️⃣ Program, kullanıcıdan **isim, yaş, cinsiyet ve öncelik** bilgilerini alır.  
3️⃣ **Reçete numarası otomatik atanır**.  
4️⃣ Hasta, **hastalar dizisine** eklenir.  
5️⃣ HL7 formatında veri oluşturulur.  
6️⃣ İşlem tamamlandı mesajı verilir.  
7️⃣ Ana menüye dönülür.  

#### **Hasta Listeleme Akış Şeması**
1️⃣ Kullanıcı "Hasta Listele" seçeneğini seçer.  
2️⃣ Eğer kayıtlı hasta yoksa, "Listelenecek hasta yok!" mesajı gösterilir.  
3️⃣ Hasta varsa, **ID, isim, yaş, cinsiyet, öncelik ve reçete no** bilgileri ekrana yazdırılır.  
4️⃣ Ana menüye dönülür.  

## 3️⃣ **HL7 Formatı**
Sistemde hasta kaydı **HL7 (Health Level Seven)** formatında tutulur. **Örnek HL7 mesajı:**
```
MSH|^~\&|ACIL|HOSPITAL|||
PID|1|Ahmet|45|Erkek|1|1000
```
- **MSH (Message Header)**: HL7 mesajının başlangıç kısmıdır.
- **PID (Patient Identification)**: Hasta bilgilerini içeren kısımdır.

## 4️⃣ **Veri Yapısı & Fonksiyonlar**
### **4.1. Veri Yapısı**
```c
typedef struct {
    int id;
    char isim[50];
    int yas;
    char cinsiyet[10];
    int oncelik; // 1: Yuksek, 2: Orta, 3: Dusuk
    int recete_no;
} Hasta;
```
- **id**: Hastaya atanan benzersiz kimlik numarası.
- **isim**: Hastanın adı.
- **yas**: Hastanın yaşı.
- **cinsiyet**: Hastanın cinsiyeti.
- **oncelik**: Aciliyet sırası (**1 = Yüksek, 2 = Orta, 3 = Düşük**).
- **recete_no**: Otomatik oluşturulan reçete numarası.

### **4.2. Kullanılan Fonksiyonlar**
| Fonksiyon | Açıklama |
|-----------|----------|
| `void hasta_ekle()` | Kullanıcıdan hasta bilgilerini alır, HL7 formatında kayıt oluşturur. |
| `void hasta_listele()` | Kayıtlı hastaları listeler. |
| `void menu()` | Ana menüyü yönetir. |
| `int main()` | Programın çalışmasını başlatır. |

## 5️⃣ **Geliştirme Önerileri**
- **Öncelik sırasına göre listeleme** eklenebilir.
- **Dosyaya kayıt** yapılarak hasta bilgileri saklanabilir.
- **Hasta silme ve güncelleme** fonksiyonları eklenebilir.
- **Grafiksel arayüz (GUI)** desteği eklenebilir.

---
**Bu proje, temel acil servis hasta yönetim sisteminin çalışma mantığını anlamak için geliştirilmiştir.** 🚑

