# Sample Sketch for Wio Terminal

## ����m�F��

* Arduino IDE 1.8.13
* [Seeed SAMD Boards](https://github.com/Seeed-Studio/ArduinoCore-samd) 1.7.9


## �T���v���X�P�b�`

### �{�^��

|�X�P�b�`��|�T�v|�ǉ����C�u����|
|:--|:--|:--|
|button/button|�\������Ă��鐔�����{�^���ŃJ�E���g�A�b�v���܂��B<br>A�{�^����+1�AB�{�^����+10�AC�{�^����+100�B|-|
|button/button-acebutton|�\������Ă��鐔�����{�^���ŃJ�E���g�A�b�v�A���Z�b�g���܂��B<br>A�{�^����+1�AB�{�^����+10�AC�{�^����+100�B<br>C�{�^���������Ń��Z�b�g�B|[AceButton](https://github.com/bxparks/AceButton)|

### �f�B�X�v���C

|�X�P�b�`��|�T�v|�ǉ����C�u����|�ʐ^|
|:--|:--|:--|:--|
|display/draw-text|�f�B�X�v���C�ɕ�����\�����܂��B|-|<img src="media/1.png" height="100">|
|display/draw-text-textfont|�f�B�X�v���C�ɕ�����\�����܂��B<br>�i�e�L�X�g�t�H���g���w��j|-|<img src="media/2.png" height="100">|

### Grove

|�X�P�b�`��|�T�v|�ǉ����C�u����|�ʐ^|
|:--|:--|:--|:--|
|grove/GroveButton|�{�^���̓��͏�Ԃ��V���A�����j�^�ɕ\�����܂��B|[GroveDriverPack](https://github.com/SeeedJP/GroveDriverPack)|<img src="media/3.png" height="100">|
|grove/GroveBuzzer|1�b���Ƀu�U�[��炵�܂��B|[GroveDriverPack](https://github.com/SeeedJP/GroveDriverPack)|<img src="media/4.png" height="100">|
|grove/GroveRotaryAngle|�c�}�~�i�m�u�j�̉�]�p�x���V���A�����j�^�ɕ\�����܂��B|[GroveDriverPack](https://github.com/SeeedJP/GroveDriverPack)|<img src="media/5.png" height="100">|
|grove/GroveAccelerometer16G|�����x���V���A�����j�^�ɕ\�����܂��B|[GroveDriverPack](https://github.com/SeeedJP/GroveDriverPack)|<img src="media/6.png" height="100">|

### �l�b�g���[�N

> Wio Terminal �ɍڂ��Ă���ʐM���W���[��RTL8720DN�̃t�@�[���E�F�A���ŐV�ɂ���K�v������܂��B  
> [seeed-ambd-sdk](https://github.com/Seeed-Studio/seeed-ambd-sdk)

|�X�P�b�`��|�T�v|�ǉ����C�u����|
|:--|:--|:--|
|network/http-client||LIB1, [HttpClient](https://github.com/amcewen/HttpClient)|
|network/https-client||LIB1, [HttpClient](https://github.com/amcewen/HttpClient)|
|network/mqtt-client||LIB1, [Arduino Client for MQTT](https://github.com/knolleary/pubsubclient)|
|network/mqtts-client||LIB1, [Arduino Client for MQTT](https://github.com/knolleary/pubsubclient)|

## �ǉ����C�u����

### LIB1

* [Seeed_Arduino_FreeRTOS](https://github.com/Seeed-Studio/Seeed_Arduino_FreeRTOS)
* [esp-at-lib](https://github.com/Seeed-Studio/esp-at-lib)
* [Seeed_Arduino_atUnified](https://github.com/Seeed-Studio/Seeed_Arduino_atUnified)
* [Seeed_Arduino_atWiFi](https://github.com/Seeed-Studio/Seeed_Arduino_atWiFi)
* [Seeed_Arduino_mbedtls](https://github.com/Seeed-Studio/Seeed_Arduino_mbedtls)
* [Seeed_Arduino_atWiFiClientSecure](https://github.com/Seeed-Studio/Seeed_Arduino_atWiFiClientSecure)
