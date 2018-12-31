/*Oldukça basit bir mantığa sahip C++ ile kodlanmış sayı tahmin oyunu.
	
	Yazan: Emrecan Öksüm
	Tarihi: 30-12-2018
	Sürüm: v1.2
	
	Yazılımın mantığını kavramak isteyenlerin ve meraklısının seveceği bir yazılım.
	
	Neleri kullandık?
	
		- if-else-else if ve kıyaslama operatörleri (<,>,<=,=<,==,!=)
		- for - goto (loops)
		- C++ rastgele değer oluşturma fonksiyonları srand()->rand() için tohumlama fonksiyonu ve rand()->Rastgele sayı oluşturucu.
		- Ekrandaki yazilari temizleyen basit Windows shell fonksiyonu cls ve system()
		- Chrono kullanarak C++'da saniyelik bazda bekleme ayarlamak ve milisaniyeyi almak (C++11)
	
	NOT: Bu kod C++11 kütüphanelerini kullanmaktadır. GCC'ye -std=c++11 argümanını iletmezseniz kod çalışmaz. Bunu Bloodshed Dev-C++ (veya herhangi bir forku)
	uygulamasında Tools > Compiler options bölümünde üstteki alana ilgili argümanı girip tiki işaretleyerek yapabilirsiniz.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
using namespace std;

int main() {
	
	enbas:
	system("cls");
	int sayi,el,girdi,oyuncu1skor = 0,oyuncu2skor = 0,elSay = 1,tahminHak,kalanTahminHak,zorlukSecim;
	char sec;
	
	cout << "[===== < SAYI TAHMIN OYUNU > =====]" << endl;
	cout << "|||||||||||||||||||||||||||||||||||" << endl;
	cout << "|_________by Emrecan Oksum________|" << endl;
	cout << "\n\n";
	cout << "Emrecan Oksum'un can sikintisinin dunyaya getirdigi bu sayi tahmin yazilimina hosgeldiniz! Burada amaciniz gayet basit. Oyuncu1 bir sayi belirleyecek, Oyuncu2 belirlenen sayiyi tahmin etmeye calisacak. Ancak tahminler sinirli ve tahmin siniri asilinca oyunu oyuncu1 kazaniyor :) Kac el oynayacaginiz ise size kalmis. Eger bu oyunu beraber oynayabileceginiz bir arkadasiniz yoksa kendi bilgisayarinizin islemcisine karsi mucadele verebilirsiniz ki zaten bu uygulamayi kodlamamin asil sebebi bunu yapmak icindi :)\n" << endl;
	cout << "[OYUN AYARLAMASI] Bilgisayara karsi mucadele etmek istermisiniz? (e,H) =";
	cin >> sec; cout << "" << endl;
	if(sec == 'e') {
		
		cout << "[OYUN AYARLAMASI] Zorluk seviyenizi secin: \n\n1- Kolay\n2- Orta\n3- Zor\n\nSecim =";
		cin >> zorlukSecim; cout << "" << endl;
		if(zorlukSecim == 1) {
			
			srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
			sayi = 1 + (rand() % static_cast<int>(20 - 1 + 1));
			el = 2;
			tahminHak = 5;
			
		}else if(zorlukSecim == 2) {
			
			srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
			sayi = 10 + (rand() % static_cast<int>(50 - 10 + 1));
			el = 4;
			tahminHak = 10;
		}else{
			
			srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
			sayi = 50 + (rand() % static_cast<int>(130 - 50 + 1));
			el = 6;
			tahminHak = 15;
		}
	}else{
	
		cout << "[OYUN AYARLAMASI] Kac el oynayacaksiniz? =";
		cin >> el; cout << "" << endl;
		if(el < 2) {
			
			cout << "[HATA] Oynanacak el sayisi minimum 2 olabilir. 2 olarak ayarlanacak..." << endl;
			el = 2;
		}
		cout << "[OYUN AYARLAMASI] Oyuncu2 icin kac defa tahmin hakki taninsin? =";
		cin >> tahminHak; cout << "" << endl;
		if(tahminHak < 2) {
		
			cout << "[HATA] Tahmin hakki sayisi minimum 2 olabilir. 2 olarak ayarlanacak..." << endl;
			tahminHak = 2;
		}
	}
	basla:
	if(el < elSay) {
		
		cout << "Oyun bitti! Skorlar: " << endl;
		cout << "Oyuncu1: " << oyuncu1skor << endl;
		cout << "Oyuncu2: " << oyuncu2skor << endl;
		
		if(oyuncu1skor > oyuncu2skor) {
			
			cout << "Oyuncu1 oyunu kazandi!" << endl;
			cout << "\nTekrar oynamak istermisiniz? (e,H) =";
			cin >> sec; cout << "" << endl;
			if(sec == 'e') {
				
				goto enbas;
			}
			return 0;
		}else if(oyuncu1skor < oyuncu2skor) {
			
			cout << "Oyuncu2 oyunu kazandi!" << endl;
			cout << "\nTekrar oynamak istermisiniz? (e,H) =";
			cin >> sec; cout << "" << endl;
			if(sec == 'e') {
				
				goto enbas;
			}
			return 0;
		}else{
			
			cout << "Oyun berabere bitti kazanan yok! :)" << endl;
			cout << "\nTekrar oynamak istermisiniz? (e,H) =";
			cin >> sec; cout << "" << endl;
			if(sec == 'e') {
				
				goto enbas;
			}
			return 0;
		}
	}
	
	if(sec != 'e') {
	
		cout << "Oyun bilgisi : (" << elSay << "/" << el << ")" << endl;
		cout << "[OYUNCU 1] Sayinizi belirleyin: ";
		cin >> sayi; cout << "" << endl;
	}else if(sec == 'e'){
		
		if(zorlukSecim == 1) {
			
			srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
			sayi = 1 + (rand() % static_cast<int>(20 - 1 + 1));
			
		}else if(zorlukSecim == 2) {
			
			srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
			sayi = 10 + (rand() % static_cast<int>(50 - 10 + 1));
			
		}else{
			
			srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
			sayi = 50 + (rand() % static_cast<int>(130 - 50 + 1));
			
		}
	}
	
	system("cls");
	cout << "[===== < SAYI TAHMIN OYUNU > =====]" << endl;
	cout << "|||||||||||||||||||||||||||||||||||" << endl;
	cout << "|_________by Emrecan Oksum________|" << endl;
	cout << "\n\n";
	
	if(sec == 'e'){
	
		cout << "Bilgisayariniz sayiyi belirledi! Hadi bulmaya calisin :)" << endl;
	}else{
		
		cout << "Rakibiniz Oyuncu1 sayiyi belirledi! Hadi bulmaya calisin :)" << endl;
	}
		
	int tahminler = 0;
	kalanTahminHak = tahminHak;
	oy2bul:
	if(kalanTahminHak == 0) {
		
		system("cls");
		cout << "[===== < SAYI TAHMIN OYUNU > =====]" << endl;
		cout << "|||||||||||||||||||||||||||||||||||" << endl;
		cout << "|_________by Emrecan Oksum________|" << endl;
		cout << "\n\n";
		cout << "Oyuncu2'nin tahmin hakki sona erdi. Oyuncu1'e +2 skor yaziliyor... Lutfen bekleyin" << endl;
		oyuncu1skor = oyuncu1skor + 2;
		elSay++;
		kalanTahminHak = tahminHak;
		this_thread::sleep_for(chrono::seconds(5));
		goto basla;
	}
	girdi = 0;
	cout << "Oyun bilgisi : (" << elSay << "/" << el << ")" << endl;
	if(tahminler >= kalanTahminHak*0.5) {
		
		int asalMi = 1;
		cout << "IPUCU: Aradiginiz sayi ";
		for(int i = 2; i <= sayi; i++) {
			
			if(sayi % i == 0 && sayi != i) {
				
				cout << i << " ";
				asalMi = 0;
			}
		}
		
		if(asalMi == 0) {
		
			cout << "sayi(lari) ile tam bolunebiliyor." << endl;
		}else{
			
			cout << "bir asal sayi." << endl;
		}
	}
	cout << "[OYUNCU 2] Sayiyi bulmaya calisin: ";
	cin >> girdi; cout << "" << endl;
	
	if(girdi == sayi) {
		
		if(tahminler == 0) {
			
			oyuncu2skor = oyuncu2skor + 2;
			kalanTahminHak = tahminHak;
			cout << "Tebrikler Oyuncu2! Ilk denemede sayiyi buldunuz. Bonus olarak skorunuz 2 arttirildi. Lutfen bekleyin..." << endl;
		}else{
			
			oyuncu2skor++;
			kalanTahminHak = tahminHak;
			cout << "Oyuncu2 sayiyi buldu. Skorunuz 1 arttirildi. Lutfen bekleyin..." << endl;
		}
		
		elSay++;
		this_thread::sleep_for (chrono::seconds(5));
		goto basla;
	}else if(girdi > sayi) {
		
		kalanTahminHak--;
		cout << "Aradiginiz sayi girilenden daha kucuk! Tekrar deneyin." << endl;
		cout << "Kalan tahmin hakkiniz: " << kalanTahminHak << endl;
		tahminler++;
		goto oy2bul;
	}else if(girdi < sayi) {
		
		kalanTahminHak--;
		cout << "Aradiginiz sayi girilenden daha buyuk! Tekrar deneyin." << endl;
		cout << "Kalan tahmin hakkiniz: " << kalanTahminHak << endl;
		tahminler++;
		goto oy2bul;
	}
	
	system("cls");
	cout << "Bir cesit hata meydana gelmis olacak ki bu hatayi goruyorsunuz." << endl;
	return 0;
}
