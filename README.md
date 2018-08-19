# SpeakerSwitch
Speaker Switch.

Układ pozwala przełączać zestawy głośników.
W urządzeniu wykorzystany został moduł WeMos D1 mini.
Nie we wszystkich wzmacniaczach mocy można podłączać równolegle głośniki.
Takie podłączenie zwiększa obciążenie wzmacniacza co może powodować zniekształcenia dźwięku, lub uszkodzenie wzmacniacza.
Dlatego jeśli już decydujemy się na podłączenie dodatkowych głośników, to należy zmniejszyć wysterowanie głośników.

Aby podłączyć głośniki należy odkręcić pokrywę.
Złącze na dwa kable (cztery śruby) jest do podłączenia wzmacniacza.
Należy uważać na przewody + (czerwony) i - (minus), aby nie spowodować odwrócenia faz w głośnikach, bo dźwięk może być nieprzyjemny.
Styki od lewej lewy kanał -L+ (plus czerwony), kanał prawy -R+.
Złącze na cztery kable (osiem śrub) jest do podłączenia głośników.
Styki od lewej głośniki B lewy kanał +BL-, prawy kanał +BR-, 
dalej głośniki A lewy kanał +AR-, prawy kanał +AR-.

Przy pierwszym uruchomienou należy:
1. Połączyć się z siecią WiFi SpeakerSwitch (password: 12345678).
2. W przeglądarce www wpisać http://192.168.4.1
3. Gdy strona www się uruchomi należy wybrać "Scan the WiFi Network",
4. Po krótkiej chwili na ekranie ukarze się tabela z dostępnymi sieciami WiFi.
   Należy zaznaczyć tę sieć, z którą chcemy się połączyć,
   wpisać hasło do tej sieci i wcisnąć "Connect".
5. Jeśli nie popełniłeś żadnego błędu, po krótkiej chwili na ekranie będzie komunikat, że zostałeś połączony z siecią WiFi i wyświetlony będzie adres IP naszego urządzenia w tej sieci. Należy zapamiętać ten IP - potrzebny do łączenia się z naszym urządzeniem.
6. Jeśli nie uzyskamy połączenia, czynność tę należy powtórzyć (4 i 5).
7. Po połączeniu z wybrany WiFi układ przełącza się stan STATION i po 5 minutach przestaje być widoczna sieć WiFi SpeakerSwitch. Po zerwanu połączenia z naszą siecią ponownie jest dostępny AP SpeakerSwitch.

Teraz możemy połączyć się z naszą siecią WiFi i połączyć się z urządzeniem
	http://IP  (IP naszego urządzenia).

Sterowanie głośników jest za pomocą przycisków na stronie www.

"SpeakerA - ON" (kolor czerwony) - załączone głośniki A.
"SpeakerB - ON" (kolor czerwony) - załączone głośniki B.
"SpeakersA+B - OFF" (kolor zielony) - załączone głośniki zgodnie z poprzednimi przyciskami.
"SpeakersA+B - ON" {kolor czerwony) - załączone oba zestawy głośników.

Sterowanie zdalne.
W stanie normalnym (bez zasilania) załączone są głośniki A.
http://IP/speaker/B - załącza tylko głośniki B, rozłacza pozostałe
http://IP/speaker/A - załącza tylko głośniki A. rozłącza pozostałe
http://IP/speakerAB/1 - załącza wszystkie głośniki A i B.
http://IP/speakerAB/0 - rozłącza pracę równoległą głośników, załączone głośniki A lub B 
                        zależy od stanu przełączników "SpeakerA - ON" lub "SpeakerB- ON".
                        
