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
