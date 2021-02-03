# Müzik Çalar Uygulaması



Bu proje C dilinde yazılıp amaç olarak veri yapılarının gerçek hayatta kullanımını göstermeyi ve uygulanmasını amaçlamaktadır.



Geliştirmiş olduğum proje eskilerden kullanmış olduğumuz MP3 çaların bilgisayar üzerindeki halini temsil etmektedir. Girdi dosyasındaki komutları okur ve okunan komutlara göre işlemleri gerçekleştirerek çıktı dosyasında gereken kayıtları düşmektedir.

Müzik Çalar uygulamamız şu işlevleri yerine getirebilmektedir.

* Müzik listesinin başına veya sonuna bir müzik ekleyebilme
* Müzik listesinde bulunan bir müziğin pozisyonunu istediğimiz konuma getirebilme
* Müzik listesinde çalmakta olan müzikten önceki veya sonraki müziği çalabilme
* Müzik listesinin yönünü tersine çevirebilme
* Müzik listesindeki müziklerin isimlerini yazdırabilme
* Müzik listesinde bulunan bir müziği silebilme

fonksiyonlarına sahiptir.



## Kullanım Kılavuzu



> Müzik Ekleme

````c
InsertSong <tab> KONUM <tab> MUZIK_ADI
````

Yukarıdaki formatta yazılan müzik ekleme komutu iki tip parametre içermektedir:

* H   --> Müzik listesinin başına bir müzik ekler
* T   --> Müzik listenin sonuna müzik ekler

input.txt komut dosyasının içerisine eklediğiniz bu komut ile müzik listenize yeni bir müzik eklemiş olursunuz.(InsertSong<tab>H<tab>Song_A)

InsertSong komutu çıktı dosyasına herhangi bir kayıt eklemez (output.txt)



> Müzik Silme

````c
RemoveSong <tab> MUZIK_ADI
````

Yukarıdaki formatta yazılan müzik silme komutu tek parametre içermektedir:

* MUZIK_ADI   -->  Listede bulunan bir müziğin adı

input.txt komut dosyasının içerisine eklediğiniz bu komut ile müzik listenizdeki bir müziği silebilirsiniz.(RemoveSong<tab>Song_A)



![UYARI !](https://img.icons8.com/emoji/48/000000/warning-emoji.png)  Çalmakta olan bir müzik silinmek istendiğinde çıktı dosyasına 'Cannot Remove The Playing Song' ifadesini ekler.




> Müzik Listesini Görüntüleme

````c
printPlayList <tab> YON
````

Yukarıdaki formatta yazılan çalma listesini görüntüleme komutu tek parametre içermektedir. Yazdırılacak müzik listesinin hangi yönde yazdırılacağını belirtir.

* F   -->   Çalma listesinin baştan sona doğru yazılmasını sağlar.
* R   -->   Çalma listesinin sondan başa doğru(ters) yazılmasını sağlar.

input.txt komut dosyasının içerisine eklediğiniz bu komut ile müzik listesini istediğiniz yönde görüntüleyebilirsiniz.(printPlayList<tab>YON)



![UYARI !](https://img.icons8.com/emoji/48/000000/warning-emoji.png) Müzik listesinde müzik bulunmuyorsa çıktı(output.txt) dosyasına 'No Songs To Print' ifadesini ekler




> Müzik Çalma

````c
PlaySong <tab> YON
````

Yukarıdaki formatta yazılan müzik çalma komutu tek parametre içermektedir. Çalınacak müziğin yönü parametre olarak verilir.

* N    -->  Şu an çalan müziğin önündeki (bir sonraki) müziği çalmaya başlar.
* P     -->  Şu an çalan müziğin öncesindeki (bir önceki) müziği çalmaya başlar.



![Hatırlatma :](https://img.icons8.com/ios-glyphs/30/000000/ipod-old.png) Müzik listesinin sonuna gelindiğinde bir sonraki müzik çalınmak istenirse, liste başa dönerek ilk müzik çalınmaya başlar.<br/>Aynı şekilde baştaki müzik çalmaya devam ederken bir önceki müzik çalınmak istenirse liste sona döner ve sondaki müzik çalmaya başlar.

![UYARI !](https://img.icons8.com/emoji/48/000000/warning-emoji.png) Müzik listesinde müzik bulunmuyorsa çıktı(output.txt) dosyasına 'No Songs To Play' ifadesini ekler




> Müzik Listesini Tersine Çevirme

````c
ReversePlaylist
````

Yukarıdaki formatta yazılan listeyi ters çevirme komutu parametre içermemektedir. Bu şekilde kullanıldığında müzik listesi ters yönde çalmaya çalmaya devam edecektir.

![Hatırlatma :](https://img.icons8.com/ios-glyphs/30/000000/ipod-old.png) Çalmakta olan bir müzik olduğu sırada müzik listesi ters çevrilmek istenirse müzik çalmaya devam edecektir. Bir sonraki çalacak müzik yeni konumuna göre(ters) çalacaktır.



ReversePlaylist komutu çıktı dosyasına herhangi bir kayıt eklemez (output.txt)



> Müziğin Konumunu Değiştirme

````
MoveSong <tab> KONUM <tab> HEDEF <tab> REFERANS
````

 Yukarıdaki formatta yazılan müziğin konumunu değiştirme komutu üç parametre içermektedir. KONUM parametresi, 'HEDEF' müziğin 'REFERANS' müziğin önüne veya arkasına yerleştirileceğini belirler. HEDEF parametresi, konumu değiştirilecek müziğin adını belirtir. REFERANS parametresi, konumu değişecek müziğin hangi müziğe göre ayarlanacağını belirler. KONUM parametresi iki farklı değer alır : 

* B   -->  Mevcut konumu güncellenecek müziğin referans müziğin öncesine(arkasına) konumlanmasını sağlar.
* A   -->  Mevcut konumu güncellenecek müziğin referans müziğin sonrasına(önüne) konumlanmasını sağlar.

MoveSong  komutu çıktı dosyasına herhangi bir kayıt eklemez (output.txt)



#### Projenin Çalıştırılması

Proje standart C kütüphaneleri kullanılarak yazılmıştır. Bir IDE üzerinden veya direkt olarak komut sistemi üzerinden projeyi çalıştırabilirsiniz.

input.txt dosyasına gerçekleştirmek istediğiniz komutları yazarak projeyi kolay bir şekilde kullanabilirsiniz.



## Katılımcılar

* Emirhan KIRAN  - [Emir KIRAN](https://www.linkedin.com/in/emir-kiran/)



