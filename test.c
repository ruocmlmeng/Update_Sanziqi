#include"game.h"
void menu()
{
    printf("*********************\n");
    printf("****1. play 0.exit***\n");
    printf("*********************\n");
}
void game()
{
    //�ж���Ϸ����ı���
    char ret = 0;
    //��������
    char board[ROW][COl] = {0};
    //�����̸�ֵΪ��
    InitBoard(board,ROW,COl);
    //��ӡ��ʼ��������
    DisplayBoard(board,ROW,COl);
    //Ȼ������������Կ�ʼ����
    while (1)
    {
        //�������
        PlayerMove(board,ROW,COl);
        //�ж���Ϸ����Ӯ
        ret = IsWin(board,ROW,COl);
        if(ret != 'C')
        {
            break;
        }
        DisplayBoard(board,ROW,COl);
        //��������
        ComputerMove(board,ROW,COl);
        //�ж���Ϸ����Ӯ
        ret = IsWin(board,ROW,COl);
        if(ret != 'C')
        {
            break;
        }
        DisplayBoard(board,ROW,COl);
    }
    if(ret == '*')
    {
        printf("���ʤ��^_^\n");
    }else if( ret == '#')
    {
        printf("����ʤ��\n");
    }else
    {
        printf("ƽ��\n");
    }
    DisplayBoard(board,ROW,COl);
}
int main(void)
{
    srand((unsigned int )time(NULL));//������������������

    int input = 0;
    do
    {   menu();
        printf("������ѡ��:>");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                // ���忪ʼ��Ϸ�ĺ���
                game();
            break;
            case 0:
                printf("�˳���Ϸ\n");
            break;
            default:
                printf("��������ַǷ�,����������\n");
            break;
        }
    } while (input);

    return 0;
}
