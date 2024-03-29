# Operations with large numbers in C language

#### Bilgisayar programlamada kullanılacak olan veri tipi tam sayı olduğu zaman derleyicinin tanıdığı veri boyutu ile sınırlı sayılarla işlem yapılabilmektedir. Diğer bir deyişle sayının basamak sayısı sınırlı olacaktır. Kullanılacak tamsayıların basamak sayısının çok büyük olduğu zaman derleyici tarafından tanımlanan tamsayı tipleri kullanmak sınırlama getireceğinden bunun yerine karakter dizisi(char array) kullanılabilir. Örneğin,

**Birinci sayı: 9056473829012043267 sayısı dizide:**

![](https://i.imgur.com/tMM7tLD.png)

#### şeklinde tutulur.

**İkinci sayı: 6000365738911023 sayısı dizide:**

![](https://i.imgur.com/RC57Fp8.png)

#### şeklinde tutulur. Sayılar eşit basamaklı olmak zorunda değildir.

**Toplam Sonuç sayısı: 9062474194750954290 sayısı ise dizide:**

![](https://i.imgur.com/e4cYobs.png)

**şeklinde tutulur.**

### Bu uygulamada ise bilgisayar programı iki tane sayıyı kullanıcıdan aldıktan sonra bu şekilde dizide tutacaktır. Aynı zamanda her sayının kaç basamaklı olacağı da kullanıcıdan alınıyor. Kullanıcının tercihine göre üç işlemden birini yapıp sonucu hem dizide tutup hem de ekrana yazdıracaktır.

-  Toplama
-  Çıkarma
-  Çarpma
