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
