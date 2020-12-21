#include"libOne.h"
//���_�ʒu�̍\����
struct POS {
    float x, y, z;
};
//�Q�[�����C��
void gmain() {
    window(1000, 1000);
    //���_�̐�
    const int num = 8;
    //���̒��_�ʒu�i���s�����ێ�����Ă���j
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
    //�ύX��̒��_�ʒu�̓��ꕨ�i���[�v���邽�тɕω�����j
    struct POS p[num];
    //���̒��_�ʒu����]������p�x
    float deg = 0;
    angleMode(DEGREES);
    //����state��0�̎�Y���A1�̎�X����]����
    int state = 0;
    //���C�����[�v
    while (notQuit) {
        //���炩����sin,cos���v�Z���Ă���
        float s = sin(deg);
        float c = cos(deg);
        deg++;
        //state�̕ύX
        if (deg > 360) {
            deg = 0;
            ++state %= 2;
        }
        //�z��op�̍��W��ϊ����Ĕz��p�ɏ�������
        // ( �z��op�̈ʒu�͕ς��Ȃ� )
        for (int i = 0; i < num; i++) {
            //��]
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
            //���Ɉړ�
            p[i].z += 5;
            //�����̍��W������������
            p[i].x /= p[i].z;
            p[i].y /= p[i].z;
        }
        //���_�ʒu����Ō��ї����̂ɂ���
        clear(0);
        mathAxis(0.5);//�N���A�F�Ɠ����Ŏ��͌����Ȃ����K�v�Ȗ���
        stroke(160, 200, 255);
        strokeWeight(10);
        for (int i = 0; i < 4; i++) {
            int j = (i + 1) % 4;
            //��O�̎l�p�`�̐�
            mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
            //���̎l�p�`�̐�
            mathLine(p[i+4].x, p[i+4].y, p[j+4].x, p[j+4].y);
            //�O������Ԑ�
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
        timer = time(NULL);/* ���ݎ������擾 */
        localtime_s(&local,&timer);/* �n�����ɕϊ� */
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
        //�p�xdeg������
        if (isTrigger(KEY_SPACE))deg = 0;
        if (isTrigger(KEY_D))deg += 30;
        if (isTrigger(KEY_A))deg -= 30;
        if (isPress(KEY_W))deg += 1;
        if (isPress(KEY_S))deg -= 1;
        //���_��������������P�̐���
        //deg�x��]�������Ƃ���x�Ay�����߂�
        x = cos(deg);
        y = sin(deg);
        //���̒���r�����߂āA�P���ǂ����m�F����
        r = sqrt(x * x + y * y);

        //�N���A���Ď���`��
        clear(128);
        mathAxis(1.2, 255);
        //���̑���
        strokeWeight(10);
        //�ΕӁi�����P�̐��j
        stroke(160, 200, 255);
        mathLine(0, 0, x, y);
        //���
        stroke(255, 255, 200);
        mathLine(0, 0, x, 0);
        //����
        stroke(255, 200, 200);
        mathLine(x, 0, x, y);

        //�e�L�X�g���
        textSize(40);
        fill(255, 255, 200);
        text("���=cos(" + deg + ")=" + x, 0, 60);
        fill(255, 200, 200);
        text("����=sin(" + deg + ")=" + y, 0, 120);
        fill(160, 200, 255);
        text("�Ε�(���a)=" + r, 0, 180);
    }
}
#endif