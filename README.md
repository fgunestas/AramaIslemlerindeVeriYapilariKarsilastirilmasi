## EksikElemaniBul
#Veri yapıları dersi proje ödevi.# 
</br>Furkan Güneştaş ve Esra Türkel in yaptığı veri yapıları projesidir.

**Problem Tanımı: 1 den n sayısına kadar karışık dağıtılmış sayı grubunda eksik olan sayıyı bulan fonksiyon.**


**1. Çözüm : Basit for döngüsü ile eksik sayıyı bulma.**
```
int bfSearch(int arry[8],int n)
```
**Fonksiyona gönderilen `arry` integer array verisi ve dizinin içindeki eleman sayısı olan `n` ile çalıştırıldığında dizide olmayan sayıyı integer olarak geri döndürür.**

2. Çözüm : Bağlı liste veri yapısı ile eksik sayıyı bulma.
```
int bagliListeArama(NODEPTR bl, int n)
```
**Fonksiyona gönderilen `bl` bağlı liste veri yapısı ve `n` bağlı listede bulunan eleman sayısına karşılık olarak eksik sayıyı integer olarak geri döndürür.**

3. Çözüm : İkili ağaç veri yapısı ile eksik sayıyı bulma. 
```
int treeeSearch(BTNODEPTR root, int n)
```
**Fonksiyon gönderilen `root` isimli ikili ağaç kökü ve `n` sayısı ile eksik sayıyı bulup geri döndüren fonksiyodur.**
