a3gim R4.0 リリースノート
															2016.02.29

3GIM(Ver2)に対応しました。
3GIM(Ver1/Ver1.1)をお使いになる場合には、引き続き、
R3.1の方をそのままお使いください。

R3.1からの変更点は下記の通りです。
 
以下の関数の仕様を変更しました：
  readSMS() : 最後のパラメータにスロット番号を指定可能(省略可)
  setDefaultprofile() : apn,user.passwordを直接指定するよう変更
  getDefaultprofile() : apn,user.passwordを直接取得するよう変更
 
以下の関数を新規に追加しました：
  getStatusTCP() : TCPコネクションの現在の最新状況を取得
  getLocation2() : 位置情報取得関数の増強版
  enterAT() : ATコマンドパススルーモードに入る関数
  writeBegin() : 相手先に直接iemSewrialを通じて書き込みする関数
  getResult() : private関数からpublic関数に変更
 
以下の関数を削除しました：
  put() : 3GIM(Ver2)にストレージ機能がないため提供できない
  get() : 同上
  updateProfile() : プロファイルを直接設定・取得できるために不要となった
  encryptProfile() : 同上

以下をグローバル変数として定義しました：
  a3gSerial : いくつかの機能では、このポートに対して直接読み書きする

※R4.0の改訂では、3GIM(Ver2)の機能変更により大きな仕様変更となっています。
  従来のスケッチはそのままで動作しない場合もありますが、ご了承ください。
  なお、3GIM(Ver2)の変更点に関しては、3GIM(Ver2)のマニュアルを参照ください。

--
a3gim R3.1 リリースノート
                                                            2015.03.22

3GIM(Ver1.1)でテストを行いました。

以下の2つの関数を正式にサポートしました。
　updateProfile()
　encryptProfile()

--
a3gim R3.0 リリースノート
                                                            2014.12.10

3GIM用のArduinoライブラリa3gim R3.0です。
機能的には、a3gs R3.0と同じです。


【a3gsとの差異について】

a3gimでは、電源制御とSMS受信時の割込処理のみが変更となっています。
以下、変更点を説明します：

- int start(int pin)
　　指定したpinを電源制御に使用します。
　　デフォルト(pin指定なし)では、電源制御は行いませんので
　　常にONとなります。
　　引数pinは1以上の番号を指定してください。
　　たとえば、ArduinoのD6を3GIMの1番ピンに接続した場合は、
　　　　a3gs.start(6)
　　のように呼び出してください。

- void shutdown()
　　電源制御を行っている場合、3GIMの電源をOFFにします。

- onSMSReceived()
　　3GIMではSMSを受信しても何もしません。

【a3gimライブラリの使い方】

a3gimライブラリは、Arduino UNO/Pro等で3GIMを利用するためのライブラリです。
下記の結線を行ってからご使用ください。

- Arduino D2-3,D6-13,A0-5のいずれか又は接続なし  -->  3GIM #1(PWR_SW)
- Arduino D4  -->  3GIM #3(TX)
- Arduino D5  -->  3GIM #2(RX)
- Arduino 5V  -->  3GIM #4(IOREF)
- Arduino GND -->  3GIM #6(GND)
- 3.7V電源またはリチウム電池など  --> 3GIM #5(VCC)

--
