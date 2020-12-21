#include"libOne.h"
//頂点位置の構造体
struct POS {
    float x, y, z;
};
//ゲームメイン
void gmain() {
    window(1000, 1000);
    //頂点の数
    const int num = 8;
    //元の頂点位置（実行中も保持されている）
    struct POS op[num] = {
        -1,1,-1,
        -1,-1,-1,
        1,-1,-1,
        1,1,-1,
        -1,1,1,
        -1,-1,1,
        1,-1,1,
        1,1,1,
    };
    //変更後の頂点位置の入れ物（ループするたびに変化する）
    struct POS p[num];
    //元の頂点位置を回転させる角度
    float deg = 0;
    angleMode(DEGREES);
    //このstateが0の時Y軸、1の時X軸回転する
    int state = 0;
    //メインループ
    while (notQuit) {
        //あらかじめsin,cosを計算しておく
        float s = sin(deg);
        float c = cos(deg);
        deg++;
        //stateの変更
        if (deg > 360) {
            deg = 0;
            ++state %= 2;
        }
        //配列opの座標を変換して配列pに書き込む
        // ( 配列opの位置は変わらない )
        for (int i = 0; i < num; i++) {
            //回転
            if (state == 0) {
                p[i].x = op[i].x * c + op[i].z * -s;
                p[i].y = op[i].y;
                p[i].z = op[i].x * s + op[i].z * c;
            }
            else {
                p[i].x = op[i].x;
                p[i].y = op[i].y * c + op[i].z * -s;
                p[i].z = op[i].y * s + op[i].z * c;
            }
            //奥に移動
            p[i].z += 5;
            //遠くの座標を小さくする
            p[i].x /= p[i].z;
            p[i].y /= p[i].z;
        }
        //頂点位置を線で結び立方体にする
        clear(0);
        mathAxis(0.5);//クリア色と同じで軸は見えないが必要な命令
        stroke(160, 200, 255);
        strokeWeight(10);
        for (int i = 0; i < 4; i++) {
            int j = (i + 1) % 4;
            //手前の四角形の線
            mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
            //奥の四角形の線
            mathLine(p[i+4].x, p[i+4].y, p[j+4].x, p[j+4].y);
            //前後を結ぶ線
            mathLine(p[i].x, p[i].y, p[i+4].x, p[i+4].y);
        }
    }
}
















//#define C
#ifdef C
#include"libOne.h"
void gmain() {
    window(1000, 1000);
    angleMode(RADIANS);
    let rad = -3.141592f * 2;
    let x,y;
    while (notQuit) {
        rad += 0.05f;
        if (rad > 3.141592f * 2) {
            rad = -rad;
        }
        x = cos(rad);
        y = sin(rad);
        clear(0);
        mathAxis(3.141592f*2,255);
        strokeWeight(20);
        stroke(255,160,160);
        mathPoint(rad, x);
        stroke(160, 160, 255);
        mathPoint(rad, y);

        textSize(50);
        let line = 1;
        text(rad, 0, 60*line++);
        text(y, 0, 60*line++);
        
    }
}
#endif
#ifdef B

#include"libOne.h"
#include<time.h>

time_t timer; 
struct tm local;
int hour, minute, second;

void gmain() {
    window(1080, 1080, 1);
    let x, y, deg = 0;
    angleMode(DEGREES);
    while (notQuit) {
        timer = time(NULL);/* 現在時刻を取得 */
        localtime_s(&local,&timer);/* 地方時に変換 */
        hour = local.tm_hour;
        minute = local.tm_min;
        second = local.tm_sec;

        fill(0);
        strokeWeight(0);
        rect(0, 0, width, height);
        
        mathAxis(1.8);

        fill(160);
        strokeWeight(0);
        mathCircle(0, 0, 2.6);

        //colorMode(HSV);
        //strokeWeight(60);
        //for (int i = 0; i < 360; i++) {
        //    stroke(i,255,255);
        //    mathPoint(sin(i)*0.5, cos(i)*0.5);
        //}
        //colorMode(RGB);

        deg = (hour * 30) +30* (minute / 60.0f);
        x = sin(deg)*0.7;
        y = cos(deg)*0.7;
        strokeWeight(25);
        stroke(0);
        mathLine(0, 0, x, y);

        deg = minute * 6;
        x = sin(deg);
        y = cos(deg);
        strokeWeight(25);
        stroke(0);
        mathLine(0, 0, x, y);

        deg = second * 6;
        x = sin(deg);
        y = cos(deg);
        strokeWeight(5);
        stroke(90);
        mathLine(0, 0, x, y);


        strokeWeight(30);
        stroke(90);
        mathPoint(0, 0);



    }
}
#endif
#ifdef A
#include"libOne.h"
void gmain() {
    window(1000, 1000);
    let deg = 0;
    let x, y, r;
    angleMode(DEGREES);
    while (notQuit) {
        //角度degを決定
        if (isTrigger(KEY_SPACE))deg = 0;
        if (isTrigger(KEY_D))deg += 30;
        if (isTrigger(KEY_A))deg -= 30;
        if (isPress(KEY_W))deg += 1;
        if (isPress(KEY_S))deg -= 1;
        //原点から引いた長さ１の線を
        //deg度回転させたときのx、yを求める
        x = cos(deg);
        y = sin(deg);
        //線の長さrを求めて、１かどうか確認する
        r = sqrt(x * x + y * y);

        //クリアして軸を描画
        clear(128);
        mathAxis(1.2, 255);
        //線の太さ
        strokeWeight(10);
        //斜辺（長さ１の線）
        stroke(160, 200, 255);
        mathLine(0, 0, x, y);
        //底辺
        stroke(255, 255, 200);
        mathLine(0, 0, x, 0);
        //高さ
        stroke(255, 200, 200);
        mathLine(x, 0, x, y);

        //テキスト情報
        textSize(40);
        fill(255, 255, 200);
        text("底辺=cos(" + deg + ")=" + x, 0, 60);
        fill(255, 200, 200);
        text("高さ=sin(" + deg + ")=" + y, 0, 120);
        fill(160, 200, 255);
        text("斜辺(半径)=" + r, 0, 180);
    }
}
#endif