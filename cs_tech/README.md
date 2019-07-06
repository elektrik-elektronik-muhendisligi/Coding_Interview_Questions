# Coding_Interview_Questions
## Sayı - Tahmin (CS-TECH) --> Kullanım Bilgisi
### Amaç

Bilgisayar ve kullanıcı arasında karşılıklı olarak yapılan tahminler ve bu tahminlere verilen ipuçları ile birlikte oyun hazırlanması amaçlanmaktadır.

### Kullanım

Yazılım ve kullanıcı bir sayı belirleyecek ve sonrasında tahminler yapılacaktır. Tahminler sonucunda tutulan sayı ile ilgili ipuçları verilecek. Eğer tahmin edilen sayı içinde tutulan sayının rakamlarından varsa ve basamak değeri doğruysa “+” değer olarak ipucu verilecek, basamak değeri yanlış ise “-” değer, eğer hiç bulunmuyorsa "0 " değeri döndürülerek ipucu olarak verilecektir. İki taraftan biri kazanana dek oyun sürecektir.

### _örnek: Bilgisayarın tuttuğu sayı 1234 olsun eğer kullanıcı 4831 tahmini yaptığında kullanıcıya ipucu olarak -101-1 değeri döndürülecektir.._

### Algoritma
1. Yazılım rakamları birbirinden  farklı 4 basamaklı bir sayı tutar
2. Kullanıcı rakamları birbirinden farklı 4  basamaklı bir sayı tutar
3. Yazılım yada kullanıcı doğru tahmin edene kadar oyun devam eder.
4. Yanlış tahminlerde taraflara bilgi mesajı verilir.
5. Kullanıcı ve yazılım karşılıklı tahminlerde bulunurken yazılım bilgi mesajına göre basamaklara müdahale eder veya etmez. Örneğin basamak karşılaştırma değeri 1 ise müdahale etmez, -1 ise basamakları karşılaştırıp doğru basamağı arar, 0 ise daha önce o basamak için tahmin edilen değerler haricindeki değerleri üretir böylece optimizasyon sağlanır.
   
   

### Gerçekleme
Geliştirilecek olan yazılımla ilgili tavsiye edilen uyarıları ve önerilerin gerçeklenme durumu.
- [x] Geliştirilecek yazılım herhangi bir programlama dili (C++, Java, C# vs) ile geliştirilmesi
- [x] Geliştirilecek yazılım da hata durumlarını ele alınması
- [ ] Geliştirilecek yazılımın kullanıcı ara yüzü olması
- [x] Geliştirilecek yazılımın çoğu durumda kullanıcıdan daha başarılı olması
- [x] Geliştirilecek olan yazılımın kaynak kodlarında açıklama satırlarının olması
- [x] Geliştirilecek olan yazılımın basit kullanma ve derleme kılavuzunun olması
- [x] Geliştirilecek olan yazılımın GitHub üzerinden paylaşılması

### Sonuç
Programın örnek çıktısı aşağıdadır.

#### OYUN 1: _Yazılım_

![pc1](https://user-images.githubusercontent.com/32637622/60082392-4c925080-973c-11e9-9301-128ae01df527.PNG)

#### OYUN 2: _Yazılım_
![pc2](https://user-images.githubusercontent.com/32637622/60082487-82373980-973c-11e9-9c36-f40cad792942.PNG)

#### OYUN 3: _Yazılım_

![pc3](https://user-images.githubusercontent.com/32637622/60082493-8400fd00-973c-11e9-8d68-86af8cc2620a.PNG)

#### OYUN 4: _Yazılım_

![pc4](https://user-images.githubusercontent.com/32637622/60082494-85322a00-973c-11e9-8973-8ba732ce4837.PNG)

#### OYUN 5: _Kullanıcı_

![user1](https://user-images.githubusercontent.com/32637622/60082496-86635700-973c-11e9-8748-8275251e50e0.PNG)
![user2](https://user-images.githubusercontent.com/32637622/60082501-88c5b100-973c-11e9-8c80-0b2179072b0f.PNG)
