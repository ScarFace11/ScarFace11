// ������� ������ �������, �������� �������!!! ������� ����� ���� ������ ������� ���������� ���-�� ����
// ��������� ����� ���� ������� ����� ��� ������������ ������!!
#include <iostream>

using std::cout, std::cin;



int main() {
    setlocale(0,"rus");
    srand(time(NULL));
    int player_money = 100; // ���-�� �����
    int player_put_money; // ���-�� ������������ ����� �������
    int Bot1_money = 100, Bot2_money = 100; //������ �����
    int Bot1_put_money, Bot2_put_money; // ���-�� ������������ ����� �������������
    int Bot1_card,Bot2_card, player_card; // ����� �������
    int mode; // ������� ���������
    bool player_bankrupt=false, Bot1_bankrupt=false, Bot2_bankrupt=false; // ��������

    cout << "���� ������: " << player_money << '\n'; 

    cout << "������� ������� ���������: 1) ����� 2)������� (����) 3) ������� (����) \n";
    cin >> mode;
    for (player_card; player_card != 0;) {
        switch (mode) {
        case 1:
        {
            cout << "������ ����� ������� ��������� \n";
            if (Bot1_bankrupt == false) {
                Bot1_card = 1 + rand() % 10;
                do {
                    Bot1_put_money = 1 +rand() % 20;
                } while ( Bot1_put_money >20);
                
                Bot1_money-=Bot1_put_money;
            }
            else { Bot1_card = 0;}
            if (Bot2_bankrupt == false) {
                Bot2_card = 1 + rand() % 10;
                do {
                    Bot2_put_money = 1 +rand() % 20;
                } while ( Bot2_put_money >20);
                Bot2_money-=Bot2_put_money;
            }
            else { Bot2_card = 0;}
            
            break;
        }
        default:
        {
            cout << "����� ����������� ������� ��������� \n";
            return 0;
        }
    }
    
    do {
        cout << "������� ����� ������� �� ������ ��������� �� 1 �� " << player_money << '\n';
        cin >> player_put_money;
    } while (player_put_money < 0 || player_put_money >= player_money);
    

    player_money-=player_put_money;

    if (Bot1_bankrupt == false) {
        cout << "��� 1 ��������: "<< Bot1_put_money << '\n';
    }
    if (Bot2_bankrupt == false) {
        cout << "��� 2 ��������: "<< Bot2_put_money << '\n';
    }
    

    cout << "������� ���-�� ���� ������� ������ �����: ";
    cin >> player_card;

    cout << "����� ��������: " << player_card << '\n'; 
    if (Bot1_bankrupt == false) {cout << "��� 1 ����: "<< Bot1_card << '\n';}
    if (Bot2_bankrupt == false) {cout << "��� 2 ����: "<< Bot2_card << '\n';}


    /*if (player_card > Bot1_card && player_card > Bot2_card) // ����� �������� ����
    {
        player_put_money*=2;
        player_money-=player_put_money; // ����� ����� � ����������

        Bot1_put_money*=Bot1_card;
        Bot1_money+=Bot1_put_money; // ����� ����� ������ 1 ����

        Bot2_put_money*=Bot2_card;
        Bot2_money+=Bot2_put_money; // ����� ����� ������ 2 ����

        for(player_put_money;player_put_money >0;) {
            if (Bot1_card > Bot2_card && player_put_money >0) { 
                if (player_put_money >= Bot1_card) {   // ������ ����� �������� ����� ������
                    Bot1_money+=Bot1_card;
                    player_put_money-= Bot1_card;


                    if (Bot2_card >= player_put_money) { // ���� ����������� ����� ����� ����, ������ ����� �������� �������
                        Bot2_money+=player_put_money;
                        player_put_money = 0;
                    }
                }

                if (player_put_money >= Bot2_card) { // ������ ����� �������� ����� ������
                    Bot2_money+=Bot2_card;
                    player_put_money-= Bot2_card;


                    if(Bot1_card >= player_put_money) { // ���� ����������� ����� ����� ����, ������ ����� �������� �������
                        Bot1_money+=player_put_money;
                        player_put_money = 0;
                    }
                }

            }
                
            else if (Bot2_card > Bot1_card && player_put_money >=0) { //���������� ������ �����
                if (player_put_money >= Bot2_card) {   // ������ ����� �������� ����� ������
                    Bot2_money+=Bot2_card;
                    player_put_money-= Bot2_card;


                    if (Bot1_card >= player_put_money) { // ���� ����������� ����� ����� ����, ������ ����� �������� �������
                        Bot1_money+=player_put_money;
                        player_put_money = 0;
                    }
                }

                if (player_put_money >= Bot1_card) { // ������ ����� �������� ����� ������
                    Bot1_money+=Bot1_card;
                    player_put_money-= Bot1_card;


                    if(Bot2_card >= player_put_money) { // ���� ����������� ����� ����� ����, ������ ����� �������� �������
                        Bot2_money+=player_put_money;
                        player_put_money = 0;
                    }
                }
            }
        }   
    } */
    
    if (Bot1_card > player_card && Bot1_card > Bot2_card || Bot2_card > player_card && Bot2_card > Bot1_card || player_card > Bot1_card && player_card > Bot2_card)
    {
        if (Bot1_card > player_card && Bot1_card > Bot2_card) { // ���1 �������� ����

            if (Bot1_card > player_card && Bot2_card != 0) { // ���� ���2 �� �������
                
                if (player_card>Bot2_card) { // ����� �������� ������

                    for(Bot1_put_money; Bot1_put_money >0;) { // ����� ������ ������ ��� �������� ���1
                        
                        if (player_card >= Bot1_put_money) {
                            player_money+=Bot1_put_money;
                            Bot1_put_money = 0;
                            break;
                        }
                        else if (Bot1_put_money > player_card) {
                            player_money+=player_card;
                            Bot1_put_money-=player_card;

                            if (Bot2_card >= Bot1_put_money) { // ������� ����2
                                Bot2_money+=Bot1_put_money;
                                Bot1_put_money = 0;
                                break;
                            }
                        }
                        if (Bot2_card >= Bot1_put_money) { // ����� ���� ������ ��� �������� ���1
                            Bot2_money+=Bot1_put_money;
                            Bot1_put_money = 0;
                            break;
                        }
                        else if (Bot1_put_money > Bot2_card) { //���2 ����� ������
                            Bot2_money+=Bot2_card;
                            Bot1_put_money-=Bot2_card;

                            if (player_card >= Bot1_put_money) { //������� ������
                                player_money+=Bot1_put_money;
                                Bot1_put_money = 0;
                                break;
                            } 
                        }
                    }
                }
                if (Bot2_card > player_card) { // ���2 �������� ������
                    
                    for(Bot1_put_money; Bot1_put_money >0;) {
                        
                        if (Bot2_card >= Bot1_put_money) {
                            Bot2_money+=Bot1_put_money;
                            Bot1_put_money = 0;
                            break;
                        }
                        else if (Bot1_put_money > Bot2_card) {
                            Bot2_money+=Bot2_card;
                            Bot1_put_money-=Bot2_card;

                            if (player_card >= Bot1_put_money) {
                                player_money+=Bot1_put_money;
                                Bot1_put_money = 0;
                            } 
                        }
                        if (player_card >= Bot1_put_money) {
                            player_money-=Bot1_put_money;
                            Bot1_put_money = 0;
                            break;
                        }
                        else if (Bot1_put_money > player_card) {
                            player_money+=player_card;
                            Bot1_put_money-=player_card;

                            if (Bot2_card >= Bot1_put_money) {
                                Bot2_money+=Bot1_put_money;
                                Bot1_put_money = 0;
                                break;
                            }
                        }
                    }
                }
            
                Bot1_put_money*=Bot1_card;
                Bot1_money-=Bot1_put_money; // ����� ����� ������������ ����1

                Bot2_put_money*=Bot2_card;
                Bot2_money+=Bot2_put_money; // ����� ����� ���������� ����2

                player_put_money*=player_card;
                player_money+=player_put_money; // ����� ����� ���������� ������
            } 
            if (Bot1_card > player_card && Bot2_card == 0) { // ���� ���2 �������

                Bot1_put_money*=Bot1_card;
                Bot1_money-=Bot1_put_money; // ����� ����� ������������ ����1

                player_put_money*=player_card;
                player_money+=player_put_money + Bot1_put_money; // ����� ����� ���������� ������
            }
        }

        if (Bot2_card > player_card && Bot2_card > Bot1_card) { // ���2 �������� ����
            
            if (Bot2_card > player_card && Bot1_card != 0) { // ���� ���1 �� �������
                
                if (player_card>Bot1_card) { // ����� �������� ������

                    for(Bot2_put_money; Bot2_put_money >0;) {
                        
                        if (player_card >= Bot2_put_money) {
                            player_money+=Bot2_put_money;
                            Bot2_put_money = 0;
                            break;
                        }
                        else if (Bot2_put_money > player_card) {
                            player_money+=player_card;
                            Bot2_put_money-=player_card;

                            if (Bot1_card >= Bot2_put_money) {
                                Bot1_money+=Bot2_put_money;
                                Bot2_put_money = 0;
                                break;
                            }
                        }
                        if (Bot1_card >= Bot2_put_money) {
                            Bot1_money+=Bot2_put_money;
                            Bot2_put_money = 0;
                            break;
                        }
                        else if (Bot2_put_money > Bot1_card) {
                            Bot1_money+=Bot1_card;
                            Bot2_put_money-=Bot1_card;

                            if (player_card >= Bot2_put_money) {
                                player_money+=Bot2_put_money;
                                Bot2_put_money = 0;
                                break;
                            } 
                        }
                    }
                }
                if (Bot1_card > player_card) { // ��� �������� ������
                    
                    for(Bot2_put_money; Bot2_put_money >0;) {

                        if (Bot1_card >= Bot2_put_money) {
                            Bot1_money+=Bot2_put_money;
                            Bot2_put_money=0;
                            break;
                        }
                        else if (Bot2_put_money > Bot1_card) {
                            Bot1_money+=Bot1_card;
                            Bot2_put_money-=Bot1_card;

                            if (player_card >= Bot2_put_money) {
                                player_money+=Bot2_put_money;
                                Bot2_put_money = 0;
                                break;
                            } 
                        }
                        if (player_card >= Bot2_put_money) {
                            player_money+=Bot2_put_money;
                            Bot2_put_money = 0;
                            break;
                        }
                        else if (Bot2_put_money > player_card) {
                            player_money+=player_card;
                            Bot2_put_money-=player_card;

                            if (Bot1_card >= Bot2_put_money) {
                                Bot1_money+=Bot2_put_money;
                                Bot2_put_money = 0;
                                break;
                            }
                        }
                    }
            }
            
            Bot2_put_money*=Bot2_card;
            Bot2_money-= Bot2_put_money; // ����� ����� ������������ ����2

            Bot1_put_money*=Bot1_card;
            Bot1_money+=Bot1_put_money; // ����� ����� ���������� ����1

            player_put_money*=player_card;
            player_money+=player_put_money; // ����� ����� ���������� ������
            }
            if (Bot2_card > player_card && Bot1_card == 0) { // ���� ��� 1 �������
                Bot2_put_money*=Bot2_card;
                Bot2_money-= Bot2_put_money; // ����� ����� ������������ ����2

                player_put_money*=player_card;
                player_money+=player_put_money + Bot2_put_money; // ����� ����� ���������� ������
            }
        }
        
        if (player_card > Bot1_card && player_card > Bot2_card) { // ����� �������� ����
             
            if (Bot1_card>Bot2_card && Bot2_bankrupt == false) { // ���1 �������� ������ � ���2 �� �������

                for(player_put_money; player_put_money >0;) {
                    if (Bot1_card >= player_put_money) {
                        Bot1_money+=player_put_money;
                        player_put_money = 0;
                        break;
                    }
                    else if (player_put_money > Bot1_card) { // ���1 ����� ������
                        Bot1_money+=Bot1_card;
                        player_put_money-=Bot1_card;

                        if (Bot2_card >= player_put_money) {
                            Bot2_money+=player_put_money;
                            player_put_money = 0;
                            break;
                        }
                    }
                    if (Bot2_card >= player_put_money) {
                        Bot2_money+=player_put_money;
                        player_put_money = 0;
                        break;
                    }
                    else if (player_put_money > Bot2_card) { // ���2 ����� ������
                        Bot2_money+=Bot2_card;
                        player_put_money-=Bot2_card;

                        if (Bot1_card >= player_put_money) {
                            Bot1_money+=player_put_money;
                            player_put_money = 0;
                            break;
                        } 
                    }
                }
            }
            if (Bot2_card>Bot1_card && Bot1_bankrupt == false) { // ���2 �������� ������ � ���1 �� �������

                for(player_put_money; player_put_money >0;) {
                    if (Bot2_card >= player_put_money) {
                        Bot2_money+=player_put_money;
                        player_put_money = 0;
                        break;
                    }
                    else if (player_put_money > Bot2_card) { // ���2 ����� ������
                        Bot2_money+=Bot2_card;
                        player_put_money-=Bot2_card;

                        if (Bot1_card >= player_put_money) {
                            Bot1_money+=player_put_money;
                            player_put_money = 0;
                            break;
                        }
                    }
                    if (Bot1_card >= player_put_money) {
                        Bot1_money+=player_put_money;
                        player_put_money = 0;
                        break;
                    }
                    else if (player_put_money > Bot1_card) { // ���1 ����� ������
                        Bot1_money+=Bot1_card;
                        player_put_money-=Bot1_card;

                        if (Bot2_card >= player_put_money) {
                            Bot2_money+=player_put_money;
                            player_put_money = 0;
                            break;
                        } 
                    }
                }
            }

            if (Bot1_bankrupt == true) {
                player_put_money*=player_card;
                player_money-=player_put_money; // ����� ����� ������������ ������

                Bot2_put_money*=Bot2_card;
                Bot2_money+=Bot2_put_money + player_put_money; // ����� ����� ���������� ����2
            }
            if (Bot2_bankrupt == true) {
                player_put_money*=player_card;
                player_money-=player_put_money; // ����� ����� ������������ ������

                Bot1_put_money*=Bot1_card;
                Bot1_money+=Bot1_put_money + player_put_money; // ����� ����� ���������� ����1
            }
            if (Bot2_bankrupt == false && Bot1_bankrupt == false) {
                player_put_money*=player_card;
                player_money-=player_put_money; // ����� ����� ������������ ������

                Bot1_put_money*=Bot1_card;
                Bot1_money+=Bot1_put_money + player_put_money; // ����� ����� ���������� ����1

                Bot2_put_money*=Bot2_card;
                Bot2_money+=Bot2_put_money + player_put_money; // ����� ����� ���������� ����2
            }


            
        }
        
    }

    if (player_money <=0) { // ����� ��������
        player_bankrupt = true;
        cout << "��� ��� ���� ��������� \n";
        return 0;
    }
    else { //����� �������
        cout << "���� ������: " << player_money << '\n';
    }

    if (Bot1_money <=0) { // ���1 ��������
        Bot1_bankrupt = true;
        cout << "��� ���1 ���� ��������� \n";
    }
    else { // ���1 �������
        cout << "������ 1 ����: " << Bot1_money << '\n';
    }

    if (Bot2_money <=0) { // ���2 ��������
        Bot2_bankrupt = true;
        cout << "��� ���2 ���� ��������� \n";
    }
    else { // ���2 �������
        cout << "������ 2 ����: " << Bot2_money << '\n';
    }
    
    if (Bot1_money <= 0 && Bot2_money <=0) {
        cout << "�� �������! \n";
        cout << "���� �������� ����������: " << player_money << " �����";
        return 0;
    }
    cout << "������� 0 ��� ���������� \n";
    }
    
    return 0;
}