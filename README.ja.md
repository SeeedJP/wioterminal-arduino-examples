# Sample Sketch for Wio Terminal

## 動作確認環境

* Arduino IDE 1.8.13
* [Seeed SAMD Boards](https://github.com/Seeed-Studio/ArduinoCore-samd) 1.7.8


## サンプルスケッチ

### ディスプレイ

|スケッチ名|概要|追加ライブラリ|
|:--|:--|:--|
|display/draw-text|ディスプレイに文字を表示します。|-|
|display/draw-text-textfont|ディスプレイに文字を表示します。<br>（テキストフォントを指定）|-|

### ネットワーク

> Wio Terminal に載っている通信モジュールRTL8720DNのファームウェアを最新にする必要があります。  
> [seeed-ambd-sdk](https://github.com/Seeed-Studio/seeed-ambd-sdk)

|スケッチ名|概要|追加ライブラリ|
|:--|:--|:--|
|network/http-client||LIB1,LIB2|
|network/https-client||LIB1,LIB2|
|network/mqtt-client||LIB1,LIB3|
|network/mqtts-client||LIB1,LIB3|

## 追加ライブラリ

* (LIB1) [Seeed_Arduino_FreeRTOS](https://github.com/Seeed-Studio/Seeed_Arduino_FreeRTOS)
* (LIB1) [esp-at-lib](https://github.com/Seeed-Studio/esp-at-lib)
* (LIB1) [Seeed_Arduino_atUnified](https://github.com/Seeed-Studio/Seeed_Arduino_atUnified)
* (LIB1) [Seeed_Arduino_atWiFi](https://github.com/Seeed-Studio/Seeed_Arduino_atWiFi)
* (LIB1) [Seeed_Arduino_mbedtls](https://github.com/Seeed-Studio/Seeed_Arduino_mbedtls)
* (LIB1) [Seeed_Arduino_atWiFiClientSecure](https://github.com/Seeed-Studio/Seeed_Arduino_atWiFiClientSecure)
* (LIB2) [HttpClient](https://github.com/amcewen/HttpClient)
* (LIB3) [Arduino Client for MQTT](https://github.com/SeeedJP/pubsubclient)
