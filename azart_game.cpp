// СДЕЛАТЬ БОЛЬШЕ ИГРОКОВ, СМОТРЕТЬ ЗАМЕТКИ!!! СДЕЛАТЬ ВЫВОД ЕСЛИ ИГРОКИ ВЫБРАЛИ ОДИНАКОВОЕ КОЛ-ВО КАРТ
// ИСПРАВИТЬ КОГДА КАРТ ИГРОКОВ БОЛЬШ ЧЕМ ПОСТАВЛЕННЫЕ МОНЕТЫ!!
#include <iostream>

using std::cout, std::cin;



int main() {
    setlocale(0,"rus");
    srand(time(NULL));
    int player_money = 100; // кол-во монет
    int player_put_money; // кол-во поставленных монет игроком
    int Bot1_money = 100, Bot2_money = 100; //монеты ботов
    int Bot1_put_money, Bot2_put_money; // кол-во поставленных монет игрокомботами
    int Bot1_card,Bot2_card, player_card; // карты игроков
    int mode; // уровень сложности
    bool player_bankrupt=false, Bot1_bankrupt=false, Bot2_bankrupt=false; // банкроты

    cout << "Ваши деньги: " << player_money << '\n'; 

    cout << "Введите уровень сложности: 1) лёгкий 2)средний (нету) 3) сложный (нету) \n";
    cin >> mode;
    for (player_card; player_card != 0;) {
        switch (mode) {
        case 1:
        {
            cout << "Выбран лёгкий уровень сложности \n";
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
            cout << "Введён некоректный уровень сложности \n";
            return 0;
        }
    }
    
    do {
        cout << "Введите сумму которые вы хотите Поставить от 1 до " << player_money << '\n';
        cin >> player_put_money;
    } while (player_put_money < 0 || player_put_money >= player_money);
    

    player_money-=player_put_money;

    if (Bot1_bankrupt == false) {
        cout << "Бот 1 Поставил: "<< Bot1_put_money << '\n';
    }
    if (Bot2_bankrupt == false) {
        cout << "Бот 2 Поставил: "<< Bot2_put_money << '\n';
    }
    

    cout << "Введите кол-во карт которые хотите взять: ";
    cin >> player_card;

    cout << "Игрок поставил: " << player_card << '\n'; 
    if (Bot1_bankrupt == false) {cout << "Бот 1 взял: "<< Bot1_card << '\n';}
    if (Bot2_bankrupt == false) {cout << "Бот 2 взял: "<< Bot2_card << '\n';}


    /*if (player_card > Bot1_card && player_card > Bot2_card) // игрок проиграл всем
    {
        player_put_money*=2;
        player_money-=player_put_money; // общая сумма с проигрешем

        Bot1_put_money*=Bot1_card;
        Bot1_money+=Bot1_put_money; // общая сумма победы 1 бота

        Bot2_put_money*=Bot2_card;
        Bot2_money+=Bot2_put_money; // общая сумма победы 2 бота

        for(player_put_money;player_put_money >0;) {
            if (Bot1_card > Bot2_card && player_put_money >0) { 
                if (player_put_money >= Bot1_card) {   // Первый игрок получает фишки первым
                    Bot1_money+=Bot1_card;
                    player_put_money-= Bot1_card;


                    if (Bot2_card >= player_put_money) { // Если проигравших фишек стало мало, второй игрок забирает остатки
                        Bot2_money+=player_put_money;
                        player_put_money = 0;
                    }
                }

                if (player_put_money >= Bot2_card) { // Второй игрок получает фишки вторым
                    Bot2_money+=Bot2_card;
                    player_put_money-= Bot2_card;


                    if(Bot1_card >= player_put_money) { // Если проигравших фишек стало мало, первый игрок забирает остатки
                        Bot1_money+=player_put_money;
                        player_put_money = 0;
                    }
                }

            }
                
            else if (Bot2_card > Bot1_card && player_put_money >=0) { //Победитель второй игрок
                if (player_put_money >= Bot2_card) {   // Первый игрок получает фишки первым
                    Bot2_money+=Bot2_card;
                    player_put_money-= Bot2_card;


                    if (Bot1_card >= player_put_money) { // Если проигравших фишек стало мало, второй игрок забирает остатки
                        Bot1_money+=player_put_money;
                        player_put_money = 0;
                    }
                }

                if (player_put_money >= Bot1_card) { // Второй игрок получает фишки вторым
                    Bot1_money+=Bot1_card;
                    player_put_money-= Bot1_card;


                    if(Bot2_card >= player_put_money) { // Если проигравших фишек стало мало, первый игрок забирает остатки
                        Bot2_money+=player_put_money;
                        player_put_money = 0;
                    }
                }
            }
        }   
    } */
    
    if (Bot1_card > player_card && Bot1_card > Bot2_card || Bot2_card > player_card && Bot2_card > Bot1_card || player_card > Bot1_card && player_card > Bot2_card)
    {
        if (Bot1_card > player_card && Bot1_card > Bot2_card) { // Бот1 проиграл всем

            if (Bot1_card > player_card && Bot2_card != 0) { // Если бот2 Не банкрот
                
                if (player_card>Bot2_card) { // игрок получает первым

                    for(Bot1_put_money; Bot1_put_money >0;) { // Карты игрока больше чем поставил бот1
                        
                        if (player_card >= Bot1_put_money) {
                            player_money+=Bot1_put_money;
                            Bot1_put_money = 0;
                            break;
                        }
                        else if (Bot1_put_money > player_card) {
                            player_money+=player_card;
                            Bot1_put_money-=player_card;

                            if (Bot2_card >= Bot1_put_money) { // остаток боту2
                                Bot2_money+=Bot1_put_money;
                                Bot1_put_money = 0;
                                break;
                            }
                        }
                        if (Bot2_card >= Bot1_put_money) { // Карты бота больше чем поставил бот1
                            Bot2_money+=Bot1_put_money;
                            Bot1_put_money = 0;
                            break;
                        }
                        else if (Bot1_put_money > Bot2_card) { //бот2 ходит вторым
                            Bot2_money+=Bot2_card;
                            Bot1_put_money-=Bot2_card;

                            if (player_card >= Bot1_put_money) { //остаток игроку
                                player_money+=Bot1_put_money;
                                Bot1_put_money = 0;
                                break;
                            } 
                        }
                    }
                }
                if (Bot2_card > player_card) { // бот2 получает первым
                    
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
                Bot1_money-=Bot1_put_money; // общая сумма проигравшего Бота1

                Bot2_put_money*=Bot2_card;
                Bot2_money+=Bot2_put_money; // общая сумма победителя Бота2

                player_put_money*=player_card;
                player_money+=player_put_money; // общая сумма победителя игрока
            } 
            if (Bot1_card > player_card && Bot2_card == 0) { // Если Бот2 банкрот

                Bot1_put_money*=Bot1_card;
                Bot1_money-=Bot1_put_money; // общая сумма проигравшего Бота1

                player_put_money*=player_card;
                player_money+=player_put_money + Bot1_put_money; // общая сумма победителя игрока
            }
        }

        if (Bot2_card > player_card && Bot2_card > Bot1_card) { // Бот2 проиграл всем
            
            if (Bot2_card > player_card && Bot1_card != 0) { // Если бот1 Не банкрот
                
                if (player_card>Bot1_card) { // игрок получает первым

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
                if (Bot1_card > player_card) { // бот получает первым
                    
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
            Bot2_money-= Bot2_put_money; // общая сумма проигравшего Бота2

            Bot1_put_money*=Bot1_card;
            Bot1_money+=Bot1_put_money; // общая сумма победителя Бота1

            player_put_money*=player_card;
            player_money+=player_put_money; // общая сумма победителя игрока
            }
            if (Bot2_card > player_card && Bot1_card == 0) { // Если бот 1 банкрот
                Bot2_put_money*=Bot2_card;
                Bot2_money-= Bot2_put_money; // общая сумма проигравшего Бота2

                player_put_money*=player_card;
                player_money+=player_put_money + Bot2_put_money; // общая сумма победителя игрока
            }
        }
        
        if (player_card > Bot1_card && player_card > Bot2_card) { // Игрок проиграл всем
             
            if (Bot1_card>Bot2_card && Bot2_bankrupt == false) { // Бот1 получает первым И Бот2 не банкрот

                for(player_put_money; player_put_money >0;) {
                    if (Bot1_card >= player_put_money) {
                        Bot1_money+=player_put_money;
                        player_put_money = 0;
                        break;
                    }
                    else if (player_put_money > Bot1_card) { // Бот1 ходит первым
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
                    else if (player_put_money > Bot2_card) { // Бот2 ходит вторым
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
            if (Bot2_card>Bot1_card && Bot1_bankrupt == false) { // Бот2 получает первым И Бот1 не банкрот

                for(player_put_money; player_put_money >0;) {
                    if (Bot2_card >= player_put_money) {
                        Bot2_money+=player_put_money;
                        player_put_money = 0;
                        break;
                    }
                    else if (player_put_money > Bot2_card) { // Бот2 ходит первым
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
                    else if (player_put_money > Bot1_card) { // Бот1 ходит вторым
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
                player_money-=player_put_money; // общая сумма проигравшего игрока

                Bot2_put_money*=Bot2_card;
                Bot2_money+=Bot2_put_money + player_put_money; // общая сумма победителя Бота2
            }
            if (Bot2_bankrupt == true) {
                player_put_money*=player_card;
                player_money-=player_put_money; // общая сумма проигравшего игрока

                Bot1_put_money*=Bot1_card;
                Bot1_money+=Bot1_put_money + player_put_money; // общая сумма победителя Бота1
            }
            if (Bot2_bankrupt == false && Bot1_bankrupt == false) {
                player_put_money*=player_card;
                player_money-=player_put_money; // общая сумма проигравшего игрока

                Bot1_put_money*=Bot1_card;
                Bot1_money+=Bot1_put_money + player_put_money; // общая сумма победителя Бота1

                Bot2_put_money*=Bot2_card;
                Bot2_money+=Bot2_put_money + player_put_money; // общая сумма победителя Бота2
            }


            
        }
        
    }

    if (player_money <=0) { // Игрок выбывает
        player_bankrupt = true;
        cout << "Для вас игра закончена \n";
        return 0;
    }
    else { //игрок остаётся
        cout << "Ваши деньги: " << player_money << '\n';
    }

    if (Bot1_money <=0) { // Бот1 выбывает
        Bot1_bankrupt = true;
        cout << "Для Бот1 игра закончена \n";
    }
    else { // Бот1 остаётся
        cout << "Деньги 1 бота: " << Bot1_money << '\n';
    }

    if (Bot2_money <=0) { // Бот2 выбывает
        Bot2_bankrupt = true;
        cout << "Для Бот2 игра закончена \n";
    }
    else { // Бот2 остаётся
        cout << "Деньги 2 бота: " << Bot2_money << '\n';
    }
    
    if (Bot1_money <= 0 && Bot2_money <=0) {
        cout << "Ты победил! \n";
        cout << "Твой выйгрышь составляет: " << player_money << " монет";
        return 0;
    }
    cout << "Введите 0 для завершения \n";
    }
    
    return 0;
}