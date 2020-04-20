// finance.c

int can_afford(int amount)
{
        int total;
        object gold, silver, coin;

        gold = present("gold_money");
        silver = present("silver_money");
        coin = present("coin_money");

        total = 0;
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        if (coin ) {
                if ((int)coin->value() < (amount%100))
                        return 2;
        } else if (amount%100) return 2;
        if (silver) {
                if (coin) {
                     if ((int)silver->value()+(int)coin->value()
                                < (amount % 10000))
                        return 2;
                }
        } else if (amount%10000) return 2;

        return 1;
}

int pay_money(object me,int amount)
{
        object g,s,c;
        int i,gold,silver,coin;

        seteuid(geteuid(me));

        g = present("gold",me);
        s = present("silver",me);
        c = present("coin",me);

        gold = 0;
        silver = 0;
        coin = 0;

        if(c) coin=c->value();
        if(coin >= amount) {
                c->add_amount(-amount);
                return 1;
        }
        if(s) silver=s->value();
        if((silver + coin) >= amount) {
                i = amount - coin;
                if(i%100) i = i / 100 + 1;
                else i = i / 100;

                s->add_amount(-i);
                if(!c) {
                        c = new(COIN_OB);
                        c->move(me);
                        c->set_amount(i * 100 - amount);
                }
                else    c->add_amount(i * 100 - amount);
                return 1;
        }
        i = amount - silver - coin;
        if(i % 10000) i = i / 10000 + 1;
        else i = i / 10000;
        g->add_amount(-i);
        if(!s) {
                s = new(SILVER_OB);
                s->move(me);
                s->set_amount(i * 100);
        }
        else    s->add_amount(i * 100);

        i = amount - coin;
        if(i % 100) i = i / 100 + 1;
        else i = i / 100;
        s->add_amount(-i);
        if(!c) {
                c = new(COIN_OB);
                c->move(me);
                c->set_amount(i * 100 - amount);
        }
        else    c->add_amount(i * 100 - amount);

        return 1;


}
