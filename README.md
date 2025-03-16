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


