# CSE102 Assignment 11 – Wizard War EN/TR

\<p align="center"\>
\<img src="[https://img.shields.io/badge/Language-C-blue.svg](https://img.shields.io/badge/Language-C-blue.svg)" alt="C Language"\>
\<img src="[https://img.shields.io/badge/Status-Completed-brightgreen.svg](https://img.shields.io/badge/Status-Completed-brightgreen.svg)" alt="Project Status"\>
\<img src="[https://img.shields.io/badge/License-MIT-blue.svg](https://img.shields.io/badge/License-MIT-blue.svg)" alt="License"\>
\</p\>

## English Description

This project is a C implementation of a turn-based "Wizard War" duel, developed for Gebze Technical University's CSE102 Computer Programming course (Assignment 11). Two wizards engage in a mystical duel using elemental spells, taking turns casting spells or meditating to recover mana. The battle continues recursively until one wizard is defeated. After the duel, each wizard's performance score is calculated using a recursive function based on their actions.

### Features

  * **Wizard and Spell Structures:** Uses `struct` for both Wizard and Spell entities to manage their attributes.
  * **Recursive Duel Logic:** The core `duel()` function is implemented recursively, handling turns, spell casting, mana recovery, and win conditions.
  * **Dynamic Spell Selection:** Wizards are initialized with 3 randomly selected spells loaded from `spellbook.txt`.
  * **Mana Management:** Wizards recover mana by meditating if their current mana is insufficient for a spell.
  * **Damage Calculation:** Spell damage and mana costs are randomized within defined ranges.
  * **Magic Class Bonus:** A +5 bonus damage is applied if the caster's magic class matches the spell's class.
  * **Recursive Score Calculation:** A `calculate_score()` function recursively computes each wizard's performance based on total damage dealt, total mana spent, and recoveries.
  * **Battle Statistics:** Tracks total damage dealt, total mana spent, and number of recoveries for each wizard.
  * **File I/O:** Loads spell data from `spellbook.txt`.

### `spellbook.txt` Format

The `spellbook.txt` file should contain spell data, with each spell on a new line. The format for each line is: `Name,Class,MinDamage,MaxDamage,MinMana,MaxMana`.
**Example `spellbook.txt` (only Fire and Ice spells):**

```
Fireball,fire,10,25,10,15
Inferno,fire,15,30,15,20
Flame_Surge,fire,12,22,12,18
Ice_Shard,ice,8,20,9,14
Freeze,ice,12,25,11,16
Blizzard,ice,18,35,18,25
```

### How to Compile and Run

To compile and run this program, you will need a C compiler (like GCC).

1.  **Save the code:** Save your C code as `wizard.c`. Ensure `spellbook.txt` is in the same directory.
2.  **Compile:** Open your terminal or command prompt, navigate to the directory where you saved the files, and compile using the following command:
    gcc --ansi wizard.c -o wizard_war

    *(Note: The assignment specifically requests `--ansi`.)*
3.  **Run:** Execute the compiled program:
    ./wizard_war

### Example Input/Output (Conceptual)

The program will prompt the user to enter names and magic classes for two wizards. The duel will then proceed, showing spell casts, damage, HP, mana updates, and recovery messages. Finally, it's going to declare the winner and display a battle summary with performance scores. An example output format is provided in the assignment description.

-----

## Türkçe Açıklama

Bu proje, Gebze Teknik Üniversitesi'nin CSE102 Bilgisayar Programlama dersi (Ödev 11) için geliştirilmiş, sıra tabanlı bir "Büyücü Savaşı" düello oyununun C dilinde bir uygulamasıdır. İki büyücü, temel büyüler kullanarak mistik bir düelloya girer, büyü yapmak veya mana yenilemek için sırayla hamle yaparlar. Savaş, bir büyücü yenilene kadar özyinelemeli olarak devam eder. Düellodan sonra, her büyücünün performans puanı, eylemlerine göre özyinelemeli bir fonksiyon kullanılarak hesaplanır.

### Özellikler

  * **Büyücü ve Büyü Yapıları:** Hem Büyücü hem de Büyü varlıklarının özelliklerini yönetmek için `struct` yapıları kullanılır.
  * **Özyinelemeli Düello Mantığı:** Çekirdek `duel()` fonksiyonu, sıraları, büyü yapmayı, mana yenilemeyi ve kazanma koşullarını işleyen özyinelemeli olarak uygulanmıştır.
  * **Dinamik Büyü Seçimi:** Büyücüler, `spellbook.txt` dosyasından yüklenen rastgele seçilen 3 büyü ile başlatılır.
  * **Mana Yönetimi:** Büyücüler, mevcut manaları bir büyü için yetersizse meditasyon yaparak mana yenilerler.
  * **Hasar Hesaplama:** Büyü hasarı ve mana maliyetleri, tanımlanmış aralıklar içinde rastgele belirlenir.
  * **Büyü Sınıfı Bonusu:** Büyücünün büyü sınıfı, büyünün sınıfıyla eşleşirse +5 bonus hasar uygulanır.
  * **Özyinelemeli Puan Hesaplama:** Bir `calculate_score()` fonksiyonu, her büyücünün toplam verilen hasar, harcanan toplam mana ve iyileşme sayılarına göre performansını özyinelemeli olarak hesaplar.
  * **Savaş İstatistikleri:** Her büyücü için verilen toplam hasarı, harcanan toplam manayı ve iyileşme sayısını takip eder.
  * **Dosya I/O:** Büyü verilerini `spellbook.txt` dosyasından yükler.

### `spellbook.txt` Formatı

`spellbook.txt` dosyası, büyü verilerini her satırda yeni bir büyü olacak şekilde içermelidir. Her satırın formatı şöyledir: `Ad,Sınıf,MinHasar,MaxHasar,MinMana,MaxMana`.
**Örnek `spellbook.txt` (sadece Ateş ve Buz büyüleri):**

```
Fireball,fire,10,25,10,15
Inferno,fire,15,30,15,20
Flame_Surge,fire,12,22,12,18
Ice_Shard,ice,8,20,9,14
Freeze,ice,12,25,11,16
Blizzard,ice,18,35,18,25
```

### Derleme ve Çalıştırma

Bu programı derlemek ve çalıştırmak için bir C derleyicisine (örn. GCC) ihtiyacınız olacaktır.

1.  **Kodu Kaydet:** C kodunuzu `wizard.c` olarak kaydedin. `spellbook.txt` dosyasının da aynı dizinde olduğundan emin olun.
2.  **Derle:** Terminalinizi veya komut istemcinizi açın, dosyaları kaydettiğiniz dizine gidin ve aşağıdaki komutu kullanarak derleyin:
    ```bash
    gcc --ansi wizard.c -o wizard_war
    ```
    *(Not: Ödev özellikle `--ansi` kullanılmasını istemektedir.)*
3.  **Çalıştır:** Derlenmiş programı çalıştırın:
    ```bash
    ./wizard_war
    ```

### Örnek Giriş/Çıkış (Kavramsal)

Program, kullanıcıdan iki büyücünün adını ve büyü sınıfını girmesini isteyecektir. Düello daha sonra, büyü yapma, hasar, Can Puanı (HP), mana güncellemeleri ve iyileşme mesajları gösterilerek ilerleyecektir. Son olarak, kazananı ilan edecek ve performans puanlarıyla birlikte bir savaş özetini gösterecektir. Ödev açıklamasında bir örnek çıktı formatı sağlanmıştır.

-----
