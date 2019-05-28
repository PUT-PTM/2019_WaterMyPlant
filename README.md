# 2019_WaterMyPlant
### Authors: 
- Krzysztof Czarnecki
- Błażej Czekała

### Overview
Automatyczne podlewanie kwiatkow w 2 doniczkach. Połączone ze stroną internetową, na ktorej użytkownicy mogą klikać na podlewanie doniczki.

### Description

### Tools
1 x STM32F411E-DISCO\
1 x esp8266\
1 x moisture sensor\
1 x water pump\
1 x relay\
3 x LED DIODE


### How to run
Aby odpalić program należy podłączyć płytkę stm do zasilania i zainstalować na niej
projekt znajdujący się w WaterMyPlant/PTM, a także podłączyć odpowiednie peryferia do pinów:

#### ESP8266
|    PIN ESP    |    PIN STM    |
| ------------- | ------------- |
| GND           |     GND       |
| VCC           |     3.3V      |
| TX            |     PA10      |
| RX            |     PD5       |

#### MOISTURE SENSOR
|    PIN SENSOR |    PIN STM    |
| ------------- | ------------- |
| GND           |     GND       |
| VCC           |     3.3V      |
| S             |     PA0       |

#### LED DIODS
|    PIN LED    |    PIN STM    |
| ------------- | ------------- |
| GND           |     GND       |
| LED1          |     PA1       |
| LED2          |     PA3       |
| LED3          |     PA5       |

#### WATER PUMP
Pompka do wody jest podłączon przy użyciu przekaźnika. Silnik jest podłączony do pinów NC (Normal Close).

|    Relay      |    PIN STM    |
| ------------- | ------------- |
| GND           |     GND       |
| VCC           |     5V        |
| IN1           |     PE11      |

### How to compile
Aby skompilować należy pobrać z repozytorium katalog WaterMyPlant i wrzucić go
do SystemWorkbench. Należy dostosować linki serwisów dla własnych potrzeb.

#### Links using by device:
- /get_state.php?flowerID - pobieranie stanu kwiata, informuje czy można podlać kwiata,
- /reset_flower.php?flowerID - aktualizuje punkty przypisane dla kwiata. Za każdą aktualizacją stanu punktów odejmowane jest 300 punktów ze zbioru punktów.

### Future improvements
1. Więcej diod wskazujących poziom nawodnienia
2. Usprawnienia na stronie i przekazywanie parametrów na stronę internetową
3. Dodanie oświetlenia roślinki

### Commands using by ESP8266
- AT -> do sprawdzania, czy ESP poprawnie działa
- AT+CWMODE=1 -> ustawia tryb ESP jako klienta
- AT+CIPMUX=1 -> ustawia tryb pracy jako wiele połączeń
- AT+CIPSTART=0,"TCP" -> ustanawia połączenie z serwerem
- AT+CIPSEND=x,y -> wysyła do wcześniej zdefiniowanego serwera żądanie.
  - x -> kanał połączenia
  - y -> długość tekstu do wysłania
  
  ##### Przykład zapytania wysyłanego przez ESP:
  AT+CIPMUX=1
  AT+CIPSTART=0,"TCP","krzysztof.r.czarnecki.student.put.poznan.pl",80
  AT+CIPSEND=0,86
  GET /get_state.php?id=1 HTTP/1.1
  Host:krzysztof.r.czarnecki.student.put.poznan.pl



### Attributions



### License


The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Marek Kraft/Michał Fularz/Tomasz Mańkowski/Adam Bondyra
